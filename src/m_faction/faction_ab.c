/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** entity
*/

#include "../include/main.h"

s_sprite *sprite_cpy(s_appdata *adata, s_sprite *sprite)
{
    char *id_sprite = str_add(sprite->id, get_random_id(8));
    add_sprite(adata, id_sprite, sprite->layer);

    s_sprite *new_sprite = get_sprite(adata, id_sprite);
    new_sprite->active = sfTrue;
    new_sprite->elem = sfSprite_copy(sprite->elem);
    new_sprite->hidden = sprite->hidden;
    new_sprite->id = id_sprite;
    new_sprite->layer = sprite->layer;
    new_sprite->pos = sprite->pos;
    new_sprite->rtex_id = sprite->rtex_id;
    new_sprite->texture = sprite->texture;

    char *g_obj = str_add(id_sprite, "@[:gobj]");

    add_gameobject(adata, g_obj);
    set_gameobject_ref(adata, g_obj, new_sprite, TYPE_SPRITE);

    return (new_sprite);
}

void add_game_entity(s_appdata *adata, s_entity *entity_model,
s_faction *faction)
{
    char *id_game = str_add(entity_model->id, get_random_id(8));

    add_entity(adata, id_game, 1);
    s_entity *entity = get_entity(adata, id_game, 1);
    entity->sprite = sprite_cpy(adata, entity_model->sprite);
    entity->stats = entity_model->stats;
    entity->active = 1;
    int radius = (int) faction->radius;
    int x = (rand() % (radius * 2)) +
    (faction->pos.x - radius);
    int y = (rand() % (radius * 2)) +
    (faction->pos.y - radius);

    sfVector2f pos = {x, y};
    move_entity(adata, entity->id, pos, 1);
}

void spawn_entities(s_appdata *adata)
{
    int did = 0;
    linked_node *factions = adata->game_data->factions;
    while (factions != NULL && factions->data != NULL) {
        s_faction *faction = (s_faction *) factions->data;

        sfTime time_spawn_faction = sfClock_getElapsedTime(faction->clock_spawn);
        float seconds = time_spawn_faction.microseconds / 1000000.0f;

        if (seconds >= faction->spawn_rate) {
            linked_node *entities_models = adata->game_data->entities_models;

            while(entities_models != NULL && entities_models->data != NULL) {
                s_entity *entity_model = (s_entity *) entities_models->data;

                if (in_str(entity_model->id, faction->id)) {
                    int rate = rand() % 100;
                    if (rate <= entity_model->stats->spawn_rate) {
                        add_game_entity(adata, entity_model, faction);
                    }
                }
                entities_models = entities_models->next;
            }
            sfClock_restart(faction->clock_spawn);
        }
        factions = factions->next;
    }
}