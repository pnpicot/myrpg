/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Elements utilities module
*/

#pragma once

#include "main.h"

s_entity *get_entity(s_appdata *adata, char *id);
void add_entity(s_appdata *adata, char *id);
void set_entity_sprite(s_appdata *adata, char *id, char *texture_id);
void set_entity_layer(s_appdata *adata, char *id, int layer);
void set_entity_stats(s_appdata *adata, char *id);
void set_entity_stats_dammage(s_appdata *adata, char *id, int dammage);
void set_entity_stats_dammage(s_appdata *adata, char *id, int hp);
void set_entity_stats_dammage(s_appdata *adata, char *id, int faction);
void set_entity_stats_dammage(s_appdata *adata, char *id,
int transference_level);
void set_entity_active(s_appdata *adata, char *id, sfUint8 active);
void set_entity_animation_cols(s_appdata *adata, char *id, int cols);
void set_entity_animation_rows(s_appdata *adata, char *id, int rows);
void set_entity_animation_speed(s_appdata *adata, char *id, int speed);
void set_entity_animation_mode(s_appdata *adata, char *id, int mode);
void set_entity_scale(s_appdata *adata, char *id, sfVector2f scale);
void move_entity(s_appdata *adata, char *id, sfVector2f pos);
void translate_entity(s_appdata *adata, char *id, sfVector2f add);
void rotate_entity(s_appdata *adata, char *id, float angle);
void set_entity_origin(s_appdata *adata, char *id, sfVector2f origin);
void set_entity_rtex(s_appdata *adata, char *id, char *rtex_id);
