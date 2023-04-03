/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Elements utilities module
*/

#pragma once

#include "main.h"

void add_faction(s_appdata *adata, char *id);
s_faction *get_faction(s_appdata *adata, char *id);
void set_faction_pos(s_appdata *adata, char *id, sfVector2f pos);
void set_faction_radius(s_appdata *adata, char *id, float radius);
