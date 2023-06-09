/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Element utilities module
*/

#include "main.h"

void rotate_element_next(s_appdata *adata, void *ref, int type, float angle)
{
    switch (type) {
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            sfText_setRotation(text->elem, angle);
            break;
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            rotate_button(adata, button->id, angle);
            break;
    }
}

void set_element_origin(s_appdata *adata, void *ref, \
int type, sfVector2f origin)
{
    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            sfRectangleShape_setOrigin(rect->elem, origin);
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            sfCircleShape_setOrigin(circle->elem, origin);
            break;
        case TYPE_SPRITE:
            s_sprite *sprite = (s_sprite *) ref;
            sfSprite_setOrigin(sprite->elem, origin);
            break;
        default:
            set_element_origin_next(adata, ref, type, origin);
    }
}

void scale_element_next(s_appdata *adata, void *ref, int type, \
sfVector2f factors)
{
    switch (type) {
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            sfText_setScale(text->elem, factors);
            break;
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            scale_button(adata, button->id, factors);
            break;
    }
}

void scale_element(s_appdata *adata, void *ref, int type, sfVector2f factors)
{
    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            sfRectangleShape_setScale(rect->elem, factors);
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            sfCircleShape_setScale(circle->elem, factors);
            break;
        case TYPE_SPRITE:
            s_sprite *sprite = (s_sprite *) ref;
            sfSprite_setScale(sprite->elem, factors);
            break;
        default:
            scale_element_next(adata, ref, type, factors);
    }
}

void set_element_active_final(s_appdata *adata, void *ref, \
int type, sfUint8 active)
{
    switch (type) {
        case TYPE_SLIDER:
            s_slider *slider = (s_slider *) ref;
            set_slider_active(adata, slider->id, active);
            break;
        case TYPE_EMITER:
            s_particle_src *emiter = (s_particle_src *) ref;
            emiter->active = active;
            break;
        case TYPE_BAR:
            s_bar *bar = (s_bar *) ref;
            set_bar_active(adata, bar->id, active);
            break;
    }
}
