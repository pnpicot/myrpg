/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Text module
*/

#include "../include/main.h"

sfFloatRect get_text_bounds(s_appdata *adata, char *id)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return ((sfFloatRect) { -1, -1, -1, -1 });
    }

    sfFloatRect bounds = sfText_getGlobalBounds(text->elem);
    bounds.height += sfText_getCharacterSize(text->elem) / 2;

    return (bounds);
}

const sfFont *get_text_font(s_appdata *adata, char *id)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return (NULL);
    }

    return (sfText_getFont(text->elem));
}
