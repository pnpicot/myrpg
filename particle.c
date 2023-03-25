/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Particle module
*/

#include "include/main.h"

s_particle_src *get_emiter(s_appdata *adata, char *id)
{
    linked_node *emiters = adata->lists->emiters;

    while (emiters != NULL && emiters->data != NULL) {
        s_particle_src *cur = (s_particle_src *) emiters->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        emiters = emiters->next;
    }

    return (NULL);
}

void delete_emiter(s_appdata *adata, char *id)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *emiters = adata->lists->emiters;
    int ite = 0;

    while (emiters != NULL && emiters->data != NULL) {
        s_particle_src *cur = (s_particle_src *) emiters->data;

        if (!my_strcmp(cur->id, id)) {
            sfSprite_destroy(cur->particle_model);
            free(cur->particle_pool);
            break;
        }

        ite++;
        emiters = emiters->next;
    }

    linked_delete(&adata->lists->emiters, ite);
}

void set_emiter_lifetime(s_appdata *adata, char *id, int life_time)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->emiter_life = life_time;
}

void move_emiter(s_appdata *adata, char *id, sfVector2f pos)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->emiter_pos = pos;
}

void set_emiter_particle_lifetime(s_appdata *adata, char *id, int life_time)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->life_time = life_time;
}

void set_emiter_particle_max(s_appdata *adata, char *id, int max)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->particle_max = max;
}

void set_emiter_model(s_appdata *adata, char *id, sfSprite *model)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->particle_model = model;
}

void set_emiter_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_particle_src *emiter = get_emiter(adata, id);
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (emiter == NULL || rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->render_tex = rtex;
}

void set_emiter_rotation_dir(s_appdata *adata, char *id, int dir)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->rotation_dir = dir;
}

void set_emiter_rotation_speed(s_appdata *adata, char *id, float rotation_speed)
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

void set_emiter_particle_speed(s_appdata *adata, char *id, float particle_speed)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->speed = particle_speed;
}

void set_emiter_size_range(s_appdata *adata, char *id, sfVector2f start_size, sfVector2f end_size)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->start_size = start_size;
    emiter->end_size = end_size;
}

void add_emiter(s_appdata *adata, char *id)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    s_particle_src *new_emiter = malloc(sizeof(s_particle_src));

    if (new_emiter == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    new_emiter->emiter_life = 0;
    new_emiter->emiter_pos = (sfVector2f) { 0, 0 };
    new_emiter->id = id;
    new_emiter->life_time = 1;
    new_emiter->particle_max = 0;
    new_emiter->particle_model = NULL;
    new_emiter->particle_pool = linked_new();
    new_emiter->render_tex = NULL;
    new_emiter->rotation_dir = 0;
    new_emiter->rotation_speed = 0;
    new_emiter->spawn_chance = 0;
    new_emiter->speed = 0;
    new_emiter->particle_count = 0;
    new_emiter->end_size = (sfVector2f) { 1.0f, 1.0f };
    new_emiter->start_size = (sfVector2f) { 1.0f, 1.0f };

    linked_add(adata->lists->emiters, new_emiter);
}

void try_new_particle(s_appdata *adata, s_particle_src *emiter)
{
    // ...
}

void cycle_emiter(s_appdata *adata, s_particle_src *emiter)
{
    if (emiter->emiter_life <= 0) {
        delete_emiter(adata, emiter->id);
        return;
    }

    if (emiter->particle_count < emiter->particle_max)
        try_new_particle(adata, emiter);
}

void update_emiters(s_appdata *adata)
{
    linked_node *emiters = adata->lists->emiters;

    while (emiters != NULL && emiters->data != NULL) {
        s_particle_src *cur = (s_particle_src *) emiters->data;

        cycle_emiter(adata, cur);

        emiters = emiters->next;
    }
}
