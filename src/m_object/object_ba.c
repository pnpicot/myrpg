/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Object module
*/

#include "../include/main.h"

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

void add_object_next(s_appdata *adata, char *id, \
s_ref ref, s_object *new_object)
{
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

void add_object(s_appdata *adata, char *id, s_ref ref)
{
    s_object *object = get_object(adata, id);
    if (object != NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "already_exists"));
        return;
    }
    s_object *new_object = malloc(sizeof(s_object));
    if (new_object == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return;
    }
    add_object_next(adata, id, ref, new_object);
}

void delete_object(s_appdata *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
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
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    object->pressed_bg = color;
    object->flags |= obj_pressed;
}
