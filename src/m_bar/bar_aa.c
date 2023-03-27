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
        my_printf(get_error(adata, "unknown_id"));
        return (-1);
    }

    return (bar->max - bar->current);
}
