/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Slider module
*/

#include "../include/main.h"

s_slider *get_slider(s_appdata *adata, char *id)
{
    linked_node *sliders = adata->lists->sliders;

    while (sliders != NULL && sliders->data != NULL) {
        s_slider *cur = (s_slider *) sliders->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        sliders = sliders->next;
    }

    return (NULL);
}

s_button *get_slider_left(s_appdata *adata, char *slider_id, int layer)
{
    char *id = str_add(slider_id, "@[:left_round]");
    float size = get_float(adata, "slider_size");

    add_button(adata, id, TYPE_CIRCLE, layer);
    resize_button(adata, id, (sfVector2f) { size, 0 });
    color_button_bg(adata, id, get_config_color(adata, "slider_background"));

    char *obj_id = str_add(id, ":object");

    add_object(adata, obj_id, (s_ref) { get_button(adata, id), TYPE_BUTTON });

    return (get_button(adata, id));
}

s_button *get_slider_right(s_appdata *adata, char *slider_id, int layer)
{
    char *id = str_add(slider_id, "@[:right_round]");
    float size = get_float(adata, "slider_size");

    add_button(adata, id, TYPE_CIRCLE, layer);
    resize_button(adata, id, (sfVector2f) { size, 0 });
    color_button_bg(adata, id, get_config_color(adata, "slider_background"));

    char *obj_id = str_add(id, ":object");

    add_object(adata, obj_id, (s_ref) { get_button(adata, id), TYPE_BUTTON });

    return (get_button(adata, id));
}

s_button *get_slider_middle(s_appdata *adata, char *slider_id, int layer)
{
    char *id = str_add(slider_id, "@[:middle_rect]");
    float size = get_float(adata, "slider_size");
    float length = get_float(adata, "slider_length");

    add_button(adata, id, TYPE_RECT, layer);
    resize_button(adata, id, (sfVector2f) { length, size * 2 });
    color_button_bg(adata, id, get_config_color(adata, "slider_background"));

    char *obj_id = str_add(id, ":object");

    add_object(adata, obj_id, (s_ref) { get_button(adata, id), TYPE_BUTTON });

    return (get_button(adata, id));
}

s_circle *get_slider_hover_left(s_appdata *adata, char *slider_id, int layer)
{
    char *id = str_add(slider_id, "@[:left_hover]");
    float size = get_float(adata, "slider_size");

    add_circle(adata, id, layer + 1);
    resize_circle(adata, id, size);
    color_circle(adata, id, get_config_color(adata, "slider_filled"));

    return (get_circle(adata, id));
}
