/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

int get_rank_id_entities(s_zone *zone, char *id)
{
    int i = 0;
    linked_node *entities = zone->entities;

    while (entities != NULL && entities->data != NULL) {
        s_entity *cur = (s_entity *) entities->data;

        if (cur->id != NULL && id != NULL && !my_strcmp(cur->id, id))
            return (i);

        i++;
        entities = entities->next;
    }

    return (0);
}

void update_zone(s_appdata *adata, s_entity *entity)
{
    sfVector2f pos = entity->pos;
    float zoom = get_float(adata, "zoom");
    sfVector2i pos_zone;

    pos_zone.x = pos.x / ((adata->game_data->map_width * 32 * zoom) / adata->game_data->nb_zones);
    pos_zone.y = pos.y / ((adata->game_data->map_height * 32 * zoom) / adata->game_data->nb_zones);
    pos_zone.x = f_min(adata->game_data->nb_zones - 1, (0, pos_zone.x));
    pos_zone.y = f_min(adata->game_data->nb_zones - 1, (0, pos_zone.y));

    int index = (pos_zone.y * adata->game_data->nb_zones) + pos_zone.x;

    if (entity->zone == NULL || entity->zone->id == NULL ||
        adata->game_data->zones[index]->id == NULL)
        return;

    if (my_strcmp(entity->zone->id, adata->game_data->zones[index]->id)) {
        linked_add(adata->game_data->zones[index]->entities, entity);

        int ite = get_rank_id_entities(entity->zone, entity->id);

        linked_delete(&entity->zone->entities, ite);

        entity->zone = adata->game_data->zones[index];
    }
}

void update_entities(s_appdata *adata)
{
    linked_node *entities = adata->game_data->entities;
    int ite = 0;

    while (entities != NULL && entities->data != NULL) {
        s_entity *cur = (s_entity *) entities->data;

        if (cur->hp <= 0) {
            set_bar_active(adata, cur->hp_bar->id, sfFalse);
            linked_node *parts = cur->parts;
            while (parts != NULL && parts->data != NULL) {
                s_entity_part *part = (s_entity_part *) parts->data;
                sfSprite_setColor(part->sprite->elem, sfColor_fromRGB(50, 50, 50));
                parts = parts->next;
            }
<<<<<<< HEAD
            if (cur == adata->player->host)
                try_transference(adata);
            linked_delete(&adata->game_data->entities, get_rank_id_entities(adata->game_data->entities, cur->id));
            free(cur);
=======
            if (cur->inhabited) try_transference(adata);
>>>>>>> 54e3fc35c637a1e73e0b4537a4df585e7b110eb5
            entities = entities->next;
            if (cur->zone != NULL) {
                int ite = get_rank_id_entities(cur->zone, cur->id);
                linked_delete(&cur->zone->entities, ite);
            }
            linked_delete(&adata->game_data->entities, ite);
            free(cur);
            continue;
        }

        update_zone(adata, cur);

        (*cur->behavior)(adata, cur);

        ite++;
        entities = entities->next;
    }
}

void init_entity_behaviors(s_appdata *adata)
{
    set_entity_behavior(adata, "z200", &behavior_z200);
    set_entity_behavior(adata, "mf26", &behavior_mf26);
    set_entity_behavior(adata, "p800", &behavior_p800);
    set_entity_behavior(adata, "lmx2", &behavior_lmx2);
    set_entity_behavior(adata, "lp230", &behavior_lp230);
}

void init_entity_emiters(s_appdata *adata)
{
    set_entity_emiter(adata, "mf26", &init_mf26_emiter);
}
