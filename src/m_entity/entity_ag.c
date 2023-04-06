/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** entity
*/

#include "../include/main.h"

s_entity *get_entity_by_model(s_appdata *adata, char *model_id, int mode)
{
    linked_node *entities;
    if (!mode)
        entities = adata->game_data->entities_models;
    if (mode)
        entities = adata->game_data->entities;

    while (entities != NULL && entities->data != NULL) {
        s_entity *cur = (s_entity *) entities->data;

        if (!my_strcmp(cur->stats->type, model_id)) return (cur);

        entities = entities->next;
    }

    return (NULL);
}

void set_entity_spawn_rate(s_appdata *adata, char *id, int spawn_rate)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    entity->stats->spawn_rate = spawn_rate;
}

void set_entity_behavior(s_appdata *adata, char *entity_type,
void (*behavior)(s_appdata *adata, s_entity *entity))
{
}
