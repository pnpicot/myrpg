/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

void add_entity_part(s_appdata *adata, char **entry)
{
    if (count_nil_str(entry) < 9 || !is_format(entry, "ssdssffff"))
        return;

    char *model_id = entry[1];
    s_entity *model = get_entity_model(adata, model_id);
    char *tex_id = entry[4];
    sfTexture *tex = get_texture(adata, tex_id);

    if (model == NULL || tex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    char *part_id = entry[3];
    s_entity_part *part = get_entity_model_part(adata, model_id, part_id);

    if (part != NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "already_exists"));
        return;
    }

    s_entity_part *new_part = malloc(sizeof(s_entity_part));

    if (new_part == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return;
    }

    *new_part = (s_entity_part) { 0 };

    int layer = my_getnbr(entry[2]);
    float origin_x = str_to_float(entry[5]);
    float origin_y = str_to_float(entry[6]);
    float off_x = str_to_float(entry[7]);
    float off_y = str_to_float(entry[8]);

    new_part->id = part_id;
    new_part->layer = layer;
    new_part->offset = (sfVector2f) { off_x, off_y };
    new_part->origin = (sfVector2f) { origin_x, origin_y };
    new_part->sprite = get_entity_part_model(adata, new_part, tex, model->scale);

    free(entry[0]);
    free(entry[1]);
    free(entry[2]);
    for (int i = 4; entry[i] != NULL; i++)
        free(entry[i]);
    free(entry);

    if (new_part->origin.x + new_part->offset.x > model->hitbox.width)
        model->hitbox.width = new_part->origin.x + new_part->offset.x;
    if (new_part->origin.y + new_part->offset.y > model->hitbox.height)
        model->hitbox.height = new_part->origin.y + new_part->offset.y;
    if (new_part->origin.x + new_part->offset.x < model->hitbox.left) {
        model->hitbox.left = new_part->origin.x + new_part->offset.x;
        model->hitbox.width -= model->hitbox.left;
    }
    if (new_part->origin.y + new_part->offset.y < model->hitbox.top) {
        model->hitbox.top = new_part->origin.y + new_part->offset.y;
        model->hitbox.height -= model->hitbox.top;
    }

    linked_add(model->parts, new_part);
}

void add_entity_model(s_appdata *adata, char **entry)
{
    if (count_nil_str(entry) < 12 || !is_format(entry, "sssffdffdffd"))
        return;

    char *model_id = entry[2];
    s_entity *model = get_entity_model(adata, model_id);

    if (model != NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "already_exists"));
        return;
    }

    char *faction_id = entry[1];
    s_faction *faction = get_faction(adata, faction_id);

    if (faction == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    s_entity *new_model = malloc(sizeof(s_entity));

    if (new_model == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return;
    }

    *new_model = (s_entity) { 0 };

    char *model_name = entry[2];
    float model_scale = str_to_float(entry[3]);
    float model_spawnrate = str_to_float(entry[4]);
    int model_hp = my_getnbr(entry[5]);
    float damage = str_to_float(entry[6]);
    float model_speed = str_to_float(entry[7]);
    int model_orientated = my_getnbr(entry[8]);
    float agro_length = str_to_float(entry[9]);
    float model_defense = str_to_float(entry[10]);
    int model_trf = my_getnbr(entry[11]);

    new_model->id = model_id;
    new_model->parts = linked_new();
    new_model->pos = (sfVector2f) { 0, 0 };
    new_model->hitbox = (sfFloatRect) {0, 0, 0, 0};
    new_model->st_hp = model_hp;
    new_model->hp = model_hp;
    new_model->speed = model_speed;
    new_model->spawn_rate = model_spawnrate;
    new_model->scale = model_scale;
    new_model->faction = faction;
    new_model->inhabited = sfFalse;
    new_model->behavior = NULL;
    new_model->init = sfTrue;
    new_model->hp_bar = NULL;
    new_model->floats = NULL;
    new_model->orientated = model_orientated ? sfTrue : sfFalse;
    new_model->agro_length = agro_length;
    new_model->damage = damage;
    new_model->clock = sfClock_create();
    new_model->path_clock = sfClock_create();
    new_model->dead = sfFalse;
    new_model->name = model_name;
    new_model->defense = model_defense;
    new_model->trf_require = model_trf;

    free(entry[0]);
    for (int i = 3; entry[i] != NULL; i++)
        free(entry[i]);
    free(entry);

    linked_add(adata->game_data->entity_models, new_model);
    linked_add(new_model->faction->models, new_model);
}
