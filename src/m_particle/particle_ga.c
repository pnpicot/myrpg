/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Particle module
*/

#include "../include/main.h"

void init_new_particle(s_appdata *adata, s_particle_src *emiter, \
s_particle *new_particle)
{
    sfVector2f cone = emiter->cone_range;
    sfVector2f vspeed = emiter->vortex_speed;

    new_particle->model = sfSprite_copy(emiter->particle_model);
    new_particle->angle = rand_float(cone.x, cone.y);
    new_particle->life = emiter->life_time;
    new_particle->vortex_speed = rand_float(vspeed.x, vspeed.y);
    new_particle->color = emiter->start_color;
    new_particle->speed = rand_float(emiter->speed.x, emiter->speed.y);
    emiter->particle_count++;
}

void add_new_particle(s_appdata *adata, s_particle_src *emiter, \
s_particle *new_particle)
{
    sfVector2f xoff = emiter->spawn_offset_x;
    sfVector2f yoff = emiter->spawn_offset_y;
    float rand_x = rand_float(xoff.x, xoff.y);
    float rand_y = rand_float(yoff.x, yoff.y);
    sfVector2f pos = emiter->emiter_pos;
    pos.x += rand_x;
    pos.y += rand_y;

    sfSprite_setOrigin(new_particle->model, emiter->sprite_origin);
    sfSprite_setPosition(new_particle->model, pos);
    sfSprite_setScale(new_particle->model, emiter->start_size);
    sfSprite_setColor(new_particle->model, emiter->start_color);
    linked_add(emiter->particle_pool, new_particle);
}

void try_new_particle(s_appdata *adata, s_particle_src *emiter)
{
    float seconds = get_clock_seconds(emiter->delta_clock);
    if (rand_float(0, 100.0f) > emiter->spawn_chance * seconds * 5000) return;
    s_particle *new_particle = malloc(sizeof(s_particle));
    if (new_particle == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "mem_alloc"));
        return;
    }
    new_particle->active = 1;
    if (emiter->rotation_dir == random_dir) {
        int rot = rand_int(0, 1);
        new_particle->rotation_dir = rot ? clockwise : anticlockwise;
    } else {
        new_particle->rotation_dir = emiter->rotation_dir;
    }
    init_new_particle(adata, emiter, new_particle);
    add_new_particle(adata, emiter, new_particle);
}

void display_particles(s_appdata *adata, s_particle_src *emiter)
{
    linked_node *particles = emiter->particle_pool;
    sfRenderTexture *tex = emiter->render_tex->texture;

    while (particles != NULL && particles->data != NULL) {
        s_particle *cur = (s_particle *) particles->data;

        if (cur->active == sfTrue)
            sfRenderTexture_drawSprite(tex, cur->model, NULL);

        particles = particles->next;
    }
}

void accelerate_emiter(s_appdata *adata, char *id, int cycles)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    for (int i = 0; i < cycles; i++) {
        cycle_emiter(adata, emiter);
    }
}
