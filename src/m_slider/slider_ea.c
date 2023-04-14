/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Slider module
*/

#include "../include/main.h"

void update_slider_vertex(s_appdata *adata, s_slider *slider, \
sfVector2f text_pos, sfFloatRect text_bounds)
{
    float ind_padding = get_float(adata, "slider_ind_padding");
    float t_size = get_float(adata, "slider_triangle_size");
    sfVector2f triangle_left_pos;
    triangle_left_pos.x = text_pos.x - t_size + 2.0f;
    triangle_left_pos.y = text_pos.y + (text_bounds.height / 2);
    triangle_left_pos.y += (ind_padding * 2) - 1.0f;
    sfVector2f triangle_right_pos;
    triangle_right_pos.x = text_pos.x + t_size + 2.0f;
    triangle_right_pos.y = text_pos.y + (text_bounds.height / 2);
    triangle_right_pos.y += (ind_padding * 2) - 1.0f;
    sfVector2f triangle_down_pos;
    triangle_down_pos.x = text_pos.x + 2.0f;
    triangle_down_pos.y = text_pos.y + (text_bounds.height / 2);
    triangle_down_pos.y += (ind_padding * 2) + t_size;
    move_vertex(adata, slider->indicator_triangle->id, 0, triangle_left_pos);
    move_vertex(adata, slider->indicator_triangle->id, 2, triangle_right_pos);
    move_vertex(adata, slider->indicator_triangle->id, 1, triangle_down_pos);
}

void update_slider_rect(s_appdata *adata, s_slider *slider, \
sfFloatRect text_bounds, sfVector2f text_pos)
{
    sfVector2f text_origin = get_text_origin(adata, slider->indicator_text->id);
    float ind_padding = get_float(adata, "slider_ind_padding");
    float xpad = get_float(adata, "slider_ind_xpad");
    sfVector2f ind_size;
    ind_size.x = text_bounds.width + (ind_padding * 2) + (xpad * 2);
    ind_size.y = text_bounds.height + (ind_padding * 2);
    sfVector2f ind_pos;
    ind_pos.x = text_pos.x - text_origin.x - ind_padding - xpad + 1.0f;
    ind_pos.y = text_pos.y - text_origin.y - ind_padding + 4.0f;
    resize_rect(adata, slider->indicator_rect->id, ind_size);
    move_rect(adata, slider->indicator_rect->id, ind_pos);
    update_slider_vertex(adata, slider, text_pos, text_bounds);
}

void update_slider_text(s_appdata *adata, s_slider *slider, \
sfVector2f node_pos)
{
    char *val = nbr_to_str(slider->current + slider->min);
    edit_text(adata, slider->indicator_text->id, val);
    free(val);
    sfFloatRect tx_bounds = get_text_bounds(adata, slider->indicator_text->id);
    sfVector2f text_origin;
    text_origin.x = tx_bounds.width / 2;
    text_origin.y = tx_bounds.height / 2;
    set_text_origin(adata, slider->indicator_text->id, text_origin);
    float node_size = get_float(adata, "slider_node_size");
    sfVector2f text_pos;
    text_pos.x = node_pos.x - 2.0f;
    text_pos.y = node_pos.y - node_size - (tx_bounds.height / 2) - 20.0f;
    move_text(adata, slider->indicator_text->id, text_pos);
    update_slider_rect(adata, slider, tx_bounds, text_pos);
}

void update_slider_node(s_appdata *adata, s_slider *slider, \
sfVector2f left_pos)
{
    float size = get_float(adata, "slider_size");
    float length = get_float(adata, "slider_length");
    float perc = (float) slider->current;
    perc /= (float) slider->max - (float) slider->min;
    sfVector2f right_pos;
    right_pos.x = left_pos.x + length;
    right_pos.y = left_pos.y;
    move_button(adata, slider->right_round->id, right_pos);
    sfVector2f right_hover_pos;
    right_hover_pos.x = left_pos.x + (length * perc);
    right_hover_pos.y = left_pos.y;
    move_circle(adata, slider->right_hover->id, right_hover_pos);
    sfVector2f node_pos;
    node_pos.x = right_hover_pos.x + size;
    node_pos.y = left_pos.y + size;
    move_circle(adata, slider->node->id, node_pos);
    update_slider_text(adata, slider, node_pos);
}

void update_slider(s_appdata *adata, s_slider *slider)
{
    sfFloatRect left_bounds = get_button_bounds(adata, slider->left_round->id);
    sfVector2f left_pos = { left_bounds.left, left_bounds.top };
    sfFloatRect rect_bounds = get_button_bounds(adata, slider->middle_rect->id);
    float size = get_float(adata, "slider_size");
    float length = get_float(adata, "slider_length");
    float perc = (float) slider->current;
    sfVector2f rect_pos;
    perc /= (float) slider->max - (float) slider->min;
    move_circle(adata, slider->left_hover->id, left_pos);
    rect_pos.x = left_pos.x + size;
    rect_pos.y = left_pos.y;
    move_button(adata, slider->middle_rect->id, rect_pos);
    sfVector2f middle_hover_size;
    middle_hover_size.x = length * perc;
    middle_hover_size.y = size * 2;
    move_rect(adata, slider->middle_hover->id, rect_pos);
    resize_rect(adata, slider->middle_hover->id, middle_hover_size);
    update_slider_node(adata, slider, left_pos);
}
