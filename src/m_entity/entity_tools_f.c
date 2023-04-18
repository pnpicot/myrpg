/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

linked_node *get_path_finding(s_appdata *adata, s_entity *entity,
sfVector2i start, sfVector2i end)
{
    sfIntRect from;
    from.left = start.x;
    from.top = start.y;
    from.width = 3;
    from.height = 3;

    sfVector2i *size = malloc(sizeof(sfVector2i));
    size->x = adata->game_data->map_width;
    size->y = adata->game_data->map_height;

    return (path_finding(adata->game_data->map, size, from, end));
}

sfVector2f use_path(s_appdata *adata, s_entity *entity, sfVector2i start)
{
    sfVector2f path = { 0, 0 };

    if (entity->path != NULL && entity->path->data != NULL) {
        path.x = ((sfIntRect *)entity->path->data)->left;
        path.y = ((sfIntRect *)entity->path->data)->top;
        if ((path.x >= 0 || start.x <= ((sfIntRect *)entity->path->data)->width) &&
        (path.x <= 0 || start.x >= ((sfIntRect *)entity->path->data)->width) &&
        (path.y >= 0 || start.y <= ((sfIntRect *)entity->path->data)->height) &&
        (path.y <= 0 || start.y >= ((sfIntRect *)entity->path->data)->height)) {
            free(entity->path->data);
            linked_node *save = entity->path;
            entity->path = entity->path->next;
            free(save);
        }
    }
    return (path);
}

void do_particle_behavior(s_appdata *adata, s_particle_src *src,
void (*func)(s_appdata *adata, s_particle_src *particle_src,
s_particle *particle, linked_node *touchs))
{
    if (adata == NULL || src == NULL || func == NULL)
        return;
    linked_node *node = src->particle_pool;

    for (;node != NULL; node = node->next) {
        s_particle *part = (s_particle *) node->data;
        if (part == NULL || part->active == sfFalse)
            continue;

        sfFloatRect bounds = sfSprite_getGlobalBounds(part->model);

        linked_node *touchs = what_is_touching(adata, bounds);

        if (touchs != NULL && touchs->data != NULL)
            func(adata, src, part, touchs);

        free_ll_and_data(&touchs);
    }
}
