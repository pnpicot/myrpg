/*
** EPITECH PROJECT, 2023
** src
** File description:
** spawn_ba
*/

#include "main.h"

void copy_entity_model_n(s_appdata *adata, s_entity *model,
s_entity *new_entity, char *id)
{
    *new_entity = (s_entity){
    .id = id,                .faction = model->faction,
    .hitbox = model->hitbox,        .agro_length = model->agro_length,
    .scale = model->scale,          .spawn_rate = model->spawn_rate,
    .st_hp = model->st_hp,          .hp = model->hp,
    .behavior = model->behavior,    .emiter = model->emiter,
    .speed = model->speed,          .inhabited = sfFalse,
    .init = sfTrue,                 .clock = sfClock_create(),
    .floats = linked_new(),         .orientated = model->orientated,
    .damage = model->damage,        .pos = model->pos,
    .zone = NULL,                   .dead = sfFalse,
    .name = model->name,            .path_clock = sfClock_create(),
    .defense = model->defense,      .trf_require = model->trf_require
    };
    new_entity->hp_bar = get_entity_hp_bar(adata, new_entity);
    new_entity->parts = copy_entity_model_parts(adata, model->parts);
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

    copy_entity_model_n(adata, model, new_entity, id);

    return (new_entity);
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
    int wave = game_data->wave_count;
    if (get_clock_seconds(game_data->wave_clock) < 20.0f && wave)
        return;
    if (game_data->faction_index > faction_count - 1)
        game_data->faction_index = 0;
    s_faction *faction = (s_faction *) linked_get(game_data->factions,
    game_data->faction_index)->data;
    int model_count = linked_count(faction->models);
    int wave_size = 5 + ((int) wave / 5) * 5;
    for (int i = 0; i < wave_size; i++) {
        int model_index = rand_int(0, f_max(0, model_count - 1));
        s_entity *model = (s_entity *) linked_get(faction->models,
        model_index)->data;
        try_entity_spawn(adata, model);
    }
    sfClock_restart(game_data->wave_clock);
    game_data->faction_index++;
    game_data->wave_count++;
}
