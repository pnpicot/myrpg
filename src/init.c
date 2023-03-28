/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Initialization module
*/

#include "main.h"

void init(s_appdata *adata)
{
    load_fonts(adata);
    load_textures(adata);
    load_keymaps(adata);

    if (get_int(adata, "enable_shader")) load_shaders(adata);

    load_sounds(adata);
    load_musics(adata);
}
