/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Transform module
*/

#include "../include/main.h"

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

void delete_transform_next(s_appdata *adata, s_transform *cur)
{
    free(cur->ref);
    sfClock_destroy(cur->move_clock);
    sfClock_destroy(cur->rot_clock);
    sfClock_destroy(cur->scale_clock);
    sfClock_destroy(cur->color_clock);
    sfClock_destroy(cur->end_clock);
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
            delete_transform_next(adata, cur);
            break;
        }
        ite++;
        transforms = transforms->next;
    }
    linked_delete(&adata->lists->transforms, ite);
}

void transform_move(s_appdata *adata, s_transform *trf)
{
    sfVector2f dist_vec;
    dist_vec.x = trf->target_pos.x - trf->old_pos.x;
    dist_vec.y = trf->target_pos.y - trf->old_pos.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));
    float delta = get_clock_seconds(trf->move_clock);

    trf->old_pos.x += ((trf->move_speed * delta) / dist) * dist_vec.x;
    trf->old_pos.y += ((trf->move_speed * delta) / dist) * dist_vec.y;

    move_element(adata, trf->ref->ref, trf->ref->type, trf->old_pos);
    sfClock_restart(trf->move_clock);
}

void transform_scale(s_appdata *adata, s_transform *trf)
{
    float delta = get_clock_seconds(trf->scale_clock);
    sfVector2f dist_vec;

    dist_vec.x = trf->target_scale.x - trf->old_scale.x;
    dist_vec.y = trf->target_scale.y - trf->old_scale.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));

    trf->old_scale.x += ((trf->scale_speed * delta) / dist) * dist_vec.x;
    trf->old_scale.y += ((trf->scale_speed * delta) / dist) * dist_vec.y;

    scale_element(adata, trf->ref->ref, trf->ref->type, trf->old_scale);
    sfClock_restart(trf->scale_clock);
}
