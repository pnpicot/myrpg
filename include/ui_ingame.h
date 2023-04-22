/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** In-game ui module
*/

#pragma once

#include "main.h"

void update_ingame_fps(s_appdata *adata);
void update_ingame_ui(s_appdata *adata);
void init_ingame_fps(s_appdata *adata, char *container, char *rtex);
void update_wave_count(s_appdata *adata);
void init_ingame_waves(s_appdata *adata, char *container, char *rtex);
void init_stats_title(s_appdata *adata, char *container, char *rtex,
char *rect_id);
void init_stats_health(s_appdata *adata, char *container, char *rtex,
char *rect_id);
void init_stats_transference(s_appdata *adata, char *container, char *rtex,
char *rect_id);
void init_stats_text(s_appdata *adata, char *container, char *rtex,
char *rect_id);
void init_ingame_stats(s_appdata *adata, char *container, char *rtex);
void init_live_ingame_ui(s_appdata *adata);
