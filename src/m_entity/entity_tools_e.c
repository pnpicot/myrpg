/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

void add_to_entity_float(s_appdata *adata, s_entity *entity, char *id, \
float value)
{
    s_float *tmp_float = get_entity_float(entity, id);

    if (tmp_float == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    tmp_float->value += value;
}

void add_entity_float(s_appdata *adata, s_entity *entity, char *id, \
float default_value)
{
    linked_node *floats = entity->floats;
    s_float *tmp_float = get_entity_float(entity, id);

    if (tmp_float != NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "already_exists"));
        return;
    }
    s_float *new_float = malloc(sizeof(s_float));
    if (new_float == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return;
    }
    new_float->id = id;
    new_float->value = default_value;
    linked_add(entity->floats, new_float);
}

void set_entity_float(s_appdata *adata, s_entity *entity, char *id, \
float value)
{
    s_float *tmp_float = get_entity_float(entity, id);

    if (tmp_float == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    tmp_float->value = value;
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

s_float *get_entity_float(s_entity *entity, char *id)
{
    linked_node *floats = entity->floats;

    while (floats != NULL && floats->data != NULL) {
        s_float *cur = (s_float *) floats->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        floats = floats->next;
    }

    return (NULL);
}
