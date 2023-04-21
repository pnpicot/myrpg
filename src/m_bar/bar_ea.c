/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Progression bar module
*/

#include "../include/main.h"

void set_bar_max(s_appdata *adata, char *id, float max)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    if (max <= bar->min) max = bar->min + 1;

    bar->max = max;
    bar->current = force_range(bar->current, bar->min, bar->max);

    update_bar(adata, bar);
}

void set_bar_current(s_appdata *adata, char *id, float current)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    bar->current = force_range(current, bar->min, bar->max);

    update_bar(adata, bar);
}

int get_bar_current(s_appdata *adata, char *id)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return (-1);
    }

    return (bar->current);
}

int get_bar_min(s_appdata *adata, char *id)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return (-1);
    }

    return (bar->min);
}

int get_bar_max(s_appdata *adata, char *id)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return (-1);
    }

    return (bar->max);
}
