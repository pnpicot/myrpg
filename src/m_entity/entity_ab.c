/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** entity
*/

#include "../include/main.h"

void set_entity_stats_dammage(s_appdata *adata, char *id, int dammage)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    entity->stats->dammage = dammage;
}

void set_entity_stats_hp(s_appdata *adata, char *id, int hp)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    entity->stats->dammage = hp;
}

void set_entity_stats_faction(s_appdata *adata, char *id, char *faction)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    entity->stats->faction = faction;
}

void set_entity_stats_speed(s_appdata *adata, char *id, int speed)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    entity->stats->speed = speed;
}

void set_entity_stats_transference_level(s_appdata *adata, char *id,
int transference_level)
{
    s_entity *entity = get_entity(adata, id, 0);
    if (entity == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    entity->stats->transference_level = transference_level;
}
