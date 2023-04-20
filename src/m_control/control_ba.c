/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Control module
*/

#include "../include/main.h"

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
        game_data->speed.x = game_data->speed.x > 0 ? 0 : game_data->speed.x;
    }
    if (game_data->speed.y > epsilon) {
        game_data->speed.y -= game_data->friction;
        if (game_data->speed.y < 0) game_data->speed.y = 0;
    } else if (game_data->speed.y < -epsilon) {
        game_data->speed.y += game_data->friction;
        game_data->speed.y = game_data->speed.y > 0 ? 0 : game_data->speed.y;
    }
    float sp_max = game_data->speed_max;
    game_data->speed.x = force_range(game_data->speed.x, -sp_max, sp_max);
    game_data->speed.y = force_range(game_data->speed.y, -sp_max, sp_max);
}

void move_camera(s_appdata *adata, sfVector2f pos)
{
    s_game *game_data = adata->game_data;
    sfVector2f shift;

    shift.x = pos.x - game_data->view_pos.x;
    shift.y = pos.y - game_data->view_pos.y;

    move_gameobject_lights(adata, shift);
    move_gameobject_emiters(adata, shift);
    move_gameobject_walls(adata, shift);

    game_data->view_pos = pos;
    adata->player->hitbox = (sfFloatRect){ 910 + adata->game_data->view_pos.x,
    490 + adata->game_data->view_pos.y, 100, 100 };

    sfMouseMoveEvent ms;
    ms.type = sfEvtMouseMoved;
    ms.x = 0;
    ms.y = 0;

    register_mousemove(adata, ms);
}
