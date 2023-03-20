/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Progression bar module
*/

#pragma once

#include "main.h"

void add_bar(s_appdata *adata, char *id, int layer);
void set_bar_rtex(s_appdata *adata, char *id, char *rtex_id);
void update_bar(s_appdata *adata, s_bar *bar);
void set_bar_display(s_appdata *adata, char *bar_id, sfBool display);
void move_bar(s_appdata *adata, char *id, sfVector2f pos);
void set_bar_min(s_appdata *adata, char *id, float min);
void set_bar_max(s_appdata *adata, char *id, float max);
void set_bar_current(s_appdata *adata, char *id, float current);
