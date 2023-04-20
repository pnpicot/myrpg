/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Transform module
*/

#include "../include/main.h"

void transform_next(s_appdata *adata, s_transform *ntrf, \
s_target target, float delay)
{
    float move_speed = get_vec_dist(ntrf->old_pos, target.pos) / delay;
    float rotation_speed = (target.rotation - ntrf->old_rotation) / delay;
    float scale_speed = get_vec_dist(ntrf->old_scale, target.scale) / delay;
    float red_diff = (target.color.r - ntrf->old_color.r) / delay;
    float green_diff = (target.color.g - ntrf->old_color.g) / delay;
    float blue_diff = (target.color.b - ntrf->old_color.b) / delay;
    float alpha_diff = (target.color.a - ntrf->old_color.a) / delay;
    sfVector2f color_red = { ntrf->old_color.r, red_diff };
    sfVector2f color_green = { ntrf->old_color.g, green_diff };
    sfVector2f color_blue = { ntrf->old_color.b, blue_diff };
    sfVector2f color_alpha = { ntrf->old_color.a, alpha_diff };
    ntrf->move_speed = move_speed;
    ntrf->rotation_speed = rotation_speed;
    ntrf->scale_speed = scale_speed;
    ntrf->color_red = color_red;
    ntrf->color_green = color_green;
    ntrf->color_blue = color_blue;
    ntrf->color_alpha = color_alpha;
    linked_add(adata->lists->transforms, ntrf);
}

void transform(s_appdata *adata, float delay, s_target target)
{
    s_transform *ntrf = malloc(sizeof(s_transform));
    if (ntrf == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "mem_alloc"));
        return;
    }
    transform_init(adata, ntrf, delay, target);
    transform_next(adata, ntrf, target, delay);
}
