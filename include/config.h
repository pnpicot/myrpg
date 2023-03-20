/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Configuration module
*/

#pragma once

#include "main.h"

int get_int(s_appdata *adata, char *id);
float get_float(s_appdata *adata, char *id);
char *get_str(s_appdata *adata, char *id);
sfColor get_config_color(s_appdata *adata, char *id);
void add_config_int(s_appdata *adata, char *type, char *id, char *value);
void add_config_float(s_appdata *adata, char *type, char *id, char *value);
void add_config_str(s_appdata *adata, char *type, char *id, char *value);
void add_config(s_appdata *adata, char *type, char *id, char *value);
void init_config(s_appdata *adata);
