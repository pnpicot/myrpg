/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Skill tree module
*/

#include "main.h"

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
    char *id = str_add("node-link-", get_random_id(5));
    float size = get_float(adata, "skill_node_size");
    add_text(adata, id, get_int(adata, "skill_layer") + 3);
    set_text_rtex(adata, id, get_str(adata, "rtex_ui"));
    s_ref ref = { get_text(adata, id), TYPE_TEXT };
    add_to_container(adata, game_ctn, ref);
    add_to_container(adata, skill_ctn, ref);
    set_text_font(adata, id, get_font(adata, "lobster"));
    resize_text(adata, id, 20);
    color_text(adata, id, sfLightGray);
    char *text = str_m_add(4, node->name, " (", nbr_to_str(node->price), " M)");
    edit_text(adata, id, text);
    sfFloatRect bounds = get_text_bounds(adata, id);
    sfVector2f origin = { bounds.width / 2, bounds.height / 2 };
    set_text_origin(adata, id, origin);
    sfVector2f pos;
    pos.x = node->pos.x;
    pos.y = node->pos.y - (size / 2) - 20.0f;
    move_text(adata, id, pos);
}

void try_unlock_skill(s_appdata *adata, s_ref *ref)
{
    s_rect *rect = (s_rect *) ref->ref;
    char *node_id = str_split(rect->id, '/')[1];
    s_skill_node *node = get_skill_node_abs(adata, node_id);

    if (node == NULL || node->unlocked || !node->parent->unlocked) return;

    s_player *player = adata->player;

    if (player->moula >= node->price) {
        player->moula -= node->price;
        node->unlocked = sfTrue;

        if (node->unlock_trigger != NULL)
            (*node->unlock_trigger)(adata, node->trigger_value);
    }
}
