/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Text module
*/

#pragma once

#include "main.h"

s_text *get_text(s_appdata *adata, char *id);
void delete_text(s_appdata *adata, char *id);
void add_text(s_appdata *adata, char *id, int layer);
void set_text_rtex(s_appdata *adata, char *id, char *rtex_id);
void set_text_active(s_appdata *adata, char *id, sfUint8 active);
void set_text_font(s_appdata *adata, char *id, sfFont *font);
void edit_text(s_appdata *adata, char *id, char *str);
void move_text(s_appdata *adata, char *id, sfVector2f pos);
sfVector2f get_text_pos(s_appdata *adata, char *id);
void translate_text(s_appdata *adata, char *id, sfVector2f pos_ch);
void color_text(s_appdata *adata, char *id, sfColor color);
void resize_text(s_appdata *adata, char *id, int font_size);
void scale_text(s_appdata *adata, char *id, sfVector2f factors);
void rotate_text(s_appdata *adata, char *id, float angle);
const char *get_text_str(s_appdata *adata, char *id);
sfVector2f get_text_scale(s_appdata *adata, char *id);
float get_text_rotation(s_appdata *adata, char *id);
float get_text_rotation(s_appdata *adata, char *id);
void set_text_origin(s_appdata *adata, char *id, sfVector2f origin);
sfVector2f get_text_origin(s_appdata *adata, char *id);
sfFloatRect get_text_bounds(s_appdata *adata, char *id);
const sfFont *get_text_font(s_appdata *adata, char *id);
