/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity spawning module
*/

#include "main.h"

s_sprite *copy_entity_part_sprite(s_appdata *adata, s_sprite *sprite)
{
    char *rid = get_random_id(10);
    char *id = str_m_add(3, sprite->id, "-", rid);
    free(rid);
    char *container = get_str(adata, "ctn_game");

    add_sprite(adata, id, sprite->layer);

    s_sprite *new_sprite = get_sprite(adata, id);


    new_sprite->active = sfTrue;
    sfSprite_destroy(new_sprite->elem);
    new_sprite->elem = sfSprite_copy(sprite->elem);
    new_sprite->hidden = 0;
    new_sprite->layer = sprite->layer;
    new_sprite->pos = sprite->pos;
    new_sprite->rtex_id = sprite->rtex_id;
    new_sprite->texture = sprite->texture;

    add_to_container(adata, container, (s_ref) { new_sprite, TYPE_SPRITE });

    char *obj_id = str_add(id, "@[:gobj]");

    add_gameobject(adata, obj_id);
    set_gameobject_ref(adata, obj_id, new_sprite, TYPE_SPRITE);

    return (new_sprite);
}

s_entity_part *copy_entity_part(s_appdata *adata, s_entity_part *part)
{
    s_entity_part *new_part = malloc(sizeof(s_entity_part));

    if (new_part == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return (NULL);
    }

    new_part->id = part->id;
    new_part->layer = part->layer;
    new_part->offset = part->offset;
    new_part->origin = part->origin;
    new_part->sprite = copy_entity_part_sprite(adata, part->sprite);

    return (new_part);
}

linked_node *copy_entity_model_parts(s_appdata *adata, linked_node *parts)
{
    linked_node *new_parts = linked_new();

    while (parts != NULL && parts->data != NULL) {
        s_entity_part *cur = (s_entity_part *) parts->data;

        linked_add(new_parts, copy_entity_part(adata, cur));

        parts = parts->next;
    }

    return (new_parts);
}

s_entity *copy_entity_model(s_appdata *adata, s_entity *model)
{
    int index = model->faction->entity_count;
    s_entity *new_entity = malloc(sizeof(s_entity));

    if (new_entity == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return (NULL);
    }

    new_entity->faction = model->faction;
    new_entity->id = model->id;
    new_entity->parts = copy_entity_model_parts(adata, model->parts);
    new_entity->pos = model->pos;
    new_entity->hitbox = model->hitbox;
    new_entity->scale = model->scale;
    new_entity->spawn_rate = model->spawn_rate;
    new_entity->st_hp = model->st_hp;
    new_entity->behavior = model->behavior;
    new_entity->clock = sfClock_create();

    return (new_entity);
}

void try_entity_spawn(s_appdata *adata, s_entity *model)
{
    float chance = rand_float(0, 100.0f);
    s_faction *faction = model->faction;
    int limit_reached = faction->entity_count >= faction->entity_max;

    if (chance > model->spawn_rate || limit_reached) return;

    s_entity *new_entity = copy_entity_model(adata, model);
    float rand_rad = faction->spawn_radius * sqrt(rand_float(0, 1.0f));
    float theta = rand_float(0, 1.0f) * M_PI * 2;
    sfVector2f pos;

    pos.x = faction->spawn_point.x + rand_rad * cos(theta);
    pos.y = faction->spawn_point.y + rand_rad * sin(theta);

    move_entity(adata, new_entity, pos);

    faction->entity_count++;

    linked_add(adata->game_data->entities, new_entity);
}

void trigger_spawn_cycle(s_appdata *adata)
{
    linked_node *models = adata->game_data->entity_models;

    while (models != NULL && models->data != NULL) {
        s_entity *cur = (s_entity *) models->data;

        try_entity_spawn(adata, cur);

        models = models->next;
    }
}
