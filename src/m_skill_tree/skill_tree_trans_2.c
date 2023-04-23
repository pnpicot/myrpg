/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Skill tree module
*/

#include "main.h"

void init_stree_node37(s_appdata *adata, s_skill_tree *skill3)
{
    char *node_3_7 = "node_3_7";

    add_skill_node(adata, skill3, node_3_7, 1);
    set_skill_node_name(adata, skill3, node_3_7, "LEVEL 7");
    set_skill_node_parent(adata, skill3, node_3_7,
        get_skill_node(adata, skill3, "node_3_6"));
    set_skill_node_icon(adata, skill3, node_3_7, get_texture(adata, "tree_cube"));
    set_skill_node_price(adata, skill3, node_3_7, 4000);
    set_skill_node_trigger(adata, skill3, node_3_7, &add_transference);
}

void init_stree_node38(s_appdata *adata, s_skill_tree *skill3)
{
    char *node_3_8 = "node_3_8";

    add_skill_node(adata, skill3, node_3_8, 1);
    set_skill_node_name(adata, skill3, node_3_8, "LEVEL 8");
    set_skill_node_parent(adata, skill3, node_3_8,
        get_skill_node(adata, skill3, "node_3_7"));
    set_skill_node_icon(adata, skill3, node_3_8, get_texture(adata, "tree_cube"));
    set_skill_node_price(adata, skill3, node_3_8, 4500);
    set_skill_node_trigger(adata, skill3, node_3_8, &add_transference);
}

void init_stree_node39(s_appdata *adata, s_skill_tree *skill3)
{
    char *node_3_9 = "node_3_9";

    add_skill_node(adata, skill3, node_3_9, 1);
    set_skill_node_name(adata, skill3, node_3_9, "LEVEL 9");
    set_skill_node_parent(adata, skill3, node_3_9,
        get_skill_node(adata, skill3, "node_3_8"));
    set_skill_node_icon(adata, skill3, node_3_9, get_texture(adata, "tree_cube"));
    set_skill_node_price(adata, skill3, node_3_9, 5000);
    set_skill_node_trigger(adata, skill3, node_3_9, &add_transference);
}
