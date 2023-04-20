/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Text module
*/

#include "../include/main.h"

void set_text_font(s_appdata *adata, char *id, sfFont *font)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    sfText_setFont(text->elem, font);
}

void edit_text(s_appdata *adata, char *id, char *str)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    sfText_setString(text->elem, str);
}

void move_text(s_appdata *adata, char *id, sfVector2f pos)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    text->pos = pos;

    sfText_setPosition(text->elem, pos);
}

sfVector2f get_text_pos(s_appdata *adata, char *id)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (sfText_getPosition(text->elem));
}

void translate_text(s_appdata *adata, char *id, sfVector2f pos_ch)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    sfVector2f pos = sfText_getPosition(text->elem);
    pos.x += pos_ch.x;
    pos.y += pos_ch.y;

    text->pos = pos;

    sfText_setPosition(text->elem, pos);
}
