/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Elements utilities module
*/

#include "include/main.h"

s_ref *get_ref(s_appdata *adata, void *ref, int type)
{
    s_ref *new_ref = malloc(sizeof(s_ref));

    if (new_ref == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
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
            s_rect *rect = (s_rect *) ref;
            return (rect->layer);
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            return (circle->layer);
        case TYPE_SPRITE:
            s_sprite *sprite = (s_sprite *) ref;
            return (sprite->layer);
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            return (text->layer);
        case TYPE_VERTEX:
            s_vertex *vertex = (s_vertex *) ref;
            return (vertex->layer);
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            return (button->text->layer);
    }
}

void delete_element(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            delete_rect(adata, rect->id);
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            delete_circle(adata, circle->id);
            break;
        case TYPE_SPRITE:
            s_sprite *sprite = (s_sprite *) ref;
            delete_sprite(adata, sprite->id);
            break;
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            delete_text(adata, text->id);
            break;
        case TYPE_VERTEX:
            s_vertex *vertex = (s_vertex *) ref;
            delete_vertex(adata, vertex->id);
            break;
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            delete_button(adata, button->id);
            break;
    }
}

void set_element_origin(s_appdata *adata, void *ref, int type, sfVector2f origin)
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
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            sfText_setOrigin(text->elem, origin);
            break;
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            set_button_origin(adata, button->id, origin);
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

void set_element_active(s_appdata *adata, void *ref, int type, sfUint8 active)
{
    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            rect->active = active;
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            circle->active = active;
            break;
        case TYPE_SPRITE:
            s_sprite *sprite = (s_sprite *) ref;
            sprite->active = active;
            break;
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            text->active = active;
            break;
        case TYPE_VERTEX:
            s_vertex *vertex = (s_vertex *) ref;
            vertex->active = active;
            break;
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            set_button_active(adata, button->id, active);
            break;
    }
}

void set_element_rtex(s_appdata *adata, void *ref, int type, char *rtex_id)
{
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            rect->rtex_id = rtex_id;
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            circle->rtex_id = rtex_id;
            break;
        case TYPE_SPRITE:
            s_sprite *sprite = (s_sprite *) ref;
            sprite->rtex_id = rtex_id;
            break;
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            text->rtex_id = rtex_id;
            break;
        case TYPE_VERTEX:
            s_vertex *vertex = (s_vertex *) ref;
            vertex->rtex_id = rtex_id;
            break;
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            set_button_rtex(adata, button->id, rtex_id);
            break;
    }
}

void resize_element(s_appdata *adata, void *ref, int type, sfVector2f size)
{
    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            sfRectangleShape_setSize(rect->elem, size);
            break;
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            sfCircleShape_setRadius(circle->elem, size.x ? size.x : size.y);
            break;
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            sfText_setCharacterSize(text->elem, size.x ? size.x : size.y);
            break;
        case TYPE_VERTEX:
            s_vertex *vertex = (s_vertex *) ref;
            sfVertexArray_resize(vertex->elem, (unsigned int) size.x ? size.x : size.y);
            break;
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            resize_button(adata, button->id, size);
            break;
    }
}

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
            set_button_out(adata, button->id, get_button_out_color(adata, button->id), thickness);
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
            set_button_out(adata, button->id, color, get_button_out_thickness(adata, button->id));
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

void translate_element(s_appdata *adata, void *ref, int type, sfVector2f pos_ch)
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
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            sfText_setPosition(text->elem, pos);
            break;
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            move_button(adata, button->id, pos);
            break;
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

sfVector2f get_element_scale(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            return (sfRectangleShape_getScale(rect->elem));
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            return (sfCircleShape_getScale(circle->elem));
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            return (sfText_getScale(text->elem));
        case TYPE_SPRITE:
            s_sprite *sprite = (s_sprite *) ref;
            return (sfSprite_getScale(sprite->elem));
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            return (get_button_scale(adata, button->id));
    }

    return ((sfVector2f) { -1, -1 });
}

float get_element_rotation(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            return (sfRectangleShape_getRotation(rect->elem));
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            return (sfCircleShape_getRotation(circle->elem));
        case TYPE_SPRITE:
            s_sprite *sprite = (s_sprite *) ref;
            return (sfSprite_getRotation(sprite->elem));
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            return (sfText_getRotation(text->elem));
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            return (get_button_rotation(adata, button->id));
    }

    return (-1);
}

float get_element_out_thickness(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            return (sfRectangleShape_getOutlineThickness(rect->elem));
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            return (sfCircleShape_getOutlineThickness(circle->elem));
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            return (get_button_out_thickness(adata, button->id));
    }

    return (-1);
}

sfColor get_element_out_color(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            return (sfRectangleShape_getOutlineColor(rect->elem));
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            return (sfCircleShape_getOutlineColor(circle->elem));
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            return (get_button_out_color(adata, button->id));
    }

    return (sfBlack);
}

sfColor get_element_fg(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            return (sfText_getColor(text->elem));
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            return (sfText_getColor(button->text->elem));
    }

    return (sfBlack);
}

sfUint8 get_element_active(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            return (rect->active);
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            return (circle->active);
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            return (text->active);
        case TYPE_SPRITE:
            s_sprite *sprite = (s_sprite *) ref;
            return (sprite->active);
        case TYPE_VERTEX:
            s_vertex *vertex = (s_vertex *) ref;
            return (vertex->active);
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            return (button->text->active);
    }

    return (1);
}

sfColor get_element_bg(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            return (sfRectangleShape_getFillColor(rect->elem));
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            return (sfCircleShape_getFillColor(circle->elem));
        case TYPE_SPRITE:
            s_sprite *sprite = (s_sprite *) ref;
            return (sfSprite_getColor(sprite->elem));
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            return (sfText_getColor(text->elem));
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            return (get_button_color(adata, button->id));
    }

    return (sfBlack);
}

sfVector2f get_element_pos(s_appdata *adata, void *ref, int type)
{
    switch (type) {
        case TYPE_RECT:
            s_rect *rect = (s_rect *) ref;
            return (sfRectangleShape_getPosition(rect->elem));
        case TYPE_CIRCLE:
            s_circle *circle = (s_circle *) ref;
            return (sfCircleShape_getPosition(circle->elem));
        case TYPE_SPRITE:
            s_sprite *sprite = (s_sprite *) ref;
            return (sfSprite_getPosition(sprite->elem));
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            return (sfText_getPosition(text->elem));
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            return (get_button_pos(adata, button->id));
    }

    return ((sfVector2f) { -1, -1 });
}

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
        case TYPE_TEXT:
            s_text *text = (s_text *) ref;
            sfFloatRect text_bounds = sfText_getGlobalBounds(text->elem);
            text_bounds.height += sfText_getCharacterSize(text->elem) / 2;
            return (text_bounds);
        case TYPE_VERTEX:
            s_vertex *vertex = (s_vertex *) ref;
            return (sfVertexArray_getBounds(vertex->elem));
        case TYPE_BUTTON:
            s_button *button = (s_button *) ref;
            return (get_button_bounds(adata, button->id));
    }

    return ((sfFloatRect) { -1, -1, -1, -1 });
}
