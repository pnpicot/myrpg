/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Vertex module
*/

#pragma once

#include "main.h"

s_vertex *get_vertex(s_appdata *adata, char *id);
void delete_vertex(s_appdata *adata, char *id);
void add_vertex(s_appdata *adata, char *id, int layer);
void set_vertex_rtex(s_appdata *adata, char *id, char *rtex_id);
void set_vertex_active(s_appdata *adata, char *id, sfUint8 active);
void resize_vertex(s_appdata *adata, char *id, int vertex_count);
void move_vertex(s_appdata *adata, char *id, int index, sfVector2f pos);
void color_vertex(s_appdata *adata, char *id, int index, sfColor color);
void set_vertex_type(s_appdata *adata, char *id, sfPrimitiveType type);
void translate_vertex(s_appdata *adata, char *id, int index, sfVector2f pos_ch);
void translate_vertex_all(s_appdata *adata, char *id, sfVector2f pos_ch);
void color_vertex_all(s_appdata *adata, char *id, sfColor color);
int get_vertex_size(s_appdata *adata, char *id);
sfVector2f get_vertex_pos(s_appdata *adata, char *id, int index);
sfColor get_vertex_color(s_appdata *adata, char *id, int index);
void clear_vertex(s_appdata *adata, char *id);
sfFloatRect get_vertex_bounds(s_appdata *adata, char *id);
