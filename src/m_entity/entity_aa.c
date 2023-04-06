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
    new_entity->body_part = linked_new();
    new_entity->stats = malloc(sizeof(s_entity_stats));
    new_entity->clock_move = sfClock_create();

    if (!mode)
        linked_add(adata->game_data->entities_models, new_entity);
    if (mode)
        linked_add(adata->game_data->entities, new_entity);
}

void set_entity_sprite(s_appdata *adata, char *id, char *texture_id, char *entity_sprite_id)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }
    add_sprite(adata, entity_sprite_id, 1);
    sfTexture *texture = get_texture(adata, texture_id);
    set_sprite_texture(adata, entity_sprite_id, texture);

    linked_add(entity->body_part, get_sprite(adata, entity_sprite_id));
}

void set_entity_layer(s_appdata *adata, char *id, int index, int layer)
{
    s_entity *entity = get_entity(adata, id, 0);

    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    int i = 0;
    linked_node *body_part = entity->body_part;
    while (body_part != NULL && body_part->data != NULL) {
        s_sprite *sprite = (s_sprite *) body_part->data;

        if (i == index) {
            sprite->layer = layer;
        }

        i++;
        body_part = body_part->next;
    }
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
