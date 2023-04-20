/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Skill tree module
*/

#pragma once

#include "main.h"

s_skill_tree *get_skill_tree(s_appdata *adata, char *id);
s_skill_node *get_skill_node(s_appdata *adata, s_skill_tree *tree, char *id);
void add_skill_tree(s_appdata *adata, char *id);
void add_skill_node(s_appdata *adata, s_skill_tree *tree, char *id, int level);
void delete_skill_node(s_appdata *adata, char *id);
void set_skill_node_parent(s_appdata *adata, s_skill_tree *tree, \
char *id, s_skill_node *parent);
void set_skill_node_icon(s_appdata *adata, s_skill_tree *tree, \
char *id, sfTexture *icon);
void set_skill_node_name(s_appdata *adata, s_skill_tree *tree, \
char *id, char *skill_name);
void set_skill_node_level(s_appdata *adata, s_skill_tree *tree, \
char *id, int level);
sfFloatRect init_stree_background(s_appdata *adata, char *game_ctn, \
char *skill_ctn);
void init_skills(s_appdata *adata);
void init_skill_tree(s_appdata *adata);
