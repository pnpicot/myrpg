/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Game object module
*/

#pragma once

#include "main.h"

s_gameobj *get_gameobject(s_appdata *adata, char *id);
void delete_gameobject(s_appdata *adata, char *id);
void add_gameobject(s_appdata *adata, char *id);
void set_gameobject_ref(s_appdata *adata, char *id, void *ref, int type);
void move_gameobject(s_appdata *adata, s_gameobj *game_obj);
void move_gameobject_lights(s_appdata *adata, sfVector2f pos_ch);
void translate_emiter_particles(s_appdata *adata, linked_node *pool, \
sfVector2f pos_ch);
void move_gameobject_emiters(s_appdata *adata, sfVector2f pos_ch);
void add_gameobject_hitbox(s_appdata *adata, char *id);
void move_gameobject_walls(s_appdata *adata, sfVector2f pos_ch);
void update_gameobjects(s_appdata *adata);
