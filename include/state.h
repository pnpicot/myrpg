/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** State module
*/

#pragma once

#include "main.h"

s_state *get_state(s_appdata *adata, char *id);
void delete_state(s_appdata *adata, char *id);
void set_state_container(s_appdata *adata, char *id, s_container *container);
void add_state_rtex(s_appdata *adata, char *id, s_rtex *rtex);
void set_state_ingame(s_appdata *adata, char *id, sfBool in_game);
void add_state(s_appdata *adata, char *id);
void switch_state(s_appdata *adata, char *id);
