/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "../include/main.h"

void move_entity(s_appdata *adata, char *id, sfVector2f pos, int mode)
{
    s_entity *entity = get_entity(adata, id, mode);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *body_part = entity->body_part;
    while (body_part != NULL && body_part->data != NULL) {
        s_sprite *sprite = (s_sprite *) body_part->data;

        move_sprite(adata, sprite->id, pos);

        body_part = body_part->next;
    }
}

void translate_entity(s_appdata *adata, char *id, sfVector2f add)
{
    s_entity *entity = get_entity(adata, id, 1);

    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *body_part = entity->body_part;

    while (body_part != NULL && body_part->data != NULL) {
        s_sprite *sprite = (s_sprite *) body_part->data;

        translate_sprite(adata, sprite->id, add);

        body_part = body_part->next;
    }
}

void rotate_entity(s_appdata *adata, char *id, float angle)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *body_part = entity->body_part;
    while (body_part != NULL && body_part->data != NULL) {
        s_sprite *sprite = (s_sprite *) body_part->data;

        rotate_sprite(adata, sprite->id, angle);

        body_part = body_part->next;
    }
}
