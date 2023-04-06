/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Sprite module
*/

#pragma once

#include "main.h"

s_sprite *get_sprite(s_appdata *adata, char *id);
void delete_sprite(s_appdata *adata, char *id);
void add_sprite(s_appdata *adata, char *id, int layer);
void set_sprite_texture(s_appdata *adata, char *id, sfTexture *texture);
void set_sprite_repeat(s_appdata *adata, char *id, sfBool repeat);
void move_sprite(s_appdata *adata, char *id, sfVector2f pos);
void set_sprite_origin(s_appdata *adata, char *id, sfVector2f origin);
void set_sprite_rect(s_appdata *adata, char *id, sfIntRect rect);
sfVector2f get_sprite_pos(s_appdata *adata, char *id);
void translate_sprite(s_appdata *adata, char *id, sfVector2f pos_ch);
void scale_sprite(s_appdata *adata, char *id, sfVector2f factors);
void rotate_sprite(s_appdata *adata, char *id, float angle);
sfFloatRect get_sprite_bounds(s_appdata *adata, char *id);
float get_sprite_rotation(s_appdata *adata, char *id);
sfVector2f get_sprite_scale(s_appdata *adata, char *id);
void set_sprite_rtex(s_appdata *adata, char *id, char *rtex_id);
void set_sprite_active(s_appdata *adata, char *id, sfUint8 active);
void rotate_sprite_add(s_appdata *adata, char *id, float angle_ch);
