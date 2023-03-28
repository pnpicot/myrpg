/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Rectangle shape module
*/

#include "../include/main.h"

sfVector2f get_rect_pos(s_appdata *adata, char *id)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (sfRectangleShape_getPosition(rect->elem));
}

void translate_rect(s_appdata *adata, char *id, sfVector2f pos_ch)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfVector2f pos = sfRectangleShape_getPosition(rect->elem);
    pos.x += pos_ch.x;
    pos.y += pos_ch.y;

    rect->pos = pos;

    sfRectangleShape_setPosition(rect->elem, pos);
}

sfColor get_rect_bg(s_appdata *adata, char *id)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (sfBlack);
    }

    return (sfRectangleShape_getFillColor(rect->elem));
}

sfColor get_rect_out_color(s_appdata *adata, char *id)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (sfBlack);
    }

    return (sfRectangleShape_getOutlineColor(rect->elem));
}

float get_rect_out_thickness(s_appdata *adata, char *id)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (-1);
    }

    return (sfRectangleShape_getOutlineThickness(rect->elem));
}
