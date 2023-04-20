/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Lighting module
*/

#include "../include/main.h"

sfCircleShape *get_inner_light(s_appdata *adata, s_light *light)
{
    sfCircleShape *inner = sfCircleShape_create();

    sfCircleShape_setRadius(inner, light->inner_radius);

    sfVector2f light_origin;
    light_origin.x = light->inner_radius;
    light_origin.y = light->inner_radius;

    sfCircleShape_setOrigin(inner, light_origin);

    sfColor light_color = light->color;

    sfCircleShape_setFillColor(inner, light_color);

    return (inner);
}

sfCircleShape *get_outer_light(s_appdata *adata, s_light *light)
{
    sfCircleShape *outer = sfCircleShape_create();

    sfCircleShape_setRadius(outer, light->outer_radius);

    sfVector2f light_origin;
    light_origin.x = light->outer_radius;
    light_origin.y = light->outer_radius;

    sfCircleShape_setOrigin(outer, light_origin);

    sfColor light_color = light->color;
    float light_alpha = 255 - (255 * (light->intensity / 100.0f));
    light_color.r = force_range(light_color.r - light_alpha, 0, 255);
    light_color.g = force_range(light_color.g - light_alpha, 0, 255);
    light_color.b = force_range(light_color.b - light_alpha, 0, 255);

    sfCircleShape_setFillColor(outer, light_color);

    return (outer);
}

void update_light(s_appdata *adata, s_light *light)
{
    sfCircleShape_setRadius(light->inner_light, light->inner_radius);
    sfCircleShape_setRadius(light->outer_light, light->outer_radius);
    sfVector2f inner_origin;
    inner_origin.x = light->inner_radius;
    inner_origin.y = light->inner_radius;
    sfVector2f outer_origin;
    outer_origin.x = light->outer_radius;
    outer_origin.y = light->outer_radius;
    sfCircleShape_setOrigin(light->inner_light, inner_origin);
    sfCircleShape_setOrigin(light->outer_light, outer_origin);
    sfColor light_color = light->color;
    float outer_alpha = 255.0f - (255.0f * (light->intensity / 100.0f));
    sfCircleShape_setFillColor(light->inner_light, light_color);
    light_color.r = force_range(light_color.r - outer_alpha, 0, 255);
    light_color.g = force_range(light_color.g - outer_alpha, 0, 255);
    light_color.b = force_range(light_color.b - outer_alpha, 0, 255);
    sfCircleShape_setFillColor(light->outer_light, light_color);
}

void add_light_next(s_appdata *adata, char *id, s_light *new_light)
{
    new_light->id = id;
    new_light->color = sfWhite;
    new_light->inner_radius = get_float(adata, "light_inner");
    new_light->outer_radius = get_float(adata, "light_outer");
    new_light->intensity = get_float(adata, "light_intensity");
    new_light->active = sfTrue;
    new_light->pos = (sfVector2f) { 0, 0 };
    new_light->inner_light = get_inner_light(adata, new_light);
    new_light->outer_light = get_outer_light(adata, new_light);
    new_light->game_obj = sfFalse;
    new_light->cache = sfSprite_create();
    new_light->wall_cache = sfSprite_create();
    new_light->changed = sfTrue;
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    sfVector2f mid = { win_w / 2, win_h / 2 };
    sfSprite_setOrigin(new_light->cache, mid);
    sfSprite_setOrigin(new_light->wall_cache, mid);
    linked_add(adata->lists->lights, new_light);
}

void add_light(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);
    if (light != NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "already_exists"));
        return;
    }
    s_light *new_light = malloc(sizeof(s_light));
    if (new_light == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "mem_alloc"));
        return;
    }
    add_light_next(adata, id, new_light);
}
