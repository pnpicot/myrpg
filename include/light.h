/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Lighting module
*/

#pragma once

#include "main.h"

void set_light_blur_rtex(s_appdata *adata, char *rtex_id);
void set_light_rtex(s_appdata *adata, char *rtex_id);
s_light *get_light(s_appdata *adata, char *id);
void delete_light(s_appdata *adata, char *id);
sfCircleShape *get_inner_light(s_appdata *adata, s_light *light);
sfCircleShape *get_outer_light(s_appdata *adata, s_light *light);
void add_light(s_appdata *adata, char *id);
void move_light(s_appdata *adata, char *id, sfVector2f pos);
void set_light_inner(s_appdata *adata, char *id, float inner_radius);
void set_light_outer(s_appdata *adata, char *id, float outer_radius);
void color_light(s_appdata *adata, char *id, sfColor color);
void set_light_intensity(s_appdata *adata, char *id, float intensity);
sfColor get_light_color(s_appdata *adata, char *id);
sfVector2f get_light_pos(s_appdata *adata, char *id);
float get_light_inner(s_appdata *adata, char *id);
float get_light_outer(s_appdata *adata, char *id);
float get_light_intensity(s_appdata *adata, char *id);
void set_light_active(s_appdata *adata, char *id, sfBool active);
void enable_light(s_appdata *adata, char *id);
void disable_light(s_appdata *adata, char *id);
sfBool get_light_active(s_appdata *adata, char *id);
void toggle_light(s_appdata *adata, char *id);
void set_lightres_rtex(s_appdata *adata, char *rtex_id);
void set_lightblend_rtex(s_appdata *adata, char *rtex_id);
void init_light_recommended(s_appdata *adata, int depth_start);
