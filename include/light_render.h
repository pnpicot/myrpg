/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Light rendering module
*/

#pragma once

#include "main.h"

void set_lightmask_rtex(s_appdata *adata, char *rtex_id);
void render_lights(s_appdata *adata);
sfBool in_light_range(s_appdata *adata, int depth);
