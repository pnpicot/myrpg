/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** In-game ui module
*/

#include "main.h"

void init_ingame_stats(s_appdata *adata, char *container, char *rtex)
{
    char *id = get_str(adata, "stats_widget");
    float zoom = 4.0f;

    add_sprite(adata, id, 1);
    set_sprite_texture(adata, id, get_texture(adata, "stats_w"));
    set_sprite_rtex(adata, id, rtex);
    add_to_container(adata, container, (s_ref) { get_sprite(adata, id),
    TYPE_SPRITE });
    scale_sprite(adata, id, (sfVector2f) { zoom, zoom });

    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    sfFloatRect bounds = get_sprite_bounds(adata, id);

    move_sprite(adata, id,
    (sfVector2f) { 20.0f, win_h - 20.0f - bounds.height });
    init_stats_title(adata, container, rtex, id);
    init_stats_health(adata, container, rtex, id);
    init_stats_transference(adata, container, rtex, id);
    init_stats_text(adata, container, rtex, id);
}

void init_live_ingame_ui(s_appdata *adata)
{
    char *container = get_str(adata, "ctn_game");
    char *rtex = get_str(adata, "rtex_ui");

    init_ingame_fps(adata, container, rtex);
    init_ingame_stats(adata, container ,rtex);
    init_ingame_waves(adata, container, rtex);
}
