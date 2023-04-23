/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Parasite (player) module
*/

#include "main.h"

void add_player_health(s_appdata *adata, float value)
{
    s_player *player = adata->player;

    player->health.y += value;
}

void add_player_attack(s_appdata *adata, float value)
{
    s_player *player = adata->player;

    player->attack += value;
}

void add_player_defense(s_appdata *adata, float value)
{
    s_player *player = adata->player;

    player->defense += value;
}

void add_player_trflevel(s_appdata *adata, float value)
{
    s_player *player = adata->player;

    player->transference_level += (int) value;
}

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
