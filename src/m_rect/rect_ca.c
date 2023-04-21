/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Rectangle shape module
*/

#include "../include/main.h"

void color_rect(s_appdata *adata, char *id, sfColor color)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    sfRectangleShape_setFillColor(rect->elem, color);
}

void set_rect_outline(s_appdata *adata, char *id, \
sfColor color, float thickness)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    sfRectangleShape_setOutlineColor(rect->elem, color);
    sfRectangleShape_setOutlineThickness(rect->elem, thickness);
}

void set_rect_origin(s_appdata *adata, char *id, sfVector2f origin)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    sfRectangleShape_setOrigin(rect->elem, origin);
}

void rotate_rect(s_appdata *adata, char *id, float angle)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    sfRectangleShape_setRotation(rect->elem, angle);
}

void scale_rect(s_appdata *adata, char *id, sfVector2f factors)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    sfRectangleShape_setScale(rect->elem, factors);
}
