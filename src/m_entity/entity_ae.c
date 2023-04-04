/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** entity
*/

#include "../include/main.h"

void move_entity(s_appdata *adata, char *id, sfVector2f pos)
{
    s_entity *entity = get_entity(adata, id);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    move_sprite(adata, entity->sprite->id, pos);
}

void translate_entity(s_appdata *adata, char *id, sfVector2f add)
{
    s_entity *entity = get_entity(adata, id);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    translate_sprite(adata, entity->sprite->id, add);
}

void rotate_entity(s_appdata *adata, char *id, float angle)
{
    s_entity *entity = get_entity(adata, id);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    rotate_sprite(adata, entity->sprite->id, angle);
}

void set_entity_spawn(s_appdata *adata, char *id)
{
    s_entity *entity = get_entity(adata, id);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }
    linked_node *factions = adata->game_data->factions;
    while (factions != NULL && factions->data != NULL) {
        s_faction *faction = (s_faction *) factions->data;
        if (in_str(id, faction->id)) {
            int radius = (int) faction->radius;
            int x = (rand() % (radius * 2)) +
            (faction->pos.x - radius);
            int y = (rand() % (radius * 2)) +
            (faction->pos.y - radius);
            sfVector2f pos = {x, y};
            move_entity(adata, entity->id, pos);
            return;
        }
        factions = factions->next;
    }
}
