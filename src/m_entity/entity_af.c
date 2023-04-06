/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "../include/main.h"

sfFloatRect get_entity_bounds(s_appdata *adata, char *id, int rank)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfFloatRect) { -1, -1, -1, -1 });
    }

    int i = 0;
    linked_node *body_part = entity->body_part;
    while (body_part != NULL && body_part->data != NULL) {
        s_sprite *sprite = (s_sprite *) body_part->data;

        if (i == rank)
            return (get_sprite_bounds(adata, sprite->id));

        i++;
        body_part = body_part->next;
    }

    return ((sfFloatRect) { -1, -1, -1, -1 });
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

sfVector2f get_entity_scale(s_appdata *adata, char *id, int rank)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    int i = 0;
    linked_node *body_part = entity->body_part;
    while (body_part != NULL && body_part->data != NULL) {
        s_sprite *sprite = (s_sprite *) body_part->data;

        if (i == rank)
            return (get_sprite_scale(adata, sprite->id));

        i++;
        body_part = body_part->next;
    }

    return ((sfVector2f) { -1, -1 });
}

float get_entity_rotation(s_appdata *adata, char *id, int rank)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (-1);
    }

    int i = 0;
    linked_node *body_part = entity->body_part;
    while (body_part != NULL && body_part->data != NULL) {
        s_sprite *sprite = (s_sprite *) body_part->data;

        if (i == rank)
            return (get_sprite_rotation(adata, sprite->id));

        i++;
        body_part = body_part->next;
    }

    return (-1);
}
