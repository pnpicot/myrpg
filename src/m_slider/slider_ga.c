/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Slider module
*/

#include "../include/main.h"

int get_slider_value(s_appdata *adata, char *id)
{
    s_slider *slider = get_slider(adata, id);

    if (slider == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return (-1);
    }

    return (slider->current + slider->min);
}

void delete_slider_next(s_appdata *adata, s_slider *cur)
{
    delete_button(adata, cur->left_round->id);
    delete_button(adata, cur->right_round->id);
    delete_button(adata, cur->middle_rect->id);
    delete_circle(adata, cur->left_hover->id);
    delete_circle(adata, cur->right_hover->id);
    delete_rect(adata, cur->middle_hover->id);
    delete_circle(adata, cur->node->id);
    delete_rect(adata, cur->indicator_rect->id);
    delete_text(adata, cur->indicator_text->id);
    delete_vertex(adata, cur->indicator_triangle->id);
}

void delete_slider(s_appdata *adata, char *id)
{
    s_slider *slider = get_slider(adata, id);
    if (slider == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }
    linked_node *sliders = adata->lists->sliders;
    int ite = 0;
    while (sliders != NULL && sliders->data != NULL) {
        s_slider *cur = (s_slider *) sliders->data;
        if (!my_strcmp(cur->id, id)) {
            delete_slider_next(adata, cur);
            break;
        }
        ite++;
        sliders = sliders->next;
    }
    linked_delete(&adata->lists->sliders, ite);
}

void set_slider_min(s_appdata *adata, char *id, int min)
{
    s_slider *slider = get_slider(adata, id);

    if (slider == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    slider->min = min;

    if (slider->min >= slider->max) slider->min = slider->max - 1;

    slider->current = force_range(slider->current, slider->min, slider->max);
    update_slider(adata, slider);
}

void set_slider_max(s_appdata *adata, char *id, int max)
{
    s_slider *slider = get_slider(adata, id);

    if (slider == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    slider->max = max;

    if (slider->max <= slider->min) slider->max = slider->min + 1;

    slider->current = force_range(slider->current, slider->min, slider->max);
    update_slider(adata, slider);
}
