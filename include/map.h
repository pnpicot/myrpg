/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Map module
*/

#pragma once

#include "main.h"

s_tile *get_tile(s_appdata *adata, char id);
void add_tile(s_appdata *adata, char ch, char *tex_id, sfBool solid);
void load_tiles(s_appdata *adata);
void add_tile_to_map_n(s_appdata *adata, char *tile_id, sfIntRect rect,
sfVector2f pos);
void add_tile_to_map(s_appdata *adata, char ch, sfVector2f pos, \
sfVector2f size);
void load_map(s_appdata *adata, char *map);
void init_map(s_appdata *adata, char *filename);
void init_map_path_finding(s_appdata *adata, char **entries, int size_x,
int size_y);
