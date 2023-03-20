/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Elements utilities module
*/

#pragma once

#include "main.h"

void set_element_origin(s_appdata *adata, void *ref, int type, sfVector2f origin);
void scale_element(s_appdata *adata, void *ref, int type, sfVector2f factors);
void rotate_element(s_appdata *adata, void *ref, int type, float angle);
void resize_element_out(s_appdata *adata, void *ref, int type, float thickness);
void color_element_out(s_appdata *adata, void *ref, int type, sfColor color);
void color_element(s_appdata *adata, void *ref, int type, sfColor color);
void translate_element(s_appdata *adata, void *ref, int type, sfVector2f pos_ch);
void move_element(s_appdata *adata, void *ref, int type, sfVector2f pos);
sfVector2f get_element_origin(s_appdata *adata, void *ref, int type);
sfVector2f get_element_scale(s_appdata *adata, void *ref, int type);
float get_element_rotation(s_appdata *adata, void *ref, int type);
float get_element_out_thickness(s_appdata *adata, void *ref, int type);
sfColor get_element_out_color(s_appdata *adata, void *ref, int type);
sfColor get_element_bg(s_appdata *adata, void *ref, int type);
sfVector2f get_element_pos(s_appdata *adata, void *ref, int type);
sfFloatRect get_element_bounds(s_appdata *adata, void *ref, int type);
s_ref *get_ref(s_appdata *adata, void *ref, int type);
void delete_element(s_appdata *adata, void *ref, int type);
void resize_element(s_appdata *adata, void *ref, int type, sfVector2f size);
void set_element_active(s_appdata *adata, void *ref, int type, sfUint8 active);
void set_element_rtex(s_appdata *adata, void *ref, int type, char *rtex_id);
int get_element_layer(s_appdata *adata, void *ref, int type);
sfColor get_element_fg(s_appdata *adata, void *ref, int type);
void color_element_fg(s_appdata *adata, void *ref, int type, sfColor color);
sfUint8 get_element_active(s_appdata *adata, void *ref, int type);
