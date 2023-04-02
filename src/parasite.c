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
    float epsilon = 10e-4;

    if (in_range(speed.x, -epsilon, epsilon) && in_range(speed.y, -epsilon, epsilon)) {
        pause_animation(adata, sprite_id);
        return;
    } else {
        start_animation(adata, sprite_id);
    }

    float angle = (atan2f(speed.y, speed.x) * (180 / M_PI)) + 90.0f;
    float rv_angle = angle - 270.0f;

    if (rv_angle < 0) rv_angle += 360.0f;
    else if (rv_angle > 0) rv_angle -= 360.0f;

    sfVector2f part_angle;
    part_angle.x = rv_angle - 35.0f;
    part_angle.y = rv_angle + 35.0f;

    set_emiter_cone(adata, get_str(adata, "player_particles"), part_angle);
    rotate_sprite(adata, sprite_id, angle);
}

void init_player_particles(s_appdata *adata)
{
    char *particles = get_str(adata, "player_particles");
    char *rtex = get_str(adata, "rtex_game");
    char *container = get_str(adata, "ctn_game");
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");

    add_emiter(adata, particles);
    set_emiter_rtex(adata, particles, rtex);
    add_to_container(adata, container, (s_ref) { get_emiter(adata, particles), TYPE_EMITER });
    set_emiter_lifetime(adata, particles, 1500000);
    set_emiter_particle_lifetime(adata, particles, 3500);
    set_emiter_particle_max(adata, particles, 550);
    set_emiter_spawnrate(adata, particles, 1.0f);
    set_emiter_model(adata, particles, "gen");
    set_emiter_colors(adata, particles, sfBlack, sfDarkGray);
    set_emiter_gameobject(adata, particles, sfFalse);
    set_emiter_size_range(adata, particles, (sfVector2f) { 1.3f, 1.3f }, (sfVector2f) { 0, 0 });
    set_emiter_cone(adata, particles, (sfVector2f) { 0, 360.0f });
    set_emiter_particle_speed(adata, particles, (sfVector2f) { 250.0f, 380.0f });
    set_emiter_vortex_dir(adata, particles, clockwise);
    set_emiter_vortex_speed(adata, particles, (sfVector2f) { -5.0f, 5.0f });
    set_emiter_rotation_dir(adata, particles, random_dir);
    set_emiter_rotation_speed(adata, particles, 30.0f);
    set_emiter_layer(adata, particles, 4);
    move_emiter(adata, particles, (sfVector2f) { win_w / 2, win_h / 2});
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
    set_animation_speed(adata, sprite_id, 0.05f);
    set_animation_mode(adata, sprite_id, animation_reverse);
    set_sprite_origin(adata, sprite_id, (sfVector2f) { 24, 24 });
    move_sprite(adata, sprite_id, (sfVector2f) { win_w / 2, win_h / 2 });
    pause_animation(adata, sprite_id);
    init_player_particles(adata);
}
