/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Particle module
*/

#include "../include/main.h"

void set_emiter_rotation_dir(s_appdata *adata, char *id, int dir)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->rotation_dir = dir;
}

void set_emiter_rotation_speed(s_appdata *adata, char *id, \
float rotation_speed)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->rotation_speed = rotation_speed;
}

void set_emiter_spawnrate(s_appdata *adata, char *id, float spawn_chance)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->spawn_chance = spawn_chance;
}

void set_emiter_particle_speed(s_appdata *adata, char *id, \
sfVector2f particle_speed)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->speed = particle_speed;
}

void set_emiter_spawn_xoffset(s_appdata *adata, char *id, sfVector2f offset)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->spawn_offset_x = offset;
}
