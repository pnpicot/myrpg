/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** entity
*/

#include "../include/main.h"

void move_entity(s_appdata *adata, char *id, sfVector2f pos)
{
    s_entity *entity = get_entity(adata, id);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    move_sprite(adata, entity->sprite->id, pos);
}

void translate_entity(s_appdata *adata, char *id, sfVector2f add)
{
    s_entity *entity = get_entity(adata, id);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    translate_sprite(adata, entity->sprite->id, add);
}

void rotate_entity(s_appdata *adata, char *id, float angle)
{
    s_entity *entity = get_entity(adata, id);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    rotate_sprite(adata, entity->sprite->id, angle);
}
