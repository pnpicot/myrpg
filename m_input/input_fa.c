/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Input module
*/

#include "../include/main.h"

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
