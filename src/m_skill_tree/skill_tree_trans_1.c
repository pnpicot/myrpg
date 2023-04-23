/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Skill tree module
*/

#include "main.h"

void init_stree_node32(s_appdata *adata, s_skill_tree *skill3)
{
    char *node_3_2 = "node_3_2";

    add_skill_node(adata, skill3, node_3_2, 1);
    set_skill_node_name(adata, skill3, node_3_2, "LEVEL 2");
    set_skill_node_parent(adata, skill3, node_3_2,
        get_skill_node(adata, skill3, "node_3_1"));
    set_skill_node_icon(adata, skill3, node_3_2, get_texture(adata, "tree_cube"));
    set_skill_node_price(adata, skill3, node_3_2, 1500);
    set_skill_node_trigger(adata, skill3, node_3_2, &add_transference);
}

void init_stree_node33(s_appdata *adata, s_skill_tree *skill3)
{
    char *node_3_3 = "node_3_3";

    add_skill_node(adata, skill3, node_3_3, 1);
    set_skill_node_name(adata, skill3, node_3_3, "LEVEL 3");
    set_skill_node_parent(adata, skill3, node_3_3,
        get_skill_node(adata, skill3, "node_3_2"));
    set_skill_node_icon(adata, skill3, node_3_3, get_texture(adata, "tree_cube"));
    set_skill_node_price(adata, skill3, node_3_3, 2000);
    set_skill_node_trigger(adata, skill3, node_3_3, &add_transference);
}

void init_stree_node34(s_appdata *adata, s_skill_tree *skill3)
{
    char *node_3_4 = "node_3_4";

    add_skill_node(adata, skill3, node_3_4, 1);
    set_skill_node_name(adata, skill3, node_3_4, "LEVEL 4");
    set_skill_node_parent(adata, skill3, node_3_4,
        get_skill_node(adata, skill3, "node_3_3"));
    set_skill_node_icon(adata, skill3, node_3_4, get_texture(adata, "tree_cube"));
    set_skill_node_price(adata, skill3, node_3_4, 2500);
    set_skill_node_trigger(adata, skill3, node_3_4, &add_transference);
}

void init_stree_node35(s_appdata *adata, s_skill_tree *skill3)
{
    char *node_3_5 = "node_3_5";

    add_skill_node(adata, skill3, node_3_5, 1);
    set_skill_node_name(adata, skill3, node_3_5, "LEVEL 5");
    set_skill_node_parent(adata, skill3, node_3_5,
        get_skill_node(adata, skill3, "node_3_4"));
    set_skill_node_icon(adata, skill3, node_3_5, get_texture(adata, "tree_cube"));
    set_skill_node_price(adata, skill3, node_3_5, 3000);
    set_skill_node_trigger(adata, skill3, node_3_5, &add_transference);
}

void init_stree_node36(s_appdata *adata, s_skill_tree *skill3)
{
    char *node_3_6 = "node_3_6";

    add_skill_node(adata, skill3, node_3_6, 1);
    set_skill_node_name(adata, skill3, node_3_6, "LEVEL 6");
    set_skill_node_parent(adata, skill3, node_3_6,
        get_skill_node(adata, skill3, "node_3_5"));
    set_skill_node_icon(adata, skill3, node_3_6, get_texture(adata, "tree_cube"));
    set_skill_node_price(adata, skill3, node_3_6, 3500);
    set_skill_node_trigger(adata, skill3, node_3_6, &add_transference);
}
