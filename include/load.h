/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Load module
*/

#pragma once

#include "main.h"

void modify_game_syringe(s_appdata *adata, linked_node *syringe, \
char **lines, int i);
void modify_game(s_appdata *adata, char *content);
void load_game(s_appdata *adata, s_ref *ref);
void init_load_input(s_appdata *adata, char *container, char *rtex);
void init_load_btn(s_appdata *adata, char *container, char *rtex);
void modify_game_syringe(s_appdata *adata, linked_node *syringe, \
char **lines, int i);
void modify_game_quests(s_appdata *adata, linked_node *quests, \
char **lines, int i);
void modify_game_skill_trees(s_appdata *adata, linked_node *trees, \
char **lines, int i);
void modify_game_entities(s_appdata *adata, linked_node *models, \
char **lines, int i);
