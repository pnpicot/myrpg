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

    linked_add(adata->game_data->skill_trees, new_tree);
}

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

    new_node->id = id;
    new_node->level = level;
    new_node->icon = NULL;
    new_node->name = NULL;

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

void set_skill_node_icon(s_appdata *adata, s_skill_tree *tree, \
char *id, sfTexture *icon)
{
    s_skill_node *node = get_skill_node(adata, tree, id);

    if (node == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    node->icon = icon;
}

void set_skill_node_name(s_appdata *adata, s_skill_tree *tree, \
char *id, char *skill_name)
{
    s_skill_node *node = get_skill_node(adata, tree, id);

    if (node == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    node->name = skill_name;
}

void set_skill_node_level(s_appdata *adata, s_skill_tree *tree, \
char *id, int level)
{
    s_skill_node *node = get_skill_node(adata, tree, id);

    if (node == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }
}

sfFloatRect init_stree_background(s_appdata *adata, char *game_ctn, \
char *skill_ctn)
{
    char *id = get_str(adata, "skill_tree");
    int layer = get_int(adata, "skill_layer");
    float width = get_float(adata, "skill_width");
    float height = get_float(adata, "skill_height");
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    char *rtex = get_str(adata, "rtex_ui");
    sfColor primary = get_config_color(adata, "skill_primary");
    sfColor secondary = get_config_color(adata, "skill_secondary");

    add_rect(adata, id, layer);

    sfVector2f size = { width * win_w, height * win_h };
    sfVector2f origin = { size.x / 2, size.y / 2 };
    sfVector2f pos = { win_w / 2, win_h / 2 };

    resize_rect(adata, id, size);
    set_rect_origin(adata, id, origin);
    move_rect(adata, id, pos);
    color_rect(adata, id, primary);
    set_rect_outline(adata, id, secondary, 2.0f);
    set_rect_rtex(adata, id, rtex);

    s_ref ref = { get_rect(adata, id), TYPE_RECT };

    add_to_container(adata, game_ctn, ref);
    add_to_container(adata, skill_ctn, ref);

    return (get_rect_bounds(adata, id));
}

void init_skills(s_appdata *adata)
{
    // ...
}

void init_skill_tree(s_appdata *adata)
{
    char *game_ctn = get_str(adata, "ctn_game");
    char *skill_ctn = get_str(adata, "ctn_skill");
    // sfFloatRect background_bounds = init_stree_background(adata, game_ctn, skill_ctn);

    init_skills(adata);
}
