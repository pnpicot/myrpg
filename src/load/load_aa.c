/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Save module
*/

#include "main.h"

void modify_game(s_appdata *adata, char *content)
{
    char **lines = str_split(content, '#');
    int j = 0;
    while (lines[j] != NULL) {
        printf("%s\n",lines[j]);
        j++;
    }

    s_player *player = adata->player;
    player->attack = str_to_float(lines[0]);
    player->defense = str_to_float(lines[1]);
    player->health_rate = str_to_float(lines[2]);
    player->health.x = str_to_float(lines[3]);
    player->health.y = str_to_float(lines[4]);
    player->moula = str_to_float(lines[5]);
    player->transference_rate = str_to_float(lines[6]);
    player->transference.x = str_to_float(lines[7]);
    player->transference.y = str_to_float(lines[8]);
    player->transference_level = my_getnbr(lines[9]);
    int i = 11;
    while (my_strcmp(lines[i], "$array")) {
        linked_node *syringe = adata->game_data->syringes;
        modify_game_syringe(adata, syringe, lines, i);
        i++;
    }
    i += 2;

    while (my_strcmp(lines[i], "$array")) {
        linked_node *quests = adata->game_data->quests;
        modify_game_quests(adata, quests, lines, i);
        i++;
    }
    i++;

    adata->game_data->view_pos.x = str_to_float(lines[i]);
    adata->game_data->view_pos.y = str_to_float(lines[i + 1]);
    adata->game_data->velocity = str_to_float(lines[i + 2]);
    adata->game_data->speed_max = str_to_float(lines[i + 3]);
    adata->game_data->speed.x = str_to_float(lines[i + 4]);
    adata->game_data->speed.y = str_to_float(lines[i + 5]);
    i += 7;

    while (my_strcmp(lines[i], "$array")) {
        linked_node *trees = adata->game_data->skill_trees;
        modify_game_skill_trees(adata, trees, lines, i);
        i++;
    }
    i += 2;

    free_ll_and_data(&adata->game_data->entities);
    adata->game_data->entities = linked_new();


    linked_node *factions = adata->game_data->factions;
    while (factions != NULL && factions->data != NULL) {
        s_faction *faction = (s_faction *) factions->data;
        faction->entity_count = 0;
        factions = factions->next;
    }

    while (my_strcmp(lines[i], "$array")) {
        linked_node *models = adata->game_data->entity_models;
        modify_game_entities(adata, models, lines, i);
        i++;
    }
}
