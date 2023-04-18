/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

void translate_entity(s_appdata *adata, s_entity *entity, sfVector2f pos_ch)
{
    entity->pos.x += pos_ch.x;
    entity->pos.y += pos_ch.y;

    linked_node *parts = entity->parts;

    while (parts != NULL && parts->data != NULL) {
        s_entity_part *cur = (s_entity_part *) parts->data;

        cur->sprite->pos.x += pos_ch.x;
        cur->sprite->pos.y += pos_ch.y;

        parts = parts->next;
    }
}

void rotate_entity(s_appdata *adata, s_entity *entity, float angle)
{
    linked_node *parts = entity->parts;

    while (parts != NULL && parts->data != NULL) {
        s_entity_part *cur = (s_entity_part *) parts->data;
        float cur_angle = sfSprite_getRotation(cur->sprite->elem);

        cur_angle += angle;

        if (cur_angle > 360.0f) cur_angle -= 360.0f;
        if (cur_angle < 0) cur_angle += 360.0f;

        rotate_sprite(adata, cur->sprite->id, cur_angle);

        parts = parts->next;
    }
}

void rotate_entity_abs(s_appdata *adata, s_entity *entity, float angle)
{
    linked_node *parts = entity->parts;

    while (parts != NULL && parts->data != NULL) {
        s_entity_part *cur = (s_entity_part *) parts->data;

        rotate_sprite(adata, cur->sprite->id, angle);

        parts = parts->next;
    }
}

void rotate_entity_part(s_appdata *adata, s_entity *entity, \
char *part_id, float angle)
{
    linked_node *parts = entity->parts;

    while (parts != NULL && parts->data != NULL) {
        s_entity_part *cur = (s_entity_part *) parts->data;

        if (!my_strcmp(cur->id, part_id)) {
            float cur_angle = sfSprite_getRotation(cur->sprite->elem);

            cur_angle += angle;
            cur_angle = cur_angle > 360.0f ? cur_angle - 360.0f : cur_angle;
            cur_angle = cur_angle < 0 ? cur_angle + 360.0f : cur_angle;

            sfSprite_setRotation(cur->sprite->elem, cur_angle);
        }

        parts = parts->next;
    }
}

void rotate_entity_part_abs(s_appdata *adata, s_entity *entity, \
char *part_id, float angle)
{
    linked_node *parts = entity->parts;

    while (parts != NULL && parts->data != NULL) {
        s_entity_part *cur = (s_entity_part *) parts->data;

        if (!my_strcmp(cur->id, part_id)) {
            sfSprite_setRotation(cur->sprite->elem, angle);
        }

        parts = parts->next;
    }
}
