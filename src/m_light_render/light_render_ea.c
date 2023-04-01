/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Light rendering module
*/

#include "../include/main.h"

sfBool in_light_range(s_appdata *adata, int depth)
{
    if (adata->mask_rtex == NULL || adata->light_blend_rtex == NULL)
        return (sfFalse);

    int mask_depth = adata->mask_rtex->depth;
    int blend_depth = adata->light_blend_rtex->depth;

    return (depth >= mask_depth && depth <= blend_depth);
}

void set_lightmask_rtex(s_appdata *adata, char *rtex_id)
{
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    adata->mask_rtex = rtex;
}

int dist_cmp(linked_node *first_node, linked_node *second_node)
{
    s_dist *dist_a = (s_dist *) first_node->data;
    s_dist *dist_b = (s_dist *) second_node->data;

    return (dist_a->dist > dist_b->dist);
}

void vec2_sort(sfVector2f *list, int count, sfVector2f pos)
{
    for (int i = 0; i < count - 1; i++) {
        float d_a = get_vec_dist(pos, list[i]);
        float d_b = get_vec_dist(pos, list[i + 1]);

        if (d_a > d_b) {
            sfVector2f tmp = list[i];
            list[i] = list[i + 1];
            list[i + 1] = tmp;

            vec2_sort(list, count, pos);
            break;
        }
    }
}

sfVector2f nearest_point(sfVector2f pos, linked_node *points, int index)
{
    int count = linked_count(points);
    sfVector2f *dists = malloc(sizeof(sfVector2f) * count);
    int ite = 0;

    while (points != NULL && points->data != NULL) {
        sfVector2f *cur = (sfVector2f *) points->data;

        dists[ite] = (sfVector2f) { cur->x, cur->y };

        ite++;
        points = points->next;
    }

    vec2_sort(dists, count, pos);

    return (dists[index]);
}
