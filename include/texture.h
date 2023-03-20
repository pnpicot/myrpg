/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Texture module
*/

#pragma once

#include "main.h"

sfTexture *get_texture(s_appdata *adata, char *id);
void delete_texture(s_appdata *adata, char *id);
void add_texture(s_appdata *adata, char *id, char *filename);
void load_textures(s_appdata *adata);
