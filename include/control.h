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
void update_speed(s_appdata *adata);
void move_camera(s_appdata *adata, sfVector2f pos);
void update_controls_next(s_appdata *adata, s_game *game_data, \
float delta, s_clocks *clocks);
void update_controls(s_appdata *adata);
void translate_player(s_appdata *adata, sfVector2f pos_ch);
