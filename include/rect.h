/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Rectangle shape module
*/

#pragma once

#include "main.h"

s_rect *get_rect(s_appdata *adata, char *id);
void delete_rect(s_appdata *adata, char *id);
void add_rect(s_appdata *adata, char *id, int layer);
void resize_rect(s_appdata *adata, char *id, sfVector2f size);
void move_rect(s_appdata *adata, char *id, sfVector2f pos);
void color_rect(s_appdata *adata, char *id, sfColor color);
void set_rect_outline(s_appdata *adata, char *id, \
sfColor color, float thickness);
void set_rect_origin(s_appdata *adata, char *id, sfVector2f origin);
void rotate_rect(s_appdata *adata, char *id, float angle);
void scale_rect(s_appdata *adata, char *id, sfVector2f factors);
sfVector2f get_rect_pos(s_appdata *adata, char *id);
void translate_rect(s_appdata *adata, char *id, sfVector2f pos_ch);
sfColor get_rect_bg(s_appdata *adata, char *id);
sfColor get_rect_out_color(s_appdata *adata, char *id);
float get_rect_out_thickness(s_appdata *adata, char *id);
sfVector2f get_rect_origin(s_appdata *adata, char *id);
float get_rect_rotation(s_appdata *adata, char *id);
sfVector2f get_rect_scale(s_appdata *adata, char *id);
sfFloatRect get_rect_bounds(s_appdata *adata, char *id);
void set_rect_rtex(s_appdata *adata, char *id, char *rtex_id);
void set_rect_active(s_appdata *adata, char *id, sfUint8 active);
sfUint8 get_rect_active(s_appdata *adata, char *id);
