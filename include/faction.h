/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Faction module
*/

#pragma once

#include "main.h"

s_faction *get_faction(s_appdata *adata, char *id);
void delete_faction(s_appdata *adata, char *id);
void add_faction(s_appdata *adata, char **entry);
void load_entity_config(s_appdata *adata);
