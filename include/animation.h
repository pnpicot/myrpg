/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Animation module
*/

#pragma once

#include "main.h"

s_animation *get_animation(s_appdata *adata, char *sprite_id);
void set_animation_speed(s_appdata *adata, char *sprite_id, float speed);
void set_animation_rows(s_appdata *adata, char *sprite_id, int row_count);
void set_animation_cols(s_appdata *adata, char *sprite_id, int col_count);
void shift_animation_row(s_appdata *adata, char *sprite_id, int row_index);
void set_animation_mode(s_appdata *adata, char *sprite_id, int mode);
void animate_restart(s_appdata *adata, s_animation *animation);
void animate_reverse(s_appdata *adata, s_animation *animation);
void set_animation_rect(s_appdata *adata, s_animation *animation);
void update_sprite_animation(s_appdata *adata, s_animation *animation, \
sfBool force);
void update_animations(s_appdata *adata);
void animate_sprite_next(s_appdata *adata, s_animation *new_animation, \
s_sprite *sprite);
void animate_sprite(s_appdata *adata, char *sprite_id);
void start_animation(s_appdata *adata, char *sprite_id);
void pause_animation(s_appdata *adata, char *sprite_id);
