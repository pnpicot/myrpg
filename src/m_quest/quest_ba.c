/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Quest module
*/

#include "main.h"

s_quest *get_quest(s_appdata *adata, char *id)
{
    linked_node *quests = adata->game_data->quests;

    while (quests != NULL && quests->data != NULL) {
        s_quest *cur = (s_quest *) quests->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        quests = quests->next;
    }

    return (NULL);
}

void delete_quest(s_appdata *adata, char *id)
{
    s_quest *quest = get_quest(adata, id);

    if (quest == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    linked_node *quests = adata->game_data->quests;
    int ite = 0;

    while (quests != NULL && quests->data != NULL) {
        s_quest *cur = (s_quest *) quests->data;

        if (!my_strcmp(cur->id, id)) break;

        ite++;
        quests = quests->next;
    }

    linked_delete(&adata->game_data->quests, ite);
}

void add_quest(s_appdata *adata, char *id)
{
    s_quest *quest = get_quest(adata, id);
    if (quest != NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "already_exists"));
        return;
    }
    s_quest *new_quest = malloc(sizeof(s_quest));
    if (new_quest == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return;
    }
    *new_quest = (s_quest) {0};
    new_quest->id = id;
    new_quest->completed = sfFalse;
    linked_add(adata->game_data->quests, new_quest);
}

void set_quest_completed(s_appdata *adata, char *id, sfBool completed)
{
    s_quest *quest = get_quest(adata, id);

    if (quest == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    quest->completed = completed;
}

void set_quest_check(s_appdata *adata, char *id, \
void (*completion_check)(s_appdata *adata, s_quest *quest))
{
    s_quest *quest = get_quest(adata, id);

    if (quest == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    quest->completion_check = completion_check;
}
