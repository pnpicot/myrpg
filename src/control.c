/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Control module
*/

#include "main.h"

void set_friction(s_appdata *adata, float friction)
{
    s_game *game_data = adata->game_data;

    game_data->friction = friction;
}

void set_velocity(s_appdata *adata, float velocity)
{
    s_game *game_data = adata->game_data;

    game_data->velocity = velocity;
}

void set_max_speed(s_appdata *adata, float max_speed)
{
    s_game *game_data = adata->game_data;

    game_data->speed_max = max_speed;
}

void update_speed(s_appdata *adata)
{
    s_game *game_data = adata->game_data;
    float epsilon = 10e-3;

    if (game_data->speed.x > epsilon) {
        game_data->speed.x -= game_data->friction;

        if (game_data->speed.x < 0) game_data->speed.x = 0;
    } else if (game_data->speed.x < -epsilon) {
        game_data->speed.x += game_data->friction;

        if (game_data->speed.x > 0) game_data->speed.x = 0;
    }

    if (game_data->speed.y > epsilon) {
        game_data->speed.y -= game_data->friction;

        if (game_data->speed.y < 0) game_data->speed.y = 0;
    } else if (game_data->speed.y < -epsilon) {
        game_data->speed.y += game_data->friction;

        if (game_data->speed.y > 0) game_data->speed.y = 0;
    }

    game_data->speed.x = force_range(game_data->speed.x, -game_data->speed_max, game_data->speed_max);
    game_data->speed.y = force_range(game_data->speed.y, -game_data->speed_max, game_data->speed_max);
}

void update_controls(s_appdata *adata)
{
    s_game *game_data = adata->game_data;
    s_clocks *clocks = adata->clocks;
    float delta = get_clock_seconds(clocks->movement_clock);

    if (get_key(adata, sfKeyQ)) {
        game_data->speed.x -= game_data->velocity;
    }

    if (get_key(adata, sfKeyD)) {
        game_data->speed.x += game_data->velocity;
    }

    if (get_key(adata, sfKeyZ)) {
        game_data->speed.y -= game_data->velocity;
    }

    if (get_key(adata, sfKeyS)) {
        game_data->speed.y += game_data->velocity;
    }

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
