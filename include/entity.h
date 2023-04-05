/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Elements utilities module
*/

#pragma once

#include "main.h"

s_entity *get_entity(s_appdata *adata, char *id, int mode);
void add_entity(s_appdata *adata, char *id, int mode);
void set_entity_sprite(s_appdata *adata, char *id, char *texture_id, char *entity_sprite_id);
void set_entity_layer(s_appdata *adata, char *id, int rank, int layer);
void set_entity_stats(s_appdata *adata, char *id);
void set_entity_stats_dammage(s_appdata *adata, char *id, int dammage);
void set_entity_stats_hp(s_appdata *adata, char *id, int hp);
void set_entity_stats_faction(s_appdata *adata, char *id, char *faction);
void set_entity_stats_speed(s_appdata *adata, char *id, int speed);
void set_entity_stats_type(s_appdata *adata, char *id, char *type);
void set_entity_stats_transference_level(s_appdata *adata, char *id,
int transference_level);
void set_entity_active(s_appdata *adata, char *id, sfUint8 active);
void set_entity_animation_cols(s_appdata *adata, char *id, int cols);
void set_entity_animation_rows(s_appdata *adata, char *id, int rows);
void set_entity_animation_speed(s_appdata *adata, char *id, int speed);
void set_entity_animation_mode(s_appdata *adata, char *id, int mode);
void set_entity_scale(s_appdata *adata, char *id, sfVector2f scale);
void move_entity(s_appdata *adata, char *id, sfVector2f pos, int mode);
void translate_entity(s_appdata *adata, char *id, sfVector2f add);
void rotate_entity(s_appdata *adata, char *id, float angle);
void set_entity_origin(s_appdata *adata, char *id, sfVector2f origin);
void set_entity_rtex(s_appdata *adata, char *id, char *rtex_id);
void init_entities(s_appdata *adata);
void load_entity_faction(s_appdata *adata);
void set_entity_spawn(s_appdata *adata, char *id);
void set_entity_spawn_rate(s_appdata *adata, char *id, int spawn_rate);
sfFloatRect get_entity_bounds(s_appdata *adata, char *id, int rank);
sfVector2f get_entity_scale(s_appdata *adata, char *id, int rank);
float get_entity_rotation(s_appdata *adata, char *id, int rank);
