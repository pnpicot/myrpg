/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Skill tree module
*/

#include "main.h"

void init_skill_tree(s_appdata *adata)
{
    char *game_ctn = get_str(adata, "ctn_game");
    char *skill_ctn = get_str(adata, "ctn_skill");
    sfFloatRect background_bounds = init_stree_background(adata,
        game_ctn, skill_ctn);

    init_stree_title(adata, game_ctn, skill_ctn, background_bounds);
    init_skills(adata);
    init_stree_trees(adata, game_ctn, skill_ctn, background_bounds);
}

void update_stree_nodes(s_appdata *adata, s_skill_tree *tree)
{
    linked_node *nodes = tree->nodes;

    while (nodes != NULL && nodes->data != NULL) {
        s_skill_node *cur = (s_skill_node *) nodes->data;

        if (cur->unlocked) {
            set_sprite_color(adata, cur->node_sprite->id, sfWhite);
        } else {
            set_sprite_color(adata, cur->node_sprite->id, sfRed);
        }

        nodes = nodes->next;
    }
}

void update_skill_tree(s_appdata *adata)
{
    linked_node *trees = adata->game_data->skill_trees;

    while (trees != NULL && trees->data != NULL) {
        s_skill_tree *cur = (s_skill_tree *) trees->data;

        update_stree_nodes(adata, cur);

        trees = trees->next;
    }
}
