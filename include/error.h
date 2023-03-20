/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Error module
*/

#pragma once

#include "main.h"

char *get_error(s_appdata *adata, char *id);
void add_error(s_appdata *adata, char *id, char *format);
void init_errors(s_appdata *adata);
