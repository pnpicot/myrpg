/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Particle module
*/

#include "../include/main.h"

void add_emiter_first(s_appdata *adata, char *id, s_particle_src *new_emiter)
{
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
    new_emiter->speed = (sfVector2f) { 0, 0 };
    new_emiter->particle_count = 0;
    new_emiter->end_size = (sfVector2f) { 1.0f, 1.0f };
    new_emiter->start_size = (sfVector2f) { 1.0f, 1.0f };
    new_emiter->sprite_origin = (sfVector2f) { 0, 0 };
    new_emiter->spawn_offset_x = (sfVector2f) { 0, 0 };
    new_emiter->spawn_offset_y = (sfVector2f) { 0, 0 };
    new_emiter->cone_range = (sfVector2f) { 270.0f, 270.0f };
    new_emiter->delta_clock = sfClock_create();
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
    add_emiter_first(adata, id, new_emiter);
    new_emiter->vortex_dir = clockwise;
    new_emiter->vortex_speed = (sfVector2f) { 0, 0 };
    new_emiter->start_color = sfWhite;
    new_emiter->end_color = sfWhite;
    new_emiter->lerp_div = 1.0f;
    new_emiter->game_obj = sfFalse;
    new_emiter->active = sfTrue;
    linked_add(adata->lists->emiters, new_emiter);
}

void set_emiter_cone(s_appdata *adata, char *id, sfVector2f angle_range)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->cone_range = angle_range;
}

void set_emiter_colors(s_appdata *adata, char *id, sfColor start, sfColor end)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->start_color = start;
    emiter->end_color = end;
}

void set_emiter_lerp_factor(s_appdata *adata, char *id, float lerp_factor)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->lerp_div = lerp_factor;
}
