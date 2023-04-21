/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Lighting module
*/

#include "../include/main.h"

void set_light_gameobject(s_appdata *adata, char *id, sfBool game_obj)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    light->game_obj = game_obj;
}

void move_light(s_appdata *adata, char *id, sfVector2f pos)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    light->pos = pos;
    sfSprite_setPosition(light->cache, pos);
    sfSprite_setPosition(light->wall_cache, pos);
}

void translate_light(s_appdata *adata, char *id, sfVector2f pos_ch)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    light->pos.x += pos_ch.x;
    light->pos.y += pos_ch.y;

    sfSprite_setPosition(light->cache, light->pos);
    sfSprite_setPosition(light->wall_cache, light->pos);
}

void set_light_inner(s_appdata *adata, char *id, float inner_radius)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    light->inner_radius = inner_radius;
    update_light(adata, light);
}

void set_light_outer(s_appdata *adata, char *id, float outer_radius)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    light->outer_radius = outer_radius;
    update_light(adata, light);
}
