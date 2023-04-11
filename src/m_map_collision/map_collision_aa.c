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
    movement->x = 0;
    movement->y = 0;
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
        sfFloatRect rect = sfSprite_getGlobalBounds(
        ((s_sprite *)cur->parts->data)->elem);

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
    if (hitbox.left != 910 || hitbox.top != 490
    || hitbox.width != 100 || hitbox.height != 100)
        _is_colliding(hitbox, (sfFloatRect){910, 490, 100, 100}, &movement);
    if (movement.x == 0 && movement.y == 0)
        return (movement);
    is_map_colliding_wall(adata, hitbox, &movement);
    if (movement.x == 0 && movement.y == 0)
        return (movement);
    is_map_colliding_entity(adata, hitbox, &movement);
    if (hitbox.left == 910 && hitbox.top == 490
    && hitbox.width == 100 && hitbox.height == 100)
    return (movement);
}
