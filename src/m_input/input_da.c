/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Input module
*/

#include "../include/main.h"

void input_type_next(s_appdata *adata, s_input *input, \
char new_char, const char *text)
{
    char *char_str = malloc(sizeof(char) * 2);

    char_str[0] = new_char;
    char_str[1] = '\0';

    edit_text(adata, input->input_text->id, str_add(text, char_str));
    update_input(adata, input);

    input->contains = 1;

    if (input->on_input != NULL)
        (*input->on_input)(adata, str_add(text, char_str));
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
    input_type_next(adata, input, new_char, text);
}

void add_input_next(s_appdata *adata, char *id, int layer, s_input *new_input)
{
    new_input->id = id;
    new_input->input_rect = get_input_rect(adata, id, layer);
    new_input->placeholder = get_str(adata, "input_placeholder");
    char *placeholder = new_input->placeholder;
    new_input->input_text = get_input_text(adata, id, layer, placeholder);
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

void add_input(s_appdata *adata, char *id, int layer)
{
    s_input *input = get_input(adata, id);
    if (input != NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "already_exists"));
        return;
    }
    s_input *new_input = malloc(sizeof(s_input));
    if (new_input == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "mem_alloc"));
        return;
    }
    add_input_next(adata, id, layer, new_input);
}

void set_input_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_input *input = get_input(adata, id);
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (input == NULL || rtex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    set_rect_rtex(adata, input->input_rect->id, rtex_id);
    set_text_rtex(adata, input->input_text->id, rtex_id);
    set_rect_rtex(adata, input->input_caret->id, rtex_id);
}
