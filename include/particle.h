/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Particle module
*/

#pragma once

#include "main.h"

s_particle_src *get_emiter(s_appdata *adata, char *id);
void delete_emiter(s_appdata *adata, char *id);
void set_emiter_lifetime(s_appdata *adata, char *id, int life_time);
void move_emiter(s_appdata *adata, char *id, sfVector2f pos);
void set_emiter_particle_lifetime(s_appdata *adata, char *id, int life_time);
void set_emiter_particle_max(s_appdata *adata, char *id, int max);
void set_emiter_model(s_appdata *adata, char *id, sfSprite *model);
void set_emiter_rtex(s_appdata *adata, char *id, char *rtex_id);
void set_emiter_rotation_dir(s_appdata *adata, char *id, int dir);
void set_emiter_rotation_speed(s_appdata *adata, char *id, float rotation_speed);
void set_emiter_spawnrate(s_appdata *adata, char *id, float spawn_chance);
void set_emiter_particle_speed(s_appdata *adata, char *id, float particle_speed);
void set_emiter_size_range(s_appdata *adata, char *id, sfVector2f start_size, sfVector2f end_size);
void add_emiter(s_appdata *adata, char *id);
void try_new_particle(s_appdata *adata, s_particle_src *emiter);
void cycle_emiter(s_appdata *adata, s_particle_src *emiter);
void update_emiters(s_appdata *adata);
void set_emiter_spawn_offset(s_appdata *adata, char *id, sfVector2f offset);
