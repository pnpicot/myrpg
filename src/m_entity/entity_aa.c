/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** entity
*/

#include "../include/main.h"

s_entity *get_entity(s_appdata *adata, char *id, int mode)
{
    linked_node *entities;
    if (!mode)
        entities = adata->game_data->entities_models;
    if (mode)
        entities = adata->game_data->entities;

    while (entities != NULL && entities->data != NULL) {
        s_entity *cur = (s_entity *) entities->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        entities = entities->next;
    }

    return (NULL);
}

void add_entity(s_appdata *adata, char *id, int mode)
{
    s_entity *entity = get_entity(adata, id, mode);
    if (entity != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    s_entity *new_entity = malloc(sizeof(s_entity));

    new_entity->active = sfTrue;
    new_entity->id = id;
    new_entity->sprite = malloc(sizeof(s_sprite));
    new_entity->stats = malloc(sizeof(s_entity_stats));

    if (!mode)
        linked_add(adata->game_data->entities_models, new_entity);
    if (mode)
        linked_add(adata->game_data->entities, new_entity);
}

void set_entity_sprite(s_appdata *adata, char *id, char *texture_id)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    char *id_sprite = str_add(id, "@[:sprite]");
    add_sprite(adata, id_sprite, 1);
    sfTexture *texture = get_texture(adata, texture_id);
    set_sprite_texture(adata, id_sprite, texture);

    entity->sprite = get_sprite(adata, id_sprite);
}

void set_entity_layer(s_appdata *adata, char *id, int layer)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    entity->sprite->layer = layer;
}

void set_entity_stats(s_appdata *adata, char *id)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }
    s_entity_stats *stats = malloc(sizeof(s_entity_stats));
    if (stats == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
    }
    stats->dammage = 0;
    stats->hp = 0;
    stats->faction = NULL;
    stats->transference_level = 0;
    entity->stats = stats;
}
