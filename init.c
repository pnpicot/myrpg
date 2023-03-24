/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Initialization module
*/

#include "include/main.h"

void init(s_appdata *adata)
{
    load_fonts(adata);
    load_textures(adata);
    load_keymaps(adata);
    load_shaders(adata);
}
