/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

int get_rank_id_entities(linked_node *entities, char *id)
{
    linked_node *tmp = entities;
    int i = 0;

    while (tmp != NULL && tmp->data != NULL) {
        s_entity *cur = (s_entity *) tmp->data;
        if (!my_strcmp(cur->id, id))
            return (i);
        i++;
        tmp = tmp->next;
    }
    return (0);
}

void update_zone(s_appdata *adata, s_entity *entity)
{
    sfVector2f pos = entity->pos;
    sfVector2i pos_zone;
    float zoom = get_float(adata, "zoom");
    pos_zone.x = pos.x / ((adata->game_data->map_width * 32 * zoom) / adata->game_data->nb_zones);
    pos_zone.y = pos.y / ((adata->game_data->map_height* 32 * zoom) / adata->game_data->nb_zones);
    int index = (pos_zone.y * adata->game_data->nb_zones) + pos_zone.x;

    if (my_strcmp(entity->zone->id, adata->game_data->zones[index]->id)) {
        linked_add(adata->game_data->zones[index]->entities, entity);
        linked_delete(&entity->zone->entities, get_rank_id_entities(entity->zone->entities, entity->id));
        entity->zone = adata->game_data->zones[index];
    }
}

void update_entities(s_appdata *adata)
{
    linked_node *entities = adata->game_data->entities;

    while (entities != NULL && entities->data != NULL) {
        s_entity *cur = (s_entity *) entities->data;

        if (cur->hp <= 0) {
            set_bar_active(adata, cur->hp_bar->id, sfFalse);
            linked_node *node = cur->parts;
            while (node != NULL && node->data != NULL) {
                s_entity_part *part = (s_entity_part *) node->data;
                sfSprite_setColor(part->sprite->elem, sfColor_fromRGB(50, 50, 50));
                node = node->next;
            }
            if (cur == adata->player->host)
                try_transference(adata);
            linked_delete(&adata->game_data->entities, get_rank_id_entities(adata->game_data->entities, cur->id));
            free(cur);
            entities = entities->next;
            continue;
        }

        update_zone(adata, cur);

        (*cur->behavior)(adata, cur);

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
