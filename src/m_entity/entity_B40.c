/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** entity
*/

#include "../include/main.h"

void B40_bevahior(s_appdata *adata, s_entity *B40)
{
    float second = get_clock_seconds(B40->clock_move);

    if (second >= 1 && B40->active) {
        sfVector2f add = {B40->stats->speed, B40->stats->speed};
        translate_entity(adata, B40->id, add);

        sfClock_restart(B40->clock_move);
    }
}
