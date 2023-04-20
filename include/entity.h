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
s_float *get_entity_float(s_entity *entity, char *id);
void add_to_entity_float(s_appdata *adata, s_entity *entity, char *id, \
float value);
void add_entity_float(s_appdata *adata, s_entity *entity, char *id, \
float default_value);
void set_entity_float(s_appdata *adata, s_entity *entity, char *id, \
float value);
void move_entity(s_appdata *adata, s_entity *entity, sfVector2f pos);
void translate_entity(s_appdata *adata, s_entity *entity, sfVector2f pos_ch);
void rotate_entity(s_appdata *adata, s_entity *entity, float angle);
void rotate_entity_part(s_appdata *adata, s_entity *entity, \
char *part_id, float angle);
void rotate_entity_part_abs(s_appdata *adata, s_entity *entity, \
char *part_id, float angle);
void set_entity_behavior(s_appdata *adata, char *id, \
void (*behavior)(s_appdata *adata, s_entity *s_entity));
void set_entity_emiter(s_appdata *adata, char *id, \
void (*emiter)(s_appdata *adata, s_entity *s_entity));
void update_entities(s_appdata *adata);
sfFloatRect get_entity_hitbox(s_appdata *adata, s_entity *entity);
void init_mf26_emiter(s_appdata *adata, s_entity *entity);
void behavior_z200(s_appdata *adata, s_entity *entity);
void behavior_mf26(s_appdata *adata, s_entity *entity);
void behavior_p800(s_appdata *adata, s_entity *entity);
void update_entity_bar(s_appdata *adata, s_entity *entity);
void behavior_lmx2(s_appdata *adata, s_entity *entity);
void init_entity_behaviors(s_appdata *adata);
void init_entity_emiters(s_appdata *adata);
void rotate_entity_abs(s_appdata *adata, s_entity *entity, float angle);
void do_particle_behavior(s_appdata *adata, s_particle_src *src,
s_entity *entity, void (*func)(s_appdata *adata, s_entity *s_entity,
s_particle *particle, linked_node *touchs));
sfVector2f get_way(s_appdata *adata, s_entity *entity, sfVector2i destination);
void behavior_lp230(s_appdata *adata, s_entity *entity);
sfVector2f agro(s_appdata *adata, s_entity *entity);
linked_node *get_path_finding(s_appdata *adata, s_entity *entity,
sfVector2i end);
sfVector2f use_path(s_appdata *adata, s_entity *entity);
void update_entity_collision_map(s_appdata *adata, s_entity *entity, void *ptr);
void behavior_revenant(s_appdata *adata, s_entity *entity);
