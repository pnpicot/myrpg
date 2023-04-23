/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Parasite (player) module
*/

#include "main.h"

void update_player_info_text_n(s_appdata *adata)
{
    s_text *info = adata->player->info_text;
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");

    sfFloatRect bounds = get_text_bounds(adata, info->id);
    sfVector2f origin = {bounds.width / 2, bounds.height / 2};
    set_text_origin(adata, info->id, origin);
    sfVector2f pos = {win_w / 2, win_h / 2 - 85.0f};
    move_text(adata, info->id, pos);
    char *stats_text = str_m_add(9, nbr_to_str((int) adata->player->attack),
    " Atk / ", nbr_to_str((int) adata->player->defense), " Def / ",
    "Trans. LV. ", nbr_to_str(adata->player->transference_level), " / ",
    nbr_to_str(adata->player->moula), " Moula");
    if (adata->player->stats != NULL)
        edit_text(adata, adata->player->stats->id, stats_text);
}

void update_player_info_text(s_appdata *adata)
{
    s_text *info = adata->player->info_text;
    s_player *player = adata->player;
    int win_h = get_int(adata, "win_h");
    int win_w = get_int(adata, "win_w");

    sfBool found = sfFalse;
    sfVector2f player_pos;
    player_pos.x = adata->game_data->view_pos.x + (win_w / 2);
    player_pos.y = adata->game_data->view_pos.y + (win_h / 2);
    if (player->host == NULL)
        player_search_host(adata, player_pos, &found);
    if (!found) {
        edit_text(adata, info->id, "");
        player->potential_host = NULL;
    }

    update_player_info_text_n(adata);
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
    add_to_container(adata, get_str(adata, "ctn_game"),
    (s_ref) { info_text, TYPE_TEXT });
    edit_text(adata, id, "");

    adata->player->info_text = info_text;

    update_player_info_text(adata);
}

void init_player_next(s_appdata *adata, s_player *player)
{
    player->health = (sfVector2f) { 1000, 1000 };
    player->transference = (sfVector2f) { 0, 5000.0f };
    player->transference_clock = sfClock_create();
    player->health_rate = 0.02f;
    player->hitbox = (sfFloatRect){ 910 + adata->game_data->view_pos.x,
    490 + adata->game_data->view_pos.y, 100, 100 };
    player->transference_rate = 1;
    player->info_text = NULL;
    player->host = NULL;
    player->potential_host = NULL;
    player->solid = sfTrue;
    player->transfered = sfFalse;
    player->transference_level = 1;
    player->stats = NULL;
    player->attack = 5.0f;
    player->defense = 0.3f;
    player->moula = 3000;
}

void init_player_final(s_appdata *adata, s_player *player, char *sprite_id)
{
    float zoom = get_float(adata, "zoom");
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
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
