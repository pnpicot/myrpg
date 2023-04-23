/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Slider module
*/

#include "../include/main.h"

s_vertex *get_slider_triangle(s_appdata *adata, char *slider_id, int layer)
{
    char *id = str_add(slider_id, "@[:triangle]");

    add_vertex(adata, id, layer);
    resize_vertex(adata, id, 3);
    set_vertex_type(adata, id, sfTriangles);
    color_vertex_all(adata, id, get_config_color(adata, "slider_ind"));
    set_vertex_active(adata, id, 0);

    return (get_vertex(adata, id));
}

void slider_check_released(s_appdata *adata)
{
    if (adata->last_slider != NULL) {
        s_slider *slider = (s_slider *) adata->last_slider;

        set_rect_active(adata, slider->indicator_rect->id, 0);
        set_text_active(adata, slider->indicator_text->id, 0);
        set_vertex_active(adata, slider->indicator_triangle->id, 0);

        adata->last_slider = NULL;
    }
}

void slider_update_change(s_appdata *adata)
{
    if (adata->last_slider == NULL) return;

    s_slider *slider = (s_slider *) adata->last_slider;
    sfVector2f mouse = get_mouse(adata);
    sfVector2f left = get_button_pos(adata, slider->left_round->id);
    float size = get_float(adata, "slider_size");
    float length = get_float(adata, "slider_length");
    float shift = force_range(mouse.x - (left.x + size), 0, length);
    float in_range = (shift / length) * (slider->max - slider->min);

    slider->current = in_range;

    if (slider->current != slider->last && slider->on_change != NULL)
        (*slider->on_change)(adata, NULL);

    update_slider(adata, slider);
}

void slider_change(s_appdata *adata, char *id)
{
    s_slider *slider = get_slider(adata, id);

    if (slider == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    adata->last_slider = slider;

    set_rect_active(adata, slider->indicator_rect->id, 1);
    set_text_active(adata, slider->indicator_text->id, 1);
    set_vertex_active(adata, slider->indicator_triangle->id, 1);
}

void set_slider_onchange(s_appdata *adata, char *id, \
void (*on_change)(s_appdata *adata, s_ref *ref))
{
    s_slider *slider = get_slider(adata, id);

    if (slider == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }
    char *node_obj = str_add(slider->node->id, ":object");
    char *left_obj = str_add(slider->left_round->id, ":object");
    char *middle_obj = str_add(slider->middle_rect->id, ":object");
    char *right_obj = str_add(slider->right_round->id, ":object");
    set_object_onpressed(adata, node_obj, on_change);
    set_object_onpressed(adata, left_obj, on_change);
    set_object_onpressed(adata, middle_obj, on_change);
    set_object_onpressed(adata, right_obj, on_change);
    free(node_obj);
    free(left_obj);
    free(middle_obj);
    free(right_obj);
    slider->on_change = on_change;
}
