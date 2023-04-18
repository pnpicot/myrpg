/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

void init_entity_behaviors(s_appdata *adata)
{
    set_entity_behavior(adata, "z200", &behavior_z200);
    set_entity_behavior(adata, "mf26", &behavior_mf26);
    set_entity_behavior(adata, "p800", &behavior_p800);
    set_entity_behavior(adata, "lmx2", &behavior_lmx2);
}

void init_entity_emiters(s_appdata *adata)
{
    set_entity_emiter(adata, "mf26", &init_mf26_emiter);
}
