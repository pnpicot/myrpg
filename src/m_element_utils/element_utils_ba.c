/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Elements utilities module
*/

#include "../include/main.h"

s_ref *get_ref(s_appdata *adata, void *ref, int type)
{
    s_ref *new_ref = malloc(sizeof(s_ref));

    if (new_ref == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return (NULL);
    }

    new_ref->ref = ref;
    new_ref->type = type;

    return (new_ref);
}

int get_element_layer(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            {
            s_rect *rect = (s_rect *) ref;
            return (rect->layer);
            }
        case TYPE_CIRCLE:
            {
            s_circle *circle = (s_circle *) ref;
            return (circle->layer);
            }
        case TYPE_SPRITE:
            {
            s_sprite *sprite = (s_sprite *) ref;
            return (sprite->layer);
            }
        case TYPE_TEXT:
            {
            s_text *text = (s_text *) ref;
            return (text->layer);
            }
        case TYPE_VERTEX:
            {
            s_vertex *vertex = (s_vertex *) ref;
            return (vertex->layer);
            }
        case TYPE_BUTTON:
            {
            s_button *button = (s_button *) ref;
            return (button->text->layer);
            }
    }
}

void delete_element_next(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_TEXT:
            {
            s_text *text = (s_text *) ref;
            delete_text(adata, text->id);
            break;
            }
        case TYPE_VERTEX:
            {
            s_vertex *vertex = (s_vertex *) ref;
            delete_vertex(adata, vertex->id);
            break;
            }
        case TYPE_BUTTON:
            {
            s_button *button = (s_button *) ref;
            delete_button(adata, button->id);
            break;
            }
    }
}

void delete_element(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            {
            s_rect *rect = (s_rect *) ref;
            delete_rect(adata, rect->id);
            break;
            }
        case TYPE_CIRCLE:
            {
            s_circle *circle = (s_circle *) ref;
            delete_circle(adata, circle->id);
            break;
            }
        case TYPE_SPRITE:
            {
            s_sprite *sprite = (s_sprite *) ref;
            delete_sprite(adata, sprite->id);
            break;
            }
        default:
            {
            delete_element_next(adata, ref, type);
            }
    }
}

void set_element_origin_next(s_appdata *adata, void *ref, \
int type, sfVector2f origin)
{
    switch (type) {
        case TYPE_TEXT:
            {
            s_text *text = (s_text *) ref;
            sfText_setOrigin(text->elem, origin);
            break;
            }
        case TYPE_BUTTON:
            {
            s_button *button = (s_button *) ref;
            set_button_origin(adata, button->id, origin);
            break;
            }
    }
}
