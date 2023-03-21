/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Render texture module
*/

#pragma once

#include "main.h"

s_rtex *get_rtex(s_appdata *adata, char *id);
sfRenderStates *get_default_rstate(void);
void add_rtex(s_appdata *adata, char *id, int depth);
void delete_rtex(s_appdata *adata, char *id);
void set_rtex_shader(s_appdata *adata, char *id, sfShader *shader);
void set_rtex_blendmode(s_appdata *adata, char *id, sfBlendMode mode);
void clear_rtex(s_appdata *adata, char *id, sfColor color);
void set_rtex_inherit(s_appdata *adata, char *id, sfUint8 inherit);
sfShader *get_rtex_shader(s_appdata *adata, char *id);
s_rtex *get_rtex_d(s_appdata *adata, int depth);
