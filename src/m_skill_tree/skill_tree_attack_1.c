/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Skill tree module
*/

#include "main.h"

void init_stree_node02(s_appdata *adata, s_skill_tree *skill0)
{
    char *node_0_2 = "node_0_2";

    add_skill_node(adata, skill0, node_0_2, 1);
    set_skill_node_name(adata, skill0, node_0_2, "LEVEL 2");
    set_skill_node_parent(adata, skill0, node_0_2,
        get_skill_node(adata, skill0, "node_0_1"));
    set_skill_node_icon(adata, skill0, node_0_2, get_texture(adata, "tcube"));
    set_skill_node_price(adata, skill0, node_0_2, 0);
    set_skill_node_value(adata, skill0, node_0_2, 2);
    set_skill_node_trigger(adata, skill0, node_0_2, &add_attack);
}

void init_stree_node03(s_appdata *adata, s_skill_tree *skill0)
{
    char *node_0_3 = "node_0_3";

    add_skill_node(adata, skill0, node_0_3, 1);
    set_skill_node_name(adata, skill0, node_0_3, "LEVEL 3");
    set_skill_node_parent(adata, skill0, node_0_3,
        get_skill_node(adata, skill0, "node_0_2"));
    set_skill_node_icon(adata, skill0, node_0_3, get_texture(adata, "tcube"));
    set_skill_node_price(adata, skill0, node_0_3, 0);
    set_skill_node_value(adata, skill0, node_0_3, 2);
    set_skill_node_trigger(adata, skill0, node_0_3, &add_attack);
}

void init_stree_node04(s_appdata *adata, s_skill_tree *skill0)
{
    char *node_0_4 = "node_0_4";

    add_skill_node(adata, skill0, node_0_4, 1);
    set_skill_node_name(adata, skill0, node_0_4, "LEVEL 4");
    set_skill_node_parent(adata, skill0, node_0_4,
        get_skill_node(adata, skill0, "node_0_3"));
    set_skill_node_icon(adata, skill0, node_0_4, get_texture(adata, "tcube"));
    set_skill_node_price(adata, skill0, node_0_4, 0);
    set_skill_node_value(adata, skill0, node_0_4, 2);
    set_skill_node_trigger(adata, skill0, node_0_4, &add_attack);
}

void init_stree_node05(s_appdata *adata, s_skill_tree *skill0)
{
    char *node_0_5 = "node_0_5";

    add_skill_node(adata, skill0, node_0_5, 1);
    set_skill_node_name(adata, skill0, node_0_5, "LEVEL 5");
    set_skill_node_parent(adata, skill0, node_0_5,
        get_skill_node(adata, skill0, "node_0_4"));
    set_skill_node_icon(adata, skill0, node_0_5, get_texture(adata, "tcube"));
    set_skill_node_price(adata, skill0, node_0_5, 0);
    set_skill_node_value(adata, skill0, node_0_5, 2);
    set_skill_node_trigger(adata, skill0, node_0_5, &add_attack);
}

void init_stree_node06(s_appdata *adata, s_skill_tree *skill0)
{
    char *node_0_6 = "node_0_6";

    add_skill_node(adata, skill0, node_0_6, 1);
    set_skill_node_name(adata, skill0, node_0_6, "LEVEL 6");
    set_skill_node_parent(adata, skill0, node_0_6,
        get_skill_node(adata, skill0, "node_0_5"));
    set_skill_node_icon(adata, skill0, node_0_6, get_texture(adata, "tcube"));
    set_skill_node_price(adata, skill0, node_0_6, 0);
    set_skill_node_value(adata, skill0, node_0_6, 2);
    set_skill_node_trigger(adata, skill0, node_0_6, &add_attack);
}
