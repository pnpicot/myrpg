/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Button module
*/

#include "../include/main.h"

void update_button(s_appdata *adata, s_button *button)
{
    sfVector2f scale = sfText_getScale(button->text->elem);
    s_ref *ref = button->elem;
    sfFloatRect rect_bounds = get_element_bounds(adata, ref->ref, ref->type);
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
