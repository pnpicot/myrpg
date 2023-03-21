/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Progression bar module
*/

#pragma once

#include "main.h"

s_bar *get_bar(s_appdata *adata, char *id);
s_rect *get_bar_back(s_appdata *adata, char *bar_id, int layer);
s_rect *get_bar_fill(s_appdata *adata, char *bar_id, int layer);
void set_bar_display(s_appdata *adata, char *bar_id, sfBool display);
void update_bar(s_appdata *adata, s_bar *bar);
void add_bar(s_appdata *adata, char *id, int layer);
void set_bar_rtex(s_appdata *adata, char *id, char *rtex_id);
void move_bar(s_appdata *adata, char *id, sfVector2f pos);
void translate_bar(s_appdata *adata, char *id, sfVector2f pos_ch);
void set_bar_origin(s_appdata *adata, char *id, sfVector2f origin);
void color_bar(s_appdata *adata, char *id, sfColor empty, sfColor filled);
void set_bar_out(s_appdata *adata, char *id, sfColor color, float thickness);
void set_bar_active(s_appdata *adata, char *id, sfUint8 active);
void set_bar_min(s_appdata *adata, char *id, float min);
void set_bar_max(s_appdata *adata, char *id, float max);
void set_bar_current(s_appdata *adata, char *id, float current);
int get_bar_current(s_appdata *adata, char *id);
int get_bar_min(s_appdata *adata, char *id);
int get_bar_max(s_appdata *adata, char *id);
int get_bar_rest(s_appdata *adata, char *id);
void update_bar_text(s_appdata *adata, s_bar *bar, sfFloatRect back_bounds);
