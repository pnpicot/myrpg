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
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    s_tile *new_tile = malloc(sizeof(s_tile));

    if (new_tile == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    sfTexture *tex = get_texture(adata, tex_id);

    if (tex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    new_tile->id = ch;
    new_tile->tex = tex;
    new_tile->wall = solid;

    linked_add(adata->lists->tiles, new_tile);
}

void load_tiles(s_appdata *adata)
{
    char *file_content = file_extract("bonus/tiles.myrpg");
    char **entries = str_split(file_content, '\n');
    int ite = 0;

    free(file_content);
    while (entries[ite] != NULL) {
        if (entries[ite][0] == '#') {
            ite++;
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

        ite++;
    }
    for (int i = 0; entries[i] != NULL; i++)
        free(entries[i]);
    free(entries);
}

void add_tile_to_map(s_appdata *adata, char ch, sfVector2f pos, \
sfVector2f size)
{
    s_tile *tile = get_tile(adata, ch);

    if (tile == NULL) return;

    char *rid = get_random_id(6);
    char *tile_id = str_add("@[:tile]-", rid);
    char *rtex = get_str(adata, tile->wall ? "rtex_wall" : "rtex_game");
    char *container = get_str(adata, "ctn_game");
    float zoom = get_float(adata, "zoom");
    sfIntRect rect;

    free(rid);
    rect.left = 0;
    rect.top = 0;
    rect.width = 32 * size.x;
    rect.height = 32 * size.y;

    add_sprite(adata, tile_id, 1);
    set_sprite_rtex(adata, tile_id, rtex);
    add_to_container(adata, container, (s_ref) { get_sprite(adata, tile_id ), TYPE_SPRITE });
    set_sprite_texture(adata, tile_id, tile->tex);
    scale_sprite(adata, tile_id, (sfVector2f) { zoom, zoom });
    set_sprite_rect(adata, tile_id, rect);
    set_sprite_repeat(adata, tile_id, sfTrue);
    move_sprite(adata, tile_id, (sfVector2f) { pos.x * 32 * zoom, pos.y * 32 * zoom });

    char *gobj = str_add(tile_id, "@[:gobj]");

    add_gameobject(adata, gobj);
    set_gameobject_ref(adata, gobj, get_sprite(adata, tile_id), TYPE_SPRITE );

    if (tile->wall)
        add_gameobject_hitbox(adata, gobj);
}

void load_map(s_appdata *adata, char *map)
{
    char **entries = str_split(map, '\n');
    int ite = 0;
    int max_x = 0;
    int max_y = 0;

    while (entries[ite] != NULL) {
        char **entry_data = str_split(entries[ite], ' ');

        if (count_nil_str(entry_data) < 5) {
            ite++;
            continue;
        }

        char type = entry_data[0][0];
        int x = my_getnbr(entry_data[1]);
        int y = my_getnbr(entry_data[2]);
        int width = my_getnbr(entry_data[3]);
        int height = my_getnbr(entry_data[4]);

        if (x + width > max_x) max_x = x + width;
        if (y + height > max_y) max_y = y + height;

        add_tile_to_map(adata, type, (sfVector2f) { x, y }, (sfVector2f) { width, height });

        for (int i = 0; entry_data[i] != NULL; i++)
            free(entry_data[i]);
        free(entry_data);
        ite++;
    }

    init_map_path_finding(adata, entries, max_x, max_y);

    for (int i = 0; entries[i] != NULL; i++)
        free(entries[i]);
    free(entries);
}

void init_map(s_appdata *adata, char *filename)
{
    load_tiles(adata);

    char *path = str_add("bonus/maps/", filename);
    char *map = file_extract(path);
    free(path);

    if (map == NULL) {
        my_printf(get_error(adata, "no_file"));
        return;
    }

    load_map(adata, map);
    free(map);
}
