/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Slider module
*/

#include "include/main.h"

s_slider *get_slider(s_appdata *adata, char *id)
{
    linked_node *sliders = adata->lists->sliders;

    while (sliders != NULL && sliders->data != NULL) {
        s_slider *cur = (s_slider *) sliders->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        sliders = sliders->next;
    }

    return (NULL);
}

s_button *get_slider_left(s_appdata *adata, char *slider_id, int layer)
{
    char *id = str_add(slider_id, "@[:left_round]");
    float size = get_float(adata, "slider_size");

    add_button(adata, id, TYPE_CIRCLE, layer);
    resize_button(adata, id, (sfVector2f) { size, 0 });
    color_button_bg(adata, id, get_config_color(adata, "slider_background"));

    char *obj_id = str_add(id, ":object");

    add_object(adata, obj_id, (s_ref) { get_button(adata, id), TYPE_BUTTON });

    return (get_button(adata, id));
}

s_button *get_slider_right(s_appdata *adata, char *slider_id, int layer)
{
    char *id = str_add(slider_id, "@[:right_round]");
    float size = get_float(adata, "slider_size");

    add_button(adata, id, TYPE_CIRCLE, layer);
    resize_button(adata, id, (sfVector2f) { size, 0 });
    color_button_bg(adata, id, get_config_color(adata, "slider_background"));

    char *obj_id = str_add(id, ":object");

    add_object(adata, obj_id, (s_ref) { get_button(adata, id), TYPE_BUTTON });

    return (get_button(adata, id));
}

s_button *get_slider_middle(s_appdata *adata, char *slider_id, int layer)
{
    char *id = str_add(slider_id, "@[:middle_rect]");
    float size = get_float(adata, "slider_size");
    float length = get_float(adata, "slider_length");

    add_button(adata, id, TYPE_RECT, layer);
    resize_button(adata, id, (sfVector2f) { length, size * 2 });
    color_button_bg(adata, id, get_config_color(adata, "slider_background"));

    char *obj_id = str_add(id, ":object");

    add_object(adata, obj_id, (s_ref) { get_button(adata, id), TYPE_BUTTON });

    return (get_button(adata, id));
}

s_circle *get_slider_hover_left(s_appdata *adata, char *slider_id, int layer)
{
    char *id = str_add(slider_id, "@[:left_hover]");
    float size = get_float(adata, "slider_size");

    add_circle(adata, id, layer + 1);
    resize_circle(adata, id, size);
    color_circle(adata, id, get_config_color(adata, "slider_filled"));

    return (get_circle(adata, id));
}

s_circle *get_slider_hover_right(s_appdata *adata, char *slider_id, int layer)
{
    char *id = str_add(slider_id, "@[:right_hover]");
    float size = get_float(adata, "slider_size");

    add_circle(adata, id, layer + 1);
    resize_circle(adata, id, size);
    color_circle(adata, id, get_config_color(adata, "slider_filled"));

    return (get_circle(adata, id));
}

s_rect *get_slider_hover_middle(s_appdata *adata, char *slider_id, int layer)
{
    char *id = str_add(slider_id, "@[:middle_hover]");
    float size = get_float(adata, "slider_size");
    float length = get_float(adata, "slider_length");

    add_rect(adata, id, layer + 1);
    resize_rect(adata, id, (sfVector2f) { length, size * 2 });
    color_rect(adata, id, get_config_color(adata, "slider_filled"));

    return (get_rect(adata, id));
}

s_circle *get_slider_node(s_appdata *adata, char *slider_id, int layer)
{
    char *id = str_add(slider_id, "@[:node]");
    float size = get_float(adata, "slider_node_size");

    add_circle(adata, id, layer + 2);
    resize_circle(adata, id, size);
    color_circle(adata, id, get_config_color(adata, "slider_node_idle"));
    set_circle_origin(adata, id, (sfVector2f) { size, size });

    char *obj_id = str_add(id, ":object");

    add_object(adata, obj_id, (s_ref) { get_circle(adata, id), TYPE_CIRCLE });
    set_object_hover_bg(adata, obj_id, get_config_color(adata, "slider_node_hover"));
    set_object_pressed_bg(adata, obj_id, get_config_color(adata, "slider_node_pressed"));

    return (get_circle(adata, id));
}

s_text *get_slider_text(s_appdata *adata, char *slider_id, int layer)
{
    char *id = str_add(slider_id, "@[:text]");
    int font_size = get_int(adata, "slider_font_size");
    char *font_id = get_str(adata, "slider_font_id");

    add_text(adata, id, layer + 1);
    resize_text(adata, id, font_size);
    set_text_font(adata, id, get_font(adata, font_id));
    color_text(adata, id, get_config_color(adata, "slider_text"));
    set_text_active(adata, id, 0);

    return (get_text(adata, id));
}

s_rect *get_slider_rect(s_appdata *adata, char *slider_id, int layer)
{
    char *id = str_add(slider_id, "@[:rect]");

    add_rect(adata, id, layer);
    color_rect(adata, id, get_config_color(adata, "slider_ind"));
    set_rect_active(adata, id, 0);

    return (get_rect(adata, id));
}

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
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    adata->last_slider = slider;

    set_rect_active(adata, slider->indicator_rect->id, 1);
    set_text_active(adata, slider->indicator_text->id, 1);
    set_vertex_active(adata, slider->indicator_triangle->id, 1);
}

void set_slider_onchange(s_appdata *adata, char *id, void (*on_change)(s_appdata *adata, s_ref *ref))
{
    s_slider *slider = get_slider(adata, id);

    if (slider == NULL) {
        my_printf(get_error(adata, "unknown_id"));
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
    slider->on_change = on_change;
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

    edit_text(adata, slider->indicator_text->id, nbr_to_str(slider->current + slider->min));

    sfFloatRect text_bounds = get_text_bounds(adata, slider->indicator_text->id);
    sfVector2f text_origin;

    text_origin.x = text_bounds.width / 2;
    text_origin.y = text_bounds.height / 2;

    set_text_origin(adata, slider->indicator_text->id, text_origin);

    float node_size = get_float(adata, "slider_node_size");

    sfVector2f text_pos;
    text_pos.x = node_pos.x - 2.0f;
    text_pos.y = node_pos.y - node_size - (text_bounds.height / 2) - 20.0f;

    move_text(adata, slider->indicator_text->id, text_pos);

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

    float t_size = get_float(adata, "slider_triangle_size");

    sfVector2f triangle_left_pos;
    triangle_left_pos.x = text_pos.x - t_size + 2.0f;
    triangle_left_pos.y = text_pos.y + (text_bounds.height / 2) + (ind_padding * 2) - 1.0f;

    sfVector2f triangle_right_pos;
    triangle_right_pos.x = text_pos.x + t_size + 2.0f;
    triangle_right_pos.y = text_pos.y + (text_bounds.height / 2) + (ind_padding * 2) - 1.0f;

    sfVector2f triangle_down_pos;
    triangle_down_pos.x = text_pos.x + 2.0f;
    triangle_down_pos.y = text_pos.y + (text_bounds.height / 2) + (ind_padding * 2) + t_size;

    move_vertex(adata, slider->indicator_triangle->id, 0, triangle_left_pos);
    move_vertex(adata, slider->indicator_triangle->id, 2, triangle_right_pos);
    move_vertex(adata, slider->indicator_triangle->id, 1, triangle_down_pos);
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

int get_slider_value(s_appdata *adata, char *id)
{
    s_slider *slider = get_slider(adata, id);

    if (slider == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (-1);
    }

    return (slider->current + slider->min);
}

void delete_slider(s_appdata *adata, char *id)
{
    s_slider *slider = get_slider(adata, id);

    if (slider == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *sliders = adata->lists->sliders;
    int ite = 0;

    while (sliders != NULL && sliders->data != NULL) {
        s_slider *cur = (s_slider *) sliders->data;

        if (!my_strcmp(cur->id, id)) {
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
        my_printf(get_error(adata, "unknown_id"));
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
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    slider->max = max;

    if (slider->max <= slider->min) slider->max = slider->min + 1;

    slider->current = force_range(slider->current, slider->min, slider->max);
    update_slider(adata, slider);
}

void set_slider_current(s_appdata *adata, char *id, int value)
{
    s_slider *slider = get_slider(adata, id);

    if (slider == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    slider->current = force_range(value, slider->min, slider->max);

    update_slider(adata, slider);
}

void set_slider_origin(s_appdata *adata, char *id, sfVector2f origin)
{
    s_slider *slider = get_slider(adata, id);

    if (slider == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    set_button_origin(adata, slider->left_round->id, origin);
    update_slider(adata, slider);
}

void translate_slider(s_appdata *adata, char *id, sfVector2f pos_ch)
{
    s_slider *slider = get_slider(adata, id);

    if (slider == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    translate_button(adata, slider->left_round->id, pos_ch);
    update_slider(adata, slider);
}
