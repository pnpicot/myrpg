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
    s_player *player = adata->player;

    next_pos.x += add.x;
    next_pos.y += add.y;

    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    float zoom = get_float(adata, "zoom");

    if (player->solid)
        add = is_map_colliding(adata, NULL, add);

    for (int i = adata->player->hitbox.top; i < (adata->player->hitbox.top +
    adata->player->hitbox.height) && i > 0 &&
    i < adata->game_data->col_map_size.y; i++) {
        for (int j = adata->player->hitbox.left; j < (adata->player->hitbox.left
        + adata->player->hitbox.width) && j > 0 &&
        j < adata->game_data->col_map_size.x; j++) {
            adata->game_data->col_map[i][j] = NULL;
        }
    }

    sfVector2f shift;
    shift.x = -add.x;
    shift.y = -add.y;

    move_gameobject_lights(adata, shift);
    move_gameobject_emiters(adata, shift);
    move_gameobject_walls(adata, shift);
    game_data->view_pos.x += add.x;
    game_data->view_pos.y += add.y;

    adata->player->hitbox = (sfFloatRect){ 910 + adata->game_data->view_pos.x,
    490 + adata->game_data->view_pos.y, 100, 100 };
    for (int i = adata->player->hitbox.top; i < (adata->player->hitbox.top +
    adata->player->hitbox.height) && i >= 0 &&
    i < adata->game_data->col_map_size.y; i++) {
        for (int j = adata->player->hitbox.left; j < (adata->player->hitbox.left
        + adata->player->hitbox.width) && j >= 0 &&
        j < adata->game_data->col_map_size.x; j++) {
            adata->game_data->col_map[i][j] = (s_entity *)2;
        }
    }

    sfMouseMoveEvent ms;
    ms.type = sfEvtMouseMoved;
    ms.x = 0;
    ms.y = 0;
    register_mousemove(adata, ms);
    sfClock_restart(clocks->movement_clock);
}

void update_controls(s_appdata *adata)
{
    s_player *player = adata->player;

    if (player->host != NULL) {
        update_host_controls(adata);
        return;
    }

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
