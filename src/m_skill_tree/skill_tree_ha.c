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
    set_skill_node_icon(adata, skill0, node_0_1, get_texture(adata, "tree_cube"));
    set_skill_node_price(adata, skill0, node_0_1, 300);
}

void init_stree_node11(s_appdata *adata, s_skill_tree *skill1)
{
    char *node_1_1 = "node_1_1";

    add_skill_node(adata, skill1, node_1_1, 0);
    set_skill_node_name(adata, skill1, node_1_1, "HEALTH");
    set_skill_node_parent(adata, skill1, node_1_1, NULL);
    set_skill_node_icon(adata, skill1, node_1_1, get_texture(adata, "tree_cube"));
    set_skill_node_price(adata, skill1, node_1_1, 300);
}

void init_stree_node21(s_appdata *adata, s_skill_tree *skill2)
{
    char *node_2_1 = "node_2_1";

    add_skill_node(adata, skill2, node_2_1, 0);
    set_skill_node_name(adata, skill2, node_2_1, "SPEED");
    set_skill_node_parent(adata, skill2, node_2_1, NULL);
    set_skill_node_icon(adata, skill2, node_2_1, get_texture(adata, "tree_cube"));
    set_skill_node_price(adata, skill2, node_2_1, 300);
}

void init_stree_node31(s_appdata *adata, s_skill_tree *skill3)
{
    char *node_3_1 = "node_3_1";

    add_skill_node(adata, skill3, node_3_1, 0);
    set_skill_node_name(adata, skill3, node_3_1, "TRANSFERENCE");
    set_skill_node_parent(adata, skill3, node_3_1, NULL);
    set_skill_node_icon(adata, skill3, node_3_1, get_texture(adata, "tree_cube"));
    set_skill_node_price(adata, skill3, node_3_1, 300);
}

void init_skills(s_appdata *adata)
{
    char *tree_0 = "tree_0";
    char *tree_1 = "tree_1";
    char *tree_2 = "tree_2";
    char *tree_3 = "tree_3";
    add_skill_tree(adata, tree_0);
    add_skill_tree(adata, tree_1);
    add_skill_tree(adata, tree_2);
    add_skill_tree(adata, tree_3);
    s_skill_tree *skill0 = get_skill_tree(adata, tree_0);
    s_skill_tree *skill1 = get_skill_tree(adata, tree_1);
    s_skill_tree *skill2 = get_skill_tree(adata, tree_2);
    s_skill_tree *skill3 = get_skill_tree(adata, tree_3);

    init_stree_node01(adata, skill0);
    init_stree_node02(adata, skill0);
    init_stree_node03(adata, skill0);
    init_stree_node04(adata, skill0);
    init_stree_node05(adata, skill0);
    init_stree_node06(adata, skill0);

    init_stree_node11(adata, skill1);
    init_stree_node12(adata, skill1);
    init_stree_node13(adata, skill1);
    init_stree_node14(adata, skill1);
    init_stree_node15(adata, skill1);
    init_stree_node16(adata, skill1);

    init_stree_node21(adata, skill2);
    init_stree_node22(adata, skill2);
    init_stree_node23(adata, skill2);
    init_stree_node24(adata, skill2);
    init_stree_node25(adata, skill2);
    init_stree_node26(adata, skill2);

    init_stree_node31(adata, skill3);
    init_stree_node32(adata, skill3);
    init_stree_node33(adata, skill3);
    init_stree_node34(adata, skill3);
    init_stree_node35(adata, skill3);
    init_stree_node36(adata, skill3);
    init_stree_node37(adata, skill3);
    init_stree_node38(adata, skill3);
    init_stree_node39(adata, skill3);

    printf("1\n");
}
