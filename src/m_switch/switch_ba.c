/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Switch module
*/

#include "../include/main.h"

s_switch *get_switch(s_appdata *adata, char *id)
{
    linked_node *switches = adata->lists->switches;

    while (switches != NULL && switches->data != NULL) {
        s_switch *cur = (s_switch *) switches->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        switches = switches->next;
    }

    return (NULL);
}

s_button *get_switch_left(s_appdata *adata, char *id, int layer)
{
    add_button(adata, id, TYPE_CIRCLE, layer);

    float size = get_float(adata, "switch_size");

    resize_button(adata, id, (sfVector2f) { size, 0 });
    color_button_bg(adata, id, get_config_color(adata, "switch_off"));

    char *obj_id = str_add(id, ":object");

    add_object(adata, obj_id, (s_ref) { get_button(adata, id), TYPE_BUTTON });

    return (get_button(adata, id));
}

s_button *get_switch_right(s_appdata *adata, char *id, int layer)
{
    add_button(adata, id, TYPE_CIRCLE, layer);

    float size = get_float(adata, "switch_size");

    resize_button(adata, id, (sfVector2f) { size, 0 });
    color_button_bg(adata, id, get_config_color(adata, "switch_off"));

    char *obj_id = str_add(id, ":object");

    add_object(adata, obj_id, (s_ref) { get_button(adata, id), TYPE_BUTTON });

    return (get_button(adata, id));
}

s_button *get_switch_middle(s_appdata *adata, char *id, int layer)
{
    float length = get_float(adata, "switch_length");
    float size = get_float(adata, "switch_size");

    add_button(adata, id, TYPE_RECT, layer);
    resize_button(adata, id, (sfVector2f) { length, size * 2 });
    color_button_bg(adata, id, get_config_color(adata, "switch_off"));

    char *obj_id = str_add(id, ":object");

    add_object(adata, obj_id, (s_ref) { get_button(adata, id), TYPE_BUTTON });

    return (get_button(adata, id));
}

s_button *get_switch_indicator(s_appdata *adata, char *id, int layer)
{
    float size = get_float(adata, "switch_size");
    float padding = get_float(adata, "switch_padding");
    sfColor idle_color = get_config_color(adata, "switch_indicator_idle");
    sfColor hover_color = get_config_color(adata, "switch_indicator_hover");
    sfColor pressed_color = get_config_color(adata, "switch_indicator_pressed");

    add_button(adata, id, TYPE_CIRCLE, layer + 1);
    resize_button(adata, id, (sfVector2f) { size - padding, 0 });
    color_button_bg(adata, id, idle_color);

    char *obj_id = str_add(id, ":object");

    add_object(adata, obj_id, (s_ref) { get_button(adata, id), TYPE_BUTTON });
    set_object_hover_bg(adata, obj_id, hover_color);
    set_object_pressed_bg(adata, obj_id, pressed_color);

    return (get_button(adata, id));
}
