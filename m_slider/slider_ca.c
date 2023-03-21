/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Slider module
*/

#include "../include/main.h"

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
    sfColor hover_color = get_config_color(adata, "slider_node_hover");
    sfColor pressed_color = get_config_color(adata, "slider_node_pressed");

    add_object(adata, obj_id, (s_ref) { get_circle(adata, id), TYPE_CIRCLE });
    set_object_hover_bg(adata, obj_id, hover_color);
    set_object_pressed_bg(adata, obj_id, pressed_color);

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
