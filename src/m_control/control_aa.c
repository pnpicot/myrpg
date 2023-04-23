/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Control module
*/

#include "../include/main.h"

void update_player_col_map(s_appdata *adata, s_entity *ptr)
{
    for (int i = adata->player->hitbox.top; i < (adata->player->hitbox.top +
    adata->player->hitbox.height) && i > 0 &&
    i < adata->game_data->col_map_size.y; i++) {
        for (int j = adata->player->hitbox.left; j < (adata->player->hitbox.left
        + adata->player->hitbox.width) && j > 0 &&
        j < adata->game_data->col_map_size.x; j++) {
            adata->game_data->col_map[i][j] = ptr;
        }
    }
}

void translate_player(s_appdata *adata, sfVector2f pos_ch)
{
    s_game *game_data = adata->game_data;

    update_player_col_map(adata, NULL);

    sfVector2f shift;
    shift.x = -pos_ch.x;
    shift.y = -pos_ch.y;

    move_gameobject_lights(adata, shift);
    move_gameobject_emiters(adata, shift);
    move_gameobject_walls(adata, shift);
    game_data->view_pos.x += pos_ch.x;
    game_data->view_pos.y += pos_ch.y;

    adata->player->hitbox = (sfFloatRect){ 910 + adata->game_data->view_pos.x,
    490 + adata->game_data->view_pos.y, 100, 100 };

    update_player_col_map(adata, (s_entity *)2);
}

void update_controls_next(s_appdata *adata, s_game *game_data, \
float delta, s_clocks *clocks)
{
    update_speed(adata);

    sfVector2f add = {game_data->speed.x * delta, game_data->speed.y * delta};
    sfVector2f next_pos = game_data->view_pos;
    sfVector2f save = add;
    s_player *player = adata->player;
    next_pos.x += add.x;
    next_pos.y += add.y;
    if (player->solid)
        add = is_map_colliding(adata, NULL, add);
    if (add.x != save.x)
        game_data->speed.x = 0;
    if (add.y != save.y)
        game_data->speed.y = 0;
    translate_player(adata, add);
    sfMouseMoveEvent ms = {.type = sfEvtMouseMoved, .x = 0, .y = 0};
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
