/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Container module
*/

#pragma once

#include "main.h"

s_container *get_container(s_appdata *adata, char *id);
void delete_container(s_appdata *adata, char *id);
void add_container(s_appdata *adata, char *id);
void add_to_container(s_appdata *adata, char *id, s_ref ref);
void translate_container(s_appdata *adata, char *id, sfVector2f pos_ch);
void color_container(s_appdata *adata, char *id, sfColor color);
void set_container_outline(s_appdata *adata, char *id, \
sfColor color, float thickness);
void rotate_container(s_appdata *adata, char *id, float angle);
void scale_container(s_appdata *adata, char *id, sfVector2f factors);
void get_container_bounds_next(s_appdata *adata, \
linked_node *nodes, sfFloatRect *max);
sfFloatRect get_container_bounds(s_appdata *adata, char *id);
void set_container_rtex(s_appdata *adata, char *id, char *rtex_id);
void set_container_active(s_appdata *adata, char *id, sfUint8 active);
