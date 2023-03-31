/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Object module
*/

#pragma once

#include "main.h"

s_object *get_object(s_appdata *adata, char *id);
void add_object_next(s_appdata *adata, char *id, \
s_ref ref, s_object *new_object);
void add_object(s_appdata *adata, char *id, s_ref ref);
void delete_object(s_appdata *adata, char *id);
void set_object_pressed_bg(s_appdata *adata, char *id, sfColor color);
void set_object_pressed_fg(s_appdata *adata, char *id, sfColor color);
void set_object_pressed_out(s_appdata *adata, char *id, sfColor color);
void set_object_hover_bg(s_appdata *adata, char *id, sfColor color);
void set_object_hover_fg(s_appdata *adata, char *id, sfColor color);
void set_object_hover_out(s_appdata *adata, char *id, sfColor color);
void set_object_onpressed(s_appdata *adata, char *id, \
void (*on_pressed)(s_appdata *adata, s_ref *ref));
void set_object_onclick(s_appdata *adata, char *id, \
void (*on_click)(s_appdata *adata, s_ref *ref));
void set_object_onhover(s_appdata *adata, char *id, \
void (*on_hover)(s_appdata *adata, s_ref *ref));
void object_check_hover_color(s_appdata *adata, int contains, \
s_ref *ref, s_object *cur);
void object_check_hover(s_appdata *adata);
int object_check_pressed_next(s_appdata *adata, int contains, \
s_ref *ref, s_object *cur);
void object_check_pressed(s_appdata *adata);
int object_check_released(s_appdata *adata);
void disable_object_hover_color(s_appdata *adata, char *id);
void disable_object_pressed_color(s_appdata *adata, char *id);
void disable_object_onpressed(s_appdata *adata, char *id);
void disable_object_onclick(s_appdata *adata, char *id);
void disable_object_onhover(s_appdata *adata, char *id);
void enable_object_hover_color(s_appdata *adata, char *id);
void enable_object_pressed_color(s_appdata *adata, char *id);
void enable_object_onpressed(s_appdata *adata, char *id);
void enable_object_onclick(s_appdata *adata, char *id);
void enable_object_onhover(s_appdata *adata, char *id);
