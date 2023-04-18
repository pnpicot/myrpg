/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Quest module
*/

#pragma once

#include "main.h"

s_quest *get_quest(s_appdata *adata, char *id);
void delete_quest(s_appdata *adata, char *id);
void add_quest(s_appdata *adata, char *id);
void set_quest_text(s_appdata *adata, char *id, char *text);
void set_quest_icon(s_appdata *adata, char *id, sfTexture *texture);
void init_quest_ui(s_appdata *adata);
void init_quests(s_appdata *adata);
void set_quest_title(s_appdata *adata, char *id, char *title);
