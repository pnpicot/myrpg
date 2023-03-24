/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Wall module
*/

#pragma once

#include "main.h"

s_wall *get_wall(s_appdata *adata, char *id);
void delete_wall(s_appdata *adata, char *id);
void set_wall_rtex(s_appdata *adata, char *rtex_id, int layer);
s_rect *get_wall_hitbox(s_appdata *adata, char *wall_id, sfFloatRect hitbox);
void add_wall(s_appdata *adata, char *id, sfFloatRect hitbox);
void move_wall(s_appdata *adata, char *id, sfVector2f pos);
void resize_wall(s_appdata *adata, char *id, sfVector2f size);
void translate_wall(s_appdata *adata, char *id, sfVector2f pos_ch);
void set_wall_origin(s_appdata *adata, char *id, sfVector2f origin);
void show_walls(s_appdata *adata);
void hide_walls(s_appdata *adata);
void update_current_wall(s_appdata *adata);
