/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

void behavior_p800(s_appdata *adata, s_entity *entity)
{
    linked_node *parts = entity->parts;
    update_entity_bar(adata, entity);
    sfVector2f path = { 0, 0 };
    get_p800_path(adata, entity, &path);
    if (entity->init) behavior_p800_init(adata, entity);
    parts = parts->next;
    char *blade_id = ((s_entity_part *) parts->data)->sprite->id;
    float angle;
    behavior_p800_next(adata, entity, path, &angle);
    if (entity->move_now_entity != NULL) {
        entity->move_now.x = 0;
        entity->move_now.y = 0;
        entity->move_now_entity = NULL;
    }
    behavior_p800_blade(adata, entity, angle);
    sfClock_restart(entity->clock);
}
