/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#pragma once

#include "main.h"

s_entity *get_entity_model(s_appdata *adata, char *id);
void delete_entity_model(s_appdata *adata, char *id);
s_entity_part *get_entity_model_part(s_appdata *adata, char *model_id, \
char *part_id);
s_sprite *get_entity_part_model(s_appdata *adata, \
s_entity_part *model, sfTexture *tex, float scale);
void add_entity_part(s_appdata *adata, char **entry);
void add_entity_model(s_appdata *adata, char **entry);
void move_entity(s_appdata *adata, s_entity *entity, sfVector2f pos);
void translate_entity(s_appdata *adata, s_entity *entity, sfVector2f pos_ch);
void rotate_entity(s_appdata *adata, s_entity *entity, float angle);
void rotate_entity_part(s_appdata *adata, s_entity *entity, \
char *part_id, float angle);
void set_entity_behavior(s_appdata *adata, char *id, \
void (*behavior)(s_appdata *adata, s_entity *s_entity));
void init_entity_behaviors(s_appdata *adata);
void update_entities(s_appdata *adata);
