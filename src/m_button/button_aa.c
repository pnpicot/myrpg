/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Button module
*/

#include "../include/main.h"

sfColor get_button_out_color(s_appdata *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return (sfBlack);
    }

    s_ref *ref = button->elem;
    return (get_element_out_color(adata, ref->ref, ref->type));
}

float get_button_out_thickness(s_appdata *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return (-1);
    }

    s_ref *ref = button->elem;
    return (get_element_out_thickness(adata, ref->ref, ref->type));
}

void resize_button_text(s_appdata *adata, char *id, int font_size)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    sfText_setCharacterSize(button->text->elem, font_size);
}

const char *get_button_string(s_appdata *adata, char *id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return (NULL);
    }

    return (sfText_getString(button->text->elem));
}
