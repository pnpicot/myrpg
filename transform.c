/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Transform module
*/

#include "include/main.h"

s_transform *get_transform(s_appdata *adata, char *id)
{
    linked_node *transforms = adata->lists->transforms;

    while (transforms != NULL && transforms->data != NULL) {
        s_transform *cur = (s_transform *) transforms->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        transforms = transforms->next;
    }

    return (NULL);
}

void delete_transform(s_appdata *adata, char *id)
{
    s_transform *transform = get_transform(adata, id);

    if (transform == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *transforms = adata->lists->transforms;
    int ite = 0;

    while (transforms != NULL && transforms->data != NULL) {
        s_transform *cur = (s_transform *) transforms->data;

        if (!my_strcmp(cur->id, id)) {
            free(cur->ref);
            sfClock_destroy(cur->move_clock);
            sfClock_destroy(cur->rot_clock);
            sfClock_destroy(cur->scale_clock);
            sfClock_destroy(cur->color_clock);
            sfClock_destroy(cur->end_clock);
            break;
        }

        ite++;
        transforms = transforms->next;
    }

    linked_delete(&adata->lists->transforms, ite);
}

void transform_move(s_appdata *adata, s_transform *transform)
{
    sfVector2f dist_vec;
    dist_vec.x = transform->target_pos.x - transform->old_pos.x;
    dist_vec.y = transform->target_pos.y - transform->old_pos.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));
    float delta = sfClock_getElapsedTime(transform->move_clock).microseconds / 1000000.0f;

    transform->old_pos.x += ((transform->move_speed * delta) / dist) * dist_vec.x;
    transform->old_pos.y += ((transform->move_speed * delta) / dist) * dist_vec.y;

    move_element(adata, transform->ref->ref, transform->ref->type, transform->old_pos);
    sfClock_restart(transform->move_clock);
}

void transform_scale(s_appdata *adata, s_transform *transform)
{
    float delta = sfClock_getElapsedTime(transform->scale_clock).microseconds / 1000000.0f;
    sfVector2f dist_vec;

    dist_vec.x = transform->target_scale.x - transform->old_scale.x;
    dist_vec.y = transform->target_scale.y - transform->old_scale.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));

    transform->old_scale.x += ((transform->scale_speed * delta) / dist) * dist_vec.x;
    transform->old_scale.y += ((transform->scale_speed * delta) / dist) * dist_vec.y;

    scale_element(adata, transform->ref->ref, transform->ref->type, transform->old_scale);
    sfClock_restart(transform->scale_clock);
}

void transform_color(s_appdata *adata, s_transform *transform)
{
    float delta = sfClock_getElapsedTime(transform->color_clock).microseconds / 1000000.0f;

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

void transform_rotation(s_appdata *adata, s_transform *transform)
{
    float delta = sfClock_getElapsedTime(transform->rot_clock).microseconds / 1000000.0f;

    transform->old_rotation += transform->rotation_speed * delta;

    rotate_element(adata, transform->ref->ref, transform->ref->type, transform->old_rotation);
    sfClock_restart(transform->rot_clock);
}

void end_transform(s_appdata *adata, s_transform *transform)
{
    if (transform->flags & trf_move)
        move_element(adata, transform->ref->ref, transform->ref->type, transform->target_pos);

    if (transform->flags & trf_rot)
        rotate_element(adata, transform->ref->ref, transform->ref->type, transform->target_rotation);

    if (transform->flags & trf_scale)
        scale_element(adata, transform->ref->ref, transform->ref->type, transform->target_scale);

    if (transform->flags & trf_color)
        color_element(adata, transform->ref->ref, transform->ref->type, transform->target_color);
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

void transform(s_appdata *adata, s_ref *ref, float delta_time, s_target target)
{
    char *id = get_random_id(10);
    s_transform *new_transform = malloc(sizeof(s_transform));

    if (new_transform == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    new_transform->callback = NULL;
    new_transform->move_clock = sfClock_create();
    new_transform->rot_clock = sfClock_create();
    new_transform->scale_clock = sfClock_create();
    new_transform->color_clock = sfClock_create();
    new_transform->end_clock = sfClock_create();
    new_transform->id = id;
    new_transform->ref = ref;
    new_transform->delta_time = delta_time;
    new_transform->old_pos = get_element_pos(adata, ref->ref, ref->type);
    new_transform->old_rotation = get_element_rotation(adata, ref->ref, ref->type);
    new_transform->old_scale = get_element_scale(adata, ref->ref, ref->type);
    new_transform->old_color = get_element_bg(adata, ref->ref, ref->type);
    new_transform->target_color = target.color;
    new_transform->target_pos = target.pos;
    new_transform->target_rotation = target.rotation;
    new_transform->target_scale = target.scale;
    new_transform->flags = target.flags;

    float dist = get_vec_dist(new_transform->old_pos, target.pos);
    float move_speed = get_vec_dist(new_transform->old_pos, target.pos) / delta_time;
    float rotation_speed = (target.rotation - new_transform->old_rotation) / delta_time;
    float scale_speed = get_vec_dist(new_transform->old_scale, target.scale) / delta_time;

    float red_diff = (target.color.r - new_transform->old_color.r) / delta_time;
    float green_diff = (target.color.g - new_transform->old_color.g) / delta_time;
    float blue_diff = (target.color.b - new_transform->old_color.b) / delta_time;
    float alpha_diff = (target.color.a - new_transform->old_color.a) / delta_time;

    sfVector2f color_red = { new_transform->old_color.r, red_diff };
    sfVector2f color_green = { new_transform->old_color.g, green_diff };
    sfVector2f color_blue = { new_transform->old_color.b, blue_diff };
    sfVector2f color_alpha = { new_transform->old_color.a, alpha_diff };

    new_transform->move_speed = move_speed;
    new_transform->rotation_speed = rotation_speed;
    new_transform->scale_speed = scale_speed;
    new_transform->color_red = color_red;
    new_transform->color_green = color_green;
    new_transform->color_blue = color_blue;
    new_transform->color_alpha = color_alpha;

    linked_add(adata->lists->transforms, new_transform);
}
