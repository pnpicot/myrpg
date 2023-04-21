/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Lighting module
*/

#include "../include/main.h"

float get_light_outer(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return (-1);
    }

    return (light->outer_radius);
}

float get_light_intensity(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return (-1);
    }

    return (light->intensity);
}

void set_light_active(s_appdata *adata, char *id, sfBool active)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    light->active = active;
}

void enable_light(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    light->active = sfTrue;
}

void disable_light(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    light->active = sfFalse;
}
