/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

linked_node *get_path_finding(s_appdata *adata, s_entity *entity,
sfVector2i end, sfIntRect hitbox)
{
    if (sqrt(abs(hitbox.left - end.x) + abs(hitbox.top - end.y)) <= 1)
        return (NULL);

    sfVector2i size = {0};
    size.x = adata->game_data->map_width;
    size.y = adata->game_data->map_height;

    return (path_finding(adata->game_data->map, &size, hitbox, end));
}

sfVector2f use_path(s_appdata *adata, s_entity *entity)
{
    sfVector2f path = { 0, 0 };
    float zoom = get_float(adata, "zoom");
    sfVector2i start = { entity->pos.x / (32 * zoom),
    entity->pos.y / (32 * zoom) };

    if (entity->path != NULL && entity->path->data != NULL) {
        path.x = ((sfIntRect *)entity->path->data)->left;
        path.y = ((sfIntRect *)entity->path->data)->top;
        if ((path.x >= 0 || start.x <= ((sfIntRect *)entity->path->data)->width)
        &&
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
s_entity *entity, void (*func)(s_appdata *adata, s_entity *s_entity,
s_particle *particle, linked_node *touchs))
{
    if (adata == NULL || src == NULL || entity == NULL || func == NULL)
        return;
    linked_node *node = src->particle_pool;

    for (;node != NULL; node = node->next) {
        s_particle *part = (s_particle *) node->data;
        if (part == NULL || part->active == sfFalse)
            continue;

        sfFloatRect bounds = sfSprite_getGlobalBounds(part->model);

        bounds.top += adata->game_data->view_pos.y;
        bounds.left += adata->game_data->view_pos.x;

        linked_node *touchs = what_is_touching(adata, bounds);

        if (touchs != NULL && touchs->data != NULL)
            func(adata, entity, part, touchs);

        free_ll_and_data(&touchs);
    }
}

sfVector2f get_way(s_appdata *adata, s_entity *entity, sfVector2i destination)
{
    if (entity->path == NULL) {
        float zoom = get_float(adata, "zoom");
        sfIntRect hitbox = { entity->pos.x / (32 * zoom),
        entity->pos.y / (32 * zoom), 3, 3};
        entity->path = get_path_finding(adata, entity, destination, hitbox);
    }
    sfVector2f rvalue = use_path(adata, entity);
    return (rvalue);
}

sfVector2f actualize_path(s_appdata *adata, s_entity *entity, sfVector2i end)
{
    linked_node *node = entity->path;
    linked_node *closest = node;
    if (entity->path == NULL)
        return (get_way(adata, entity, end));
    while (node->next != NULL) {
        if (sqrt(abs(((sfIntRect *)node->data)->width - end.x) +
        abs(((sfIntRect *)node->data)->height - end.y)) <
        sqrt(abs(((sfIntRect *)closest->data)->width - end.x) +
        abs(((sfIntRect *)closest->data)->height - end.y)))
            closest = node;
        node = node->next;
    } if (closest == entity->path) {
        free_ll_and_data(&entity->path);
        return (get_way(adata, entity, end));
    }
    sfIntRect hitbox = {((sfIntRect *)closest->data)->width,
    ((sfIntRect *)closest->data)->height, 3, 3};
    closest->next = get_path_finding(adata, entity, end, hitbox);
    sfVector2f rvalue = use_path(adata, entity);
    return (rvalue);
}
