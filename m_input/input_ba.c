/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Input module
*/

#include "../include/main.h"

s_input *get_input(s_appdata *adata, char *id)
{
    linked_node *inputs = adata->lists->inputs;

    while (inputs != NULL && inputs->data != NULL) {
        s_input *cur = (s_input *) inputs->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        inputs = inputs->next;
    }

    return (NULL);
}

void trigger_input(s_appdata *adata, s_ref *ref)
{
    s_input *input;
    s_rect *rect = (s_rect *) ref->ref;
    linked_node *inputs = adata->lists->inputs;
    while (inputs != NULL && inputs->data != NULL) {
        s_input *cur = (s_input *) inputs->data;
        if (!my_strcmp(cur->input_rect->id, rect->id)) {
            input = cur;
            break;
        }
        inputs = inputs->next;
    }
    const char *text = get_text_str(adata, input->input_text->id);
    sfClock_restart(input->caret_clock);
    if (!input->contains) edit_text(adata, input->input_text->id, "");
    sfColor text_color = get_config_color(adata, "input_foreground");
    color_text(adata, input->input_text->id, text_color);
    update_input(adata, input);
    adata->last_input = input;
}

s_rect *get_input_rect(s_appdata *adata, char *input_id, int layer)
{
    char *id = str_add(input_id, "@[:rect]");
    float width = get_float(adata, "input_width");
    float height = get_float(adata, "input_height");

    add_rect(adata, id, layer);
    resize_rect(adata, id, (sfVector2f) { width, height });
    color_rect(adata, id, get_config_color(adata, "input_background"));

    char *obj_id = str_add(id, ":object");

    add_object(adata, id, (s_ref) { get_rect(adata, id), TYPE_RECT });

    sfColor hover_color = get_config_color(adata, "input_background_hover");
    sfColor pressed_color = get_config_color(adata, "input_background_pressed");

    set_object_hover_bg(adata, id, hover_color);
    set_object_pressed_bg(adata, id, pressed_color);
    set_object_onclick(adata, id, &trigger_input);

    return (get_rect(adata, id));
}

s_text *get_input_text(s_appdata *adata, char *input_id, \
int layer, char *placeholder)
{
    char *id = str_add(input_id, "@[:text]");

    add_text(adata, id, layer + 1);
    set_text_font(adata, id, get_font(adata, get_str(adata, "default_font")));
    edit_text(adata, id, placeholder);
    color_text(adata, id, get_config_color(adata, "input_idle"));
    resize_text(adata, id, get_int(adata, "input_font_size"));

    return (get_text(adata, id));
}

s_rect *get_input_caret(s_appdata *adata, char *input_id, int layer)
{
    char *id = str_add(input_id, "@[:caret]");
    int font_size = get_int(adata, "input_font_size");

    add_rect(adata, id, layer + 1);
    resize_rect(adata, id, (sfVector2f) { 2.0f, font_size });
    color_rect(adata, id, get_config_color(adata, "input_foreground"));
    move_rect(adata, id, (sfVector2f) { 10, 10 });
    set_rect_active(adata, id, 0);

    return (get_rect(adata, id));
}
