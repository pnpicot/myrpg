/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Circle module
*/

#pragma once

#include "main.h"

s_circle *get_circle(s_appdata *adata, char *id);
void delete_circle(s_appdata *adata, char *id);
void add_circle(s_appdata *adata, char *id, int layer);
void set_circle_rtex(s_appdata *adata, char *id, char *rtex_id);
void set_circle_active(s_appdata *adata, char *id, sfUint8 active);
void move_circle(s_appdata *adata, char *id, sfVector2f pos);
void resize_circle(s_appdata *adata, char *id, float radius);
sfVector2f get_circle_pos(s_appdata *adata, char *id);
void translate_circle(s_appdata *adata, char *id, sfVector2f pos_ch);
void color_circle(s_appdata *adata, char *id, sfColor color);
void set_circle_out(s_appdata *adata, char *id, sfColor color, float thickness);
void rotate_circle(s_appdata *adata, char *id, float angle);
void scale_circle(s_appdata *adata, char *id, sfVector2f factors);
void set_circle_origin(s_appdata *adata, char *id, sfVector2f origin);
sfFloatRect get_circle_bounds(s_appdata *adata, char *id);
float get_circle_rotation(s_appdata *adata, char *id);
sfVector2f get_circle_scale(s_appdata *adata, char *id);
sfColor get_circle_bg(s_appdata *adata, char *id);
sfColor get_circle_out_color(s_appdata *adata, char *id);
float get_circle_radius(s_appdata *adata, char *id);
