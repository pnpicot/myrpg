/*
** EPITECH PROJECT, 2023
** src
** File description:
** map_collision_aa
*/

#include "main.h"

static int is_map_colliding_horizontal(s_appdata *adata, s_entity *act_entity,
s_entity *entity, sfVector2f *movement)
{
    if (act_entity == NULL || act_entity == entity || (entity == NULL &&
    act_entity == (s_entity *)2) || (act_entity != (s_entity *)1 &&
    act_entity != (s_entity *)2 && act_entity->dead == 1) ||
    (act_entity == (s_entity *)2 && adata->player->host != NULL) ||
    (entity != NULL && act_entity == entity->move_now_entity))
        return (0);
    if (act_entity == (s_entity *)1 || act_entity == (s_entity *)2) {
        movement->x = 0;
        return (1);
    }
    sfFloatRect hitbox = (entity == NULL) ? adata->player->hitbox :
    get_entity_hitbox(adata, entity);
    sfFloatRect ahitbox = get_entity_hitbox(adata, act_entity);

    movement->x = (hitbox.left + hitbox.width - ahitbox.left < 0) ? 1 : -1;
    act_entity->move_now.x = movement->x;
    act_entity->move_now_entity = (entity == NULL) ? (s_entity *)2 : entity;
    return (0);
}

static int is_map_colliding_vertical(s_appdata *adata, s_entity *act_entity,
s_entity *entity, sfVector2f *movement)
{
    if (act_entity == NULL || act_entity == entity || (entity == NULL &&
    act_entity == (s_entity *)2) || (act_entity != (s_entity *)1 &&
    act_entity != (s_entity *)2 && act_entity->dead == 1) ||
    (act_entity == (s_entity *)2 && adata->player->host != NULL) ||
    (entity != NULL && act_entity == entity->move_now_entity))
        return (0);
    if (act_entity == (s_entity *)1 || act_entity == (s_entity *)2) {
        movement->y = 0;
        return (1);
    }
    sfFloatRect hitbox = (entity == NULL) ? adata->player->hitbox :
    get_entity_hitbox(adata, entity);
    sfFloatRect ahitbox = get_entity_hitbox(adata, act_entity);

    movement->y = (hitbox.top + hitbox.height - ahitbox.top < 0) ? 1 : -1;
    act_entity->move_now.y = movement->y;
    act_entity->move_now_entity = (entity == NULL) ? (s_entity *)2 : entity;
    return (0);
}

static int is_map_colliding_base_hitbox(s_appdata *adata, s_entity *act_entity,
s_entity *entity, sfVector2f *movement)
{
    if (act_entity == NULL || act_entity == entity || (entity == NULL &&
    act_entity == (s_entity *)2) || (act_entity != (s_entity *)1 &&
    act_entity != (s_entity *)2 && act_entity->dead == 1) ||
    (act_entity == (s_entity *)2 && adata->player->host != NULL) ||
    (entity != NULL && act_entity == entity->move_now_entity))
        return (0);
    if (act_entity == (s_entity *)1 || act_entity == (s_entity *)2) {
        movement->x = 0;
        movement->y = 0;
        return (1);
    }
    sfFloatRect hitbox = (entity == NULL) ? adata->player->hitbox :
    get_entity_hitbox(adata, entity);
    sfFloatRect ahitbox = get_entity_hitbox(adata, act_entity);

    movement->x = (hitbox.left + hitbox.width - ahitbox.left < 0) ? -1 : 1;
    movement->y = (hitbox.top + hitbox.height - ahitbox.top < 0) ? -1 : 1;
    act_entity->move_now = (sfVector2f){-movement->x, -movement->y};
    act_entity->move_now_entity = (entity == NULL) ? (s_entity *)2 : entity;
    return (0);
}

static sfVector2f do_loop(s_appdata *adata, s_entity *entity,
sfFloatRect rmovement, int (*func)(s_appdata *adata, s_entity *act_entity,
s_entity *entity, sfVector2f *movement))
{
    sfFloatRect hitbox = {0, 0, 0, 0};
    sfVector2f movement = {rmovement.left, rmovement.top};
    sfVector2f new_movement = {rmovement.width, rmovement.height};
    int rvalue = 0;

    if (entity != NULL)
        hitbox = get_entity_hitbox(adata, entity);
    else
        hitbox = adata->player->hitbox;

    for (int i = hitbox.top + movement.y; i < (hitbox.top + movement.y +
    hitbox.height) && i >= 0 && i < adata->game_data->col_map_size.y; i++) {
        for (int j = hitbox.left + movement.x; j < (hitbox.left + movement.x +
        hitbox.width) && j >= 0 && j < adata->game_data->col_map_size.x; j++) {
            rvalue = func(adata, adata->game_data->col_map[i][j],
            entity, &new_movement);
            j = (rvalue == 1) ? -11 : j;
        }
    }
    return (new_movement);
}

sfVector2f is_map_colliding(s_appdata *adata, s_entity *entity,
sfVector2f movement)
{
    movement = do_loop(adata, entity, (sfFloatRect){0, 0, movement.x,
    movement.y}, is_map_colliding_base_hitbox);
    if (movement.x == 0 && movement.y == 0)
        return (movement);
    movement = do_loop(adata, entity, (sfFloatRect){movement.x, 0, movement.x,
    movement.y}, is_map_colliding_horizontal);
    if (movement.x == 0 && movement.y == 0)
        return (movement);
    movement = do_loop(adata, entity, (sfFloatRect){0, movement.y, movement.x,
    movement.y}, is_map_colliding_vertical);
    return (movement);
}
