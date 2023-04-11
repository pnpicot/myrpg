/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Syringe item module
*/

#pragma once

#include "main.h"

s_syringe *get_syringe(s_appdata *adata, char *id);
void delete_syringe(s_appdata *adata, char *id);
void add_syringe(s_appdata *adata, char *id);
void set_syringe_use(s_appdata *adata, char *id, \
void (*on_use)(s_appdata *adata, s_syringe *syringe));
void set_syringe_count(s_appdata *adata, char *id, int count);
void syringe_increment(s_appdata *adata, char *id, int amount);
void syringe_decrement(s_appdata *adata, char *id, int amount);
void set_syringe_texture(s_appdata *adata, char *id, sfTexture *texture);
int get_syringe_count(s_appdata *adata, char *id);
sfTexture *get_syringe_texture(s_appdata *adata, char *id);
