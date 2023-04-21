/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Progression bar module
*/

#include "../include/main.h"

int get_bar_rest(s_appdata *adata, char *id)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return (-1);
    }

    return (bar->max - bar->current);
}

void resize_bar(s_appdata *adata, char *id, sfVector2f size)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    resize_rect(adata, bar->back_rect->id, size);
    update_bar(adata, bar);
}
