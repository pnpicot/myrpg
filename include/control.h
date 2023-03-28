/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Control module
*/

#pragma once

#include "main.h"

void set_friction(s_appdata *adata, float friction);
void set_velocity(s_appdata *adata, float velocity);
void set_max_speed(s_appdata *adata, float max_speed);
void update_controls(s_appdata *adata);
