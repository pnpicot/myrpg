/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Quest module
*/

#include "main.h"

void init_quest_ui(s_appdata *adata)
{
    char *id = get_str(adata, "quest_bg");
    float width = get_float(adata, "quest_width");
    float padding = get_float(adata, "quest_padding");
    int layer = get_int(adata, "quest_layer");
    int win_h = get_int(adata, "win_h");
    float item_height = get_float(adata, "quest_item_height");
    int quest_count = linked_count(adata->game_data->quests);

    add_rect(adata, id, layer);
    sfVector2f size;
    size.x = width;
    size.y = 50.0f + (item_height * quest_count) + (padding * quest_count);
    sfVector2f pos = { 10, (win_h / 2) - (size.y / 2) };
    init_quest_ui_n(adata, id);
    resize_rect(adata, id, size);
    move_rect(adata, id, pos);
    init_quest_title(adata, id, size, pos);
}

void update_quests(s_appdata *adata)
{
    linked_node *quests = adata->game_data->quests;

    while (quests != NULL && quests->data != NULL) {
        s_quest *cur = (s_quest *) quests->data;

        update_quest_ui(adata, cur);

        if (cur->completed) {
            quests = quests->next;
            continue;
        }

        if (cur->completion_check != NULL)
            (*cur->completion_check)(adata, cur);

        quests = quests->next;
    }
}
