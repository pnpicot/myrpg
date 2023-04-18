/*
** EPITECH PROJECT, 2023
** m_map_collision
** File description:
** what_is_touching
*/

#include "main.h"

static int _is_colliding(sfFloatRect hitbox, sfFloatRect other)
{
    if (hitbox.left >= other.left + other.width ||
    hitbox.left + hitbox.width <= other.left ||
    hitbox.top >= other.top + other.height ||
    hitbox.top + hitbox.height <= other.top)
        return (0);
    return (1);
}

static void is_touching_wall(s_appdata *adata, sfFloatRect hitbox,
linked_node **touchs)
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
        if (_is_colliding(hitbox, rect)) {
            linked_node *new = linked_new();
            s_touch_t *touch = malloc(sizeof(s_touch_t));
            touch->touch_type = TOUCH_WALL;
            touch->wall = cur;
            new->data = touch;
            new->next = *touchs;
            *touchs = new;
        }
    }
}

static void is_touching_entity(s_appdata *adata, sfFloatRect hitbox,
linked_node **touchs)
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
        if (_is_colliding(hitbox, rect)) {
            linked_node *new = linked_new();
            s_touch_t *touch = malloc(sizeof(s_touch_t));
            touch->touch_type = TOUCH_ENTITY;
            touch->entity = cur;
            new->data = touch;
            new->next = *touchs;
            *touchs = new;
        }
    }
}

linked_node *what_is_touching(s_appdata *adata, sfFloatRect hitbox)
{
    linked_node *touchs = NULL;

    if (adata->player->host == NULL &&
    (hitbox.left != adata->player->hitbox.left ||
    hitbox.top != adata->player->hitbox.top ||
    hitbox.width != adata->player->hitbox.width ||
    hitbox.height != adata->player->hitbox.height) &&
    _is_colliding(hitbox, adata->player->hitbox)) {
        linked_node *new = linked_new();
        s_touch_t *touch = malloc(sizeof(s_touch_t));
        touch->touch_type = TOUCH_PARASITE;
        new->data = touch;
        new->next = touchs;
        touchs = new;
    }
    is_touching_wall(adata, hitbox, &touchs);
    is_touching_entity(adata, hitbox, &touchs);
    return (touchs);
}
