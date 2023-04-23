/*
** EPITECH PROJECT, 2023
** m_quest
** File description:
** quest_ga
*/

#include "main.h"

void show_quests(s_appdata *adata, s_quest *quest)
{
    linked_node *quests = adata->game_data->quests;
    char *ctn = get_str(adata, "ctn_quest");

    adata->game_data->show_quest = sfTrue;
    set_container_active(adata, ctn, 1);
    while (quests != NULL && quests->data != NULL) {
        s_quest *cur = (s_quest *) quests->data;
        cur->popup_rect->active = 0;
        cur->popup_text->active = 0;
        quests = quests->next;
    }
}

void check_first_quest(s_appdata *adata, s_quest *quest)
{
    s_player *player = adata->player;

    if (!player->transfered || quest->completed == sfTrue)
        return;
    quest->completed = sfTrue;
    show_quests(adata, NULL);
}

void check_second_quest(s_appdata *adata, s_quest *quest)
{
    s_player *player = adata->player;

    if (!player->killed_enemy || quest->completed == sfTrue)
        return;
    quest->completed = sfTrue;
    show_quests(adata, NULL);
}

void check_third_quest(s_appdata *adata, s_quest *quest)
{
    s_player *player = adata->player;

    if (!player->use_syringe || quest->completed == sfTrue)
        return;
    quest->completed = sfTrue;
    show_quests(adata, NULL);
}
