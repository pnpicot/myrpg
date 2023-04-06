/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "../include/main.h"

void B40_bevahior(s_appdata *adata, s_entity *entity)
{
    float second = get_clock_seconds(entity->clock);

    if (second >= 1.0f) {
        sfVector2f add = { entity->stats->speed, entity->stats->speed }; // ??

        translate_entity(adata, entity->id, add);

        sfClock_restart(entity->clock);
    }
}
