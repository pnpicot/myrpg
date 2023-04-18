/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Parasite (player) module
*/

#pragma once

#include "main.h"

void update_player_ui(s_appdata *adata);
void player_host_behavior(s_appdata *adata);
void update_player(s_appdata *adata);
void init_player_particles(s_appdata *adata);
void player_search_host(s_appdata *adata, sfVector2f player_pos, sfBool *found);
void update_player_info_text(s_appdata *adata);
void init_player_info(s_appdata *adata, char *player_id);
void init_player(s_appdata *adata);
void try_transference(s_appdata *adata);
void check_game_keys(s_appdata *adata, int keycode);
void update_host_controls(s_appdata *adata);
void try_transference(s_appdata *adata);
