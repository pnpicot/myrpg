/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Particle module
*/

#include "../include/main.h"

void set_emiter_spawn_yoffset(s_appdata *adata, char *id, sfVector2f offset)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->spawn_offset_y = offset;
}

void set_emiter_size_range(s_appdata *adata, char *id, \
sfVector2f start_size, sfVector2f end_size)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->start_size = start_size;
    emiter->end_size = end_size;
}

void set_emiter_vortex_dir(s_appdata *adata, char *id, int vortex_dir)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->vortex_dir = vortex_dir;
}

void set_emiter_vortex_speed(s_appdata *adata, char *id, \
sfVector2f vortex_speed)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->vortex_speed = vortex_speed;
}

void set_emiter_active(s_appdata *adata, char *id, sfBool active)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->active = active;
}
