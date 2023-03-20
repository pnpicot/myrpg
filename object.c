/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Object module
*/

#include "include/main.h"

s_object *get_object(s_appdata *adata, char *id)
{
    linked_node *objects = adata->lists->objects;

    while (objects != NULL && objects->data != NULL) {
        s_object *cur = (s_object *) objects->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        objects = objects->next;
    }

    return (NULL);
}

void add_object(s_appdata *adata, char *id, s_ref ref)
{
    s_object *object = get_object(adata, id);

    if (object != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    s_object *new_object = malloc(sizeof(s_object));

    if (new_object == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    new_object->id = id;
    new_object->ref = get_ref(adata, ref.ref, ref.type);
    new_object->off_bg = get_element_bg(adata, ref.ref, ref.type);
    new_object->off_fg = get_element_fg(adata, ref.ref, ref.type);
    new_object->off_out = get_element_out_color(adata, ref.ref, ref.type);
    new_object->pressed_bg = new_object->off_bg;
    new_object->pressed_fg = new_object->off_fg;
    new_object->pressed_out = new_object->off_out;
    new_object->hover_bg = new_object->off_bg;
    new_object->hover_fg = new_object->off_fg;
    new_object->hover_out = new_object->off_out;
    new_object->flags = 0;
    new_object->on_pressed = NULL;
    new_object->on_click = NULL;
    new_object->on_hover = NULL;

    linked_add(adata->lists->objects, new_object);
}

void delete_object(s_appdata *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *objects = adata->lists->objects;
    int ite = 0;

    while (objects != NULL && objects->data != NULL) {
        s_object *cur = (s_object *) objects->data;

        if (!my_strcmp(cur->id, id)) break;

        ite++;
        objects = objects->next;
    }

    linked_delete(&adata->lists->objects, ite);
}

void set_object_pressed_bg(s_appdata *adata, char *id, sfColor color)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    object->pressed_bg = color;
    object->flags |= obj_pressed;
}

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

void set_object_onpressed(s_appdata *adata, char *id, void (*on_pressed)(s_appdata *adata, s_ref *ref))
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    object->on_pressed = on_pressed;
    object->flags |= obj_onpressed;
}

void set_object_onclick(s_appdata *adata, char *id, void (*on_click)(s_appdata *adata, s_ref *ref))
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    object->on_click = on_click;
    object->flags |= obj_onclick;
}

void set_object_onhover(s_appdata *adata, char *id, void (*on_hover)(s_appdata *adata, s_ref *ref))
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    object->on_hover = on_hover;
    object->flags |= obj_onhover;
}

void object_check_hover(s_appdata *adata)
{
    linked_node *objects = adata->lists->objects;
    s_object *last = (s_object *) adata->last_pressed;

    while (objects != NULL && objects->data != NULL) {
        s_object *cur = (s_object *) objects->data;
        sfUint8 active = get_element_active(adata, cur->ref->ref, cur->ref->type);

        if (!(cur->flags & obj_hover) || !active || (last != NULL && !my_strcmp(cur->id, last->id))) {
            objects = objects->next;
            continue;
        }

        sfFloatRect object_bounds = get_element_bounds(adata, cur->ref->ref, cur->ref->type);
        sfVector2f mouse = get_mouse(adata);
        int contains = sfFloatRect_contains(&object_bounds, mouse.x, mouse.y);

        if (contains) {
            color_element(adata, cur->ref->ref, cur->ref->type, cur->hover_bg);
            color_element_fg(adata, cur->ref->ref, cur->ref->type, cur->hover_fg);
            color_element_out(adata, cur->ref->ref, cur->ref->type, cur->hover_out);
        } else {
            color_element(adata, cur->ref->ref, cur->ref->type, cur->off_bg);
            color_element_fg(adata, cur->ref->ref, cur->ref->type, cur->off_fg);
            color_element_out(adata, cur->ref->ref, cur->ref->type, cur->off_out);
        }

        if (contains && (cur->flags & obj_onhover))
            (*cur->on_hover)(adata, cur->ref);

        objects = objects->next;
    }
}

void object_check_pressed(s_appdata *adata)
{
    linked_node *objects = adata->lists->objects;

    while (objects != NULL && objects->data != NULL) {
        s_object *cur = (s_object *) objects->data;
        sfUint8 active = get_element_active(adata, cur->ref->ref, cur->ref->type);

        if (!active) {
            objects = objects->next;
            continue;
        }

        sfFloatRect object_bounds = get_element_bounds(adata, cur->ref->ref, cur->ref->type);
        sfVector2f mouse = get_mouse(adata);
        int contains = sfFloatRect_contains(&object_bounds, mouse.x, mouse.y);

        if (contains && (cur->flags & obj_pressed)) {
            color_element(adata, cur->ref->ref, cur->ref->type, cur->pressed_bg);
            color_element_fg(adata, cur->ref->ref, cur->ref->type, cur->pressed_fg);
            color_element_out(adata, cur->ref->ref, cur->ref->type, cur->pressed_out);
        }

        if (contains && (cur->flags & obj_onpressed))
            (*cur->on_pressed)(adata, cur->ref);

        if (contains) adata->last_pressed = cur;

        objects = objects->next;
    }
}

void object_check_released(s_appdata *adata)
{
    s_object *last = (s_object *) adata->last_pressed;

    if (last == NULL) return;

    color_element(adata, last->ref->ref, last->ref->type, last->off_bg);
    color_element_fg(adata, last->ref->ref, last->ref->type, last->off_fg);
    color_element_out(adata, last->ref->ref, last->ref->type, last->off_out);

    if (last->flags & obj_onclick)
        (*last->on_click)(adata, last->ref);

    adata->last_pressed = NULL;
    object_check_hover(adata);
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

void enable_object_onpressed(s_appdata *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    object->flags |= obj_onpressed;
}

void enable_object_onclick(s_appdata *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    object->flags |= obj_onclick;
}

void enable_object_onhover(s_appdata *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    object->flags |= obj_onhover;
}
