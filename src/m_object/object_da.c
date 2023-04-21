/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Object module
*/

#include "../include/main.h"

void set_object_onpressed(s_appdata *adata, char *id, \
void (*on_pressed)(s_appdata *adata, s_ref *ref))
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    object->on_pressed = on_pressed;
    object->flags |= obj_onpressed;
}

void set_object_onclick(s_appdata *adata, char *id, \
void (*on_click)(s_appdata *adata, s_ref *ref))
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    object->on_click = on_click;
    object->flags |= obj_onclick;
}

void set_object_onhover(s_appdata *adata, char *id, \
void (*on_hover)(s_appdata *adata, s_ref *ref))
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    object->on_hover = on_hover;
    object->flags |= obj_onhover;
}

void object_check_hover_color(s_appdata *adata, int contains, \
s_ref *ref, s_object *cur)
{
    if (contains) {
        color_element(adata, ref->ref, ref->type, cur->hover_bg);
        color_element_fg(adata, ref->ref, ref->type, cur->hover_fg);
        color_element_out(adata, ref->ref, ref->type, cur->hover_out);
    } else {
        color_element(adata, ref->ref, ref->type, cur->off_bg);
        color_element_fg(adata, ref->ref, ref->type, cur->off_fg);
        color_element_out(adata, ref->ref, ref->type, cur->off_out);
    }
}

void object_check_hover(s_appdata *adata)
{
    linked_node *objects = adata->lists->objects;
    s_object *last = (s_object *) adata->last_pressed;
    while (objects != NULL && objects->data != NULL) {
        s_object *cur = (s_object *) objects->data;
        s_ref *ref = cur->ref;
        sfUint8 active = get_element_active(adata, ref->ref, ref->type);
        int not_last = last != NULL && !my_strcmp(cur->id, last->id);
        if (!(cur->flags & obj_hover) || !active || not_last) {
            objects = objects->next;
            continue;
        }
        sfFloatRect obj_bounds = get_element_bounds(adata, ref->ref, ref->type);
        sfVector2f mouse = get_mouse(adata);
        int contains = sfFloatRect_contains(&obj_bounds, mouse.x, mouse.y);
        object_check_hover_color(adata, contains, ref, cur);
        if (contains && (cur->flags & obj_onhover))
            (*cur->on_hover)(adata, cur->ref);
        objects = objects->next;
    }
}
