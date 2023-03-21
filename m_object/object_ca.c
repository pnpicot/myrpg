/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Object module
*/

#include "../include/main.h"

void set_object_pressed_fg(s_appdata *adata, char *id, sfColor color)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    object->pressed_fg = color;
    object->flags |= obj_pressed;
}

void set_object_pressed_out(s_appdata *adata, char *id, sfColor color)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    object->pressed_out = color;
    object->flags |= obj_pressed;
}

void set_object_hover_bg(s_appdata *adata, char *id, sfColor color)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    object->hover_bg = color;
    object->flags |= obj_hover;
}

void set_object_hover_fg(s_appdata *adata, char *id, sfColor color)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    object->hover_fg = color;
    object->flags |= obj_hover;
}

void set_object_hover_out(s_appdata *adata, char *id, sfColor color)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    object->hover_out = color;
    object->flags |= obj_hover;
}
