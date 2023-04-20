/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Slider module
*/

#include "../include/main.h"

void set_slider_current(s_appdata *adata, char *id, int value)
{
    s_slider *slider = get_slider(adata, id);

    if (slider == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    slider->current = force_range(value, slider->min, slider->max);

    update_slider(adata, slider);
}

void set_slider_origin(s_appdata *adata, char *id, sfVector2f origin)
{
    s_slider *slider = get_slider(adata, id);

    if (slider == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    set_button_origin(adata, slider->left_round->id, origin);
    update_slider(adata, slider);
}

void translate_slider(s_appdata *adata, char *id, sfVector2f pos_ch)
{
    s_slider *slider = get_slider(adata, id);

    if (slider == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    translate_button(adata, slider->left_round->id, pos_ch);
    update_slider(adata, slider);
}
