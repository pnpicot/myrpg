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

void update_entities(s_appdata *adata)
{
    linked_node *entities = adata->game_data->entities;
    int ite = 0;

    while (entities != NULL && entities->data != NULL) {
        s_entity *cur = (s_entity *) entities->data;

        if (cur->dead == 0 && cur->hp <= 0) {
            kill_entities(adata, cur, ite);
            entities = entities->next;
            ++ite;
            continue;
        }
        if (cur->dead == 0) {
            (*cur->behavior)(adata, cur);
        }

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
    set_entity_behavior(adata, "revenant", &behavior_revenant);
}

void init_entity_emiters(s_appdata *adata)
{
    set_entity_emiter(adata, "mf26", &init_mf26_emiter);
}
