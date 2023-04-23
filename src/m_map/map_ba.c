/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Map module
*/

#include "main.h"

s_tile *get_tile(s_appdata *adata, char id)
{
    linked_node *tiles = adata->lists->tiles;

    while (tiles != NULL && tiles->data != NULL) {
        s_tile *cur = (s_tile *) tiles->data;

        if (cur->id == id) return (cur);

        tiles = tiles->next;
    }

    return (NULL);
}

void add_tile(s_appdata *adata, char ch, char *tex_id, sfBool solid)
{
    s_tile *tile = get_tile(adata, ch);
    if (tile != NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "already_exists"));
        return;
    }
    s_tile *new_tile = malloc(sizeof(s_tile));
    if (new_tile == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return;
    }
    sfTexture *tex = get_texture(adata, tex_id);
    if (tex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }
    *new_tile = (s_tile) {.id = ch, .tex = tex, .wall = solid};
    linked_add(adata->lists->tiles, new_tile);
}

void load_tiles(s_appdata *adata)
{
    char *file_content = file_extract("bonus/tiles.myrpg");
    char **entries = str_split(file_content, '\n');
    int ite = 0;
    free(file_content);
    for (; entries[ite] != NULL; ++ite) {
        if (entries[ite][0] == '#') {
            continue;
        }
        char **entry_data = str_m_split(entries[ite], 2, '=', ' ');
        char ch = entry_data[0][0];
        char *tex_id = entry_data[1];
        sfBool solid = entry_data[2][0] != '0' ? sfTrue : sfFalse;
        add_tile(adata, ch, tex_id, solid);
        for (int i = 0; entry_data[i] != NULL; i++)
            free(entry_data[i]);
        free(entry_data);
    }
    for (int i = 0; entries[i] != NULL; i++)
        free(entries[i]);
    free(entries);
}

void add_tile_to_map_n(s_appdata *adata, char *tile_id, sfIntRect rect,
sfVector2f pos)
{
    float zoom = get_float(adata, "zoom");

    scale_sprite(adata, tile_id, (sfVector2f) { zoom, zoom });
    set_sprite_rect(adata, tile_id, rect);
    set_sprite_repeat(adata, tile_id, sfTrue);
    move_sprite(adata, tile_id,
    (sfVector2f) { pos.x * 32 * zoom, pos.y * 32 * zoom });
    char *gobj = str_add(tile_id, "@[:gobj]");
    add_gameobject(adata, gobj);
    set_gameobject_ref(adata, gobj, get_sprite(adata, tile_id), TYPE_SPRITE );
}

void add_tile_to_map(s_appdata *adata, char ch, sfVector2f pos, \
sfVector2f size)
{
    s_tile *tile = get_tile(adata, ch);
    if (tile == NULL) return;
    char *rid = get_random_id(6);
    char *tile_id = str_add("@[:tile]-", rid);
    char *rtex = get_str(adata, tile->wall ? "rtex_wall" : "rtex_game");
    char *gobj = str_add(tile_id, "@[:gobj]");
    char *container = get_str(adata, "ctn_game");
    sfIntRect rect = { 0, 0, 32 * size.x, 32 * size.y};
    free(rid);
    add_sprite(adata, tile_id, 1);
    set_sprite_rtex(adata, tile_id, rtex);
    add_to_container(adata, container,
    (s_ref) { get_sprite(adata, tile_id ), TYPE_SPRITE });
    set_sprite_texture(adata, tile_id, tile->tex);
    add_tile_to_map_n(adata, tile_id, rect, pos);
    if (tile->wall)
        add_gameobject_hitbox(adata, gobj);
    free(gobj);
}
