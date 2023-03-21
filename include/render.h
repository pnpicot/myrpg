/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Render module
*/

#pragma once

#include "main.h"

void render_rects(s_appdata *adata, int layer, s_rtex *rtex);
void render_circles(s_appdata *adata, int layer, s_rtex *rtex);
void render_sprites(s_appdata *adata, int layer, s_rtex *rtex);
void render_texts(s_appdata *adata, int layer, s_rtex *rtex);
void render_vertexes(s_appdata *adata, int layer, s_rtex *rtex);
void render_elements(s_appdata *adata, s_rtex *rtex);
void render_textures(s_appdata *adata, int depth);
void clear_rtexs(s_appdata *adata);
void display_rtexs(s_appdata *adata);
void render(s_appdata *adata, float render_rate);
