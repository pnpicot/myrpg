/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** NPC Module
*/

#pragma once

#include "main.h"

void init_npc(s_appdata *adata);
void update_npc(s_appdata *adata);
void update_npc_bubble(s_appdata *adata, char *text);
void update_npc(s_appdata *adata);
void init_npc_rect(s_appdata *adata, char *text_id, \
char *rtex, char *container);
void init_npc_text_next(s_appdata *adata, char *id);
void init_npc_text(s_appdata *adata, sfVector2f npc_pos);
