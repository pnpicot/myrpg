/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Light rendering module
*/

#include "../include/main.h"

void shadow_cast(s_appdata *adata, s_light *light)
{
    linked_node *walls = adata->lists->walls;
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    sfVector2f mid = { win_w / 2, win_h / 2 };
    sfVector2f shift = { 0, 0 };
    sfBool is_obj = light->game_obj;
    if (is_obj) {
        shift.x = mid.x - light->pos.x;
        shift.y = mid.y - light->pos.y;
    }
    while (walls != NULL && walls->data != NULL) {
        s_wall *cur = (s_wall *) walls->data;
        sfFloatRect wall_bounds = get_rect_bounds(adata, cur->hitbox->id);
        create_shadow_mask(adata, is_obj ? mid : light->pos, cur, shift);
        walls = walls->next;
    }
    set_shader_float(adata, "gradient", "max_dist", light->outer_radius);
    draw_light(adata, light);
}

void render_light_cycle(s_appdata *adata, s_rtex *mask_rtex, \
s_rtex *light_rtex, s_light *cur)
{
    shadow_cast(adata, cur);
    clear_rtex(adata, mask_rtex->id, mask_rtex->clear_color);
    clear_rtex(adata, light_rtex->id, light_rtex->clear_color);
}

void render_lights_next(s_appdata *adata, sfBool obj)
{
    linked_node *lights = adata->lists->lights;
    s_rtex *mask_rtex = adata->mask_rtex;
    s_rtex *light_rtex = adata->light_rtex;
    s_rtex *light_res_rtex = adata->light_res_rtex;
    if (obj) clear_rtex(adata, adata->light_blend_rtex->id, sfTransparent);
    while (lights != NULL && lights->data != NULL) {
        s_light *cur = (s_light *) lights->data;
        if (!cur->changed || cur->game_obj != obj) {
            lights = lights->next;
            continue;
        }
        render_light_cycle(adata, mask_rtex, light_rtex, cur);
        if (obj) clear_rtex(adata, adata->light_blend_rtex->id, sfTransparent);
        for (int i = light_rtex->depth; i <= light_res_rtex->depth; i++) {
            s_rtex *rtex = get_rtex_d(adata, i);
            clear_rtex(adata, rtex->id, rtex->clear_color);
        }
        lights = lights->next;
    }
}

void render_lights(s_appdata *adata)
{
    if (adata->mask_rtex == NULL) return;

    s_ints *integers = adata->integers;

    integers->light_count = 0;

    clear_rtex(adata, adata->light_blend_rtex->id, sfTransparent);
    render_lights_next(adata, sfTrue);
    clear_rtex(adata, adata->light_blend_rtex->id, sfBlack);
    clear_rtex(adata, get_str(adata, "rtex_wall_light"), sfBlack);
    render_lights_next(adata, sfFalse);
    draw_cached_lights(adata);
    force_rtex(adata, adata->light_blend_rtex->id);
}
