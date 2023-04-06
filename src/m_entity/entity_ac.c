/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "../include/main.h"

void set_entity_active(s_appdata *adata, char *id, sfUint8 active)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *body_part = entity->body_part;
    while (body_part != NULL && body_part->data != NULL) {
        s_sprite *sprite = (s_sprite *) body_part->data;

        sprite->active = active;

        body_part = body_part->next;
    }
}

void set_entity_scale(s_appdata *adata, char *id, sfVector2f scale)
{
    s_entity *entity = get_entity(adata, id, 1);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *body_part = entity->body_part;
    while (body_part != NULL && body_part->data != NULL) {
        s_sprite *sprite = (s_sprite *) body_part->data;

        scale_sprite(adata, sprite->id, scale);

        body_part = body_part->next;
    }

}

void set_entity_origin(s_appdata *adata, char *id, sfVector2f origin)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *body_part = entity->body_part;
    while (body_part != NULL && body_part->data != NULL) {
        s_sprite *sprite = (s_sprite *) body_part->data;

        set_sprite_origin(adata, sprite->id, origin);

        body_part = body_part->next;
    }
}

void set_entity_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_entity *entity = get_entity(adata, id, 0);
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (entity == NULL || rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *body_part = entity->body_part;
    while (body_part != NULL && body_part->data != NULL) {
        s_sprite *sprite = (s_sprite *) body_part->data;

        set_sprite_rtex(adata, sprite->id, rtex->id);

        body_part = body_part->next;
    }
}

void set_entity_stats_type(s_appdata *adata, char *id, char *type)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    entity->stats->type = type;
}
