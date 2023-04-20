/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Rectangle shape module
*/

#include "../include/main.h"

sfVector2f get_rect_origin(s_appdata *adata, char *id)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (sfRectangleShape_getOrigin(rect->elem));
}

float get_rect_rotation(s_appdata *adata, char *id)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return (-1);
    }

    return (sfRectangleShape_getRotation(rect->elem));
}

sfVector2f get_rect_scale(s_appdata *adata, char *id)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (sfRectangleShape_getScale(rect->elem));
}

sfFloatRect get_rect_bounds(s_appdata *adata, char *id)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return ((sfFloatRect) { -1, -1, -1, -1 });
    }

    return (sfRectangleShape_getGlobalBounds(rect->elem));
}

void set_rect_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_rect *rect = get_rect(adata, id);
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (rect == NULL || rtex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    rect->rtex_id = rtex_id;
}
