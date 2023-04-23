/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

void add_entity_part_n(s_appdata *adata, char **etr, s_entity_part *new_part)
{
    s_entity *mod = get_entity_model(adata, etr[1]);
    sfTexture *tex = get_texture(adata, etr[4]);
    new_part->id = etr[3];
    new_part->layer = my_getnbr(etr[2]);
    new_part->offset = (sfVector2f){str_to_float(etr[7]), str_to_float(etr[8])};
    new_part->origin = (sfVector2f){str_to_float(etr[5]), str_to_float(etr[6])};
    new_part->sprite = get_entity_part_model(adata, new_part, tex, mod->scale);
    if (new_part->origin.x + new_part->offset.x > mod->hitbox.width)
        mod->hitbox.width = new_part->origin.x + new_part->offset.x;
    if (new_part->origin.y + new_part->offset.y > mod->hitbox.height)
        mod->hitbox.height = new_part->origin.y + new_part->offset.y;
    if (new_part->origin.x + new_part->offset.x < mod->hitbox.left) {
        mod->hitbox.left = new_part->origin.x + new_part->offset.x;
        mod->hitbox.width -= mod->hitbox.left;
    } if (new_part->origin.y + new_part->offset.y < mod->hitbox.top) {
        mod->hitbox.top = new_part->origin.y + new_part->offset.y;
        mod->hitbox.height -= mod->hitbox.top;
    }
}

void add_entity_part(s_appdata *adata, char **entry)
{
    if (count_nil_str(entry) < 9 || !is_format(entry, "ssdssffff"))
        return;
    s_entity *model = get_entity_model(adata, entry[1]);
    if (get_entity_model_part(adata, entry[1], entry[3]) != NULL) {
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
    add_entity_part_n(adata, entry, new_part);
    for (int i = 0; entry[i] != NULL; i++)
        if (i != 3)
            free(entry[i]);
    free(entry);
    linked_add(model->parts, new_part);
}

void add_entity_model_n(s_appdata *adata, char **entry, s_entity *new_model)
{
    *new_model = (s_entity) {.id = entry[2], .parts = linked_new(),
    .pos = (sfVector2f) { 0, 0 }, .hitbox = (sfFloatRect) {0, 0, 0, 0},
    .st_hp = my_getnbr(entry[5]), .hp = my_getnbr(entry[5]),
    .speed = str_to_float(entry[7]), .spawn_rate = str_to_float(entry[3]),
    .scale = str_to_float(entry[4]), .faction = NULL, .inhabited = sfFalse,
    .behavior = NULL, .init = sfTrue, .hp_bar = NULL, .floats = NULL,
    .orientated = my_getnbr(entry[8]) ? sfTrue : sfFalse,
    .agro_length = str_to_float(entry[9]), .damage = str_to_float(entry[6]),
    .clock = sfClock_create(), .path_clock = sfClock_create(), .dead = sfFalse,
    .name = entry[2], .defense = str_to_float(entry[10]),
    .trf_require = my_getnbr(entry[11])
    };
}

void add_entity_model(s_appdata *adata, char **entry)
{
    if (count_nil_str(entry) < 12 || !is_format(entry, "sssffdffdffd"))
        return;
    s_entity *model = get_entity_model(adata, entry[2]);
    if (model != NULL)
        return;
    char *faction_id = entry[1];
    s_faction *faction = get_faction(adata, faction_id);
    if (faction == NULL)
        return;
    s_entity *new_model = malloc(sizeof(s_entity));
    if (new_model == NULL)
        return;
    add_entity_model_n(adata, entry, new_model);
    new_model->faction = faction;
    free(entry[0]);
    for (int i = 3; entry[i] != NULL; i++)
        free(entry[i]);
    free(entry);
    linked_add(adata->game_data->entity_models, new_model);
    linked_add(new_model->faction->models, new_model);
}
