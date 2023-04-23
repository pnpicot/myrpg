/*
** EPITECH PROJECT, 2023
** m_inventory
** File description:
** inventory_da
*/

#include "main.h"

void use_syringe_health(s_appdata *adata, s_ref *ref)
{
    s_syringe *cur = (s_syringe *)ref->ref;

    if (cur->count <= 0)
        return;
    cur->count--;
    adata->player->health.x = adata->player->health.y;
}

void use_syringe_trf(s_appdata *adata, s_ref *ref)
{
    s_syringe *cur = (s_syringe *)ref->ref;

    if (cur->count <= 0)
        return;
    cur->count--;
    adata->player->transference.x = adata->player->transference.y;
}

void use_syringe_attack(s_appdata *adata, s_ref *ref)
{
    s_syringe *cur = (s_syringe *)ref->ref;

    if (cur->count <= 0)
        return;
    cur->count--;
    adata->player->attack += 5;
}

void use_syringe_defense(s_appdata *adata, s_ref *ref)
{
    s_syringe *cur = (s_syringe *)ref->ref;

    if (cur->count <= 0)
        return;
    cur->count--;
    adata->player->defense += 0.05;
}
