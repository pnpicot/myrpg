/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Transform module
*/

#include "../include/main.h"

void transform_color(s_appdata *adata, s_transform *transform)
{
    float delta = get_clock_seconds(transform->color_clock);

    transform->color_red.x += transform->color_red.y * delta;
    transform->color_green.x += transform->color_green.y * delta;
    transform->color_blue.x += transform->color_blue.y * delta;
    transform->color_alpha.x += transform->color_alpha.y * delta;

    sfColor new_color;
    new_color.r = transform->color_red.x;
    new_color.g = transform->color_green.x;
    new_color.b = transform->color_blue.x;
    new_color.a = transform->color_alpha.x;

    color_element(adata, transform->ref->ref, transform->ref->type, new_color);
    sfClock_restart(transform->color_clock);
}

void transform_rotation(s_appdata *adata, s_transform *trf)
{
    float delta = get_clock_seconds(trf->rot_clock);

    trf->old_rotation += trf->rotation_speed * delta;

    rotate_element(adata, trf->ref->ref, trf->ref->type, trf->old_rotation);
    sfClock_restart(trf->rot_clock);
}

void end_transform(s_appdata *adata, s_transform *trf)
{
    s_ref *ref = trf->ref;

    if (trf->flags & trf_move)
        move_element(adata, ref->ref, ref->type, trf->target_pos);

    if (trf->flags & trf_rot)
        rotate_element(adata, ref->ref, ref->type, trf->target_rotation);

    if (trf->flags & trf_scale)
        scale_element(adata, ref->ref, ref->type, trf->target_scale);

    if (trf->flags & trf_color)
        color_element(adata, ref->ref, ref->type, trf->target_color);
}

void transform_update(s_appdata *adata)
{
    linked_node *transforms = adata->lists->transforms;
    while (transforms != NULL && transforms->data != NULL) {
        s_transform *cur = (s_transform *) transforms->data;
        sfTime elapsed = sfClock_getElapsedTime(cur->end_clock);
        float seconds = elapsed.microseconds / 1000000.0f;
        if (seconds >= cur->delta_time) {
            transforms = transforms->next;
            end_transform(adata, cur);
            delete_transform(adata, cur->id);
            continue;
        }
        if (cur->flags & trf_color) transform_color(adata, cur);
        if (cur->flags & trf_rot) transform_rotation(adata, cur);
        if (cur->flags & trf_scale) transform_scale(adata, cur);
        if (cur->flags & trf_move) transform_move(adata, cur);
        transforms = transforms->next;
    }
}

void transform_init(s_appdata *adata, s_transform *ntrf, \
float delta_time, s_target target)
{
    ntrf->callback = NULL;
    ntrf->move_clock = sfClock_create();
    ntrf->rot_clock = sfClock_create();
    ntrf->scale_clock = sfClock_create();
    ntrf->color_clock = sfClock_create();
    ntrf->end_clock = sfClock_create();
    ntrf->id = get_random_id(10);
    ntrf->ref = target.ref;
    ntrf->delta_time = delta_time;
    ntrf->old_pos = get_element_pos(adata, target.ref->ref, target.ref->type);
    float rot = get_element_rotation(adata, target.ref->ref, target.ref->type);
    ntrf->old_rotation = rot;
    sfVector2f sc = get_element_scale(adata, target.ref->ref, target.ref->type);
    ntrf->old_scale = sc;
    ntrf->old_color = get_element_bg(adata, target.ref->ref, target.ref->type);
    ntrf->target_color = target.color;
    ntrf->target_pos = target.pos;
    ntrf->target_rotation = target.rotation;
    ntrf->target_scale = target.scale;
    ntrf->flags = target.flags;
}
