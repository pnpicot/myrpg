/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Elements utilities module
*/

#include "../include/main.h"

sfFloatRect get_element_bounds(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            {
            s_rect *rect = (s_rect *) ref;
            return (sfRectangleShape_getGlobalBounds(rect->elem));
            }
        case TYPE_CIRCLE:
            {
            s_circle *circle = (s_circle *) ref;
            return (sfCircleShape_getGlobalBounds(circle->elem));
            }
        case TYPE_SPRITE:
            {
            s_sprite *sprite = (s_sprite *) ref;
            return (sfSprite_getGlobalBounds(sprite->elem));
            }
        default:
            {
            return (get_element_bounds_next(adata, ref, type));
            }
    }
    return ((sfFloatRect) { -1, -1, -1, -1 });
}

sfVector2f get_element_rel_pos(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            {
            s_rect *rect = (s_rect *) ref;
            return (rect->pos);
            }
        case TYPE_CIRCLE:
            {
            s_circle *circle = (s_circle *) ref;
            return (circle->pos);
            }
        case TYPE_TEXT:
            {
            s_text *text = (s_text *) ref;
            return (text->pos);
            }
        case TYPE_SPRITE:
            {
            s_sprite *sprite = (s_sprite *) ref;
            return (sprite->pos);
            }
        case TYPE_VERTEX:
            {
            s_vertex *vertex = (s_vertex *) ref;
            return (vertex->pos);
            }
        case TYPE_BUTTON:
            {
            s_button *button = (s_button *) ref;
            return (get_element_rel_pos(adata, button->elem->ref, button->elem->type));
            }
    }
}
