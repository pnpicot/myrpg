/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Progression bar module
*/

#include "../include/main.h"

void update_bar(s_appdata *adata, s_bar *bar)
{
    sfFloatRect back_bounds = get_rect_bounds(adata, bar->back_rect->id);
    sfVector2f fill_pos;

    fill_pos.x = back_bounds.left;
    fill_pos.y = back_bounds.top;

    move_rect(adata, bar->fill_rect->id, fill_pos);

    sfVector2f fill_size;
    fill_size.x = (bar->current / (bar->max + bar->min)) * back_bounds.width;
    fill_size.y = back_bounds.height;

    resize_rect(adata, bar->fill_rect->id, fill_size);

    if (bar->text != NULL)
        update_bar_text(adata, bar, back_bounds);
}

void add_bar(s_appdata *adata, char *id, int layer)
{
    s_bar *bar = get_bar(adata, id);
    if (bar != NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }
    s_bar *new_bar = malloc(sizeof(s_bar));
    if (new_bar == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return;
    }
    *new_bar = (s_bar) {.id = id, .min = get_float(adata, "bar_min"),
    .max = get_float(adata, "bar_max"), .current = get_float(adata,
    "bar_current"), .back_rect = get_bar_back(adata, id, layer),
    .fill_rect = get_bar_fill(adata, id, layer), .text = NULL
    };
    update_bar(adata, new_bar);
    update_bar(adata, new_bar);
    linked_add(adata->lists->bars, new_bar);
}

void set_bar_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_bar *bar = get_bar(adata, id);
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (bar == NULL || rtex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    set_rect_rtex(adata, bar->back_rect->id, rtex_id);
    set_rect_rtex(adata, bar->fill_rect->id, rtex_id);

    if (bar->text != NULL)
        set_text_rtex(adata, bar->text->id, rtex_id);
}

void move_bar(s_appdata *adata, char *id, sfVector2f pos)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    move_rect(adata, bar->back_rect->id, pos);
    update_bar(adata, bar);
}

void translate_bar(s_appdata *adata, char *id, sfVector2f pos_ch)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    translate_rect(adata, bar->back_rect->id, pos_ch);
    update_bar(adata, bar);
}
