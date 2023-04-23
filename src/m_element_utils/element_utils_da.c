/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Element utilities module
*/

#include "main.h"

void translate_element_next(s_appdata *adata, void *ref, \
int type, sfVector2f pos_ch)
{
    switch (type) {
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            translate_text(adata, text->id, pos_ch);
            break;
        case TYPE_VERTEX:
            s_vertex *vertex = (s_vertex *) ref;
            translate_vertex_all(adata, vertex->id, pos_ch);
            break;
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            translate_button(adata, button->id, pos_ch);
            break;
        case TYPE_BAR:
            s_bar *bar = (s_bar *) ref;
            translate_bar(adata, bar->id, pos_ch);
            break;
    }
}

void translate_element(s_appdata *adata, void *ref, int type, \
sfVector2f pos_ch)
{
    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            translate_rect(adata, rect->id, pos_ch);
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            translate_circle(adata, circle->id, pos_ch);
            break;
        case TYPE_SPRITE:
            s_sprite *sprite = (s_sprite *) ref;
            translate_sprite(adata, sprite->id, pos_ch);
            break;
        default:
            translate_element_next(adata, ref, type, pos_ch);
    }
}

void move_element_next(s_appdata *adata, void *ref, int type, sfVector2f pos)
{
    switch (type) {
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            sfText_setPosition(text->elem, pos);
            break;
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            move_button(adata, button->id, pos);
            break;
        case TYPE_BAR:
            s_bar *bar = (s_bar *) ref;
            move_bar(adata, bar->id, pos);
            break;
    }
}

void move_element(s_appdata *adata, void *ref, int type, sfVector2f pos)
{
    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            sfRectangleShape_setPosition(rect->elem, pos);
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            sfCircleShape_setPosition(circle->elem, pos);
            break;
        case TYPE_SPRITE:
            s_sprite *sprite = (s_sprite *) ref;
            sfSprite_setPosition(sprite->elem, pos);
            break;
        default:
            move_element_next(adata, ref, type, pos);
    }
}

sfVector2f get_element_origin(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            return (sfRectangleShape_getOrigin(rect->elem));
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            return (sfCircleShape_getOrigin(circle->elem));
        case TYPE_SPRITE:
            s_sprite *sprite = (s_sprite *) ref;
            return (sfSprite_getOrigin(sprite->elem));
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            return (sfText_getOrigin(text->elem));
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            return (get_button_origin(adata, button->id));
    }
    return ((sfVector2f) { -1, -1 });
}
