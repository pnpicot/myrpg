/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Skill tree module
*/

#include "main.h"

void init_stree_node05(s_appdata *adata, s_skill_tree *skill0)
{
    char *node_0_5 = "node_0_5";

    add_skill_node(adata, skill0, node_0_5, 2);
    set_skill_node_name(adata, skill0, node_0_5, "Node_0_5");
    set_skill_node_parent(adata, skill0, node_0_5,
        get_skill_node(adata, skill0, "node_0_2"));
    set_skill_node_icon(adata, skill0, node_0_5, get_texture(adata, "wall2"));
    set_skill_node_price(adata, skill0, node_0_5, 5000);
}

void init_stree_node03(s_appdata *adata, s_skill_tree *skill0)
{
    char *node_0_3 = "node_0_3";

    add_skill_node(adata, skill0, node_0_3, 1);
    set_skill_node_name(adata, skill0, node_0_3, "Node_0_3");
    set_skill_node_parent(adata, skill0, node_0_3,
        get_skill_node(adata, skill0, "node_0_1"));
    set_skill_node_icon(adata, skill0, node_0_3, get_texture(adata, "wall2"));
    set_skill_node_price(adata, skill0, node_0_3, 1800);
}

void init_stree_node11(s_appdata *adata, s_skill_tree *skill1)
{
    char *node_1_1 = "node_1_1";

    add_skill_node(adata, skill1, node_1_1, 0);
    set_skill_node_name(adata, skill1, node_1_1, "Node_1_1");
    set_skill_node_parent(adata, skill1, node_1_1, NULL);
    set_skill_node_icon(adata, skill1, node_1_1, get_texture(adata, "wall"));
    set_skill_node_price(adata, skill1, node_1_1, 300);
}

void init_stree_node12(s_appdata *adata, s_skill_tree *skill1)
{
    char *node_1_2 = "node_1_2";

    add_skill_node(adata, skill1, node_1_2, 1);
    set_skill_node_name(adata, skill1, node_1_2, "Node_1_2");
    set_skill_node_parent(adata, skill1, node_1_2,
        get_skill_node(adata, skill1, "node_1_1"));
    set_skill_node_icon(adata, skill1, node_1_2, get_texture(adata, "wall2"));
    set_skill_node_price(adata, skill1, node_1_2, 15000);
}

void init_skills(s_appdata *adata)
{
    char *tree_0 = "tree_0";
    char *tree_1 = "tree_1";
    add_skill_tree(adata, tree_0);
    add_skill_tree(adata, tree_1);
    s_skill_tree *skill0 = get_skill_tree(adata, tree_0);
    s_skill_tree *skill1 = get_skill_tree(adata, tree_1);
    init_stree_node01(adata, skill0);
    init_stree_node02(adata, skill0);
    init_stree_node04(adata, skill0);
    init_stree_node05(adata, skill0);
    init_stree_node03(adata, skill0);
    init_stree_node11(adata, skill1);
    init_stree_node12(adata, skill1);
}
