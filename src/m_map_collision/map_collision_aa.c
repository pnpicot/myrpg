/*
** EPITECH PROJECT, 2023
** src
** File description:
** map_collision_aa
*/

#include "main.h"

static void _is_colliding_p2(sfFloatRect hitbox, sfFloatRect other,
sfVector2f *movement)
{
    if (hitbox.left + movement->x >= other.left + other.width ||
    hitbox.left + movement->x + hitbox.width <= other.left ||
    hitbox.top >= other.top + other.height ||
    hitbox.top + hitbox.height <= other.top) {
        movement->y = (movement->y > 0) ? other.top - hitbox.height -
        hitbox.top : other.top + other.height - hitbox.top ;
        return;
    }
    movement->y = (movement->y > 0) ? other.top - hitbox.height -
    hitbox.top : other.top + other.height - hitbox.top;
    movement->x = (movement->x > 0) ? other.left - hitbox.width -
    hitbox.left : other.left + other.width - hitbox.left;

    movement->y = (movement->y < -0.25) ? -0.25 : movement->y;
    movement->y = (movement->y > 0.25) ? 0.25 : movement->y;
    movement->x = (movement->x < -0.25) ? -0.25 : movement->x;
    movement->x = (movement->x > 0.25) ? 0.25 : movement->x;
}

static void _is_colliding(sfFloatRect hitbox, sfFloatRect other,
sfVector2f *movement)
{
    if (hitbox.left + movement->x >= other.left + other.width ||
    hitbox.left + movement->x + hitbox.width <= other.left ||
    hitbox.top + movement->y >= other.top + other.height ||
    hitbox.top + movement->y + hitbox.height <= other.top)
        return;
    if (hitbox.left >= other.left + other.width ||
    hitbox.left + hitbox.width <= other.left ||
    hitbox.top + movement->y >= other.top + other.height ||
    hitbox.top + movement->y + hitbox.height <= other.top) {
        movement->x = (movement->x > 0) ? other.left - hitbox.width -
        hitbox.left : other.left + other.width - hitbox.left;
        return;
    }
    _is_colliding_p2(hitbox, other, movement);
}

static void is_map_colliding_wall(s_appdata *adata, sfFloatRect hitbox,
sfVector2f *movement)
{
    linked_node *walls = adata->lists->walls;

    for (;walls != NULL; walls = walls->next) {
        if (walls->data == NULL)
            continue;

        s_wall *cur = (s_wall *)walls->data;
        sfFloatRect rect = sfRectangleShape_getGlobalBounds(cur->hitbox->elem);

        if (hitbox.left == rect.left && hitbox.top == rect.top && hitbox.width
        == rect.width && hitbox.height == rect.height)
            continue;
        _is_colliding(hitbox, rect, movement);
        if (movement->x == 0 && movement->y == 0)
            return;
    }
}

static void is_map_colliding_entity(s_appdata *adata, sfFloatRect hitbox,
sfVector2f *movement)
{
    linked_node *entity = adata->game_data->entities;

    for (;entity != NULL; entity = entity->next) {
        if (entity->data == NULL)
            continue;

        s_entity *cur = (s_entity *) entity->data;

        sfFloatRect rect = get_entity_hitbox(adata, cur);

        if (hitbox.left == rect.left && hitbox.top == rect.top && hitbox.width
        == rect.width && hitbox.height == rect.height)
            continue;
        _is_colliding(hitbox, rect, movement);
        if (movement->x == 0 && movement->y == 0)
            return;
    }
}

sfVector2f is_map_colliding(s_appdata *adata, sfFloatRect hitbox,
sfVector2f movement)
{
    sfVector2f save = movement;

    if (adata->player->host == NULL && (
    hitbox.left != adata->player->hitbox.left ||
    hitbox.top != adata->player->hitbox.top ||
    hitbox.width != adata->player->hitbox.width ||
    hitbox.height != adata->player->hitbox.height))
        _is_colliding(hitbox, adata->player->hitbox, &movement);
    if (movement.x == 0 && movement.y == 0)
        return (movement);
    is_map_colliding_wall(adata, hitbox, &movement);
    if (movement.x == 0 && movement.y == 0)
        return (movement);
    is_map_colliding_entity(adata, hitbox, &movement);

    return (movement);
}
