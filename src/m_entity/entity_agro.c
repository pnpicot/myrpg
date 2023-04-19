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
<<<<<<< HEAD
            printf("agro from %s to %s\n", entity->id, cur->id);
            float zoom = get_float(adata, "zoom");
=======
>>>>>>> 54e3fc35c637a1e73e0b4537a4df585e7b110eb5
            sfVector2i pos_zone;

            pos_zone.x = cur->pos.x / ((game_data->map_width * 32 * zoom) / game_data->nb_zones);
            pos_zone.y = cur->pos.y / ((game_data->map_height * 32 * zoom) / game_data->nb_zones);
            entity->path = get_path_finding(adata, entity, pos_zone);

            return (use_path(adata, entity));
        }

        entities = entities->next;
    }
<<<<<<< HEAD
    return ((sfVector2f) {-1.0f, -1.0f});
=======

    return ((sfVector2f) { 0, 0 });
>>>>>>> 54e3fc35c637a1e73e0b4537a4df585e7b110eb5
}
