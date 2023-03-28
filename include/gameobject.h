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
void update_gameobjects(s_appdata *adata);
void move_gameobject_lights(s_appdata *adata, sfVector2f pos_ch);
void move_gameobject_emiters(s_appdata *adata, sfVector2f pos_ch);
void move_gameobject_walls(s_appdata *adata, sfVector2f pos_ch);
void add_gameobject_hitbox(s_appdata *adata, char *id);
