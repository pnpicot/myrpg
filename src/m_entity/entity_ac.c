/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** entity
*/

#include "../include/main.h"

void set_entity_active(s_appdata *adata, char *id, sfUint8 active)
{
    s_entity *entity = get_entity(adata, id);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    entity->sprite->active = active;
}

void set_entity_scale(s_appdata *adata, char *id, sfVector2f scale)
{
    s_entity *entity = get_entity(adata, id);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    scale_sprite(adata, entity->sprite->id, scale);
}

void set_entity_origin(s_appdata *adata, char *id, sfVector2f origin)
{
    s_entity *entity = get_entity(adata, id);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    set_sprite_origin(adata, entity->sprite->id, origin);
}

void set_entity_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_entity *entity = get_entity(adata, id);
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (entity == NULL || rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    set_sprite_rtex(adata, entity->sprite->id, rtex->id);
}
