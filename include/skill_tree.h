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
void add_skill_node_next(s_skill_node *new_node, char *id, int level);
void add_skill_node(s_appdata *adata, s_skill_tree *tree, char *id, int level);
void delete_skill_node(s_appdata *adata, char *id);
void set_skill_node_value(s_appdata *adata, s_skill_tree *tree, \
char *id, float value);
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
void try_unlock_skill(s_appdata *adata, s_ref *ref);
void init_stree_hitbox(s_appdata *adata, s_skill_node *node, \
char *skill_ctn, char *game_ctn);
void init_stree_nodes_next(s_appdata *adata, s_tmp_stree dt);
float get_stree_yshift(s_appdata *adata, int index);
void add_stree_node_ctn(s_appdata *adata, char *id, \
char *game_ctn, char *skill_ctn);
void init_stree_nodes(s_appdata *adata, char *skill_ctn, \
sfFloatRect bg_bounds, int index);
void init_stree_trees(s_appdata *adata, char *game_ctn, char *skill_ctn, \
sfFloatRect bg_bounds);
void init_stree_title(s_appdata *adata, char *game_ctn, char *skill_ctn, \
sfFloatRect bg_bounds);

void init_stree_node01(s_appdata *adata, s_skill_tree *skill0);
void init_stree_node02(s_appdata *adata, s_skill_tree *skill0);
void init_stree_node03(s_appdata *adata, s_skill_tree *skill0);
void init_stree_node04(s_appdata *adata, s_skill_tree *skill0);
void init_stree_node05(s_appdata *adata, s_skill_tree *skill0);
void init_stree_node06(s_appdata *adata, s_skill_tree *skill0);

void init_stree_node11(s_appdata *adata, s_skill_tree *skill1);
void init_stree_node12(s_appdata *adata, s_skill_tree *skill1);
void init_stree_node13(s_appdata *adata, s_skill_tree *skill1);
void init_stree_node14(s_appdata *adata, s_skill_tree *skill1);
void init_stree_node15(s_appdata *adata, s_skill_tree *skill1);
void init_stree_node16(s_appdata *adata, s_skill_tree *skill1);

void init_stree_node21(s_appdata *adata, s_skill_tree *skill2);
void init_stree_node22(s_appdata *adata, s_skill_tree *skill2);
void init_stree_node23(s_appdata *adata, s_skill_tree *skill2);
void init_stree_node24(s_appdata *adata, s_skill_tree *skill2);
void init_stree_node25(s_appdata *adata, s_skill_tree *skill2);
void init_stree_node26(s_appdata *adata, s_skill_tree *skill2);

void init_stree_node31(s_appdata *adata, s_skill_tree *skill3);
void init_stree_node32(s_appdata *adata, s_skill_tree *skill3);
void init_stree_node33(s_appdata *adata, s_skill_tree *skill3);
void init_stree_node34(s_appdata *adata, s_skill_tree *skill3);
void init_stree_node35(s_appdata *adata, s_skill_tree *skill3);
void init_stree_node36(s_appdata *adata, s_skill_tree *skill3);
void init_stree_node37(s_appdata *adata, s_skill_tree *skill3);
void init_stree_node38(s_appdata *adata, s_skill_tree *skill3);
void init_stree_node39(s_appdata *adata, s_skill_tree *skill3);

void init_skills(s_appdata *adata);
void init_skill_tree(s_appdata *adata);
void update_stree_nodes(s_appdata *adata, s_skill_tree *tree);
void update_skill_tree(s_appdata *adata);
void add_health(s_appdata *adata, float value);
void add_attack(s_appdata *adata, float value);
void add_speed(s_appdata *adata, float value);
void add_transference(s_appdata *adata, float value);
