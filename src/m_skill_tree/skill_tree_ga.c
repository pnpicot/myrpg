/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Skill tree module
*/

#include "main.h"

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
    float y_shift = bg_bounds.top + bg_bounds.height - 30.0f;
    sfVector2f pos = { bg_bounds.left + (bg_bounds.width / 2), y_shift };
    set_text_origin(adata, id, origin);
    move_text(adata, id, pos);
}

void init_stree_node01(s_appdata *adata, s_skill_tree *skill0)
{
    char *node_0_1 = "node_0_1";

    add_skill_node(adata, skill0, node_0_1, 0);
    set_skill_node_name(adata, skill0, node_0_1, "Node_0_1");
    set_skill_node_parent(adata, skill0, node_0_1, NULL);
    set_skill_node_icon(adata, skill0, node_0_1, get_texture(adata, "wall"));
    set_skill_node_price(adata, skill0, node_0_1, 300);
}

void init_stree_node02(s_appdata *adata, s_skill_tree *skill0)
{
    char *node_0_2 = "node_0_2";

    add_skill_node(adata, skill0, node_0_2, 1);
    set_skill_node_name(adata, skill0, node_0_2, "Node_0_2");
    set_skill_node_parent(adata, skill0, node_0_2,
        get_skill_node(adata, skill0, "node_0_1"));
    set_skill_node_icon(adata, skill0, node_0_2, get_texture(adata, "wall2"));
    set_skill_node_price(adata, skill0, node_0_2, 600);
    set_skill_node_trigger(adata, skill0, node_0_2, &add_player_trflevel);
    set_skill_node_value(adata, skill0, node_0_2, 2);
}

void init_stree_node04(s_appdata *adata, s_skill_tree *skill0)
{
    char *node_0_4 = "node_0_4";

    add_skill_node(adata, skill0, node_0_4, 2);
    set_skill_node_name(adata, skill0, node_0_4, "Node_0_4");
    set_skill_node_parent(adata, skill0, node_0_4,
        get_skill_node(adata, skill0, "node_0_2"));
    set_skill_node_icon(adata, skill0, node_0_4, get_texture(adata, "wall2"));
    set_skill_node_price(adata, skill0, node_0_4, 3000);
}
