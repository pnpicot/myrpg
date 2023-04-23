/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Skill tree module
*/

#include "main.h"

void init_stree_node01(s_appdata *adata, s_skill_tree *skill0)
{
    char *node_0_1 = "node_0_1";

    add_skill_node(adata, skill0, node_0_1, 0);
    set_skill_node_name(adata, skill0, node_0_1, "ATTACK");
    set_skill_node_parent(adata, skill0, node_0_1, NULL);
    set_skill_node_icon(adata, skill0, node_0_1, get_texture(adata, "tcube1"));
    set_skill_node_price(adata, skill0, node_0_1, 0);
}

void init_stree_node11(s_appdata *adata, s_skill_tree *skill1)
{
    char *node_1_1 = "node_1_1";

    add_skill_node(adata, skill1, node_1_1, 0);
    set_skill_node_name(adata, skill1, node_1_1, "HEALTH");
    set_skill_node_parent(adata, skill1, node_1_1, NULL);
    set_skill_node_icon(adata, skill1, node_1_1, get_texture(adata, "tcube1"));
    set_skill_node_price(adata, skill1, node_1_1, 0);
}

void init_stree_node21(s_appdata *adata, s_skill_tree *skill2)
{
    char *node_2_1 = "node_2_1";

    add_skill_node(adata, skill2, node_2_1, 0);
    set_skill_node_name(adata, skill2, node_2_1, "SPEED");
    set_skill_node_parent(adata, skill2, node_2_1, NULL);
    set_skill_node_icon(adata, skill2, node_2_1, get_texture(adata, "tcube1"));
    set_skill_node_price(adata, skill2, node_2_1, 0);
}

void init_stree_node31(s_appdata *adata, s_skill_tree *skill3)
{
    char *node_3_1 = "node_3_1";

    add_skill_node(adata, skill3, node_3_1, 0);
    set_skill_node_name(adata, skill3, node_3_1, "TRANSFERENCE");
    set_skill_node_parent(adata, skill3, node_3_1, NULL);
    set_skill_node_icon(adata, skill3, node_3_1, get_texture(adata, "tcube1"));
    set_skill_node_price(adata, skill3, node_3_1, 0);
}
