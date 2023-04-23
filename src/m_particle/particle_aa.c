/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Particle module
*/

#include "../include/main.h"

void update_particles(s_appdata *adata, s_particle_src *emiter)
{
    linked_node *particles = emiter->particle_pool;
    float delta = get_clock_seconds(emiter->delta_clock);
    float render_rate = get_float(adata, "render_rate");
    s_game *game_data = adata->game_data;
    while (particles != NULL && particles->data != NULL) {
        s_particle *cur = (s_particle *) particles->data;
        sfVector2f scale = sfSprite_getScale(cur->model);
        update_particle_pos(cur, delta);
        update_particle_scale(emiter, cur, 0, delta);
        update_particle_rotation(cur, delta, emiter);
        update_particle_color(cur, emiter);
        cur->life--;
        if ((scale.x <= 0.05f && scale.y <= 0.05f) || cur->life <= 0)
            update_particle_end(adata, emiter, cur);
        particles = particles->next;
    }
    sfClock_restart(emiter->delta_clock);
}

void cycle_emiter(s_appdata *adata, s_particle_src *emiter)
{
    if (emiter->emiter_life <= 0) {
        delete_emiter(adata, emiter->id);
        return;
    }

    if (emiter->particle_count < emiter->particle_max)
        try_new_particle(adata, emiter);

    update_particles(adata, emiter);
    display_particles(adata, emiter);
}

void set_emiter_layer(s_appdata *adata, char *id, int layer)
{
    s_particle_src *emiter = get_emiter(adata, id);
    s_ints *integers = adata->integers;

    if (emiter == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    emiter->layer = layer;

    if (layer > integers->max_layer) integers->max_layer = layer;
    if (layer < integers->min_layer) integers->min_layer = layer;
}

void update_emiters(s_appdata *adata, s_ref *ref)
{

    s_particle_src *cur = (s_particle_src *) ref->ref;

    if (!cur->active) {
        return;
    }

    cycle_emiter(adata, cur);
}
