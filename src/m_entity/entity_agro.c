/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

sfVector2f agro(s_appdata *adata, s_entity *entity)
{
    s_zone *zone = entity->zone;

    linked_node *entities = zone->entities;

    float zoom = get_float(adata, "zoom");
    s_game *game_data = adata->game_data;

    while (entities != NULL && entities->data != NULL) {
        s_entity *cur = (s_entity *) entities->data;
        float dist = get_vec_dist(cur->pos, entity->pos);
        if (cur->id == NULL) {
            entities = entities->next;
            continue;
        }
        if (dist <= entity->agro_length && my_strcmp(cur->id, entity->id)) {
            sfVector2i pos_zone;
            pos_zone.x = cur->pos.x / ((32 * zoom));
            pos_zone.y = cur->pos.y / ((32 * zoom));
            entity->path = get_path_finding(adata, entity, pos_zone);
            return (use_path(adata, entity));
        }
        entities = entities->next;
    }
    
    return ((sfVector2f) {-1.0f, -1.0f});
}
