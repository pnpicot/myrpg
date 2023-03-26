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

void set_emiter_model(s_appdata *adata, char *id, char *texture_id)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfSprite *particle_model = sfSprite_create();
    sfSprite_setTexture(particle_model, get_texture(adata, texture_id), sfTrue);

    emiter->particle_model = particle_model;

    const sfTexture *tex = sfSprite_getTexture(particle_model);
    sfVector2u size = sfTexture_getSize(tex);

    emiter->sprite_origin = (sfVector2f) { size.x / 2, size.y / 2 };
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

void set_emiter_spawn_offset(s_appdata *adata, char *id, sfVector2f offset)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->spawn_offset = offset;
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

void set_emiter_vortex_dir(s_appdata *adata, char *id, int vortex_dir)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->vortex_dir = vortex_dir;
}

void set_emiter_vortex_speed(s_appdata *adata, char *id, sfVector2f vortex_speed)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    emiter->vortex_speed = vortex_speed;
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
    new_emiter->sprite_origin = (sfVector2f) { 0, 0 };
    new_emiter->spawn_offset = (sfVector2f) { 0, 0 };
    new_emiter->cone_range = (sfVector2f) { 270.0f, 270.0f };
    new_emiter->delta_clock = sfClock_create();
    new_emiter->vortex_dir = particle_clockwise;
    new_emiter->vortex_speed = (sfVector2f) { 0, 0 };
    new_emiter->start_color = sfWhite;
    new_emiter->end_color = sfWhite;
    new_emiter->lerp_div = 1.0f;

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

void try_new_particle(s_appdata *adata, s_particle_src *emiter)
{
    float nb = rand_float(0, 100.0f);

    if (nb <= emiter->spawn_chance) {
        s_particle *new_particle = malloc(sizeof(s_particle));

        if (new_particle == NULL) {
            my_printf(get_error(adata, "mem_alloc"));
            return;
        }

        new_particle->active = 1;

        if (emiter->rotation_dir == particle_random_dir) {
            int rot = rand_int(0, 1);

            new_particle->rotation_dir = rot ? particle_clockwise : particle_anticlockwise;
        } else {
            new_particle->rotation_dir = emiter->rotation_dir;
        }

        new_particle->model = sfSprite_copy(emiter->particle_model);
        new_particle->angle = rand_float(emiter->cone_range.x, emiter->cone_range.y);
        new_particle->life = emiter->life_time;
        new_particle->vortex_speed = rand_float(emiter->vortex_speed.x, emiter->vortex_speed.y);
        new_particle->color = emiter->start_color;

        emiter->particle_count++;

        float rand_x = rand_float(emiter->spawn_offset.x, emiter->spawn_offset.y);
        float rand_y = rand_float(emiter->spawn_offset.x, emiter->spawn_offset.y);
        sfVector2f pos = emiter->emiter_pos;
        pos.x += rand_x;
        pos.y += rand_y;

        sfSprite_setOrigin(new_particle->model, emiter->sprite_origin);
        sfSprite_setPosition(new_particle->model, pos);
        sfSprite_setScale(new_particle->model, emiter->start_size);
        sfSprite_setColor(new_particle->model, emiter->start_color);
        linked_add(emiter->particle_pool, new_particle);
    }
}

void display_particles(s_appdata *adata, s_particle_src *emiter)
{
    linked_node *particles = emiter->particle_pool;

    while (particles != NULL && particles->data != NULL) {
        s_particle *cur = (s_particle *) particles->data;

        sfRenderTexture_drawSprite(emiter->render_tex->texture, cur->model, NULL);

        particles = particles->next;
    }
}

void update_particles(s_appdata *adata, s_particle_src *emiter)
{
    linked_node *particles = emiter->particle_pool;
    float delta = get_clock_seconds(emiter->delta_clock);
    float render_rate = get_float(adata, "render_rate");
    float scale_speed = get_vec_dist(emiter->start_size, emiter->end_size) / ((float) emiter->life_time * render_rate);

    while (particles != NULL && particles->data != NULL) {
        s_particle *cur = (s_particle *) particles->data;
        sfVector2f pos = sfSprite_getPosition(cur->model);
        sfVector2f scale = sfSprite_getScale(cur->model);
        float cur_angle = sfSprite_getRotation(cur->model);
        float dir = cur->angle * (3.14159f / 180);

        pos.x += (float) (emiter->speed * delta * cos(dir));
        pos.y += (float) (emiter->speed * delta * sin(dir));

        sfSprite_setPosition(cur->model, pos);

        if (emiter->start_size.x != emiter->end_size.x || emiter->start_size.y != emiter->end_size.y) {
            sfVector2f scale_vec;
            scale_vec.x = emiter->end_size.x - scale.x;
            scale_vec.y = emiter->end_size.y - scale.y;

            float scale_dist = sqrt(pow(scale_vec.x, 2) + pow(scale_vec.y, 2));

            scale.x += ((scale_speed * delta) / scale_dist) * scale_vec.x;
            scale.y += ((scale_speed * delta) / scale_dist) * scale_vec.y;

            sfSprite_setScale(cur->model, scale);
        }

        if (cur->rotation_dir == particle_clockwise) {
            cur_angle += emiter->rotation_speed * delta;

            if (cur_angle > 360.0f) cur_angle -= 360.0f;
        } else {
            cur_angle -= emiter->rotation_speed * delta;

            if (cur_angle < 0) cur_angle += 360.0f ;
        }

        if (emiter->vortex_dir == particle_clockwise) {
            cur->angle += cur->vortex_speed * delta;
        } else {
            cur->angle -= cur->vortex_speed * delta;
        }

        sfSprite_setRotation(cur->model, cur_angle);

        float color_factor = ((float) cur->life / emiter->lerp_div) / (float) emiter->life_time;
        color_factor = 1 - color_factor;

        cur->color = lerp_color(emiter->start_color, emiter->end_color, color_factor);

        sfSprite_setColor(cur->model, cur->color);

        cur->life--;

        if ((scale.x <= 0.05f && scale.y <= 0.05f) || cur->life <= 0) {
            float rand_x = rand_float(emiter->spawn_offset.x, emiter->spawn_offset.y);
            float rand_y = rand_float(emiter->spawn_offset.x, emiter->spawn_offset.y);
            sfVector2f new_pos = emiter->emiter_pos;

            new_pos.x += rand_x;
            new_pos.y += rand_y;

            sfSprite_setPosition(cur->model, new_pos);
            sfSprite_setScale(cur->model, emiter->start_size);
            sfSprite_setOrigin(cur->model, emiter->sprite_origin);
            sfSprite_setColor(cur->model, emiter->start_color);

            cur->vortex_speed = rand_float(emiter->vortex_speed.x, emiter->vortex_speed.y);
            cur->angle = rand_float(emiter->cone_range.x, emiter->cone_range.y);
            cur->color = emiter->start_color;
            cur->life = emiter->life_time;
        }

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

    // emiter->emiter_life--;
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
