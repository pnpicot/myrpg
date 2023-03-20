/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Input module
*/

#pragma once

#include "main.h"

s_input *get_input(s_appdata *adata, char *id);
void trigger_input(s_appdata *adata, s_ref *ref);
s_rect *get_input_rect(s_appdata *adata, char *input_id, int layer);
s_text *get_input_text(s_appdata *adata, char *input_id, int layer, char *placeholder);
s_rect *get_input_caret(s_appdata *adata, char *input_id, int layer);
void update_input(s_appdata *adata, s_input *input);
void input_check_released(s_appdata *adata);
void input_update(s_appdata *adata);
char get_keycode_char(s_appdata *adata, int keycode);
void input_type(s_appdata *adata, int keycode);
void add_input(s_appdata *adata, char *id, int layer);
void set_input_rtex(s_appdata *adata, char *id, char *rtex_id);
void move_input(s_appdata *adata, char *id, sfVector2f pos);
void set_input_placeholder(s_appdata *adata, char *id, char *placeholder);
void set_input_origin(s_appdata *adata, char *id, sfVector2f origin);
void translate_input(s_appdata *adata, char *id, sfVector2f pos_ch);
const char *get_input_str(s_appdata *adata, char *id);
void resize_input(s_appdata *adata, char *id, sfVector2f size);
void clear_input(s_appdata *adata, char *id);
void edit_input(s_appdata *adata, char *id, char *str);
void set_input_font(s_appdata *adata, char *id, sfFont *font);
void resize_input_text(s_appdata *adata, char *id, int font_size);
sfVector2f get_input_pos(s_appdata *adata, char *id);
sfVector2f get_input_origin(s_appdata *adata, char *id);
void set_input_align(s_appdata *adata, char *id, char *align);
