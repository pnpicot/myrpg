/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Elements utilities module
*/

#include "../include/main.h"

sfUint8 get_element_active_next(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_SPRITE:
            {
            s_sprite *sprite = (s_sprite *) ref;
            return (sprite->active);
            }
        case TYPE_VERTEX:
            {
            s_vertex *vertex = (s_vertex *) ref;
            return (vertex->active);
            }
        case TYPE_BUTTON:
            {
            s_button *button = (s_button *) ref;
            return (button->text->active);
            }
    }
    return (1);
}

sfUint8 get_element_active(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            {
            s_rect *rect = (s_rect *) ref;
            return (rect->active);
            }
        case TYPE_CIRCLE:
            {
            s_circle *circle = (s_circle *) ref;
            return (circle->active);
            }
        case TYPE_TEXT:
            {
            s_text *text = (s_text *) ref;
            return (text->active);
            }
        case TYPE_BUTTON:
            {
            s_button *button = (s_button *) ref;
            return (button->text->active);
            }
        case TYPE_BAR:
            {
            s_bar *bar = (s_bar *) ref;
            return (bar->back_rect->active);
            }
        case TYPE_SLIDER:
            {
            s_slider *slider = (s_slider *) ref;
            return (slider->middle_rect->text->active);
            }
        default:
            {
            return (get_element_active_next(adata, ref, type));
            }
    }
}

sfColor get_element_bg(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            {
            s_rect *rect = (s_rect *) ref;
            return (sfRectangleShape_getFillColor(rect->elem));
            }
        case TYPE_CIRCLE:
            {
            s_circle *circle = (s_circle *) ref;
            return (sfCircleShape_getFillColor(circle->elem));
            }
        case TYPE_SPRITE:
            {
            s_sprite *sprite = (s_sprite *) ref;
            return (sfSprite_getColor(sprite->elem));
            }
        case TYPE_TEXT:
            {
            s_text *text = (s_text *) ref;
            return (sfText_getColor(text->elem));
            }
        case TYPE_BUTTON:
            {
            s_button *button = (s_button *) ref;
            return (get_button_color(adata, button->id));
            }
    }
    return (sfBlack);
}

sfVector2f get_element_pos(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            {
            s_rect *rect = (s_rect *) ref;
            return (sfRectangleShape_getPosition(rect->elem));
            }
        case TYPE_CIRCLE:
            {
            s_circle *circle = (s_circle *) ref;
            return (sfCircleShape_getPosition(circle->elem));
            }
        case TYPE_SPRITE:
            {
            s_sprite *sprite = (s_sprite *) ref;
            return (sfSprite_getPosition(sprite->elem));
            }
        case TYPE_TEXT:
            {
            s_text *text = (s_text *) ref;
            return (sfText_getPosition(text->elem));
            }
        case TYPE_BUTTON:
            {
            s_button *button = (s_button *) ref;
            return (get_button_pos(adata, button->id));
            }
    }
    return ((sfVector2f) { -1, -1 });
}

sfFloatRect get_element_bounds_next(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_TEXT:
            {
            s_text *text = (s_text *) ref;
            sfFloatRect text_bounds = sfText_getGlobalBounds(text->elem);
            text_bounds.height += sfText_getCharacterSize(text->elem) / 2;
            return (text_bounds);
            }
        case TYPE_VERTEX:
            {
            s_vertex *vertex = (s_vertex *) ref;
            return (sfVertexArray_getBounds(vertex->elem));
            }
        case TYPE_BUTTON:
            {
            s_button *button = (s_button *) ref;
            return (get_button_bounds(adata, button->id));
            }
        default:
            {
            return ((sfFloatRect) { 0, 0, 0, 0 });
            }
    }
}
