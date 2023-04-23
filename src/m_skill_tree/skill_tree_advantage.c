/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Skill tree module
*/

#include "main.h"

void add_speed(s_appdata *adata, float value)
{
    adata->game_data->speed_max += 1000.0f;
}

void add_attack(s_appdata *adata, float value)
{
    adata->player->attack += 100.0f;
}

void add_health(s_appdata *adata, float value)
{
    adata->player->health.x += 50.0f;
    adata->player->health.y += 100.0f;
}

void add_transference(s_appdata *adata, float value)
{
    adata->player->transference_level++;
}