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
            s_rect *rect = (s_rect *) ref;
            return (sfRectangleShape_getGlobalBounds(rect->elem));
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            return (sfCircleShape_getGlobalBounds(circle->elem));
        case TYPE_SPRITE:
            s_sprite *sprite = (s_sprite *) ref;
            return (sfSprite_getGlobalBounds(sprite->elem));
        default:
            return (get_element_bounds_next(adata, ref, type));
    }
    return ((sfFloatRect) { -1, -1, -1, -1 });
}
