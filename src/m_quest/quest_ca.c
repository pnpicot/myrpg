/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Quest module
*/

#include "main.h"

void set_quest_title(s_appdata *adata, char *id, char *title)
{
    s_quest *quest = get_quest(adata, id);

    if (quest == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    quest->title = title;
}

void set_quest_text(s_appdata *adata, char *id, char *text)
{
    s_quest *quest = get_quest(adata, id);

    if (quest == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    quest->text = text;
}

void set_quest_icon(s_appdata *adata, char *id, sfTexture *texture)
{
    s_quest *quest = get_quest(adata, id);

    if (quest == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    quest->icon = texture;
}

void update_quest_ui(s_appdata *adata, s_quest *quest)
{
    if (quest->completed) {
        color_button_bg(adata, quest->item->id, get_color(0, 100, 30, 220));
    }
}

void check_first_quest(s_appdata *adata, s_quest *quest)
{
    s_player *player = adata->player;

    if (player->transfered) {
        quest->completed = sfTrue;
    }
}
