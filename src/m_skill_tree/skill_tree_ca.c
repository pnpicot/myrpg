/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Skill tree module
*/

#include "main.h"

void add_skill_node(s_appdata *adata, s_skill_tree *tree, char *id, int level)
{
    s_skill_node *node = get_skill_node(adata, tree, id);
    if (node != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }
    s_skill_node *new_node = malloc(sizeof(s_skill_node));
    if (new_node == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }
    add_skill_node_next(new_node, id, level);
    linked_add(tree->nodes, new_node);
}

void delete_skill_node(s_appdata *adata, char *id)
{
    s_skill_tree *tree = get_skill_tree(adata, id);

    if (tree == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *trees = adata->game_data->skill_trees;
    int ite = 0;

    while (trees != NULL && trees->data != NULL) {
        s_skill_tree *cur = (s_skill_tree *) trees->data;

        if (!my_strcmp(cur->id, id)) break;

        ite++;
        trees = trees->next;
    }

    linked_delete(&adata->game_data->skill_trees, ite);
}

void set_skill_node_value(s_appdata *adata, s_skill_tree *tree, \
char *id, float value)
{
    s_skill_node *node = get_skill_node(adata, tree, id);

    if (node == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    node->trigger_value = value;
}

void set_skill_node_trigger(s_appdata *adata, s_skill_tree *tree, \
char *id, void (*unlock_trigger)(s_appdata *adata, float value))
{
    s_skill_node *node = get_skill_node(adata, tree, id);

    if (node == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    node->unlock_trigger = unlock_trigger;
}

void set_skill_node_price(s_appdata *adata, s_skill_tree *tree, \
char *id, int price)
{
    s_skill_node *node = get_skill_node(adata, tree, id);

    if (node == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    node->price = price;
}
