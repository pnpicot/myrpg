/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Text module
*/

#include "../include/main.h"

sfColor get_text_color(s_appdata *adata, char *id)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (sfBlack);
    }

    return (sfText_getColor(text->elem));
}

sfVector2f get_text_scale(s_appdata *adata, char *id)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (sfText_getScale(text->elem));
}

float get_text_rotation(s_appdata *adata, char *id)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (-1);
    }

    return (sfText_getRotation(text->elem));
}

void set_text_origin(s_appdata *adata, char *id, sfVector2f origin)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfText_setOrigin(text->elem, origin);
}

sfVector2f get_text_origin(s_appdata *adata, char *id)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (sfText_getOrigin(text->elem));
}
