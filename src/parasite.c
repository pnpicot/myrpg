/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Parasite (player) module
*/

#include "main.h"

void update_player_ui(s_appdata *adata)
{
    char *id = get_str(adata, "stats_widget");
    char *transference_id = str_add(id, "@[:transference]");
    char *health_id = str_add(id, "@[:health]");
    s_player *player = adata->player;

    player->transference.x += player->transference_rate;

    if (player->transference.x > player->transference.y)
        player->transference.x = player->transference.y;

    set_bar_current(adata, transference_id, player->transference.x);

    player->health.x += player->health_rate;

    if (player->health.x > player->health.y)
        player->health.x = player->health.y;
    if (player->health.x < 0)
        player->health.x = 0;

    color_bar(adata, health_id, get_color(130, 21, 9, 255),
    lerp_color(sfRed, sfGreen, player->health.x / player->health.y));
    set_bar_current(adata, health_id, player->health.x);
    free(transference_id);
    free(health_id);
}

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

    if (get_clock_seconds(player->transference_clock) >= 5.0f && !player->solid)
        player->solid = sfTrue;

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
    char *rtex = get_str(adata, "rtex_wall");
    char *container = get_str(adata, "ctn_game");
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    float angle = (atan2f(-1, 0) * (180 / M_PI)) + 90.0f;
    float rv_angle = angle - 270.0f;

    if (rv_angle < 0) rv_angle += 360.0f;
    else if (rv_angle > 0) rv_angle -= 360.0f;

    sfVector2f part_angle;
    part_angle.x = rv_angle - 35.0f;
    part_angle.y = rv_angle + 35.0f;

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
    set_emiter_cone(adata, particles, part_angle);
    set_emiter_particle_speed(adata, particles, (sfVector2f) { 250.0f, 380.0f });
    set_emiter_vortex_dir(adata, particles, clockwise);
    set_emiter_vortex_speed(adata, particles, (sfVector2f) { -5.0f, 5.0f });
    set_emiter_rotation_dir(adata, particles, random_dir);
    set_emiter_rotation_speed(adata, particles, 30.0f);
    set_emiter_layer(adata, particles, 4);
    move_emiter(adata, particles, (sfVector2f) { win_w / 2, win_h / 2});
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

void update_player_info_text(s_appdata *adata)
{
    s_text *info = adata->player->info_text;
    s_player *player = adata->player;
    sfBool found = sfFalse;
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    sfVector2f player_pos;

    player_pos.x = adata->game_data->view_pos.x + (win_w / 2);
    player_pos.y = adata->game_data->view_pos.y + (win_h / 2);

    if (player->host == NULL)
        player_search_host(adata, player_pos, &found);

    if (!found) {
        edit_text(adata, info->id, "");
        player->potential_host = NULL;
    }

    sfFloatRect bounds = get_text_bounds(adata, info->id);
    sfVector2f origin;

    origin.x = bounds.width / 2;
    origin.y = bounds.height / 2;

    set_text_origin(adata, info->id, origin);

    sfVector2f pos;
    pos.x = win_w / 2;
    pos.y = (win_h / 2) - 85.0f;

    move_text(adata, info->id, pos);
}

void init_player_info(s_appdata *adata, char *player_id)
{
    char *id = str_add(player_id, "@[:info]");

    add_text(adata, id, 5);

    s_text *info_text = get_text(adata, id);

    set_text_font(adata, id, get_font(adata, "courier_bold"));
    resize_text(adata, id, 22);
    color_text(adata, id, sfYellow);
    set_text_rtex(adata, id, get_str(adata, "rtex_ui"));
    add_to_container(adata, get_str(adata, "ctn_game"), (s_ref) { info_text, TYPE_TEXT });
    edit_text(adata, id, "");

    adata->player->info_text = info_text;

    update_player_info_text(adata);
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

    player->health = (sfVector2i) { 5, 5 };
    player->transference = (sfVector2f) { 0, 5000.0f };
    player->transference_clock = sfClock_create();
    player->health_rate = 1;
    player->hitbox = (sfFloatRect){ 910 + adata->game_data->view_pos.x,
    490 + adata->game_data->view_pos.y, 100, 100 };
    player->transference_rate = 0.7f;
    player->info_text = NULL;
    player->host = NULL;
    player->potential_host = NULL;
    player->solid = sfTrue;

    add_sprite(adata, sprite_id, 5);
    set_sprite_rtex(adata, sprite_id, rtex);

    s_sprite *body = get_sprite(adata, sprite_id);

    player->body = body;

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
    init_player_info(adata, sprite_id);
}

void try_transference(s_appdata *adata)
{
    s_player *player = adata->player;
    char *emiter_id = get_str(adata, "player_particles");

    if (player->host != NULL) {
        s_entity *host = (s_entity *) player->host;
        char *host_emiter_id = str_add(host->id, "@[:emiter]");
        s_game *game_data = adata->game_data;

        host->inhabited = sfFalse;
        player->host = NULL;
        player->body->active = 1;
        game_data->speed = (sfVector2f) { 0, 0 };

        linked_node *paths = host->path;

        while (paths != NULL) {
            linked_node *save = paths;
            paths = paths->next;

            free(save->data);
            free(save);
        }

        host->path = NULL;

        sfClock_restart(host->clock);
        sfClock_restart(player->transference_clock);
        set_emiter_active(adata, emiter_id, sfTrue);
        set_emiter_active(adata, host_emiter_id, sfTrue);

        return;
    }

    player->host = player->potential_host;

    if (player->host != NULL) {
        s_entity *host = (s_entity *) player->host;
        char *host_emiter_id = str_add(host->id, "@[:emiter]");

        host->inhabited = sfTrue;
        player->body->active = 0;
        player->solid = sfFalse;

        set_emiter_active(adata, emiter_id, sfFalse);
        set_emiter_active(adata, host_emiter_id, sfFalse);
    }
}

void check_game_keys(s_appdata *adata, int keycode)
{
    if (keycode == sfKeyE) {
        try_transference(adata);
    }

    if (keycode == sfKeyC) {
        sfBool active = is_container_active(adata,
        get_str(adata, "console_id"));
        active = active == sfTrue ? sfFalse : sfTrue;
        set_container_active(adata, get_str(adata, "console_id"), active);
    }

    if (keycode == sfKeyI || keycode == sfKeyTab) {
        adata->game_data->in_inv = !adata->game_data->in_inv;

        char *ctn = get_str(adata, "ctn_inv");

        set_container_active(adata, ctn, adata->game_data->in_inv ? 1 : 0);
    }
}

void update_host_controls(s_appdata *adata)
{
    s_player *player = adata->player;
    s_entity *host = (s_entity *) player->host;
    sfVector2f add = { 0, 0 };

    if (get_key(adata, sfKeyQ)) {
        add.x -= host->speed;
    }

    if (get_key(adata, sfKeyZ)) {
        add.y -= host->speed;
    }

    if (get_key(adata, sfKeyD)) {
        add.x += host->speed;
    }

    if (get_key(adata, sfKeyS)) {
        add.y += host->speed;
    }

    add = is_map_colliding(adata, host, add);

    translate_entity(adata, host, add);

    if ((add.x != 0 || add.y != 0) && host->orientated) {
        float angle = (atan2f(add.y, add.x) * (180 / M_PI)) + 90.0f;

        rotate_entity_abs(adata, host, angle);
    }
}
