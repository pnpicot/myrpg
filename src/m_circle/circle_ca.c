/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Circle module
*/

#include "../include/main.h"

void move_circle(s_appdata *adata, char *id, sfVector2f pos)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    circle->pos = pos;

    sfCircleShape_setPosition(circle->elem, pos);
}

void resize_circle(s_appdata *adata, char *id, float radius)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfCircleShape_setRadius(circle->elem, radius);
}

sfVector2f get_circle_pos(s_appdata *adata, char *id)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (sfCircleShape_getPosition(circle->elem));
}

float get_circle_radius(s_appdata *adata, char *id)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (-1);
    }

    return (sfCircleShape_getRadius(circle->elem));
}

void translate_circle(s_appdata *adata, char *id, sfVector2f pos_ch)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfVector2f pos = sfCircleShape_getPosition(circle->elem);
    pos.x += pos_ch.x;
    pos.y += pos_ch.y;

    circle->pos = pos;

    sfCircleShape_setPosition(circle->elem, pos);
}
