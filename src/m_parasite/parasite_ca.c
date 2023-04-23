/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Parasite (player) module
*/

#include "main.h"

void player_host_behavior(s_appdata *adata)
{
    s_player *player = adata->player;
    s_game *game_data = adata->game_data;
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    s_entity *host = (s_entity *) player->host;
    sfVector2f player_pos;
    player_pos.x = adata->game_data->view_pos.x + (win_w / 2);
    player_pos.y = adata->game_data->view_pos.y + (win_h / 2);
    sfVector2f offset;
    offset.x = host->pos.x - player_pos.x;
    offset.y = host->pos.y - player_pos.y;
    sfVector2f rev_offset = { -offset.x, -offset.y };
    move_gameobject_lights(adata, rev_offset);
    move_gameobject_emiters(adata, rev_offset);
    move_gameobject_walls(adata, rev_offset);
    game_data->view_pos.x += offset.x;
    game_data->view_pos.y += offset.y;
}

void update_player(s_appdata *adata)
{
    char *sprite_id = get_str(adata, "player_body");
    s_player *player = adata->player;
    s_game *game_data = adata->game_data;
    sfVector2f speed = game_data->speed;
    float epsilon = 10e-4;
    if (player->host != NULL)
        player_host_behavior(adata);
    if (in_range(speed.x, -epsilon, epsilon) &&
    in_range(speed.y, -epsilon, epsilon)) {
        pause_animation(adata, sprite_id);
        return;
    } else
        start_animation(adata, sprite_id);
    float angle = (atan2f(speed.y, speed.x) * (180 / M_PI)) + 90.0f;
    float rv_angle = angle - 270.0f;
    if (rv_angle < 0) rv_angle += 360.0f;
    else if (rv_angle > 0) rv_angle -= 360.0f;
    sfVector2f part_angle = { rv_angle - 35.0f, rv_angle + 35.0f};
    set_emiter_cone(adata, get_str(adata, "player_particles"), part_angle);
    rotate_sprite(adata, sprite_id, angle);
}

void init_player_particles_n(s_appdata *adata, sfVector2f part_angle)
{
    char *particles = get_str(adata, "player_particles");
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    set_emiter_lifetime(adata, particles, 1500000);
    set_emiter_particle_lifetime(adata, particles, 1000);
    set_emiter_particle_max(adata, particles, 1000);
    set_emiter_spawnrate(adata, particles, 3.0f);
    set_emiter_model(adata, particles, "gen");
    set_emiter_colors(adata, particles, sfBlack, sfDarkGray);
    set_emiter_gameobject(adata, particles, sfFalse);
    set_emiter_size_range(adata, particles,
    (sfVector2f) { 10.0f, 10.0f }, (sfVector2f) { 0, 0 });
    set_emiter_cone(adata, particles, part_angle);
    set_emiter_particle_speed(adata, particles, (sfVector2f) {250.0f, 380.0f});
    set_emiter_vortex_dir(adata, particles, clockwise);
    set_emiter_vortex_speed(adata, particles, (sfVector2f) { -5.0f, 5.0f });
    set_emiter_rotation_dir(adata, particles, random_dir);
    set_emiter_rotation_speed(adata, particles, 30.0f);
    set_emiter_layer(adata, particles, 4);
    move_emiter(adata, particles, (sfVector2f) { win_w / 2, win_h / 2});
}

void init_player_particles(s_appdata *adata)
{
    char *particles = get_str(adata, "player_particles");
    char *rtex = get_str(adata, "rtex_wall");
    char *container = get_str(adata, "ctn_game");
    float angle = (atan2f(-1, 0) * (180 / M_PI)) + 90.0f;
    float rv_angle = angle - 270.0f;
    if (rv_angle < 0) rv_angle += 360.0f;
    else if (rv_angle > 0) rv_angle -= 360.0f;
    sfVector2f part_angle;
    part_angle.x = rv_angle - 35.0f;
    part_angle.y = rv_angle + 35.0f;
    add_emiter(adata, particles);
    set_emiter_rtex(adata, particles, rtex);
    add_to_container(adata, container,
    (s_ref) { get_emiter(adata, particles), TYPE_EMITER });
    init_player_particles_n(adata, part_angle);
}

void player_search_host(s_appdata *adata, sfVector2f player_pos, sfBool *found)
{
    linked_node *entities = adata->game_data->entities;
    s_player *player = adata->player;
    s_text *info = adata->player->info_text;

    while (entities != NULL && entities->data != NULL) {
        s_entity *cur = (s_entity *) entities->data;
        float dist = get_vec_dist(cur->pos, player_pos);

        if (dist <= get_float(adata, "player_reach")) {
            edit_text(adata, info->id, "[E] Take control");
            player->potential_host = cur;
            (*found) = sfTrue;
            break;
        }

        entities = entities->next;
    }
}
