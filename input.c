/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Input module
*/

#include "include/main.h"

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
    color_text(adata, input->input_text->id, get_config_color(adata, "input_foreground"));
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
    set_object_hover_bg(adata, id, get_config_color(adata, "input_background_hover"));
    set_object_pressed_bg(adata, id, get_config_color(adata, "input_background_pressed"));
    set_object_onclick(adata, id, &trigger_input);

    return (get_rect(adata, id));
}

s_text *get_input_text(s_appdata *adata, char *input_id, int layer, char *placeholder)
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

void update_input(s_appdata *adata, s_input *input)
{
    sfFloatRect rect_bounds = get_rect_bounds(adata, input->input_rect->id);
    sfFloatRect text_bounds = get_text_bounds(adata, input->input_text->id);
    int font_size = sfText_getCharacterSize(input->input_text->elem);
    sfVector2f text_pos;

    text_pos.y = rect_bounds.top - (font_size / 2) + (rect_bounds.height / 2) - 4.0f;

    if (!input->align) {
        text_pos.x = rect_bounds.left + input->x_padding;
    } else if (input->align == 1) {
        text_pos.x = rect_bounds.left + (rect_bounds.width / 2) - (text_bounds.width / 2);
    } else {
        text_pos.x = rect_bounds.left + rect_bounds.width - (input->x_padding * 2) - text_bounds.width;
    }

    move_text(adata, input->input_text->id, text_pos);

    const char *text = get_text_str(adata, input->input_text->id);
    int len = my_strlen(text);

    sfVector2f caret_pos;
    caret_pos.x = text_pos.x + text_bounds.width + (len ? 5.0f : 0);
    caret_pos.y = text_pos.y + (len ? 4.0f : 2.0f);

    move_rect(adata, input->input_caret->id, caret_pos);
}

void input_check_released(s_appdata *adata)
{
    if (adata->last_input != NULL) {
        s_input *input = (s_input *) adata->last_input;

        if (!input->contains) {
            edit_text(adata, input->input_text->id, input->placeholder);
            color_text(adata, input->input_text->id, get_config_color(adata, "input_idle"));
        }

        input->input_caret->active = 0;
        update_input(adata, input);

        adata->last_input = NULL;
    }
}

void input_update(s_appdata *adata)
{
    if (adata->last_input == NULL) return;

    s_input *input = (s_input *) adata->last_input;
    sfTime elapsed = sfClock_getElapsedTime(input->caret_clock);
    float seconds = elapsed.microseconds / 1000000.0f;
    float speed = get_float(adata, "input_caret_speed");

    if (seconds >= speed) {
        sfUint8 active = input->input_caret->active;

        input->input_caret->active = active ? 0 : 1;

        sfClock_restart(input->caret_clock);
    }
}

char get_keycode_char(s_appdata *adata, int keycode)
{
    s_ints *integers = adata->integers;

    if (keycode >= sfKeyA && keycode <= sfKeyZ) {
        return ((unsigned char) keycode + (integers->capital ? 65 : 97));
    }

    s_keymap *keymap = get_keymap(adata, keycode);

    return (keymap == NULL ? 255 : keymap->ch);
}

void input_type(s_appdata *adata, int keycode)
{
    s_input *input = (s_input *) adata->last_input;
    const char *text = get_text_str(adata, input->input_text->id);
    int len = my_strlen(text);
    int is_del = len >= input->max_length && keycode != sfKeyBack;
    int banned = keycode == sfKeyLShift || keycode == sfKeyLControl;
    banned = banned || keycode == sfKeyEscape || keycode == -1;

    if (is_del || banned) return;

    if (keycode == sfKeyBack) {
        if (len <= 0) return;

        char *new_str = substr(text, 0, len - 2);

        edit_text(adata, input->input_text->id, new_str);
        update_input(adata, input);

        if (!my_strlen(new_str)) input->contains = 0;
        if (input->on_input != NULL) (*input->on_input)(adata, new_str);

        return;
    }

    char new_char = get_keycode_char(adata, keycode);

    if (new_char == 255) return;

    char *char_str = malloc(sizeof(char) * 2);
    char_str[0] = new_char;
    char_str[1] = '\0';

    edit_text(adata, input->input_text->id, str_add(text, char_str));
    update_input(adata, input);

    input->contains = 1;

    if (input->on_input != NULL) (*input->on_input)(adata, str_add(text, char_str));
}

void add_input(s_appdata *adata, char *id, int layer)
{
    s_input *input = get_input(adata, id);

    if (input != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    s_input *new_input = malloc(sizeof(s_input));

    if (new_input == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    new_input->id = id;
    new_input->input_rect = get_input_rect(adata, id, layer);
    new_input->placeholder = get_str(adata, "input_placeholder");
    new_input->input_text = get_input_text(adata, id, layer, new_input->placeholder);
    new_input->input_caret = get_input_caret(adata, id, layer);
    new_input->max_length = 100;
    new_input->align = 1;
    new_input->contains = 0;
    new_input->on_input = NULL;
    new_input->caret_clock = sfClock_create();
    new_input->x_padding = get_float(adata, "input_x_padding");

    update_input(adata, new_input);
    linked_add(adata->lists->inputs, new_input);
}

void set_input_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_input *input = get_input(adata, id);
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (input == NULL || rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    input->input_rect->rtex_id = rtex_id;
    input->input_text->rtex_id = rtex_id;
    input->input_caret->rtex_id = rtex_id;
}

void move_input(s_appdata *adata, char *id, sfVector2f pos)
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    move_rect(adata, input->input_rect->id, pos);
    update_input(adata, input);
}

void set_input_placeholder(s_appdata *adata, char *id, char *placeholder)
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    input->placeholder = placeholder;

    if (!input->contains) {
        edit_text(adata, input->input_text->id, placeholder);
        update_input(adata, input);
    }
}

void set_input_origin(s_appdata *adata, char *id, sfVector2f origin)
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    set_rect_origin(adata, input->input_rect->id, origin);
    update_input(adata, input);
}

void translate_input(s_appdata *adata, char *id, sfVector2f pos_ch)
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    translate_rect(adata, input->input_rect->id, pos_ch);
    update_input(adata, input);
}

const char *get_input_str(s_appdata *adata, char *id)
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (NULL);
    }

    return (input->contains ? get_text_str(adata, input->input_text->id) : "");
}

void resize_input(s_appdata *adata, char *id, sfVector2f size)
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    resize_rect(adata, input->input_rect->id, size);
    update_input(adata, input);
}

void clear_input(s_appdata *adata, char *id)
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    edit_text(adata, input->input_text->id, "");

    input->contains = 0;

    update_input(adata, input);
}

void edit_input(s_appdata *adata, char *id, char *str)
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    if (!my_strlen(str) || str == NULL) {
        input->contains = 0;
    }

    edit_text(adata, input->input_text->id, str);
    update_input(adata, input);
}

void set_input_font(s_appdata *adata, char *id, sfFont *font)
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    set_text_font(adata, input->input_text->id, font);
    update_input(adata, input);
}

void resize_input_text(s_appdata *adata, char *id, int font_size)
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    resize_text(adata, input->input_text->id, font_size);
    update_input(adata, input);
}

sfVector2f get_input_pos(s_appdata *adata, char *id)
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (get_rect_pos(adata, input->input_rect->id));
}

sfVector2f get_input_origin(s_appdata *adata, char *id)
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (get_rect_origin(adata, input->input_rect->id));
}

void set_input_align(s_appdata *adata, char *id, char *align)
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    if (!my_strcmp(align, "left")) {
        input->align = 0;
    } else if (!my_strcmp(align, "center")) {
        input->align = 1;
    } else {
        input->align = 2;
    }

    update_input(adata, input);
}

void set_input_oninput(s_appdata *adata, char *id, void (*on_input)(s_appdata *adata, const char *str))
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    input->on_input = on_input;
}

void set_input_maxlength(s_appdata *adata, char *id, int max_length)
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    if (max_length < 0) max_length = 0;

    input->max_length = max_length;
}
