/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Progression bar module
*/

#include "../include/main.h"

void set_bar_origin(s_appdata *adata, char *id, sfVector2f origin)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    set_rect_origin(adata, bar->back_rect->id, origin);
    update_bar(adata, bar);
}

void color_bar(s_appdata *adata, char *id, sfColor empty, sfColor filled)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    color_rect(adata, bar->back_rect->id, empty);
    color_rect(adata, bar->fill_rect->id, filled);
}

void set_bar_out(s_appdata *adata, char *id, sfColor color, float thickness)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    set_rect_outline(adata, bar->back_rect->id, color, thickness);
}

void set_bar_active(s_appdata *adata, char *id, sfUint8 active)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    bar->back_rect->active = active;
    bar->fill_rect->active = active;

    if (bar->text != NULL) bar->text->active = active;
}

void set_bar_min(s_appdata *adata, char *id, float min)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    if (min >= bar->max) min = bar->max - 1;

    bar->min = min;
    bar->current = force_range(bar->current, bar->min, bar->max);

    update_bar(adata, bar);
}
