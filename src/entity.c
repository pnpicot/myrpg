/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

s_entity *get_entity_model(s_appdata *adata, char *id)
{
    linked_node *models = adata->game_data->entity_models;

    while (models != NULL && models->data != NULL) {
        s_entity *cur = (s_entity *) models->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        models = models->next;
    }

    return (NULL);
}

void delete_entity_model(s_appdata *adata, char *id)
{
    s_entity *model = get_entity_model(adata, id);

    if (model == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *models = adata->game_data->entity_models;
    int ite = 0;

    while (models != NULL && models->data != NULL) {
        s_entity *cur = (s_entity *) models->data;

        if (!my_strcmp(cur->id, id)) break;

        ite++;
        models = models->next;
    }

    linked_delete(&adata->game_data->entity_models, ite);
}

s_entity_part *get_entity_model_part(s_appdata *adata, char *model_id, \
char *part_id)
{
    s_entity *model = get_entity_model(adata, model_id);

    if (model == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (NULL);
    }

    linked_node *parts = model->parts;

    while (parts != NULL && parts->data != NULL) {
        s_entity_part *cur = (s_entity_part *) parts->data;

        if (!my_strcmp(cur->id, part_id)) return (cur);

        parts = parts->next;
    }

    return (NULL);
}

s_sprite *get_entity_part_model(s_appdata *adata, \
s_entity_part *model, sfTexture *tex, float scale)
{
    char *id = str_add(model->id, "@[:part]");
    char *rtex = get_str(adata, "rtex_game");
    char *container = get_str(adata, "ctn_game");

    add_sprite(adata, id, model->layer);
    set_sprite_texture(adata, id, tex);
    set_sprite_active(adata, id, 0);
    set_sprite_origin(adata, id, model->origin);
    move_sprite(adata, id, model->offset);
    scale_sprite(adata, id, (sfVector2f) { scale, scale });
    set_sprite_rtex(adata, id, rtex);

    return (get_sprite(adata, id));
}

void add_entity_part(s_appdata *adata, char **entry)
{
    if (count_nil_str(entry) < 9 || !is_format(entry, "ssdssffff"))
        return;

    char *model_id = entry[1];
    s_entity *model = get_entity_model(adata, model_id);
    char *tex_id = entry[4];
    sfTexture *tex = get_texture(adata, tex_id);

    if (model == NULL || tex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    char *part_id = entry[3];
    s_entity_part *part = get_entity_model_part(adata, model_id, part_id);

    if (part != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    s_entity_part *new_part = malloc(sizeof(s_entity_part));

    if (new_part == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
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
    if (count_nil_str(entry) < 5 || !is_format(entry, "sssffd"))
        return;

    char *model_id = entry[2];
    s_entity *model = get_entity_model(adata, model_id);

    if (model != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    char *faction_id = entry[1];
    s_faction *faction = get_faction(adata, faction_id);

    if (faction == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    s_entity *new_model = malloc(sizeof(s_entity));

    if (new_model == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    *new_model = (s_entity) { 0 };

    float model_scale = str_to_float(entry[3]);
    float model_spawnrate = str_to_float(entry[4]);
    int model_hp = my_getnbr(entry[5]);

    new_model->id = model_id;
    new_model->parts = linked_new();
    new_model->pos = (sfVector2f) { 0, 0 };
    new_model->hitbox = (sfFloatRect) {0, 0, 0, 0};
    new_model->st_hp = model_hp;
    new_model->spawn_rate = model_spawnrate;
    new_model->scale = model_scale;
    new_model->faction = faction;
    new_model->behavior = NULL;

    linked_add(adata->game_data->entity_models, new_model);
}

void move_entity(s_appdata *adata, s_entity *entity, sfVector2f pos)
{
    entity->pos = pos;

    linked_node *parts = entity->parts;

    while (parts != NULL && parts->data != NULL) {
        s_entity_part *cur = (s_entity_part *) parts->data;
        sfVector2f new_pos;

        new_pos.x = pos.x + cur->offset.x;
        new_pos.y = pos.y + cur->offset.y;

        move_sprite(adata, cur->sprite->id, new_pos);

        parts = parts->next;
    }
}

void translate_entity(s_appdata *adata, s_entity *entity, sfVector2f pos_ch)
{
    entity->pos.x += pos_ch.x;
    entity->pos.y += pos_ch.y;

    linked_node *parts = entity->parts;

    while (parts != NULL && parts->data != NULL) {
        s_entity_part *cur = (s_entity_part *) parts->data;

        cur->sprite->pos.x += pos_ch.x;
        cur->sprite->pos.y += pos_ch.y;

        parts = parts->next;
    }
}

void rotate_entity(s_appdata *adata, s_entity *entity, float angle)
{
    linked_node *parts = entity->parts;

    while (parts != NULL && parts->data != NULL) {
        s_entity_part *cur = (s_entity_part *) parts->data;
        float cur_angle = sfSprite_getRotation(cur->sprite->elem);

        cur_angle += angle;

        if (cur_angle > 360.0f) cur_angle -= 360.0f;
        if (cur_angle < 0) cur_angle += 360.0f;

        rotate_sprite(adata, cur->sprite->id, cur_angle);

        parts = parts->next;
    }
}

void rotate_entity_part(s_appdata *adata, s_entity *entity, \
char *part_id, float angle)
{
    linked_node *parts = entity->parts;

    while (parts != NULL && parts->data != NULL) {
        s_entity_part *cur = (s_entity_part *) parts->data;

        if (!my_strcmp(cur->id, part_id)) {
            float cur_angle = sfSprite_getRotation(cur->sprite->elem);

            cur_angle += angle;
            cur_angle = cur_angle > 360.0f ? cur_angle - 360.0f : cur_angle;
            cur_angle = cur_angle < 0 ? cur_angle + 360.0f : cur_angle;

            sfSprite_setRotation(cur->sprite->elem, cur_angle);
        }

        parts = parts->next;
    }
}

void rotate_entity_part_abs(s_appdata *adata, s_entity *entity, \
char *part_id, float angle)
{
    linked_node *parts = entity->parts;

    while (parts != NULL && parts->data != NULL) {
        s_entity_part *cur = (s_entity_part *) parts->data;

        if (!my_strcmp(cur->id, part_id)) {
            sfSprite_setRotation(cur->sprite->elem, angle);
        }

        parts = parts->next;
    }
}

void set_entity_behavior(s_appdata *adata, char *id, \
void (*behavior)(s_appdata *adata, s_entity *s_entity))
{
    s_entity *model = get_entity_model(adata, id);

    if (model == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    model->behavior = behavior;
}

void update_entities(s_appdata *adata)
{
    linked_node *entities = adata->game_data->entities;

    while (entities != NULL && entities->data != NULL) {
        s_entity *cur = (s_entity *) entities->data;

        (*cur->behavior)(adata, cur);

        entities = entities->next;
    }
}

sfFloatRect get_entity_hitbox(s_appdata *adata, s_entity *entity)
{
    sfFloatRect hitbox =
    {.left = entity->pos.x + entity->hitbox.left - adata->game_data->view_pos.x
    - entity->hitbox.width * entity->scale / 2,
    .top = entity->pos.y + entity->hitbox.top - adata->game_data->view_pos.y
    - entity->hitbox.height * entity->scale / 2 ,
    .width = entity->hitbox.width * entity->scale,
    .height = entity->hitbox.height * entity->scale};
    return (hitbox);
}

// TODO: add clock so we can use a delta in velocity vector formulas
void behavior_z200(s_appdata *adata, s_entity *entity)
{
    float seconds = get_clock_seconds(entity->clock);

    rotate_entity_part(adata, entity, "blades_1", -5.0f * seconds * 100);
    rotate_entity_part(adata, entity, "blades_2", 5.0f * seconds * 100);
    rotate_entity_part(adata, entity, "rotors", 10.0f * seconds * 100);

    sfVector2f add = { 0.3f * seconds * 100, 0.1f * seconds * 100};

    add = is_map_colliding(adata, get_entity_hitbox(adata, entity), add);

    translate_entity(adata, entity, add);

    sfClock_restart(entity->clock);
}

void behavior_mf26(s_appdata *adata, s_entity *entity)
{
    float seconds = get_clock_seconds(entity->clock);

    sfVector2f add = { 0.3f * seconds * 2000, 0.1f * seconds * 2000};

    float angle = (atan2f(add.y, add.x) * (180 / M_PI)) + 90.0f;
    rotate_entity_part_abs(adata, entity, "body", angle);

    add = is_map_colliding(adata, get_entity_hitbox(adata, entity), add);

    translate_entity(adata, entity, add);

    sfClock_restart(entity->clock);
}

void init_entity_behaviors(s_appdata *adata)
{
    set_entity_behavior(adata, "z200", &behavior_z200);
    set_entity_behavior(adata, "mf26", &behavior_mf26);
}
