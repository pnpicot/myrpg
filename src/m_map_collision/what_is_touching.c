/*
** EPITECH PROJECT, 2023
** src
** File description:
** map_collision_aa
*/

#include "main.h"

static void add_it(linked_node **node, touch_type_t touch_type,
s_entity *entity)
{
    linked_node *new_node = linked_new();
    s_touch_t *touch = malloc(sizeof(s_touch_t));

    if (new_node == NULL || touch == NULL)
        return;

    touch->touch_type = touch_type;
    touch->entity = entity;
    new_node->data = touch;
    new_node->next = *node;
    *node = new_node;
}

static void already_exist(linked_node **node, touch_type_t touch_type,
s_entity *entity)
{
    linked_node *copy = *node;
    s_touch_t *touch = NULL;

    for (; copy != NULL; copy = copy->next) {
        touch = copy->data;
        if (touch->touch_type == touch_type && touch->entity == entity)
            return;
    }
    add_it(node, touch_type, entity);
}

static void add_to_linked(s_appdata *adata, s_entity *act_entity,
linked_node **node)
{
    if (act_entity == NULL)
        return;
    if (act_entity == (s_entity *)1) {
        already_exist(node, TOUCH_WALL, NULL);
        return;
    }
    if (act_entity == (s_entity *)2) {
        if (adata->player->host == NULL)
            already_exist(node, TOUCH_PARASITE, NULL);
        return;
    }
    if (act_entity->dead == 1)
        return;
    already_exist(node, TOUCH_ENTITY, act_entity);
}

static void do_loop(s_appdata *adata, sfFloatRect hitbox, linked_node **node,
void (*func)(s_appdata *adata, s_entity *act_entity, linked_node **node))
{
    for (int i = hitbox.top; i < (hitbox.top +
    hitbox.height) && i > 0 && i < adata->game_data->col_map_size.y; i++) {
        for (int j = hitbox.left; j < (hitbox.left +
        hitbox.width) && j > 0 && j < adata->game_data->col_map_size.x; j++) {
            func(adata, adata->game_data->col_map[i][j], node);
        }
    }
}

linked_node *what_is_touching(s_appdata *adata, sfFloatRect hitbox)
{
    linked_node *node = NULL;

    do_loop(adata, hitbox, &node, add_to_linked);
    return (node);
}
