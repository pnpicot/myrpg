/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Inventory module
*/

#include "main.h"

void init_syringe_health(s_appdata *adata)
{
    char *id = get_str(adata, "health_syr");

    add_syringe(adata, id);
    set_syringe_texture(adata, id, get_texture(adata, "health_syr"));
    set_syringe_count(adata, id, 0);
    set_syringe_name(adata, id, "Health");
    set_syringe_color(adata, id, sfRed);
}

void init_syringe_trf(s_appdata *adata)
{
    char *id = get_str(adata, "trf_syr");

    add_syringe(adata, id);
    set_syringe_texture(adata, id, get_texture(adata, "health_syr"));
    set_syringe_count(adata, id, 0);
    set_syringe_name(adata, id, "Transference");
    set_syringe_color(adata, id, sfGreen);
}

void init_syringe_attack(s_appdata *adata)
{
    char *id = get_str(adata, "attack_syr");

    add_syringe(adata, id);
    set_syringe_texture(adata, id, get_texture(adata, "health_syr"));
    set_syringe_count(adata, id, 0);
    set_syringe_name(adata, id, "Attack");
    set_syringe_color(adata, id, sfOrange);
}

void init_syringe_defense(s_appdata *adata)
{
    char *id = get_str(adata, "defense_syr");

    add_syringe(adata, id);
    set_syringe_texture(adata, id, get_texture(adata, "health_syr"));
    set_syringe_count(adata, id, 0);
    set_syringe_name(adata, id, "Defense");
    set_syringe_color(adata, id, sfCyan);
}

void init_syringes(s_appdata *adata)
{
    init_syringe_health(adata);
    init_syringe_trf(adata);
    init_syringe_attack(adata);
    init_syringe_defense(adata);
}
