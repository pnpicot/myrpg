/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Circle module
*/

#include "../include/main.h"

sfFloatRect get_circle_bounds(s_appdata *adata, char *id)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return ((sfFloatRect) { -1, -1, -1, -1 });
    }

    return (sfCircleShape_getGlobalBounds(circle->elem));
}

float get_circle_rotation(s_appdata *adata, char *id)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return (-1);
    }

    return (sfCircleShape_getRotation(circle->elem));
}

sfVector2f get_circle_scale(s_appdata *adata, char *id)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (sfCircleShape_getScale(circle->elem));
}

sfColor get_circle_bg(s_appdata *adata, char *id)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return (sfBlack);
    }

    return (sfCircleShape_getFillColor(circle->elem));
}

sfColor get_circle_out_color(s_appdata *adata, char *id)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return (sfBlack);
    }

    return (sfCircleShape_getOutlineColor(circle->elem));
}
