/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Control module
*/

#include "../include/main.h"

void update_controls_next(s_appdata *adata, s_game *game_data, \
float delta, s_clocks *clocks)
{
    update_speed(adata);
    float add_x = game_data->speed.x * delta;
    float add_y = game_data->speed.y * delta;
    sfVector2f next_pos = game_data->view_pos;

    next_pos.x += add_x;
    next_pos.y += add_y;

    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    float zoom = get_float(adata, "zoom");

    if (next_pos.x < 0) add_x = 0;
    if (next_pos.y < 0) add_y = 0;
    if (next_pos.x > (game_data->map_width * 32 * zoom) - win_w) add_x = 0;
    if (next_pos.y > (game_data->map_height * 32 * zoom) - win_h) add_y = 0;

    sfVector2f shift;
    shift.x = -add_x;
    shift.y = -add_y;

    move_gameobject_lights(adata, shift);
    move_gameobject_emiters(adata, shift);
    move_gameobject_walls(adata, shift);
    game_data->view_pos.x += add_x;
    game_data->view_pos.y += add_y;
    sfMouseMoveEvent ms;
    ms.type = sfEvtMouseMoved;
    ms.x = 0;
    ms.y = 0;
    register_mousemove(adata, ms);
    sfClock_restart(clocks->movement_clock);
}

void update_controls(s_appdata *adata)
{
    s_game *game_data = adata->game_data;
    s_clocks *clocks = adata->clocks;
    float delta = get_clock_seconds(clocks->movement_clock);

    if (get_key(adata, sfKeyQ))
        game_data->speed.x -= game_data->velocity;
    if (get_key(adata, sfKeyD))
        game_data->speed.x += game_data->velocity;
    if (get_key(adata, sfKeyZ))
        game_data->speed.y -= game_data->velocity;
    if (get_key(adata, sfKeyS))
        game_data->speed.y += game_data->velocity;

    update_controls_next(adata, game_data, delta, clocks);
}
