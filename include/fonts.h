/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Fonts module
*/

#pragma once

#include "main.h"

sfFont *get_font(s_appdata *adata, char *id);
void add_font(s_appdata *adata, char *id, char *filename);
void load_fonts(s_appdata *adata);

