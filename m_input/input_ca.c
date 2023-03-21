/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Input module
*/

#include "../include/main.h"

void update_input_next(s_appdata *adata, s_input *input, \
sfVector2f text_pos, sfFloatRect text_bounds)
{
    const char *text = get_text_str(adata, input->input_text->id);
    int len = my_strlen(text);
    sfVector2f caret_pos;
    caret_pos.x = text_pos.x + text_bounds.width + (len ? 5.0f : 0);
    caret_pos.y = text_pos.y + (len ? 4.0f : 2.0f);
    move_rect(adata, input->input_caret->id, caret_pos);
}

void update_input(s_appdata *adata, s_input *input)
{
    sfFloatRect rect_bounds = get_rect_bounds(adata, input->input_rect->id);
    sfFloatRect text_bounds = get_text_bounds(adata, input->input_text->id);
    int font_size = sfText_getCharacterSize(input->input_text->elem);
    sfVector2f text_pos;
    text_pos.y = rect_bounds.top - (font_size / 2);
    text_pos.y += (rect_bounds.height / 2) - 4.0f;
    if (!input->align) {
        text_pos.x = rect_bounds.left + input->x_padding;
    } else if (input->align == 1) {
        text_pos.x = rect_bounds.left + (rect_bounds.width / 2);
        text_pos.x -= text_bounds.width / 2;
    } else {
        text_pos.x = rect_bounds.left + rect_bounds.width;
        text_pos.x -= (input->x_padding * 2) - text_bounds.width;
    }
    move_text(adata, input->input_text->id, text_pos);
    update_input_next(adata, input, text_pos, text_bounds);
}

void input_check_released(s_appdata *adata)
{
    if (adata->last_input != NULL) {
        s_input *input = (s_input *) adata->last_input;

        if (!input->contains) {
            edit_text(adata, input->input_text->id, input->placeholder);

            sfColor idle_color = get_config_color(adata, "input_idle");

            color_text(adata, input->input_text->id, idle_color);
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
