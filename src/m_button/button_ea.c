/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Button module
*/

#include "../include/main.h"

void translate_button(s_appdata *adata, char *id, sfVector2f pos_ch)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    translate_element(adata, button->elem->ref, button->elem->type, pos_ch);
    update_button(adata, button);
}

void set_button_origin(s_appdata *adata, char *id, sfVector2f origin)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    set_element_origin(adata, button->elem->ref, button->elem->type, origin);
    update_button(adata, button);
}

void set_button_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    set_element_rtex(adata, button->elem->ref, button->elem->type, rtex_id);
    set_text_rtex(adata, button->text->id, rtex_id);
}

void set_button_active(s_appdata *adata, char *id, sfUint8 active)
{
    s_button *button = get_button(adata, id);

    if (button == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    set_element_active(adata, button->elem->ref, button->elem->type, active);
    button->text->active = active;
}

sfFloatRect get_button_bounds(s_appdata *adata, char *id)
{
    s_button *button = get_button(adata, id);
    if (button == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return ((sfFloatRect) { -1, -1, -1, -1 });
    }
    s_ref *ref = button->elem;
    sfFloatRect bg_bounds = get_element_bounds(adata, ref->ref, ref->type);
    sfFloatRect tx_bounds = get_text_bounds(adata, button->text->id);
    if (tx_bounds.left < bg_bounds.left) bg_bounds.left = tx_bounds.left;
    if (tx_bounds.top < bg_bounds.top) bg_bounds.top = tx_bounds.top;
    if (tx_bounds.left + tx_bounds.width > bg_bounds.left + bg_bounds.width) {
        bg_bounds.width += tx_bounds.left + tx_bounds.width;
        bg_bounds.width -= bg_bounds.left + bg_bounds.width;
    }
    if (tx_bounds.top + tx_bounds.height > bg_bounds.top + bg_bounds.height) {
        bg_bounds.height += tx_bounds.top + tx_bounds.height;
        bg_bounds.height -= bg_bounds.top + bg_bounds.height;
    }
    return (bg_bounds);
}
