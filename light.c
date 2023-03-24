/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Lighting module
*/

#include "include/main.h"

void set_lightblend_rtex(s_appdata *adata, char *rtex_id)
{
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    adata->light_blend_rtex = rtex;
}

void set_light_rtex(s_appdata *adata, char *rtex_id)
{
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    adata->light_rtex = rtex;
}

void set_lightres_rtex(s_appdata *adata, char *rtex_id)
{
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    adata->light_res_rtex = rtex;
}

s_light *get_light(s_appdata *adata, char *id)
{
    linked_node *lights = adata->lists->lights;

    while (lights != NULL && lights->data != NULL) {
        s_light *cur = (s_light *) lights->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        lights = lights->next;
    }

    return (NULL);
}

void delete_light(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *lights = adata->lists->lights;
    int ite = 0;

    while (lights != NULL && lights->data != NULL) {
        s_light *cur = (s_light *) lights->data;

        if (!my_strcmp(cur->id, id)) break;

        ite++;
        lights = lights->next;
    }

    linked_delete(&adata->lists->lights, ite);
}

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
    sfCircleShape_setPosition(light->inner_light, light->pos);
    sfCircleShape_setPosition(light->outer_light, light->pos);

    sfColor light_color = light->color;
    float outer_alpha = 255.0f - (255.0f * (light->intensity / 100.0f));

    sfCircleShape_setFillColor(light->inner_light, light_color);

    light_color.r = force_range(light_color.r - outer_alpha, 0, 255);
    light_color.g = force_range(light_color.g - outer_alpha, 0, 255);
    light_color.b = force_range(light_color.b - outer_alpha, 0, 255);

    sfCircleShape_setFillColor(light->outer_light, light_color);
}

void add_light(s_appdata *adata, char *id)
{
    if (adata->light_rtex == NULL) {
        my_printf(get_error(adata, "missing_light_rtex"));
        return;
    }

    s_light *light = get_light(adata, id);

    if (light != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    s_light *new_light = malloc(sizeof(s_light));

    if (new_light == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    new_light->id = id;
    new_light->color = sfWhite;
    new_light->inner_radius = get_float(adata, "light_inner");
    new_light->outer_radius = get_float(adata, "light_outer");
    new_light->intensity = get_float(adata, "light_intensity");
    new_light->active = sfTrue;
    new_light->pos = (sfVector2f) { 0, 0 };
    new_light->inner_light = get_inner_light(adata, new_light);
    new_light->outer_light = get_outer_light(adata, new_light);

    linked_add(adata->lists->lights, new_light);
}

void move_light(s_appdata *adata, char *id, sfVector2f pos)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    light->pos = pos;
    update_light(adata, light);
}

void set_light_inner(s_appdata *adata, char *id, float inner_radius)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    light->inner_radius = inner_radius;
    update_light(adata, light);
}

void set_light_outer(s_appdata *adata, char *id, float outer_radius)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    light->outer_radius = outer_radius;
    update_light(adata, light);
}

void color_light(s_appdata *adata, char *id, sfColor color)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    light->color = color;
    update_light(adata, light);
}

void set_light_intensity(s_appdata *adata, char *id, float intensity)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    light->intensity = force_range(intensity, 0.0f, 100.0f);
    update_light(adata, light);
}

sfColor get_light_color(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (sfBlack);
    }

    return (light->color);
}

sfVector2f get_light_pos(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (light->pos);
}

float get_light_inner(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (-1);
    }

    return (light->inner_radius);
}

float get_light_outer(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (-1);
    }

    return (light->outer_radius);
}

float get_light_intensity(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (-1);
    }

    return (light->intensity);
}

void set_light_active(s_appdata *adata, char *id, sfBool active)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    light->active = active;
}

void enable_light(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    light->active = sfTrue;
}

void disable_light(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    light->active = sfFalse;
}

sfBool get_light_active(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (sfFalse);
    }

    return (light->active);
}

void toggle_light(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfBool active = light->active;

    light->active = active ? sfFalse : sfTrue;
}
