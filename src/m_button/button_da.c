/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Button module
*/

#include "../include/main.h"

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
