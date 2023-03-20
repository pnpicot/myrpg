/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Button module
*/

#pragma once

#include "main.h"

s_button *get_button(s_appdata *adata, char *id);
void add_button(s_appdata *adata, char *id, int type, int layer);
void delete_button(s_appdata *adata, char *id);
void update_button(s_appdata *adata, s_button *button);
void resize_button(s_appdata *adata, char *id, sfVector2f size);
void move_button(s_appdata *adata, char *id, sfVector2f pos);
void edit_button(s_appdata *adata, char *id, char *str);
void color_button_bg(s_appdata *adata, char *id, sfColor color);
void set_button_out(s_appdata *adata, char *id, sfColor color, float thickness);
void color_button_fg(s_appdata *adata, char *id, sfColor color);
void scale_button(s_appdata *adata, char *id, sfVector2f factors);
void rotate_button(s_appdata *adata, char *id, float angle);
void set_button_font(s_appdata *adata, char *id, sfFont *font);
void translate_button(s_appdata *adata, char *id, sfVector2f pos_ch);
void set_button_origin(s_appdata *adata, char *id, sfVector2f origin);
void set_button_rtex(s_appdata *adata, char *id, char *rtex_id);
void set_button_active(s_appdata *adata, char *id, sfUint8 active);
sfFloatRect get_button_bounds(s_appdata *adata, char *id);
sfVector2f get_button_pos(s_appdata *adata, char *id);
float get_button_rotation(s_appdata *adata, char *id);
sfVector2f get_button_origin(s_appdata *adata, char *id);
sfVector2f get_button_scale(s_appdata *adata, char *id);
sfColor get_button_color(s_appdata *adata, char *id);
sfColor get_button_out_color(s_appdata *adata, char *id);
float get_button_out_thickness(s_appdata *adata, char *id);
void resize_button_text(s_appdata *adata, char *id, int font_size);
const char *get_button_string(s_appdata *adata, char *id);
