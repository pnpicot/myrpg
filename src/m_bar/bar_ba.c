/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Progression bar module
*/

#include "../include/main.h"

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
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
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
    add_text(adata, id, bar->fill_rect->layer + 1);
    set_text_font(adata, id, get_font(adata, get_str(adata, "bar_font")));
    color_text(adata, id, get_config_color(adata, "bar_foreground"));
    resize_text(adata, id, get_int(adata, "bar_font_size"));
    bar->text = get_text(adata, id);
    set_text_rtex(adata, id, bar->back_rect->rtex_id);
    update_bar(adata, bar);
}

void update_bar_text(s_appdata *adata, s_bar *bar, sfFloatRect back_bounds)
{
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
