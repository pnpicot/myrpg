/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Input module
*/

#include "../include/main.h"

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
