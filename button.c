/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Button module
*/

#include "include/main.h"

s_button *get_button(s_appdata *adata, char *id)
{
    linked_node *buttons = adata->lists->buttons;

    while (buttons != NULL && buttons->data != NULL) {
        s_button *cur = (s_button *) buttons->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        buttons = buttons->next;
    }

    return (NULL);
}

void add_button(s_appdata *adata, char *id, int type, int layer)
{
    s_button *button = get_button(adata, id);

    if (button != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    s_button *new_button = malloc(sizeof(s_button));

    if (new_button == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    new_button->id = id;
    
    char *text_id = str_add(id, "@[:text]");

    add_text(adata, text_id, layer);

    new_button->text = get_text(adata, text_id);

    switch (type) {
        case TYPE_RECT:
            char *rect_id = str_add(id, "@[:rect]");
            add_rect(adata, rect_id, layer);
            new_button->elem = get_ref(adata, get_rect(adata, rect_id), TYPE_RECT);
            break;
        case TYPE_CIRCLE:
            char *circle_id = str_add(id, "@[:circle]");
            add_circle(adata, circle_id, layer);
            new_button->elem = get_ref(adata, get_circle(adata, circle_id), TYPE_CIRCLE);
            break;
        case TYPE_SPRITE:
            char *sprite_id = str_add(id, "@[:sprite]");
            add_sprite(adata, sprite_id, layer);
            new_button->elem = get_ref(adata, get_sprite(adata, sprite_id), TYPE_SPRITE);
            break;
        case TYPE_TEXT:
            char *text_id = str_add(id, "@[:text_sub]");
            add_text(adata, text_id, layer);
            new_button->elem = get_ref(adata, get_text(adata, text_id), TYPE_TEXT);
            break;
        case TYPE_VERTEX:
            char *vertex_id = str_add(id, "@[:vertex]");
            add_vertex(adata, vertex_id, layer);
            new_button->elem = get_ref(adata, get_vertex(adata, vertex_id), TYPE_VERTEX);
            break;
    }

    linked_add(adata->lists->buttons, new_button);
}

void delete_button(s_appdata *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *buttons = adata->lists->buttons;
    int ite = 0;

    while (buttons != NULL && buttons->data != NULL) {
        s_button *cur = (s_button *) buttons->data;

        if (!my_strcmp(cur->id, id)) {
            delete_element(adata, cur->elem->ref, cur->elem->type);
            delete_text(adata, cur->text->id);
            break;
        }

        ite++;
        buttons = buttons->next;
    }

    linked_delete(&adata->lists->buttons, ite);
}

void update_button(s_appdata *adata, s_button *button)
{
    sfVector2f scale = sfText_getScale(button->text->elem);
    sfFloatRect rect_bounds = get_element_bounds(adata, button->elem->ref, button->elem->type);
    float o_angle = sfText_getRotation(button->text->elem);

    sfText_setRotation(button->text->elem, 0);
    sfText_setScale(button->text->elem, (sfVector2f) { 1, 1 });

    sfFloatRect text_bounds = get_text_bounds(adata, button->text->id);

    sfText_setOrigin(button->text->elem,
        (sfVector2f) { text_bounds.width / 2, text_bounds.height / 2 });
    sfText_setRotation(button->text->elem, o_angle);
    sfText_setScale(button->text->elem, scale);

    sfVector2f new_text_pos;
    new_text_pos.x = rect_bounds.left + (rect_bounds.width / 2);
    new_text_pos.y = rect_bounds.top + (rect_bounds.height / 2);

    sfText_setPosition(button->text->elem, new_text_pos);
}

void resize_button(s_appdata *adata, char *id, sfVector2f size)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    resize_element(adata, button->elem->ref, button->elem->type, size);
    update_button(adata, button);
}

void move_button(s_appdata *adata, char *id, sfVector2f pos)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    move_element(adata, button->elem->ref, button->elem->type, pos);
    update_button(adata, button);
}

void edit_button(s_appdata *adata, char *id, char *str)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    edit_text(adata, button->text->id, str);
    update_button(adata, button);
}

void color_button_bg(s_appdata *adata, char *id, sfColor color)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    color_element(adata, button->elem->ref, button->elem->type, color);
}

void set_button_out(s_appdata *adata, char *id, sfColor color, float thickness)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    color_element_out(adata, button->elem->ref, button->elem->type, color);
    resize_element_out(adata, button->elem->ref, button->elem->type, thickness);
}

void color_button_fg(s_appdata *adata, char *id, sfColor color)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfText_setColor(button->text->elem, color);
}

void scale_button(s_appdata *adata, char *id, sfVector2f factors)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    scale_element(adata, button->elem->ref, button->elem->type, factors);
    update_button(adata, button);
}

void rotate_button(s_appdata *adata, char *id, float angle)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    rotate_element(adata, button->elem->ref, button->elem->type, angle);
}

void set_button_font(s_appdata *adata, char *id, sfFont *font)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfText_setFont(button->text->elem, font);
    update_button(adata, button);
}

void translate_button(s_appdata *adata, char *id, sfVector2f pos_ch)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    translate_element(adata, button->elem->ref, button->elem->type, pos_ch);
    update_button(adata, button);
}

void set_button_origin(s_appdata *adata, char *id, sfVector2f origin)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    set_element_origin(adata, button->elem->ref, button->elem->type, origin);
    update_button(adata, button);
}

void set_button_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    set_element_rtex(adata, button->elem->ref, button->elem->type, rtex_id);
    set_text_rtex(adata, button->text->id, rtex_id);
}

void set_button_active(s_appdata *adata, char *id, sfUint8 active)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    set_element_active(adata, button->elem->ref, button->elem->type, active);
    button->text->active = active;
}

sfFloatRect get_button_bounds(s_appdata *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfFloatRect) { -1, -1, -1, -1 });
    }

    sfFloatRect bg_bounds = get_element_bounds(adata, button->elem->ref, button->elem->type);
    sfFloatRect text_bounds = get_text_bounds(adata, button->text->id);
    
    if (text_bounds.left < bg_bounds.left) bg_bounds.left = text_bounds.left;
    if (text_bounds.top < bg_bounds.top) bg_bounds.top = text_bounds.top;
    
    if (text_bounds.left + text_bounds.width > bg_bounds.left + bg_bounds.width)
        bg_bounds.width += (text_bounds.left + text_bounds.width) - (bg_bounds.left + bg_bounds.width);

    if (text_bounds.top + text_bounds.height > bg_bounds.top + bg_bounds.height)
        bg_bounds.height += (text_bounds.top + text_bounds.height) - (bg_bounds.top + bg_bounds.height);

    return (bg_bounds);
}

sfVector2f get_button_pos(s_appdata *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (get_element_pos(adata, button->elem->ref, button->elem->type));
}

float get_button_rotation(s_appdata *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (-1);
    }

    return (get_element_rotation(adata, button->elem->ref, button->elem->type));
}

sfVector2f get_button_origin(s_appdata *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (get_element_origin(adata, button->elem->ref, button->elem->type));
}

sfVector2f get_button_scale(s_appdata *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (get_element_scale(adata, button->elem->ref, button->elem->type));
}

sfColor get_button_color(s_appdata *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (sfBlack);
    }

    return (get_element_bg(adata, button->elem->ref, button->elem->type));
}

sfColor get_button_out_color(s_appdata *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (sfBlack);
    }

    return (get_element_out_color(adata, button->elem->ref, button->elem->type));
}

float get_button_out_thickness(s_appdata *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (-1);
    }

    return (get_element_out_thickness(adata, button->elem->ref, button->elem->type));
}

void resize_button_text(s_appdata *adata, char *id, int font_size)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfText_setCharacterSize(button->text->elem, font_size);
}

const char *get_button_string(s_appdata *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (NULL);
    }

    return (sfText_getString(button->text->elem));
}
