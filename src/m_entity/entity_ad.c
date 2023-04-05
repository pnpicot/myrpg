/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** entity
*/

#include "../include/main.h"

void set_entity_animation_cols(s_appdata *adata, char *id, int cols)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    set_animation_cols(adata, entity->sprite->id, cols);
}

void set_entity_animation_rows(s_appdata *adata, char *id, int rows)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    set_animation_rows(adata, entity->sprite->id, rows);
}

void set_entity_animation_speed(s_appdata *adata, char *id, int speed)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    set_animation_speed(adata, entity->sprite->id, speed);
}

void set_entity_animation_mode(s_appdata *adata, char *id, int mode)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    set_animation_mode(adata, entity->sprite->id, mode);
}
