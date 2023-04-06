/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "../include/main.h"

void set_entity_animation_cols(s_appdata *adata, char *id, int cols)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *body_part = entity->body_part;
    while (body_part != NULL && body_part->data != NULL) {
        s_sprite *sprite = (s_sprite *) body_part->data;

        set_animation_cols(adata, sprite->id, cols);

        body_part = body_part->next;
    }
}

void set_entity_animation_rows(s_appdata *adata, char *id, int rows)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *body_part = entity->body_part;
    while (body_part != NULL && body_part->data != NULL) {
        s_sprite *sprite = (s_sprite *) body_part->data;

        set_animation_rows(adata, sprite->id, rows);

        body_part = body_part->next;
    }
}

void set_entity_animation_speed(s_appdata *adata, char *id, int speed)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *body_part = entity->body_part;
    while (body_part != NULL && body_part->data != NULL) {
        s_sprite *sprite = (s_sprite *) body_part->data;

        set_animation_speed(adata, sprite->id, speed);

        body_part = body_part->next;
    }
}

void set_entity_animation_mode(s_appdata *adata, char *id, int mode)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *body_part = entity->body_part;
    while (body_part != NULL && body_part->data != NULL) {
        s_sprite *sprite = (s_sprite *) body_part->data;

        set_animation_mode(adata, sprite->id, mode);

        body_part = body_part->next;
    }
}
