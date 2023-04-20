/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Input module
*/

#include "../include/main.h"

sfVector2f get_input_pos(s_appdata *adata, char *id)
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (get_rect_pos(adata, input->input_rect->id));
}

sfVector2f get_input_origin(s_appdata *adata, char *id)
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (get_rect_origin(adata, input->input_rect->id));
}

void set_input_align(s_appdata *adata, char *id, char *align)
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
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

void set_input_oninput(s_appdata *adata, char *id, \
void (*on_input)(s_appdata *adata, const char *str))
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    input->on_input = on_input;
}

void set_input_maxlength(s_appdata *adata, char *id, int max_length)
{
    s_input *input = get_input(adata, id);

    if (input == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    if (max_length < 0) max_length = 0;

    input->max_length = max_length;
}
