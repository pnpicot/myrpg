/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity spawning module
*/

#include "main.h"

s_sprite *copy_entity_part_sprite(s_appdata *adata, s_sprite *sprite)
{
    char *id = str_m_add(3, sprite->id, "-", get_random_id(10));
    char *container = get_str(adata, "ctn_game");

    add_sprite(adata, id, sprite->layer);

    s_sprite *new_sprite = get_sprite(adata, id);

    new_sprite->active = sfTrue;
    new_sprite->elem = sfSprite_copy(sprite->elem);
    new_sprite->hidden = 0;
    new_sprite->layer = sprite->layer;
    new_sprite->pos = sprite->pos;
    set_sprite_rtex(adata, id, sprite->rtex_id);
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
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
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

s_bar *get_entity_hp_bar(s_appdata *adata, s_entity *entity)
{
    char *id = str_add(entity->id, "@[:hp_bar]");
    char *rtex = get_str(adata, "rtex_game");

    add_bar(adata, id, 5);

    s_bar *bar = get_bar(adata, id);

    set_bar_rtex(adata, id, rtex);
    resize_bar(adata, id, (sfVector2f) { 300, 5.0f });
    set_bar_origin(adata, id, (sfVector2f) { 150, 2.5f });
    sfVector2f pos;
    pos.x = 0;
    pos.y = 0;
    translate_bar(adata, id, pos);
    color_bar(adata, id, get_color(150, 0, 0, 255), sfGreen);
    set_bar_min(adata, id, 0);
    set_bar_max(adata, id, entity->st_hp);
    set_bar_current(adata, id, entity->st_hp);

    return (bar);
}

void copy_entity_model_n(s_appdata *adata, s_entity *model,
s_entity *new_entity)
{
    new_entity->hitbox = model->hitbox;
    new_entity->scale = model->scale;
    new_entity->spawn_rate = model->spawn_rate;
    new_entity->st_hp = model->st_hp;
    new_entity->hp = model->hp;
    new_entity->behavior = model->behavior;
    new_entity->emiter = model->emiter;
    new_entity->speed = model->speed;
    new_entity->inhabited = sfFalse;
    new_entity->hp_bar = get_entity_hp_bar(adata, new_entity);
    new_entity->init = sfTrue;
    new_entity->clock = sfClock_create();
    new_entity->floats = linked_new();
    new_entity->orientated = model->orientated;
    new_entity->agro_length = model->agro_length;
    new_entity->damage = model->damage;
    new_entity->pos = (sfVector2f) { 0, 0 };
    new_entity->zone = NULL;
    new_entity->dead = sfFalse;
    new_entity->name = model->name;
    new_entity->path_clock = sfClock_create();
    new_entity->faction = model->faction;
}

s_entity *copy_entity_model(s_appdata *adata, s_entity *model)
{
    int index = model->faction->entity_count;
    char *id = str_m_add(4, model->id, "@[:entity-", nbr_to_str(index), "]");
    s_entity *new_entity = malloc(sizeof(s_entity));

    if (new_entity == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return (NULL);
    }

    *new_entity = (s_entity) { 0 };

    new_entity->faction = model->faction;
    new_entity->id = id;
    new_entity->parts = copy_entity_model_parts(adata, model->parts);
    new_entity->pos = model->pos;
    copy_entity_model_n(adata, model, new_entity);

    return (new_entity);
}

s_zone *fill_zone(s_appdata *adata, s_entity *entity, sfVector2f pos)
{
    sfVector2i pos_zone;
    float zoom = get_float(adata, "zoom");

    pos_zone.x = pos.x / ((adata->game_data->map_width * 32 * zoom) / adata->game_data->nb_zones);
    pos_zone.y = pos.y / ((adata->game_data->map_height * 32 * zoom) / adata->game_data->nb_zones);
    pos_zone.x = MIN(adata->game_data->nb_zones - 1, MAX(0, pos_zone.x));
    pos_zone.y = MIN(adata->game_data->nb_zones - 1, MAX(0, pos_zone.y));

    int index = (pos_zone.y * adata->game_data->nb_zones) + pos_zone.x;

    linked_add(adata->game_data->zones[index]->entities, entity);

    return (adata->game_data->zones[index]);
}

void try_entity_spawn_n(s_appdata *adata, s_entity *model,
s_entity *new_entity, sfVector2f pos)
{
    move_entity(adata, new_entity, pos);

    if (new_entity->emiter != NULL) {
        int win_w = get_int(adata, "win_w");
        int win_h = get_int(adata, "win_h");

        (*new_entity->emiter)(adata, new_entity);

        char *emiter_id = str_add(new_entity->id, "@[:emiter]");

        pos.x -= adata->game_data->view_pos.x;
        pos.y -= adata->game_data->view_pos.y;

        translate_emiter(adata, emiter_id, pos);
    }
}

void try_entity_spawn(s_appdata *adata, s_entity *model)
{
    s_faction *faction = model->faction;

    sfClock_restart(model->clock);

    s_entity *new_entity = copy_entity_model(adata, model);
    float tile_size = 32 * get_float(adata, "zoom");
    sfVector2f pos = { 124 * tile_size, 124 * tile_size };

    new_entity->zone = fill_zone(adata, new_entity, pos);

    try_entity_spawn_n(adata, model, new_entity, pos);

    faction->entity_count++;

    linked_add(adata->game_data->entities, new_entity);
}

void trigger_spawn_cycle(s_appdata *adata)
{
    s_game *game_data = adata->game_data;
    int faction_count = linked_count(game_data->factions);

    if (get_clock_seconds(game_data->wave_clock) < 10.0f
        && game_data->wave_count > 1)
        return;

    if (game_data->faction_index > faction_count - 1)
        game_data->faction_index = 0;

    s_faction *faction = (s_faction *) linked_get(game_data->factions,
                                        game_data->faction_index)->data;
    linked_node *models = game_data->entity_models;

    while (models != NULL && models->data != NULL) {
        s_entity *cur = (s_entity *) models->data;

        if (my_strcmp(cur->faction, faction->id)) {
            models = models->next;
            continue;
        }

        for (int i = 0; i < 20; i++) {
            try_entity_spawn(adata, cur);
        }

        models = models->next;
    }

    sfClock_restart(game_data->wave_clock);
    game_data->faction_index++;
    game_data->wave_count++;
}
