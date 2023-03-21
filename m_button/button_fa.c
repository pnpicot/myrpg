/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Button module
*/

#include "../include/main.h"

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
