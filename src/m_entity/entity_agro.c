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

    while (entities != NULL && entities->data != NULL) {
        s_entity *cur = (s_entity *) entities->data;

        float dist = get_vec_dist(cur->pos, entity->pos);

        if (dist <= entity->agro_length) {
            float zoom = get_float(adata, "zoom");
            sfVector2i pos_zone;
            pos_zone.x = cur->pos.x / ((adata->game_data->map_width * 32 * zoom) / adata->game_data->nb_zones);
            pos_zone.y = cur->pos.y / ((adata->game_data->map_height * 32 * zoom) / adata->game_data->nb_zones);
            entity->path = get_path_finding(adata, entity, pos_zone);
            return (use_path(adata, entity));
        }
        entities = entities->next;
    }
    return ((sfVector2f) {0, 0});
}
