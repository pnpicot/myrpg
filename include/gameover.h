/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Gameover module
*/

#pragma once

#include "main.h"

void trigger_respawn_next(s_appdata *adata);
void trigger_respawn(s_appdata *adata, s_ref *ref);
void init_gameover_button_next(s_appdata *adata, char *id);
void init_gameover_button(s_appdata *adata, char *rtex, char *ctn);
void init_gameover_text(s_appdata *adata, char *rtex, char *ctn);
void init_gameover(s_appdata *adata);
