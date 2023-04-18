/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Map module
*/

#pragma once

#include "main.h"

void init_map(s_appdata *adata, char *filename);
void init_map_path_finding(s_appdata *adata, char **entries, int size_x,
int size_y);
s_tile *get_tile(s_appdata *adata, char id);
