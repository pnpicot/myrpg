/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

s_zone *get_zone(s_appdata *adata, char *id)
{
    s_zone **zones = adata->game_data->zones;
    int i = 0;

    while (zones[i] != NULL) {
        if (!my_strcmp(id, zones[i]->id)) {
            return (zones[i]);
        }
        i++;
    }

    return (NULL);
}

sfVector2f get_path(s_appdata *adata, s_entity *entity, s_zone *zone)
{
    linked_node *entities = zone->entities;
    float zoom = get_float(adata, "zoom");

    while (entities != NULL && entities->data != NULL) {
        s_entity *cur = (s_entity *) entities->data;
        float dist = get_vec_dist(cur->pos, entity->pos);
        if (cur->id == NULL) {
            entities = entities->next;
            continue;
        }
        if (!my_strcmp(cur->faction->id, entity->faction->id)) {
            entities = entities->next;
            continue;
        }
        if (dist <= entity->agro_length && my_strcmp(cur->id, entity->id)) {
            sfVector2i pos_zone;
            pos_zone.x = cur->pos.x / ((32 * zoom));
            pos_zone.y = cur->pos.y / ((32 * zoom));
            // entity->path = get_path_finding(adata, entity, pos_zone);
            return (use_path(adata, entity));
        }
        entities = entities->next;
    }

    return ((sfVector2f) {-11.0f, -11.0f});
}

sfVector2f agro_v2(s_appdata *adata, s_entity *entity)
{
    // ...
}

sfVector2f agro(s_appdata *adata, s_entity *entity)
{
    sfVector2i pos;
    pos.x = my_getnbr(&entity->zone->id[5]);
    pos.y = my_getnbr(&entity->zone->id[6]);

    int len_zone_check = entity->agro_length / adata->game_data->size_zone.y + 1;
    int nb_zone_check = 8 * len_zone_check;
    //printf("nb zone = %d\n", nb_zone_check);

    s_zone *zone = entity->zone;
    sfVector2f path = get_path(adata, entity, zone);
    if (path.x != -1.0f && path.y != -1.0f) {
        return (path);
    }

    int origin_x = pos.x;
    int origin_y = pos.y;
    pos.x -= pos.x - 1 == -1 ? 0 : 1;
    pos.y -= pos.y - 1 == -1 ? 0 : 1;
    int origin_x_corner = pos.x;
    int origin_y_corner = pos.y;
    char *s_posx = nbr_to_str(pos.x);
    char *s_posy = nbr_to_str(pos.y);
    char *next_zone_id = str_m_add(3, "zone", s_posx, s_posy);
    free(s_posx);
    free(s_posy);
    zone = get_zone(adata, next_zone_id);
    free(next_zone_id);

    for (int i = 0; i < 9; i++) {
        sfVector2f path = get_path(adata, entity, zone);
        if (path.x != -11.0f && path.y != -11.0f) {
            return (path);
        }

        pos.x++;
        if (pos.x == origin_x) pos.x++;
        if (pos.x == adata->game_data->nb_zones) {
            pos.x = origin_x_corner;
            pos.y += adata->game_data->nb_zones == pos.y + 1 ? 0 : 1;
        }

        s_posx = nbr_to_str(pos.x);
        s_posy = nbr_to_str(pos.y);
        char *next_zone_id = str_m_add(3, "zone", s_posx, s_posy);
        free(s_posx);
        free(s_posy);
        zone = get_zone(adata, next_zone_id);
        free(next_zone_id);
    }

    return ((sfVector2f) {-11.0f, -11.0f});
}
