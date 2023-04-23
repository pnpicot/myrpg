/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Skill tree module
*/

#include "main.h"

void init_stree_node22(s_appdata *adata, s_skill_tree *skill2)
{
    char *node_2_2 = "node_2_2";

    add_skill_node(adata, skill2, node_2_2, 2);
    set_skill_node_name(adata, skill2, node_2_2, "LEVEL 2");
    set_skill_node_parent(adata, skill2, node_2_2,
        get_skill_node(adata, skill2, "node_2_1"));
    set_skill_node_icon(adata, skill2, node_2_2, get_texture(adata, "tcube"));
    set_skill_node_price(adata, skill2, node_2_2, 0);
    set_skill_node_value(adata, skill2, node_2_2, 2);
    set_skill_node_trigger(adata, skill2, node_2_2, &add_speed);
    set_skill_node_level(adata, skill2, node_2_2, 1);
}

void init_stree_node23(s_appdata *adata, s_skill_tree *skill2)
{
    char *node_2_3 = "node_2_3";

    add_skill_node(adata, skill2, node_2_3, 3);
    set_skill_node_name(adata, skill2, node_2_3, "LEVEL 3");
    set_skill_node_parent(adata, skill2, node_2_3,
        get_skill_node(adata, skill2, "node_2_2"));
    set_skill_node_icon(adata, skill2, node_2_3, get_texture(adata, "tcube"));
    set_skill_node_price(adata, skill2, node_2_3, 0);
    set_skill_node_value(adata, skill2, node_2_3, 2);
    set_skill_node_trigger(adata, skill2, node_2_3, &add_speed);
    set_skill_node_level(adata, skill2, node_2_3, 2);
}

void init_stree_node24(s_appdata *adata, s_skill_tree *skill2)
{
    char *node_2_4 = "node_2_4";

    add_skill_node(adata, skill2, node_2_4, 4);
    set_skill_node_name(adata, skill2, node_2_4, "LEVEL 4");
    set_skill_node_parent(adata, skill2, node_2_4,
        get_skill_node(adata, skill2, "node_2_3"));
    set_skill_node_icon(adata, skill2, node_2_4, get_texture(adata, "tcube"));
    set_skill_node_price(adata, skill2, node_2_4, 0);
    set_skill_node_value(adata, skill2, node_2_4, 2);
    set_skill_node_trigger(adata, skill2, node_2_4, &add_speed);
    set_skill_node_level(adata, skill2, node_2_4, 3);
}

void init_stree_node25(s_appdata *adata, s_skill_tree *skill2)
{
    char *node_2_5 = "node_2_5";

    add_skill_node(adata, skill2, node_2_5, 5);
    set_skill_node_name(adata, skill2, node_2_5, "LEVEL 5");
    set_skill_node_parent(adata, skill2, node_2_5,
        get_skill_node(adata, skill2, "node_2_4"));
    set_skill_node_icon(adata, skill2, node_2_5, get_texture(adata, "tcube"));
    set_skill_node_price(adata, skill2, node_2_5, 0);
    set_skill_node_value(adata, skill2, node_2_5, 2);
    set_skill_node_trigger(adata, skill2, node_2_5, &add_speed);
    set_skill_node_level(adata, skill2, node_2_5, 4);
}

void init_stree_node26(s_appdata *adata, s_skill_tree *skill2)
{
    char *node_2_6 = "node_2_6";

    add_skill_node(adata, skill2, node_2_6, 6);
    set_skill_node_name(adata, skill2, node_2_6, "LEVEL 6");
    set_skill_node_parent(adata, skill2, node_2_6,
        get_skill_node(adata, skill2, "node_2_5"));
    set_skill_node_icon(adata, skill2, node_2_6, get_texture(adata, "tcube"));
    set_skill_node_price(adata, skill2, node_2_6, 0);
    set_skill_node_value(adata, skill2, node_2_6, 2);
    set_skill_node_trigger(adata, skill2, node_2_6, &add_speed);
    set_skill_node_level(adata, skill2, node_2_6, 5);
}