/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Parasite (player) module
*/

#include "main.h"

void update_player(s_appdata *adata)
{
    char *sprite_id = get_str(adata, "player_body");
    s_player *player = adata->player;
    s_game *game_data = adata->game_data;
    sfVector2f speed = game_data->speed;
    float angle = get_sprite_rotation(adata, sprite_id);
    float epsilon = 10e-4;

    if (in_range(speed.x, -epsilon, epsilon) && in_range(speed.y, -epsilon, epsilon)) {
        pause_animation(adata, sprite_id);
        return;
    } else {
        start_animation(adata, sprite_id);
    }

    if (speed.x > 0 && in_range(speed.y, -epsilon, epsilon)) angle = 90.0f;
    else if (speed.x > 0 && speed.y < 0) angle = 45.0f;
    else if (speed.x > 0 && speed.y > 0) angle = 135.0f;

    if (speed.x < 0 && in_range(speed.y, -epsilon, epsilon)) angle = 270.0f;
    else if (speed.x < 0 && speed.y < 0) angle = 315.0f;
    else if (speed.x < 0 && speed.y > 0) angle = 225.0f;

    if (speed.y < 0 && in_range(speed.x, -epsilon, epsilon)) angle = 0;
    else if (speed.y > 0 && in_range(speed.x, -epsilon, epsilon)) angle = 180.0f;

    rotate_sprite(adata, sprite_id, angle);
}

void init_player(s_appdata *adata)
{
    adata->player = malloc(sizeof(s_player));

    if (adata->player == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    s_player *player = adata->player;
    char *sprite_id = get_str(adata, "player_body");
    char *rtex = get_str(adata, "rtex_game");
    char *container = get_str(adata, "ctn_game");
    float zoom = get_float(adata, "zoom");
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");

    player->health = 5;

    add_sprite(adata, sprite_id, 3);
    set_sprite_rtex(adata, sprite_id, rtex);

    s_sprite *body = get_sprite(adata, sprite_id);

    add_to_container(adata, container, (s_ref) { body, TYPE_SPRITE });
    set_sprite_texture(adata, sprite_id, get_texture(adata, "parasite"));
    scale_sprite(adata, sprite_id, (sfVector2f) { zoom * 1.5f, zoom * 1.5f });
    animate_sprite(adata, sprite_id);
    set_animation_rows(adata, sprite_id, 1);
    set_animation_cols(adata, sprite_id, 7);
    set_animation_speed(adata, sprite_id, 0.04f);
    set_sprite_origin(adata, sprite_id, (sfVector2f) { 24, 24 });
    move_sprite(adata, sprite_id, (sfVector2f) { win_w / 2, win_h / 2 });
    pause_animation(adata, sprite_id);
}
