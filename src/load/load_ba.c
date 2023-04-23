/*
** EPITECH PROJECT, 2023
** load
** File description:
** load_ba
*/

#include "main.h"

void modify_game_syringe(s_appdata *adata, linked_node *syringe, \
char **lines, int i)
{
    char **syr_stat = str_split(lines[i], '~');
    while (syringe != NULL && syringe->data != NULL) {
        s_syringe *syr_cur = (s_syringe *) syringe->data;
        if (!my_strcmp(syr_cur->name, syr_stat[0])) {
            syr_cur->count = my_getnbr(syr_stat[1]);
            break;
        }
        syringe = syringe->next;
    }
}

void modify_game_quests(s_appdata *adata, linked_node *quests, \
char **lines, int i)
{
    char **quest_stat = str_split(lines[i], '~');
    while (quests != NULL && quests->data != NULL) {
        s_quest *quest_cur = (s_quest *) quests->data;
        if (!my_strcmp(quest_cur->title, quest_stat[0])) {
            quest_cur->completed = my_getnbr(quest_stat[1]);
            break;
        }
        quests = quests->next;
    }
}

void modify_game_skill_trees(s_appdata *adata, linked_node *trees, \
char **lines, int i)
{
    char **trees_stat = str_split(lines[i], '~');
    while (trees != NULL && trees->data != NULL) {
        s_skill_tree *trees_cur = (s_skill_tree *) trees->data;
        if (!my_strcmp(trees_cur->id, trees_stat[0])) {
            trees_cur->y_end = my_getnbr(trees_stat[2]);
            break;
        }
        trees = trees->next;
    }
}

void modify_game_entities_emiter(s_appdata *adata, s_entity *new_entity,
sfVector2f pos)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    (*new_entity->emiter)(adata, new_entity);
    char *emiter_id = str_add(new_entity->id, "@[:emiter]");
    pos.x -= adata->game_data->view_pos.x;
    pos.y -= adata->game_data->view_pos.y;
    translate_emiter(adata, emiter_id, pos);
}

void modify_game_entities(s_appdata *adata, linked_node *models, \
char **lines, int i)
{
    char **model_stat = str_split(lines[i], '~');

    for (; models != NULL && models->data != NULL; models = models->next) {
        s_entity *model = (s_entity *) models->data;
        s_faction *faction = model->faction;
        if (my_strcmp(faction->id, model_stat[0]))
            continue;
        sfClock_restart(model->clock);
        s_entity *new_entity = copy_entity_model(adata, model);
        sfVector2f pos = {str_to_float(model_stat[1]),
        str_to_float(model_stat[2])};
        new_entity->pos = pos;
        faction->entity_count++;

        if (new_entity->emiter != NULL)
            modify_game_entities_emiter(adata, new_entity, pos);

        linked_add(adata->game_data->entities, new_entity);
    }
}
