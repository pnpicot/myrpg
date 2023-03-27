/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Slider module
*/

#include "../include/main.h"

void add_slider_next(s_appdata *adata, char *id, \
int layer, s_slider *new_slider)
{
    new_slider->id = id;
    new_slider->min = get_int(adata, "slider_min");
    new_slider->max = get_int(adata, "slider_max");
    new_slider->current = get_int(adata, "slider_current");
    new_slider->last = new_slider->current;
    new_slider->left_round = get_slider_left(adata, id, layer);
    new_slider->right_round = get_slider_right(adata, id, layer);
    new_slider->middle_rect = get_slider_middle(adata, id, layer);
    new_slider->left_hover = get_slider_hover_left(adata, id, layer);
    new_slider->right_hover = get_slider_hover_right(adata, id, layer);
    new_slider->middle_hover = get_slider_hover_middle(adata, id, layer);
    new_slider->node = get_slider_node(adata, id, layer);
    new_slider->indicator_text = get_slider_text(adata, id, layer);
    new_slider->indicator_rect = get_slider_rect(adata, id, layer);
    new_slider->indicator_triangle = get_slider_triangle(adata, id, layer);
    new_slider->on_change = NULL;
    update_slider(adata, new_slider);
    linked_add(adata->lists->sliders, new_slider);
}

void add_slider(s_appdata *adata, char *id, int layer)
{
    s_slider *slider = get_slider(adata, id);
    if (slider != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }
    s_slider *new_slider = malloc(sizeof(s_slider));
    if (new_slider == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }
    add_slider_next(adata, id, layer, new_slider);
}

void set_slider_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_slider *slider = get_slider(adata, id);
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (slider == NULL || rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    set_button_rtex(adata, slider->left_round->id, rtex_id);
    set_button_rtex(adata, slider->right_round->id, rtex_id);
    set_button_rtex(adata, slider->middle_rect->id, rtex_id);
    slider->left_hover->rtex_id = rtex_id;
    slider->right_hover->rtex_id = rtex_id;
    slider->middle_hover->rtex_id = rtex_id;
    slider->node->rtex_id = rtex_id;
    slider->indicator_text->rtex_id = rtex_id;
    slider->indicator_rect->rtex_id = rtex_id;
    slider->indicator_triangle->rtex_id = rtex_id;
}

void set_slider_active(s_appdata *adata, char *id, sfUint8 active)
{
    s_slider *slider = get_slider(adata, id);

    if (slider == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    set_button_active(adata, slider->left_round->id, active);
    set_button_active(adata, slider->right_round->id, active);
    set_button_active(adata, slider->right_round->id, active);
    slider->left_hover->active = active;
    slider->right_hover->active = active;
    slider->middle_hover->active = active;
    slider->node->active = active;
    slider->indicator_text->active = active;
    slider->indicator_rect->active = active;
    slider->indicator_triangle->active = active;
}

void move_slider(s_appdata *adata, char *id, sfVector2f pos)
{
    s_slider *slider = get_slider(adata, id);

    if (slider == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    move_button(adata, slider->left_round->id, pos);
    update_slider(adata, slider);
}
