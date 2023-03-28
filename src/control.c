/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Control module
*/

#include "main.h"

void update_controls(s_appdata *adata)
{
    s_game *game_data = adata->game_data;

    if (get_key(adata, sfKeyQ)) {
        game_data->view_pos.x -= 10.0f;
        move_gameobject_lights(adata, (sfVector2f) { 10.0f, 0 });
        move_gameobject_emiters(adata, (sfVector2f) { 10.0f, 0 });
        move_gameobject_walls(adata, (sfVector2f) { 10.0f, 0 });
    }

    if (get_key(adata, sfKeyD)) {
        game_data->view_pos.x += 10.0f;
        move_gameobject_lights(adata, (sfVector2f) { -10.0f, 0 });
        move_gameobject_emiters(adata, (sfVector2f) { -10.0f, 0 });
        move_gameobject_walls(adata, (sfVector2f) { -10.0f, 0 });
    }

    if (get_key(adata, sfKeyZ)) {
        game_data->view_pos.y -= 10.0f;
        move_gameobject_lights(adata, (sfVector2f) { 0, 10.0f });
        move_gameobject_emiters(adata, (sfVector2f) { 0, 10.0f });
        move_gameobject_walls(adata, (sfVector2f) { 0, 10.0f });
    }

    if (get_key(adata, sfKeyS)) {
        game_data->view_pos.y += 10.0f;
        move_gameobject_lights(adata, (sfVector2f) { 0, -10.0f });
        move_gameobject_emiters(adata, (sfVector2f) { 0, -10.0f });
        move_gameobject_walls(adata, (sfVector2f) { 0, -10.0f });
    }

    sfMouseMoveEvent ms;
    ms.type = sfEvtMouseMoved;
    ms.x = 0;
    ms.y = 0;

    register_mousemove(adata, ms);
}
