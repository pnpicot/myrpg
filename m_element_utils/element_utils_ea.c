/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Elements utilities module
*/

#include "../include/main.h"

void rotate_element(s_appdata *adata, void *ref, int type, float angle)
{
    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            sfRectangleShape_setRotation(rect->elem, angle);
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            sfCircleShape_setRotation(circle->elem, angle);
            break;
        case TYPE_SPRITE:
            s_sprite *sprite = (s_sprite *) ref;
            sfSprite_setRotation(sprite->elem, angle);
            break;
        default:
            rotate_element_next(adata, ref, type, angle);
    }
}

void resize_element_out(s_appdata *adata, void *ref, int type, float thickness)
{
    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            sfRectangleShape_setOutlineThickness(rect->elem, thickness);
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            sfCircleShape_setOutlineThickness(circle->elem, thickness);
            break;
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            sfColor color = get_button_out_color(adata, button->id);
            set_button_out(adata, button->id, color, thickness);
            break;
    }
}

void color_element_out(s_appdata *adata, void *ref, int type, sfColor color)
{
    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            sfRectangleShape_setOutlineColor(rect->elem, color);
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            sfCircleShape_setOutlineColor(circle->elem, color);
            break;
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            float thickness = get_button_out_thickness(adata, button->id);
            set_button_out(adata, button->id, color, thickness);
            break;
    }
}

void color_element_fg(s_appdata *adata, void *ref, int type, sfColor color)
{
    switch (type) {
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            sfText_setColor(text->elem, color);
            break;
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            sfText_setColor(button->text->elem, color);
            break;
    }
}

void color_element(s_appdata *adata, void *ref, int type, sfColor color)
{
    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            sfRectangleShape_setFillColor(rect->elem, color);
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            sfCircleShape_setFillColor(circle->elem, color);
            break;
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            sfText_setColor(text->elem, color);
            break;
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            color_button_bg(adata, button->id, color);
            break;
    }
}
