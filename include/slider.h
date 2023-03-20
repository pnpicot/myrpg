/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Slider module
*/

#pragma once

#include "main.h"

void add_slider(s_appdata *adata, char *id, int layer);
void set_slider_rtex(s_appdata *adata, char *id, char *rtex_id);
void move_slider(s_appdata *adata, char *id, sfVector2f pos);
void set_slider_onchange(s_appdata *adata, char *id, void (*on_change)(s_appdata *adata, s_ref *ref));
void slider_check_released(s_appdata *adata);
void slider_update_change(s_appdata *adata);
void update_slider(s_appdata *adata, s_slider *slider);
void slider_change(s_appdata *adata, char *id);
void set_slider_min(s_appdata *adata, char *id, int min);
void set_slider_max(s_appdata *adata, char *id, int max);
int get_slider_value(s_appdata *adata, char *id);
