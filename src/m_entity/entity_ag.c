/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** entity
*/

#include "../include/main.h"

void set_entity_spawn_rate(s_appdata *adata, char *id, int spawn_rate)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    entity->stats->spawn_rate = spawn_rate;
}
