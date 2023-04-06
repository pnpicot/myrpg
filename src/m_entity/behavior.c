/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entities behavior initialization
*/

#include "main.h"

void update_entities(s_appdata *adata)
{
    linked_node *entities = adata->game_data->entities;

    while (entities != NULL && entities->data != NULL) {
        s_entity *cur = (s_entity *) entities->data;

        if (cur->behavior == NULL || !cur->active) {
            entities = entities->next;
            continue;
        }

        (*cur->behavior)(adata, cur);

        entities = entities->next;
    }
}

void set_entities_behaviors(s_appdata *adata)
{
    set_entity_behavior(adata, "b40", &B40_bevahior);
}
