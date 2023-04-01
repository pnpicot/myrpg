/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Light rendering module
*/

#include "../include/main.h"

void draw_cached_lights_next(s_appdata *adata, sfFloatRect screen, \
sfRenderStates *state)
{
    linked_node *lights = adata->lists->lights;
    s_rtex *blend = get_rtex(adata, adata->light_blend_rtex->id);
    s_rtex *wall = get_rtex(adata, get_str(adata, "rtex_wall_light"));

    while (lights != NULL && lights->data != NULL) {
        s_light *cur = (s_light *) lights->data;
        int in = !rect_intersects_circle(screen, cur->pos, cur->outer_radius);
        if (!cur->game_obj || in) {
            lights = lights->next;
            continue;
        }
        sfRenderTexture_drawSprite(blend->texture, cur->cache, state);
        sfRenderTexture_drawSprite(wall->texture, cur->wall_cache, state);
        adata->integers->light_count++;
        lights = lights->next;
    }
}

void draw_cached_lights(s_appdata *adata)
{
    sfRenderStates *state = malloc(sizeof(sfRenderStates));
    sfFloatRect screen;
    screen.left = 0;
    screen.top = 0;
    screen.width = get_int(adata, "win_w");
    screen.height = get_int(adata, "win_h");
    state->blendMode = sfBlendAdd;
    state->shader = NULL;
    state->texture = NULL;
    state->transform = sfTransform_Identity;
    draw_cached_lights_next(adata, screen, state);
}

void draw_light_base(s_appdata *adata, s_light *light, int is_obj)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    sfVector2f mid = { win_w / 2, win_h / 2 };

    if (is_obj) {
        set_shader_vec2(adata, "gradient", "pos", mid);
        sfCircleShape_setPosition(light->outer_light, mid);
        sfCircleShape_setPosition(light->inner_light, mid);
    } else {
        set_shader_vec2(adata, "gradient", "pos", light->pos);
        sfCircleShape_setPosition(light->outer_light, light->pos);
        sfCircleShape_setPosition(light->inner_light, light->pos);
        adata->integers->light_count++;
    }

    sfRenderTexture *tex = adata->light_rtex->texture;

    sfRenderTexture_drawCircleShape(tex, light->outer_light, NULL);
    sfRenderTexture_drawCircleShape(tex, light->inner_light, NULL);
}

void draw_light_over_walls(s_appdata *adata, int is_obj, \
s_light *light, s_rtex *wall)
{
    s_rtex *li_rtex = get_rtex(adata, adata->light_res_rtex->id);
    for (int i = adata->light_rtex->depth; i <= li_rtex->depth; i++) {
        s_rtex *rtex = get_rtex_d(adata, i);
        force_rtex(adata, rtex->id);
    }
    sfRenderTexture_drawSprite(wall->texture, li_rtex->sprite, li_rtex->state);
    if (is_obj) {
        const sfTexture *tex = sfRenderTexture_getTexture(wall->texture);
        sfSprite_setTexture(light->wall_cache, sfTexture_copy(tex), sfTrue);
        light->changed = sfFalse;
    }
}

void draw_light(s_appdata *adata, s_light *light)
{
    sfBool is_obj = light->game_obj;
    draw_light_base(adata, light, is_obj);
    s_rtex *li_rtex = get_rtex(adata, adata->light_res_rtex->id);
    s_rtex *blend = get_rtex(adata, adata->light_blend_rtex->id);
    s_rtex *wall = get_rtex(adata, get_str(adata, "rtex_wall_light"));
    for (int i = adata->light_rtex->depth; i <= li_rtex->depth; i++) {
        s_rtex *rtex = get_rtex_d(adata, i);
        force_rtex(adata, rtex->id);
    }
    sfRenderTexture_drawSprite(blend->texture, li_rtex->sprite, li_rtex->state);
    clear_rtex(adata, adata->mask_rtex->id, sfWhite);
    if (is_obj) {
        const sfTexture *tex = sfRenderTexture_getTexture(blend->texture);
        sfSprite_setTexture(light->cache, sfTexture_copy(tex), sfTrue);
        clear_rtex(adata, wall->id, sfTransparent);
    }
    draw_light_over_walls(adata, is_obj, light, wall);
}
