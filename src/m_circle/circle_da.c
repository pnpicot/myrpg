/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Circle module
*/

#include "../include/main.h"

void color_circle(s_appdata *adata, char *id, sfColor color)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    sfCircleShape_setFillColor(circle->elem, color);
}

void set_circle_out(s_appdata *adata, char *id, sfColor color, float thickness)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    sfCircleShape_setOutlineColor(circle->elem, color);
    sfCircleShape_setOutlineThickness(circle->elem, thickness);
}

void rotate_circle(s_appdata *adata, char *id, float angle)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    sfCircleShape_setRotation(circle->elem, angle);
}

void scale_circle(s_appdata *adata, char *id, sfVector2f factors)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    sfCircleShape_setScale(circle->elem, factors);
}

void set_circle_origin(s_appdata *adata, char *id, sfVector2f origin)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    sfCircleShape_setOrigin(circle->elem, origin);
}
