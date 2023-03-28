/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Object module
*/

#include "../include/main.h"

void disable_object_onpressed(s_appdata *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    object->flags &= ~obj_onpressed;
}

void disable_object_onclick(s_appdata *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    object->flags &= ~obj_onclick;
}

void disable_object_onhover(s_appdata *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    object->flags &= ~obj_onhover;
}

void enable_object_hover_color(s_appdata *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    object->flags |= obj_hover;
}

void enable_object_pressed_color(s_appdata *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    object->flags |= obj_pressed;
}