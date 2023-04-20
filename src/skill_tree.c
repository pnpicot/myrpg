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
    new_tree->y_end = 0;

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
    new_node->parent = NULL;
    new_node->node_sprite = NULL;
    new_node->pos = (sfVector2f) { 0, 0 };

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

void set_skill_node_parent(s_appdata *adata, s_skill_tree *tree, \
char *id, s_skill_node *parent)
{
    s_skill_node *node = get_skill_node(adata, tree, id);

    if (node == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    node->parent = parent;
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

    sfVector2f size = { (width * win_w) - 4.0f, (height * win_h) - 4.0f };
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

    return (get_rect_bounds(adata, id));
}

int get_tree_node_count(s_skill_tree *tree, int level)
{
    linked_node *nodes = tree->nodes;
    int count = 0;

    while (nodes != NULL && nodes->data != NULL) {
        s_skill_node *cur = (s_skill_node *) nodes->data;

        if (cur->level == level) count++;

        nodes = nodes->next;
    }

    return (count);
}

int get_tree_node_childs(s_skill_tree *tree, int level)
{
    linked_node *nodes = tree->nodes;
    int count = 0;

    while (nodes != NULL && nodes->data != NULL) {
        s_skill_node *cur = (s_skill_node *) nodes->data;

        if (cur->level > level) count++;

        nodes = nodes->next;
    }

    return (count);
}

void init_stree_link(s_appdata *adata, s_skill_node *node, \
char *skill_ctn, char *game_ctn)
{
    char *rtex = get_str(adata, "rtex_ui");
    char *id = str_add("node-link-", get_random_id(5));
    int layer = get_int(adata, "skill_layer");
    sfColor primary = get_config_color(adata, "skill_primary");
    sfColor secondary = get_config_color(adata, "skill_secondary");
    sfVector2f from = node->parent->pos;
    sfVector2f to = node->pos;

    add_vertex(adata, id, layer + 1);
    set_vertex_type(adata, id, sfLinesStrip);
    set_vertex_rtex(adata, id, rtex);
    resize_vertex(adata, id, 3);
    color_vertex_all(adata, id, sfLightGray);

    s_ref ref = { get_vertex(adata, id), TYPE_VERTEX };

    add_to_container(adata, game_ctn, ref);
    add_to_container(adata, skill_ctn, ref);
    move_vertex(adata, id, 0, from);
    move_vertex(adata, id, 1, (sfVector2f) { from.x, to.y });
    move_vertex(adata, id, 2, to);
}

void init_stree_name(s_appdata *adata, s_skill_node *node, \
char *skill_ctn, char *game_ctn)
{
    char *rtex = get_str(adata, "rtex_ui");
    char *id = str_add("node-link-", get_random_id(5));
    int layer = get_int(adata, "skill_layer");
    sfColor primary = get_config_color(adata, "skill_primary");
    sfColor secondary = get_config_color(adata, "skill_secondary");
    float size = get_float(adata, "skill_node_size");

    add_text(adata, id, layer + 3);
    set_text_rtex(adata, id, rtex);

    s_ref ref = { get_text(adata, id), TYPE_TEXT };

    add_to_container(adata, game_ctn, ref);
    add_to_container(adata, skill_ctn, ref);
    set_text_font(adata, id, get_font(adata, "lobster"));
    resize_text(adata, id, 20);
    color_text(adata, id, sfLightGray);
    edit_text(adata, id, node->name);

    sfFloatRect bounds = get_text_bounds(adata, id);
    sfVector2f origin = { bounds.width / 2, bounds.height / 2 };

    set_text_origin(adata, id, origin);

    sfVector2f pos;
    pos.x = node->pos.x;
    pos.y = node->pos.y - (size / 2) - 20.0f;

    move_text(adata, id, pos);
}

void init_stree_nodes(s_appdata *adata, char *skill_ctn, \
sfFloatRect bg_bounds, int index)
{
    char *id = get_str(adata, "skill_tree");
    int layer = get_int(adata, "skill_layer");
    float width = get_float(adata, "skill_width");
    float height = get_float(adata, "skill_height");
    float size = get_float(adata, "skill_node_size");
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    char *rtex = get_str(adata, "rtex_ui");
    sfColor primary = get_config_color(adata, "skill_primary");
    sfColor secondary = get_config_color(adata, "skill_secondary");
    char *game_ctn = get_str(adata, "ctn_game");
    s_skill_tree *tree = (s_skill_tree *) linked_get(adata->game_data->skill_trees, index)->data;
    linked_node *nodes = tree->nodes;
    int node_count = linked_count(nodes);
    int ite = 0;
    int s_ite = 0;
    int last = 0;
    float dist = 150.0f;
    sfVector2f start = { dist, dist };
    float y_shift = 0;

    if (index) {
        s_skill_tree *last_tree = (s_skill_tree *) linked_get(adata->game_data->skill_trees, index - 1)->data;
        y_shift = last_tree->y_end;
    }

    while (nodes != NULL && nodes->data != NULL) {
        s_skill_node *cur = (s_skill_node *) nodes->data;
        char *id = str_m_add(4, tree->id, "@[:node-", nbr_to_str(ite), "]");

        if (cur->level != last) s_ite = 0;

        add_sprite(adata, id, layer + 2);
        set_sprite_rtex(adata, id, rtex);

        s_ref ref = { get_sprite(adata, id), TYPE_SPRITE };

        add_to_container(adata, game_ctn, ref);
        add_to_container(adata, skill_ctn, ref);
        set_sprite_texture(adata, id, cur->icon);

        sfVector2f target_size = { size, size };
        sfVector2u tex_size = sfTexture_getSize(cur->icon);
        sfVector2f scale;

        scale.x = target_size.x / tex_size.x;
        scale.y = target_size.y / tex_size.y;

        scale_sprite(adata, id, scale);
        set_sprite_origin(adata, id, (sfVector2f) { size / 2, size / 2 });

        int count = get_tree_node_count(tree, cur->level);
        float y_pos = start.y + (!ite ? y_shift : 0);

        sfVector2f pos;
        pos.x = start.x + (dist * cur->level);
        pos.y = y_pos;

        if (!ite) start.y = y_pos;

        start.y += (y_pos - start.y) + dist;
        cur->node_sprite = get_sprite(adata, id);

        move_sprite(adata, id, pos);

        sfFloatRect bounds = get_sprite_bounds(adata, id);

        cur->pos = (sfVector2f) { bounds.left + (bounds.width / 2), bounds.top + (bounds.height / 2) };

        if (ite) init_stree_link(adata, cur, skill_ctn, game_ctn);
        if (ite == f_max(0, node_count - 2)) tree->y_end = start.y;

        init_stree_name(adata, cur, skill_ctn, game_ctn);

        last = cur->level;
        ite++;
        s_ite++;
        nodes = nodes->next;
    }
}

void init_stree_trees(s_appdata *adata, char *game_ctn, char *skill_ctn, \
sfFloatRect bg_bounds)
{
    linked_node *trees = adata->game_data->skill_trees;
    int ite = 0;

    while (trees != NULL && trees->data != NULL) {
        s_skill_tree *cur = (s_skill_tree *) trees->data;

        init_stree_nodes(adata, skill_ctn, bg_bounds, ite);

        ite++;
        trees = trees->next;
    }
}

void init_stree_title(s_appdata *adata, char *game_ctn, char *skill_ctn, \
sfFloatRect bg_bounds)
{
    char *id = str_add(get_str(adata, "skill_tree"), "@[:title]");
    int layer = get_int(adata, "skill_layer");
    char *rtex = get_str(adata, "rtex_ui");
    sfColor primary = get_config_color(adata, "skill_primary");
    sfColor secondary = get_config_color(adata, "skill_secondary");

    add_text(adata, id, layer + 4);
    set_text_rtex(adata, id, rtex);

    s_ref ref = { get_text(adata, id), TYPE_TEXT };

    add_to_container(adata, game_ctn, ref);
    edit_text(adata, id, "Skill tree");
    set_text_font(adata, id, get_font(adata, "lobster"));
    color_text(adata, id, secondary);
    resize_text(adata, id, 40);

    sfFloatRect bounds = get_text_bounds(adata, id);
    sfVector2f origin = { bounds.width / 2, bounds.height / 2 };
    sfVector2f pos = { bg_bounds.left + (bg_bounds.width / 2), bg_bounds.top + bg_bounds.height - 30.0f };

    set_text_origin(adata, id, origin);
    move_text(adata, id, pos);
}

void init_skills(s_appdata *adata)
{
    char *tree_0 = "tree_0";
    char *tree_1 = "tree_1";

    add_skill_tree(adata, tree_0);
    add_skill_tree(adata, tree_1);

    char *node_0_1 = "node_0_1";
    char *node_0_2 = "node_0_2";
    char *node_0_3 = "node_0_3";
    char *node_0_4 = "node_0_4";
    char *node_0_5 = "node_0_5";
    char *node_1_1 = "node_0_1";
    char *node_1_2 = "node_1_2";

    s_skill_tree *skill0 = get_skill_tree(adata, tree_0);
    s_skill_tree *skill1 = get_skill_tree(adata, tree_1);

    add_skill_node(adata, skill0, node_0_1, 0);
    set_skill_node_name(adata, skill0, node_0_1, "Node_0_1");
    set_skill_node_parent(adata, skill0, node_0_1, NULL);
    set_skill_node_icon(adata, skill0, node_0_1, get_texture(adata, "wall"));

    add_skill_node(adata, skill0, node_0_2, 1);
    set_skill_node_name(adata, skill0, node_0_2, "Node_0_2");
    set_skill_node_parent(adata, skill0, node_0_2, get_skill_node(adata, skill0, node_0_1));
    set_skill_node_icon(adata, skill0, node_0_2, get_texture(adata, "wall2"));

    add_skill_node(adata, skill0, node_0_4, 2);
    set_skill_node_name(adata, skill0, node_0_4, "Node_0_4");
    set_skill_node_parent(adata, skill0, node_0_4, get_skill_node(adata, skill0, node_0_2));
    set_skill_node_icon(adata, skill0, node_0_4, get_texture(adata, "wall2"));

    add_skill_node(adata, skill0, node_0_5, 2);
    set_skill_node_name(adata, skill0, node_0_5, "Node_0_5");
    set_skill_node_parent(adata, skill0, node_0_5, get_skill_node(adata, skill0, node_0_2));
    set_skill_node_icon(adata, skill0, node_0_5, get_texture(adata, "wall2"));

    add_skill_node(adata, skill0, node_0_3, 1);
    set_skill_node_name(adata, skill0, node_0_3, "Node_0_3");
    set_skill_node_parent(adata, skill0, node_0_3, get_skill_node(adata, skill0, node_0_1));
    set_skill_node_icon(adata, skill0, node_0_3, get_texture(adata, "wall2"));

    add_skill_node(adata, skill1, node_1_1, 0);
    set_skill_node_name(adata, skill1, node_1_1, "Node_1_1");
    set_skill_node_parent(adata, skill1, node_1_1, NULL);
    set_skill_node_icon(adata, skill1, node_1_1, get_texture(adata, "wall"));

    add_skill_node(adata, skill1, node_1_2, 1);
    set_skill_node_name(adata, skill1, node_1_2, "Node_1_2");
    set_skill_node_parent(adata, skill1, node_1_2, get_skill_node(adata, skill1, node_1_1));
    set_skill_node_icon(adata, skill1, node_1_2, get_texture(adata, "wall2"));
}

void init_skill_tree(s_appdata *adata)
{
    char *game_ctn = get_str(adata, "ctn_game");
    char *skill_ctn = get_str(adata, "ctn_skill");
    sfFloatRect background_bounds = init_stree_background(adata, game_ctn, skill_ctn);

    init_stree_title(adata, game_ctn, skill_ctn, background_bounds);
    init_skills(adata);
    init_stree_trees(adata, game_ctn, skill_ctn, background_bounds);
}
