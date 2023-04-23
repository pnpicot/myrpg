/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Save module
*/

#include "main.h"

void save_fill_player(s_appdata *adata, linked_node *lines)
{
    s_player *player = adata->player;

    linked_add(lines, float_to_str(player->attack, 2, 0));
    linked_add(lines, float_to_str(player->defense, 2, 0));
    linked_add(lines, float_to_str(player->health_rate, 2, 0));
    linked_add(lines, float_to_str(player->health.x, 2, 0));
    linked_add(lines, float_to_str(player->health.y, 2, 0));
    linked_add(lines, nbr_to_str(player->moula));
    linked_add(lines, float_to_str(player->transference_rate, 2, 0));
    linked_add(lines, float_to_str(player->transference.x, 2, 0));
    linked_add(lines, float_to_str(player->transference.y, 2, 0));
    linked_add(lines, nbr_to_str(player->transference_level));
}

void save_fill_syringes(s_appdata *adata, linked_node *lines)
{
    s_game *game_data = adata->game_data;

    linked_add(lines, "$array");

    linked_node *syringes = game_data->syringes;

    while (syringes != NULL && syringes->data != NULL) {
        s_syringe *cur = (s_syringe *) syringes->data;

        linked_add(lines, str_m_add(3, cur->name, "~", nbr_to_str(cur->count)));

        syringes = syringes->next;
    }

    linked_add(lines, "$array");
}

void save_fill_quests(s_appdata *adata, linked_node *lines)
{
    s_game *game_data = adata->game_data;

    linked_add(lines, "$array");

    linked_node *quests = game_data->quests;

    while (quests != NULL && quests->data != NULL) {
        s_quest *cur = (s_quest *) quests->data;

        linked_add(lines, str_m_add(3, cur->title, "~",
            nbr_to_str(cur->completed)));

        quests = quests->next;
    }

    linked_add(lines, "$array");
}

void save_fill_skill_trees(s_appdata *adata, linked_node *lines)
{
    s_game *game_data = adata->game_data;
    linked_add(lines, "$array");
    linked_node *skill_trees = game_data->skill_trees;
    while (skill_trees != NULL && skill_trees->data != NULL) {
        s_skill_tree *cur = (s_skill_tree *) skill_trees->data;
        linked_node *nodes = cur->nodes;
        while (nodes != NULL && nodes->data != NULL) {
            s_skill_node *cur_node = (s_skill_node *) nodes->data;
            linked_add(lines, str_m_add(5, cur->id, "~", cur_node->name, "~",
                nbr_to_str(cur_node->unlocked)));
            nodes = nodes->next;
        }
        skill_trees = skill_trees->next;
    }
    linked_add(lines, "$array");
}

void save_fill_entities(s_appdata *adata, linked_node *lines)
{
    s_game *game_data = adata->game_data;

    linked_add(lines, "$array");

    linked_node *entities = game_data->entities;

    while (entities != NULL && entities->data != NULL) {
        s_entity *cur = (s_entity *) entities->data;

        linked_add(lines, str_m_add(7, cur->faction->id, "~",
            cur->name, "~", float_to_str(cur->pos.x, 2, 0),
            "~", float_to_str(cur->pos.y, 2, 0)));

        entities = entities->next;
    }

    linked_add(lines, "$array");
}
