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
s_skill_node *get_skill_node_abs(s_appdata *adata, char *id);
void add_skill_tree(s_appdata *adata, char *id);
void add_skill_node(s_appdata *adata, s_skill_tree *tree, char *id, int level);
void delete_skill_node(s_appdata *adata, char *id);
void set_skill_node_trigger(s_appdata *adata, s_skill_tree *tree, \
char *id, void (*unlock_trigger)(s_appdata *adata, float value));
void set_skill_node_price(s_appdata *adata, s_skill_tree *tree, \
char *id, int price);
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
int get_tree_node_count(s_skill_tree *tree, int level);
int get_tree_node_childs(s_skill_tree *tree, int level);
void init_stree_link(s_appdata *adata, s_skill_node *node, \
char *skill_ctn, char *game_ctn);
void init_stree_name(s_appdata *adata, s_skill_node *node, \
char *skill_ctn, char *game_ctn);
void init_stree_hitbox(s_appdata *adata, s_skill_node *node, \
char *skill_ctn, char *game_ctn);
void init_stree_nodes(s_appdata *adata, char *skill_ctn, \
sfFloatRect bg_bounds, int index);
void init_stree_trees(s_appdata *adata, char *game_ctn, char *skill_ctn, \
sfFloatRect bg_bounds);
void init_stree_title(s_appdata *adata, char *game_ctn, char *skill_ctn, \
sfFloatRect bg_bounds);
void init_skills(s_appdata *adata);
void init_skill_tree(s_appdata *adata);
void update_stree_nodes(s_appdata *adata, s_skill_tree *tree);
void update_skill_tree(s_appdata *adata);
void set_skill_node_value(s_appdata *adata, s_skill_tree *tree, \
char *id, float value);
