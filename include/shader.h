/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Shader module
*/

#pragma once

#include "main.h"

sfShader *get_shader(s_appdata *adata, char *id);
void delete_shader(s_appdata *adata, char *id);
int add_shader_vert(s_appdata *adata, char *vert, char **vert_path);
int add_shader_frag(s_appdata *adata, char *frag, char **frag_path);
void add_shader(s_appdata *adata, char *id, char *paths);
void load_shaders(s_appdata *adata);
void set_shader_float(s_appdata *adata, char *id, char *param, float value);
void set_shader_vec2(s_appdata *adata, char *id, char *param, sfVector2f value);
void set_shader_color(s_appdata *adata, char *id, char *param, sfColor color);
void set_shader_texture(s_appdata *adata, char *id, char *param, \
const sfTexture *tex);
