/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** entity
*/

#include "../include/main.h"

linked_node *body_part_cpy(s_appdata *adata, linked_node *body_part, char *rand_id)
{
    linked_node *body_part_model = body_part;
    linked_node *new_body_part = linked_new();

    while (body_part_model != NULL && body_part_model->data != NULL) {
        s_sprite *sprite = (s_sprite *) body_part_model->data;

        char *entity_sprite_id = replace_id(sprite->id, 0, rand_id);

        add_sprite(adata, entity_sprite_id, sprite->layer);
        s_sprite *new_sprite = get_sprite(adata, entity_sprite_id);
        new_sprite->active = sfTrue;
        new_sprite->elem = sfSprite_copy(sprite->elem);
        new_sprite->hidden = sprite->hidden;
        new_sprite->id = entity_sprite_id;
        new_sprite->layer = sprite->layer;
        new_sprite->pos = sprite->pos;
        new_sprite->rtex_id = sprite->rtex_id;
        new_sprite->texture = sprite->texture;

        char *g_obj = str_add(entity_sprite_id, "@[:gobj]");
        add_gameobject(adata, g_obj);
        set_gameobject_ref(adata, g_obj, new_sprite, TYPE_SPRITE);

        linked_add(new_body_part, new_sprite);
        body_part_model = body_part_model->next;
    }

    return (new_body_part);
}

void add_game_entity(s_appdata *adata, s_entity *entity_model,
s_faction *faction)
{
    char *rand_id = get_random_id(8);
    char *new_entity_id = replace_id(entity_model->id, 0, rand_id);

    add_entity(adata, new_entity_id, 1);

    s_entity *entity = get_entity(adata, new_entity_id, 1);

    entity->body_part = body_part_cpy(adata, entity_model->body_part, rand_id);
    entity->stats = entity_model->stats;
    entity->active = 1;
    entity->behavior = entity_model->behavior;

    int radius = (int) faction->radius;
    int x = (rand() % (radius * 2)) +
    (faction->pos.x - radius);
    int y = (rand() % (radius * 2)) +
    (faction->pos.y - radius);

    set_entity_scale(adata, entity->id, (sfVector2f) {3, 3});

    sfVector2f pos = {x, y};

    move_entity(adata, entity->id, pos, 1);
}

void spawn_entities(s_appdata *adata)
{
    int did = 0;
    linked_node *factions = adata->game_data->factions;
    while (factions != NULL && factions->data != NULL) {
        s_faction *faction = (s_faction *) factions->data;

        if (faction->active) {
            float seconds = get_clock_seconds(faction->clock_spawn);

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
        }
        factions = factions->next;
    }
}