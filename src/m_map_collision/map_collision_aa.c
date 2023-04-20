/*
** EPITECH PROJECT, 2023
** src
** File description:
** map_collision_aa
*/

#include "main.h"

static void is_map_colliding_horizontal(s_appdata *adata, s_entity *act_entity,
s_entity *entity, sfVector2f *movement)
{
    if (act_entity == NULL || act_entity == entity || (entity == NULL &&
    act_entity == (s_entity *)2) || (act_entity != (s_entity *)1 &&
    act_entity != (s_entity *)2 && act_entity->dead == 1) ||
    (act_entity == (s_entity *)2 && adata->player->host != NULL))
        return;
    movement->x = 0;
}

static void is_map_colliding_vertical(s_appdata *adata, s_entity *act_entity,
s_entity *entity, sfVector2f *movement)
{
    if (act_entity == NULL || act_entity == entity || (entity == NULL &&
    act_entity == (s_entity *)2) || (act_entity != (s_entity *)1 &&
    act_entity != (s_entity *)2 && act_entity->dead == 1) ||
    (act_entity == (s_entity *)2 && adata->player->host != NULL))
        return;
    movement->y = 0;
}

static void is_map_colliding_base_hitbox(s_appdata *adata, s_entity *act_entity,
s_entity *entity, sfVector2f *movement)
{
    if (act_entity == NULL || act_entity == entity || (entity == NULL &&
    act_entity == (s_entity *)2) || (act_entity != (s_entity *)1 &&
    act_entity != (s_entity *)2 && act_entity->dead == 1) ||
    (act_entity == (s_entity *)2 && adata->player->host != NULL))
        return;
    movement->x = 0;
    movement->y = 0;
}

static sfVector2f do_loop(s_appdata *adata, s_entity *entity,
sfFloatRect rmovement, void (*func)(s_appdata *adata, s_entity *act_entity,
s_entity *entity, sfVector2f *movement))
{
    sfFloatRect hitbox = {0, 0, 0, 0};
    sfVector2f movement = {rmovement.left, rmovement.top};
    sfVector2f new_movement = {rmovement.width, rmovement.height};

    if (entity != NULL)
        hitbox = get_entity_hitbox(adata, entity);
    else
        hitbox = adata->player->hitbox;

    for (int i = hitbox.top + movement.y; i < (hitbox.top + movement.y +
    hitbox.height) && i > 0 && i < adata->game_data->col_map_size.y; i++) {
        for (int j = hitbox.left + movement.x; j < (hitbox.left + movement.x +
        hitbox.width) && j > 0 && j < adata->game_data->col_map_size.x; j++) {
            func(adata, adata->game_data->col_map[i][j], entity, &new_movement);
        }
    }
    return (new_movement);
}

sfVector2f is_map_colliding(s_appdata *adata, s_entity *entity,
sfVector2f movement)
{
    movement = do_loop(adata, entity, (sfFloatRect){0, 0, movement.x,
    movement.y}, is_map_colliding_base_hitbox);
    movement = do_loop(adata, entity, (sfFloatRect){movement.x, 0, movement.x,
    movement.y}, is_map_colliding_horizontal);
    movement = do_loop(adata, entity, (sfFloatRect){0, movement.y, movement.x,
    movement.y}, is_map_colliding_vertical);
    return (movement);
}
