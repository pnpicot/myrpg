/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Skill tree module
*/

#include "main.h"

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
    resize_rect(adata, id, size);
    set_rect_origin(adata, id, (sfVector2f) { size.x / 2, size.y / 2 });
    move_rect(adata, id, (sfVector2f) { win_w / 2, win_h / 2 });
    color_rect(adata, id, primary);
    set_rect_outline(adata, id, secondary, 2.0f);
    set_rect_rtex(adata, id, rtex);
    s_ref ref = { get_rect(adata, id), TYPE_RECT };
    add_to_container(adata, game_ctn, ref);
    return (get_rect_bounds(adata, id));
}
