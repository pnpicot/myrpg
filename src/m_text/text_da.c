/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Text module
*/

#include "../include/main.h"

void color_text(s_appdata *adata, char *id, sfColor color)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfText_setColor(text->elem, color);
}

void resize_text(s_appdata *adata, char *id, int font_size)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfText_setCharacterSize(text->elem, font_size);
}

void scale_text(s_appdata *adata, char *id, sfVector2f factors)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfText_setScale(text->elem, factors);
}

void rotate_text(s_appdata *adata, char *id, float angle)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfText_setRotation(text->elem, angle);
}

const char *get_text_str(s_appdata *adata, char *id)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (NULL);
    }

    return (sfText_getString(text->elem));
}
