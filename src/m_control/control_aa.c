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
    sfVector2f shift;
    shift.x = -(game_data->speed.x * delta);
    shift.y = -(game_data->speed.y * delta);
    move_gameobject_lights(adata, shift);
    move_gameobject_emiters(adata, shift);
    move_gameobject_walls(adata, shift);
    game_data->view_pos.x += game_data->speed.x * delta;
    game_data->view_pos.y += game_data->speed.y * delta;
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
