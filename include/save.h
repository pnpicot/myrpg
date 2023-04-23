/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Save module
*/

#pragma once

#include "main.h"

void save_fill_player(s_appdata *adata, linked_node *lines);
void save_fill_syringes(s_appdata *adata, linked_node *lines);
void save_fill_quests(s_appdata *adata, linked_node *lines);
void save_fill_skill_trees(s_appdata *adata, linked_node *lines);
void save_fill_entities(s_appdata *adata, linked_node *lines);
void save_fill_gamedata(s_appdata *adata, linked_node *lines);
void save_fill(s_appdata *adata, linked_node *lines);
void save_to_file(s_appdata *adata, char *save);
void save_game(s_appdata *adata);
