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

        ite++;
    }
}

void add_tile_to_map(s_appdata *adata, char ch, int id, sfVector2f pos)
{
    s_tile *tile = get_tile(adata, ch);

    if (tile == NULL) return;

    char *tile_id = str_add("@[:tile]-", nbr_to_str(id));
    char *rtex = get_str(adata, tile->wall ? "rtex_wall" : "rtex_game");
    char *container = get_str(adata, "ctn_game");
    float zoom = get_float(adata, "zoom");

    add_sprite(adata, tile_id, 1);
    set_sprite_rtex(adata, tile_id, rtex);
    add_to_container(adata, container, (s_ref) { get_sprite(adata, tile_id ), TYPE_SPRITE });
    set_sprite_texture(adata, tile_id, tile->tex);
    scale_sprite(adata, tile_id, (sfVector2f) { zoom, zoom });
    move_sprite(adata, tile_id, (sfVector2f) { pos.x * 32 * zoom, pos.y * 32 * zoom });

    char *gobj = str_add(tile_id, "@[:gobj]");

    add_gameobject(adata, gobj);
    set_gameobject_ref(adata, gobj, get_sprite(adata, tile_id), TYPE_SPRITE );

    if (tile->wall)
        add_gameobject_hitbox(adata, gobj);
}

void load_map(s_appdata *adata, char *map)
{
    char **rows = str_split(map, '\n');
    int ite = 0;
    int id = 0;

    while (rows[ite] != NULL) {
        for (int i = 0; i < my_strlen(rows[ite]); i++) {
            id++;
            add_tile_to_map(adata, rows[ite][i], id, (sfVector2f) { i, ite });
        }

        ite++;
    }
}

void init_map(s_appdata *adata, char *filename)
{
    load_tiles(adata);

    char *path = str_add("bonus/maps/", filename);
    char *map = file_extract(path);

    if (map == NULL) {
        my_printf(get_error(adata, "no_file"));
        return;
    }

    load_map(adata, map);
}
