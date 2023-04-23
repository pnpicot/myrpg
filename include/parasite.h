/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Parasite (player) module
*/

#pragma once

#include "main.h"

void add_player_health(s_appdata *adata, float value);
void add_player_attack(s_appdata *adata, float value);
void add_player_defense(s_appdata *adata, float value);
void add_player_trflevel(s_appdata *adata, float value);
void update_player_ui(s_appdata *adata);
void player_host_behavior(s_appdata *adata);
void update_player(s_appdata *adata);
void init_player_particles_n(s_appdata *adata, sfVector2f part_angle);
void init_player_particles(s_appdata *adata);
void player_search_host(s_appdata *adata, sfVector2f player_pos, sfBool *found);
void update_player_info_text_n(s_appdata *adata);
void update_player_info_text(s_appdata *adata);
void init_player_info(s_appdata *adata, char *player_id);
void init_player_next(s_appdata *adata, s_player *player);
void init_player_final(s_appdata *adata, s_player *player, char *sprite_id);
void init_player(s_appdata *adata);
void try_transference_n(s_appdata *adata, char *emiter_id);
void try_transference(s_appdata *adata);
void check_game_keys_n(s_appdata *adata, int keycode);
void check_game_keys(s_appdata *adata, int keycode);
void update_host_controls(s_appdata *adata);
