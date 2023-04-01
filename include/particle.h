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
void translate_emiter(s_appdata *adata, char *id, sfVector2f pos_ch);
void set_emiter_particle_lifetime(s_appdata *adata, char *id, int life_time);
void set_emiter_particle_max(s_appdata *adata, char *id, int max);
void set_emiter_gameobject(s_appdata *adata, char *id, sfBool game_obj);
void set_emiter_model(s_appdata *adata, char *id, char *texture_id);
void set_emiter_rtex(s_appdata *adata, char *id, char *rtex_id);
void set_emiter_rotation_dir(s_appdata *adata, char *id, int dir);
void set_emiter_rotation_speed(s_appdata *adata, char *id, \
float rotation_speed);
void set_emiter_spawnrate(s_appdata *adata, char *id, float spawn_chance);
void set_emiter_particle_speed(s_appdata *adata, char *id, \
sfVector2f particle_speed);
void set_emiter_spawn_xoffset(s_appdata *adata, char *id, sfVector2f offset);
void set_emiter_spawn_yoffset(s_appdata *adata, char *id, sfVector2f offset);
void set_emiter_size_range(s_appdata *adata, char *id, \
sfVector2f start_size, sfVector2f end_size);
void set_emiter_vortex_dir(s_appdata *adata, char *id, int vortex_dir);
void set_emiter_vortex_speed(s_appdata *adata, char *id, \
sfVector2f vortex_speed);
void set_emiter_active(s_appdata *adata, char *id, sfBool active);
void add_emiter_first(s_appdata *adata, char *id, s_particle_src *new_emiter);
void add_emiter(s_appdata *adata, char *id);
void set_emiter_cone(s_appdata *adata, char *id, sfVector2f angle_range);
void set_emiter_colors(s_appdata *adata, char *id, sfColor start, sfColor end);
void set_emiter_lerp_factor(s_appdata *adata, char *id, float lerp_factor);
void init_new_particle(s_appdata *adata, s_particle_src *emiter, \
s_particle *new_particle);
void add_new_particle(s_appdata *adata, s_particle_src *emiter, \
s_particle *new_particle);
void try_new_particle(s_appdata *adata, s_particle_src *emiter);
void display_particles(s_appdata *adata, s_particle_src *emiter);
void accelerate_emiter(s_appdata *adata, char *id, int cycles);
void update_particle_scale(s_particle_src *emiter, s_particle *cur, \
float scale_speed, float delta);
void update_particle_rotation(s_particle *cur, float delta, \
s_particle_src *emiter);
void update_particle_color(s_particle *cur, s_particle_src *emiter);
void update_particle_end(s_particle_src *emiter, s_particle *cur);
void update_particle_pos(s_particle *cur, float delta);
void update_particles(s_appdata *adata, s_particle_src *emiter);
void cycle_emiter(s_appdata *adata, s_particle_src *emiter);
void update_emiters(s_appdata *adata);
