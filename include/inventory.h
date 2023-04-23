/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Inventory module
*/

#pragma once

#include "main.h"

void init_syringe_health(s_appdata *adata);
void init_syringe_trf(s_appdata *adata);
void init_syringe_attack(s_appdata *adata);
void init_syringe_defense(s_appdata *adata);
void init_syringes(s_appdata *adata);
sfVector2f get_target_scale(sfVector2f target_size, sfTexture *texture);
void init_inventory_item_sprite(s_appdata *adata, sfVector2f syr_pos, \
char *syr_id, s_syringe *cur);
void init_item_object(s_appdata *adata, char *id, s_ref ref,
s_syringe *syringe);
void init_item_next(s_appdata *adata, s_tmp_invitem tmp);
void init_inventory_items(s_appdata *adata, char *container, char *rtex, \
sfFloatRect inv_bounds);
void init_inventory_title(s_appdata *adata, char *container, char *rtex, \
sfFloatRect inv_bounds);
void init_inventory_next(s_appdata *adata, char *id, \
char *container, char *rtex);
void init_ingame_inventory(s_appdata *adata, char *container, char *rtex);
void use_syringe_health(s_appdata *adata, s_ref *ref);
void use_syringe_trf(s_appdata *adata, s_ref *ref);
void use_syringe_attack(s_appdata *adata, s_ref *ref);
void use_syringe_defense(s_appdata *adata, s_ref *ref);
