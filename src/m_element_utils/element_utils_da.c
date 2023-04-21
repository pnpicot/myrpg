/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Elements utilities module
*/

#include "../include/main.h"

void set_element_rtex_next(s_appdata *adata, void *ref, \
int type, char *rtex_id)
{
    switch (type) {
        case TYPE_SPRITE:
            {
            s_sprite *sprite = (s_sprite *) ref;
            set_sprite_rtex(adata, sprite->id, rtex_id);
            break;
            }
        case TYPE_TEXT:
            {
            s_text *text = (s_text *) ref;
            set_text_rtex(adata, text->id, rtex_id);
            break;
            }
        case TYPE_VERTEX:
            {
            s_vertex *vertex = (s_vertex *) ref;
            set_vertex_rtex(adata, vertex->id, rtex_id);
            break;
            }
        case TYPE_BUTTON:
            {
            s_button *button = (s_button *) ref;
            set_button_rtex(adata, button->id, rtex_id);
            break;
            }
        case TYPE_BAR:
            {
            s_bar *bar = (s_bar *) ref;
            set_bar_rtex(adata, bar->id, rtex_id);
            break;
            }
    }
}

void set_element_rtex(s_appdata *adata, void *ref, int type, char *rtex_id)
{
    s_rtex *rtex = get_rtex(adata, rtex_id);
    if (rtex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }
    switch (type) {
        case TYPE_RECT:
            {
            s_rect *rect = (s_rect *) ref;
            set_rect_rtex(adata, rect->id, rtex_id);
            break;
            }
        case TYPE_CIRCLE:
            {
            s_circle *circle = (s_circle *) ref;
            set_circle_rtex(adata, circle->id, rtex_id);
            break;
            }
        default:
            {
            set_element_rtex_next(adata, ref, type, rtex_id);
            }
    }
}

void resize_element_next(s_appdata *adata, void *ref, \
int type, sfVector2f size)
{
    switch (type) {
        case TYPE_VERTEX:
            {
            s_vertex *vertex = (s_vertex *) ref;
            sfVertexArray_resize(vertex->elem, size.x ? size.x : size.y);
            break;
            }
        case TYPE_BUTTON:
            {
            s_button *button = (s_button *) ref;
            resize_button(adata, button->id, size);
            break;
            }
    }
}

void resize_element(s_appdata *adata, void *ref, int type, sfVector2f size)
{
    switch (type) {
        case TYPE_RECT:
            {
            s_rect *rect = (s_rect *) ref;
            sfRectangleShape_setSize(rect->elem, size);
            break;
            }
        case TYPE_CIRCLE:
            {
            s_circle *circle = (s_circle *) ref;
            sfCircleShape_setRadius(circle->elem, size.x ? size.x : size.y);
            break;
            }
        case TYPE_TEXT:
            {
            s_text *text = (s_text *) ref;
            sfText_setCharacterSize(text->elem, size.x ? size.x : size.y);
            break;
            }
        default:
            {
            resize_element_next(adata, ref, type, size);
            }
    }
}

void rotate_element_next(s_appdata *adata, void *ref, int type, float angle)
{
    switch (type) {
        case TYPE_TEXT:
            {
            s_text *text = (s_text *) ref;
            sfText_setRotation(text->elem, angle);
            break;
            }
        case TYPE_BUTTON:
            {
            s_button *button = (s_button *) ref;
            rotate_button(adata, button->id, angle);
            break;
            }
    }
}
