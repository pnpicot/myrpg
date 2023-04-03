/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** entity
*/

#include "../include/main.h"

sfFloatRect get_entity_bounds(s_appdata *adata, char *id)
{
    s_entity *entity = get_entity(adata, id);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfFloatRect) { -1, -1, -1, -1 });
    }

    return (get_sprite_bounds(adata, entity->sprite->id));
}

/* sfVector2f get_entity_origin(s_appdata *adata, char *id)
{
    s_entity *entity = get_entity(adata, id);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    return (get_sprite_origin(adata, entity->sprite->id));
} */

sfVector2f get_entity_scale(s_appdata *adata, char *id)
{
    s_entity *entity = get_entity(adata, id);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (get_sprite_scale(adata, entity->sprite->id));
}

float get_entity_rotation(s_appdata *adata, char *id)
{
    s_entity *entity = get_entity(adata, id);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (-1);
    }

    return (get_sprite_rotation(adata, entity->sprite->id));
}
