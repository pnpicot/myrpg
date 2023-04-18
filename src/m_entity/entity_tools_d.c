/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

// ! Collision map, not sure to keep
// void update_entity_collision_map(s_appdata *adata, s_entity *entity, sfVector2f pos_ch)
// {
//     if (entity->pos.x < 0 || entity->pos.y < 0 ||
//     (entity->pos.x + pos_ch.x) < 0 || (entity->pos.y + pos_ch.y) < 0)
//         return;
//     for (int i = entity->pos.y; i < (entity->pos.y + entity->hitbox.height) && i > 0 && i < adata->game_data->col_map_size.y; i++) {
//         for (int j = entity->pos.x; j < (entity->pos.x + entity->hitbox.width) && j > 0 && j < adata->game_data->col_map_size.x; j++) {
//             adata->game_data->col_map[i][j] = NULL;
//         }
//     }
//     for (int i = (entity->pos.y + entity->hitbox.height); i > entity->pos.y && i > 0 && i < adata->game_data->col_map_size.y; i--) {
//         for (int j =  (entity->pos.x + entity->hitbox.width); j > entity->pos.x && j > 0 && j < adata->game_data->col_map_size.x; j--) {
//             adata->game_data->col_map[i][j] = NULL;
//         }
//     }
//     for (int i = (entity->pos.y + pos_ch.y); i < ((entity->pos.y + pos_ch.y) + entity->hitbox.height) && i > 0 && i < adata->game_data->col_map_size.y; i++) {
//         for (int j = (entity->pos.x + pos_ch.x); j < ((entity->pos.x + pos_ch.x) + entity->hitbox.width) && j > 0 && j < adata->game_data->col_map_size.x; j++) {
//             adata->game_data->col_map[i][j] = entity;
//         }
//     }
//     for (int i = ((entity->pos.y + pos_ch.y) + entity->hitbox.height) ; i > (entity->pos.y + pos_ch.y) && i > 0 && i < adata->game_data->col_map_size.y; i--) {
//         for (int j = ((entity->pos.x + pos_ch.x) + entity->hitbox.width); j > (entity->pos.x + pos_ch.x) && j > 0 && j < adata->game_data->col_map_size.x; j--) {
//             adata->game_data->col_map[i][j] = entity;
//         }
//     }
// }

void translate_entity(s_appdata *adata, s_entity *entity, sfVector2f pos_ch)
{
    // update_entity_collision_map(adata, entity, pos_ch);
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
