/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Elements utilities module
*/

#include "../include/main.h"

sfVector2f get_element_scale(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            {
            s_rect *rect = (s_rect *) ref;
            return (sfRectangleShape_getScale(rect->elem));
            }
        case TYPE_CIRCLE:
            {
            s_circle *circle = (s_circle *) ref;
            return (sfCircleShape_getScale(circle->elem));
            }
        case TYPE_TEXT:
            {
            s_text *text = (s_text *) ref;
            return (sfText_getScale(text->elem));
            }
        case TYPE_SPRITE:
            {
            s_sprite *sprite = (s_sprite *) ref;
            return (sfSprite_getScale(sprite->elem));
            }
        case TYPE_BUTTON:
            {
            s_button *button = (s_button *) ref;
            return (get_button_scale(adata, button->id));
            }
    }
    return ((sfVector2f) { -1, -1 });
}

float get_element_rotation(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            {
            s_rect *rect = (s_rect *) ref;
            return (sfRectangleShape_getRotation(rect->elem));
            }
        case TYPE_CIRCLE:
            {
            s_circle *circle = (s_circle *) ref;
            return (sfCircleShape_getRotation(circle->elem));
            }
        case TYPE_SPRITE:
            {
            s_sprite *sprite = (s_sprite *) ref;
            return (sfSprite_getRotation(sprite->elem));
            }
        case TYPE_TEXT:
            {
            s_text *text = (s_text *) ref;
            return (sfText_getRotation(text->elem));
            }
        case TYPE_BUTTON:
            {
            s_button *button = (s_button *) ref;
            return (get_button_rotation(adata, button->id));
            }
    }
    return (-1);
}

float get_element_out_thickness(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            {
            s_rect *rect = (s_rect *) ref;
            return (sfRectangleShape_getOutlineThickness(rect->elem));
            }
        case TYPE_CIRCLE:
            {
            s_circle *circle = (s_circle *) ref;
            return (sfCircleShape_getOutlineThickness(circle->elem));
            }
        case TYPE_BUTTON:
            {
            s_button *button = (s_button *) ref;
            return (get_button_out_thickness(adata, button->id));
            }
    }
    return (-1);
}

sfColor get_element_out_color(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            {
            s_rect *rect = (s_rect *) ref;
            return (sfRectangleShape_getOutlineColor(rect->elem));
            }
        case TYPE_CIRCLE:
            {
            s_circle *circle = (s_circle *) ref;
            return (sfCircleShape_getOutlineColor(circle->elem));
            }
        case TYPE_BUTTON:
            {
            s_button *button = (s_button *) ref;
            return (get_button_out_color(adata, button->id));
            }
    }
    return (sfBlack);
}

sfColor get_element_fg(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_TEXT:
            {
            s_text *text = (s_text *) ref;
            return (sfText_getColor(text->elem));
            }
        case TYPE_BUTTON:
            {
            s_button *button = (s_button *) ref;
            return (sfText_getColor(button->text->elem));
            }
    }
    return (sfBlack);
}
