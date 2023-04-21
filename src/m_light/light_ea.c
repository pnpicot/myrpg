/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Lighting module
*/

#include "../include/main.h"

void color_light(s_appdata *adata, char *id, sfColor color)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    light->color = color;
    update_light(adata, light);
}

void set_light_intensity(s_appdata *adata, char *id, float intensity)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    light->intensity = force_range(intensity, 0.0f, 100.0f);
    update_light(adata, light);
}

sfColor get_light_color(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return (sfBlack);
    }

    return (light->color);
}

sfVector2f get_light_pos(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (light->pos);
}

float get_light_inner(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return (-1);
    }

    return (light->inner_radius);
}
