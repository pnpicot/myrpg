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

s_zone *fill_zone(s_appdata *adata, s_entity *entity, sfVector2f pos)
{
    sfVector2i pos_zone;
    float zoom = get_float(adata, "zoom");

    pos_zone.x = pos.x / ((adata->game_data->map_width * 32 * zoom) /
    adata->game_data->nb_zones);
    pos_zone.y = pos.y / ((adata->game_data->map_height * 32 * zoom) /
    adata->game_data->nb_zones);
    pos_zone.x = MIN(adata->game_data->nb_zones - 1, MAX(0, pos_zone.x));
    pos_zone.y = MIN(adata->game_data->nb_zones - 1, MAX(0, pos_zone.y));

    int index = (pos_zone.y * adata->game_data->nb_zones) + pos_zone.x;

    linked_add(adata->game_data->zones[index]->entities, entity);

    return (adata->game_data->zones[index]);
}
