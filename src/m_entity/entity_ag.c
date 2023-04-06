/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
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

s_sprite *get_sprite_by_body_part(s_appdata *adata, s_entity *entity, char *body_part_id)
{
    linked_node *body_part = entity->body_part;

    while (body_part != NULL && body_part->data != NULL) {
        s_sprite *cur = (s_sprite *) body_part->data;

        if (!my_strcmp(cur->id, body_part_id)) return (cur);

        body_part = body_part->next;
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
    s_entity *model = get_entity_by_model(adata, entity_type, 0);

    if (model == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    model->behavior = behavior;
}
