/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Progression bar module
*/

#include "include/main.h"

s_bar *get_bar(s_appdata *adata, char *id)
{
    linked_node *bars = adata->lists->bars;

    while (bars != NULL && bars->data != NULL) {
        s_bar *cur = (s_bar *) bars->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        bars = bars->next;
    }

    return (NULL);
}

s_rect *get_bar_back(s_appdata *adata, char *bar_id, int layer)
{
    char *id = str_add(bar_id, "@[:back]");
    float width = get_float(adata, "bar_width");
    float height = get_float(adata, "bar_height");

    add_rect(adata, id, layer);
    resize_rect(adata, id, (sfVector2f) { width, height });
    color_rect(adata, id, get_config_color(adata, "bar_empty"));

    return (get_rect(adata, id));
}

s_rect *get_bar_fill(s_appdata *adata, char *bar_id, int layer)
{
    char *id = str_add(bar_id, "@[:fill]");
    float width = get_float(adata, "bar_width");
    float height = get_float(adata, "bar_height");

    add_rect(adata, id, layer + 1);
    resize_rect(adata, id, (sfVector2f) { width, height });
    color_rect(adata, id, get_config_color(adata, "bar_filled"));

    return (get_rect(adata, id));
}

void set_bar_display(s_appdata *adata, char *bar_id, sfBool display)
{
    s_bar *bar = get_bar(adata, bar_id);

    if (bar == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    if (!display && bar->text != NULL) {
        bar->text->active = 0;
        return;
    } else if (display && bar->text != NULL) {
        bar->text->active = 1;
        return;
    }

    char *id = str_add(bar->id, "@[:text]");
    int font_size = get_int(adata, "bar_font_size");

    add_text(adata, id, bar->fill_rect->layer + 1);
    set_text_font(adata, id, get_font(adata, get_str(adata, "bar_font")));
    color_text(adata, id, get_config_color(adata, "bar_foreground"));
    resize_text(adata, id, font_size);

    bar->text = get_text(adata, id);
    bar->text->rtex_id = bar->back_rect->rtex_id;

    update_bar(adata, bar);
}

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

    if (bar->text != NULL) {
        edit_text(adata, bar->text->id, nbr_to_str((int) bar->current));

        sfFloatRect text_bounds = get_text_bounds(adata, bar->text->id);
        sfVector2f text_origin;
        sfVector2f text_pos;

        text_origin.x = text_bounds.width / 2;
        text_origin.y = (sfText_getCharacterSize(bar->text->elem) / 2) + 4.0f;

        text_pos.x = back_bounds.left + (back_bounds.width / 2);
        text_pos.y = back_bounds.top + (back_bounds.height / 2);

        set_text_origin(adata, bar->text->id, text_origin);
        move_text(adata, bar->text->id, text_pos);
    }
}

void add_bar(s_appdata *adata, char *id, int layer)
{
    s_bar *bar = get_bar(adata, id);

    if (bar != NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    s_bar *new_bar = malloc(sizeof(s_bar));

    if (new_bar == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    new_bar->id = id;
    new_bar->min = get_float(adata, "bar_min");
    new_bar->max = get_float(adata, "bar_max");
    new_bar->current = get_float(adata, "bar_current");
    new_bar->back_rect = get_bar_back(adata, id, layer);
    new_bar->fill_rect = get_bar_fill(adata, id, layer);
    new_bar->text = NULL;

    update_bar(adata, new_bar);
    linked_add(adata->lists->bars, new_bar);
}

// TODO: prototype functions

void set_bar_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_bar *bar = get_bar(adata, id);
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (bar == NULL || rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    bar->back_rect->rtex_id = rtex_id;
    bar->fill_rect->rtex_id = rtex_id;

    if (bar->text != NULL) bar->text->rtex_id = rtex_id;
}

void move_bar(s_appdata *adata, char *id, sfVector2f pos)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    move_rect(adata, bar->back_rect->id, pos);
    update_bar(adata, bar);
}

void translate_bar(s_appdata *adata, char *id, sfVector2f pos_ch)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    translate_rect(adata, bar->back_rect->id, pos_ch);
    update_bar(adata, bar);
}

void set_bar_origin(s_appdata *adata, char *id, sfVector2f origin)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    set_rect_origin(adata, bar->back_rect->id, origin);
    update_bar(adata, bar);
}

void color_bar(s_appdata *adata, char *id, sfColor empty, sfColor filled)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    color_rect(adata, bar->back_rect->id, empty);
    color_rect(adata, bar->fill_rect->id, filled);
}

void set_bar_out(s_appdata *adata, char *id, sfColor color, float thickness)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    set_rect_outline(adata, bar->back_rect->id, color, thickness);
}

void set_bar_active(s_appdata *adata, char *id, sfUint8 active)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf(get_error(adata, "unknown_id"));
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
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    if (min >= bar->max) min = bar->max - 1;

    bar->min = min;
    bar->current = force_range(bar->current, bar->min, bar->max);

    update_bar(adata, bar);
}

void set_bar_max(s_appdata *adata, char *id, float max)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf(get_error(adata, "unknown_id"));
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
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    bar->current = force_range(current, bar->min, bar->max);

    update_bar(adata, bar);
}

int get_bar_current(s_appdata *adata, char *id)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (-1);
    }

    return (bar->current);
}

int get_bar_min(s_appdata *adata, char *id)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (-1);
    }

    return (bar->min);
}

int get_bar_max(s_appdata *adata, char *id)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (-1);
    }

    return (bar->max);
}

int get_bar_rest(s_appdata *adata, char *id)
{
    s_bar *bar = get_bar(adata, id);

    if (bar == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    return (bar->max - bar->current);
}
