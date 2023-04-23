/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Skill tree module
*/

#include "main.h"

s_skill_tree *get_skill_tree(s_appdata *adata, char *id)
{
    linked_node *trees = adata->game_data->skill_trees;

    while (trees != NULL && trees->data != NULL) {
        s_skill_tree *cur = (s_skill_tree *) trees->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        trees = trees->next;
    }

    return (NULL);
}

s_skill_node *get_skill_node(s_appdata *adata, s_skill_tree *tree, char *id)
{
    linked_node *nodes = tree->nodes;

    while (nodes != NULL && nodes->data != NULL) {
        s_skill_node *cur = (s_skill_node *) nodes->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        nodes = nodes->next;
    }

    return (NULL);
}

s_skill_node *get_skill_node_abs(s_appdata *adata, char *id)
{
    linked_node *trees = adata->game_data->skill_trees;

    while (trees != NULL && trees->data != NULL) {
        s_skill_tree *cur = (s_skill_tree *) trees->data;
        s_skill_node *query = get_skill_node(adata, cur, id);

        if (query != NULL) return (query);

        trees = trees->next;
    }

    return (NULL);
}

void add_skill_tree(s_appdata *adata, char *id)
{
    s_skill_tree *tree = get_skill_tree(adata, id);

    if (tree != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    s_skill_tree *new_tree = malloc(sizeof(s_skill_tree));

    if (new_tree == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    new_tree->id = id;
    new_tree->nodes = linked_new();
    new_tree->y_end = 0;

    linked_add(adata->game_data->skill_trees, new_tree);
}

void add_skill_node_next(s_skill_node *new_node, char *id, int level)
{
    new_node->id = id;
    new_node->level = level;
    new_node->icon = NULL;
    new_node->name = NULL;
    new_node->parent = NULL;
    new_node->node_sprite = NULL;
    new_node->pos = (sfVector2f) { 0, 0 };
    new_node->price = 0;
    new_node->unlocked = level ? sfFalse : sfTrue;
    new_node->unlock_trigger = NULL;
    new_node->trigger_value = 0;
}
