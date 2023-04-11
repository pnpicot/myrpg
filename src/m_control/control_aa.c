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
    sfVector2f add = {game_data->speed.x * delta, game_data->speed.y * delta};
    sfVector2f next_pos = game_data->view_pos;

    next_pos.x += add.x;
    next_pos.y += add.y;

    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    float zoom = get_float(adata, "zoom");

    if (next_pos.x < 0) add.x = 0;
    if (next_pos.y < 0) add.y = 0;
    if (next_pos.x > (game_data->map_width * 32 * zoom) - win_w) add.x = 0;
    if (next_pos.y > (game_data->map_height * 32 * zoom) - win_h) add.y = 0;

    add = is_map_colliding(adata, adata->player->hitbox, add);

    sfVector2f shift;
    shift.x = -add.x;
    shift.y = -add.y;

    move_gameobject_lights(adata, shift);
    move_gameobject_emiters(adata, shift);
    move_gameobject_walls(adata, shift);
    game_data->view_pos.x += add.x;
    game_data->view_pos.y += add.y;
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
