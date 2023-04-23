/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Skill tree module
*/

#include "main.h"

void init_stree_hitbox(s_appdata *adata, s_skill_node *node, \
char *skill_ctn, char *game_ctn)
{
    char *id = str_add("node-link-", get_random_id(5));
    id = str_m_add(3, id, "/", node->id);
    int layer = get_int(adata, "skill_layer");
    float size = get_float(adata, "skill_node_size");
    add_rect(adata, id, layer + 3);
    set_rect_rtex(adata, id, get_str(adata, "rtex_ui"));
    s_ref ref = { get_rect(adata, id), TYPE_RECT };
    add_to_container(adata, game_ctn, ref);
    add_to_container(adata, skill_ctn, ref);
    color_rect(adata, id, sfTransparent);
    sfVector2f rect_size = { size, size };
    sfVector2f origin = { rect_size.x / 2, rect_size.y / 2 };
    resize_rect(adata, id, rect_size);
    set_rect_origin(adata, id, origin);
    move_rect(adata, id, node->pos);
    char *obj_id = str_add(id, "@[:object]");
    add_object(adata, obj_id, ref);
    set_object_hover_bg(adata, obj_id, get_color(255, 255, 255, 20));
    set_object_pressed_bg(adata, obj_id, get_color(255, 255, 255, 40));
    set_object_onclick(adata, obj_id, &try_unlock_skill);
}

void init_stree_nodes_next(s_appdata *adata, s_tmp_stree dt)
{
    set_sprite_texture(adata, dt.id, dt.cur->icon);
    sfVector2f target_size = { dt.size, dt.size };
    scale_sprite(adata, dt.id, get_target_scale(target_size, dt.cur->icon));
    set_sprite_origin(adata, dt.id, (sfVector2f) { dt.size / 2, dt.size / 2 });
    int count = get_tree_node_count(dt.tree, dt.cur->level);
    float y_pos = dt.start->y + (!dt.ite ? dt.y_shift : 0);
    sfVector2f pos;
    pos.x = dt.start->x + (150.0f * dt.cur->level);
    pos.y = y_pos;
    dt.start->y += (y_pos - dt.start->y) + 150.0f;
    dt.cur->node_sprite = get_sprite(adata, dt.id);
    move_sprite(adata, dt.id, pos);
    sfFloatRect bounds = get_sprite_bounds(adata, dt.id);
    dt.cur->pos = (sfVector2f) { bounds.left + (bounds.width / 2),
                                bounds.top + (bounds.height / 2) };
    if (dt.ite) init_stree_link(adata, dt.cur, dt.skill_ctn, dt.game_ctn);
    if (dt.ite == f_max(0, dt.node_count - 2)) dt.tree->y_end = dt.start->y;
    init_stree_name(adata, dt.cur, dt.skill_ctn, dt.game_ctn);
    init_stree_hitbox(adata, dt.cur, dt.skill_ctn, dt.game_ctn);
}

float get_stree_yshift(s_appdata *adata, int index)
{
    s_skill_tree *last_tree = (s_skill_tree *)
            linked_get(adata->game_data->skill_trees, index - 1)->data;

    return (last_tree->y_end);
}

void add_stree_node_ctn(s_appdata *adata, char *id, \
char *game_ctn, char *skill_ctn)
{
    s_ref ref = { get_sprite(adata, id), TYPE_SPRITE };
    add_to_container(adata, game_ctn, ref);
    add_to_container(adata, skill_ctn, ref);
}

void init_stree_nodes(s_appdata *adata, char *skill_ctn, \
sfFloatRect bg_bounds, int index)
{
    char *id = get_str(adata, "skill_tree");
    float size = get_float(adata, "skill_node_size");
    char *game_ctn = get_str(adata, "ctn_game");
    s_skill_tree *tree = (s_skill_tree *)
        linked_get(adata->game_data->skill_trees, index)->data;
    linked_node *nodes = tree->nodes;
    sfVector2f start = { 150.0f, 150.0f };
    int node_count = linked_count(nodes);
    float y_shift = 0;
    if (index) y_shift = get_stree_yshift(adata, index);
    for (int ite = 0; nodes != NULL && nodes->data != NULL;++ite) {
        s_skill_node *cur = (s_skill_node *) nodes->data;
        char *id = str_m_add(4, tree->id, "@[:node-", nbr_to_str(ite), "]");
        add_sprite(adata, id, get_int(adata, "skill_layer") + 2);
        set_sprite_rtex(adata, id, get_str(adata, "rtex_ui"));
        add_stree_node_ctn(adata, id, game_ctn, skill_ctn);
        init_stree_nodes_next(adata, (s_tmp_stree) { id, size, cur, tree,
        &start, node_count, skill_ctn, game_ctn, y_shift, ite});
        nodes = nodes->next;
    }
}
