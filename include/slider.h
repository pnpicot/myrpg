/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Slider module
*/

#pragma once

#include "main.h"

s_slider *get_slider(s_appdata *adata, char *id);
s_button *get_slider_left(s_appdata *adata, char *slider_id, int layer);
s_button *get_slider_right(s_appdata *adata, char *slider_id, int layer);
s_button *get_slider_middle(s_appdata *adata, char *slider_id, int layer);
s_circle *get_slider_hover_left(s_appdata *adata, char *slider_id, int layer);
s_circle *get_slider_hover_right(s_appdata *adata, char *slider_id, int layer);
s_rect *get_slider_hover_middle(s_appdata *adata, char *slider_id, int layer);
s_circle *get_slider_node(s_appdata *adata, char *slider_id, int layer);
s_text *get_slider_text(s_appdata *adata, char *slider_id, int layer);
s_rect *get_slider_rect(s_appdata *adata, char *slider_id, int layer);
s_vertex *get_slider_triangle(s_appdata *adata, char *slider_id, int layer);
void slider_check_released(s_appdata *adata);
void slider_update_change(s_appdata *adata);
void slider_change(s_appdata *adata, char *id);
void set_slider_onchange(s_appdata *adata, char *id, \
void (*on_change)(s_appdata *adata, s_ref *ref));
void update_slider_vertex(s_appdata *adata, s_slider *slider, \
sfVector2f text_pos, sfFloatRect text_bounds);
void update_slider_rect(s_appdata *adata, s_slider *slider, \
sfFloatRect text_bounds, sfVector2f text_pos);
void update_slider_text(s_appdata *adata, s_slider *slider, \
sfVector2f node_pos);
void update_slider_node(s_appdata *adata, s_slider *slider, \
sfVector2f left_pos);
void update_slider(s_appdata *adata, s_slider *slider);
void add_slider_next(s_appdata *adata, char *id, \
int layer, s_slider *new_slider);
void add_slider(s_appdata *adata, char *id, int layer);
void set_slider_rtex(s_appdata *adata, char *id, char *rtex_id);
void set_slider_active(s_appdata *adata, char *id, sfUint8 active);
void move_slider(s_appdata *adata, char *id, sfVector2f pos);
int get_slider_value(s_appdata *adata, char *id);
void delete_slider_next(s_appdata *adata, s_slider *cur);
void delete_slider(s_appdata *adata, char *id);
void set_slider_min(s_appdata *adata, char *id, int min);
void set_slider_max(s_appdata *adata, char *id, int max);
void set_slider_current(s_appdata *adata, char *id, int value);
void set_slider_origin(s_appdata *adata, char *id, sfVector2f origin);
void translate_slider(s_appdata *adata, char *id, sfVector2f pos_ch);
