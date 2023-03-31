/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Object module
*/

#include "../include/main.h"

int object_check_pressed_next(s_appdata *adata, int contains, \
s_ref *ref, s_object *cur)
{
    if (contains && (cur->flags & obj_pressed)) {
        color_element(adata, ref->ref, ref->type, cur->pressed_bg);
        color_element_fg(adata, ref->ref, ref->type, cur->pressed_fg);
        color_element_out(adata, ref->ref, ref->type, cur->pressed_out);
    }

    if (contains && (cur->flags & obj_onpressed))
        (*cur->on_pressed)(adata, cur->ref);

    if (contains){
        adata->last_pressed = cur;
        return (1);
    }

    return (0);
}

void object_check_pressed(s_appdata *adata)
{
    linked_node *objects = adata->lists->objects;
    while (objects != NULL && objects->data != NULL) {
        s_object *cur = (s_object *) objects->data;
        s_ref *ref = cur->ref;
        sfUint8 active = get_element_active(adata, ref->ref, ref->type);
        if (!active) {
            objects = objects->next;
            continue;
        }
        sfFloatRect obj_bounds = get_element_bounds(adata, ref->ref, ref->type);
        sfVector2f mouse = get_mouse(adata);
        int contains = sfFloatRect_contains(&obj_bounds, mouse.x, mouse.y);
        int event = object_check_pressed_next(adata, contains, ref, cur);

        if (event) break;

        objects = objects->next;
    }
}

int object_check_released(s_appdata *adata)
{
    s_object *last = (s_object *) adata->last_pressed;

    if (last == NULL) return (0);

    color_element(adata, last->ref->ref, last->ref->type, last->off_bg);
    color_element_fg(adata, last->ref->ref, last->ref->type, last->off_fg);
    color_element_out(adata, last->ref->ref, last->ref->type, last->off_out);

    if (last->flags & obj_onclick)
        (*last->on_click)(adata, last->ref);

    adata->last_pressed = NULL;
    object_check_hover(adata);

    return (1);
}

void disable_object_hover_color(s_appdata *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    object->flags &= ~obj_hover;
}

void disable_object_pressed_color(s_appdata *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    object->flags &= ~obj_pressed;
}
