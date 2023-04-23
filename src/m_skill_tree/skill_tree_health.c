/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Skill tree module
*/

#include "main.h"

void init_stree_node12(s_appdata *adata, s_skill_tree *skill1)
{
    char *node_1_2 = "node_1_2";

    add_skill_node(adata, skill1, node_1_2, 1);
    set_skill_node_name(adata, skill1, node_1_2, "LEVEL 2");
    set_skill_node_parent(adata, skill1, node_1_2,
        get_skill_node(adata, skill1, "node_1_1"));
    set_skill_node_icon(adata, skill1, node_1_2, get_texture(adata, "tcube"));
    set_skill_node_price(adata, skill1, node_1_2, 0);
    set_skill_node_value(adata, skill1, node_1_2, 2);
    set_skill_node_trigger(adata, skill1, node_1_2, &add_health);
}

void init_stree_node13(s_appdata *adata, s_skill_tree *skill1)
{
    char *node_1_3 = "node_1_3";

    add_skill_node(adata, skill1, node_1_3, 1);
    set_skill_node_name(adata, skill1, node_1_3, "LEVEL 3");
    set_skill_node_parent(adata, skill1, node_1_3,
        get_skill_node(adata, skill1, "node_1_2"));
    set_skill_node_icon(adata, skill1, node_1_3, get_texture(adata, "tcube"));
    set_skill_node_price(adata, skill1, node_1_3, 0);
    set_skill_node_value(adata, skill1, node_1_3, 2);
    set_skill_node_trigger(adata, skill1, node_1_3, &add_health);
}

void init_stree_node14(s_appdata *adata, s_skill_tree *skill1)
{
    char *node_1_4 = "node_1_4";

    add_skill_node(adata, skill1, node_1_4, 1);
    set_skill_node_name(adata, skill1, node_1_4, "LEVEL 4");
    set_skill_node_parent(adata, skill1, node_1_4,
        get_skill_node(adata, skill1, "node_1_3"));
    set_skill_node_icon(adata, skill1, node_1_4, get_texture(adata, "tcube"));
    set_skill_node_price(adata, skill1, node_1_4, 0);
    set_skill_node_value(adata, skill1, node_1_4, 2);
    set_skill_node_trigger(adata, skill1, node_1_4, &add_health);
}

void init_stree_node15(s_appdata *adata, s_skill_tree *skill1)
{
    char *node_1_5 = "node_1_5";

    add_skill_node(adata, skill1, node_1_5, 1);
    set_skill_node_name(adata, skill1, node_1_5, "LEVEL 5");
    set_skill_node_parent(adata, skill1, node_1_5,
        get_skill_node(adata, skill1, "node_1_4"));
    set_skill_node_icon(adata, skill1, node_1_5, get_texture(adata, "tcube"));
    set_skill_node_price(adata, skill1, node_1_5, 0);
    set_skill_node_value(adata, skill1, node_1_5, 2);
    set_skill_node_trigger(adata, skill1, node_1_5, &add_health);
}

void init_stree_node16(s_appdata *adata, s_skill_tree *skill1)
{
    char *node_1_6 = "node_1_6";

    add_skill_node(adata, skill1, node_1_6, 1);
    set_skill_node_name(adata, skill1, node_1_6, "LEVEL 6");
    set_skill_node_parent(adata, skill1, node_1_6,
        get_skill_node(adata, skill1, "node_1_5"));
    set_skill_node_icon(adata, skill1, node_1_6, get_texture(adata, "tcube"));
    set_skill_node_price(adata, skill1, node_1_6, 0);
    set_skill_node_value(adata, skill1, node_1_6, 2);
    set_skill_node_trigger(adata, skill1, node_1_6, &add_health);
}