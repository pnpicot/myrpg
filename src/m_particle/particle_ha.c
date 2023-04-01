/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Particle module
*/

#include "../include/main.h"

void update_particle_scale(s_particle_src *emiter, s_particle *cur, \
float scale_speed, float delta)
{
    sfVector2f scale = sfSprite_getScale(cur->model);
    int in_x = emiter->start_size.x != emiter->end_size.x;
    int in_y = emiter->start_size.y != emiter->end_size.y;

    if (in_x || in_y) {
        sfVector2f scale_vec;
        scale_vec.x = emiter->end_size.x - scale.x;
        scale_vec.y = emiter->end_size.y - scale.y;

        float scale_dist = sqrt(pow(scale_vec.x, 2) + pow(scale_vec.y, 2));

        scale.x += ((scale_speed * delta) / scale_dist) * scale_vec.x;
        scale.y += ((scale_speed * delta) / scale_dist) * scale_vec.y;

        sfSprite_setScale(cur->model, scale);
    }
}

void update_particle_rotation(s_particle *cur, float delta, \
s_particle_src *emiter)
{
    float cur_angle = sfSprite_getRotation(cur->model);

    if (cur->rotation_dir == clockwise) {
        cur_angle += emiter->rotation_speed * delta;
        cur_angle -= cur_angle > 360.0f ? 360.0f : 0;
    } else {
        cur_angle -= emiter->rotation_speed * delta;
        cur_angle += cur_angle < 0 ? 360.0f : 0 ;
    }

    if (emiter->vortex_dir == clockwise) {
        cur->angle += cur->vortex_speed * delta;
    } else {
        cur->angle -= cur->vortex_speed * delta;
    }

    sfSprite_setRotation(cur->model, cur_angle);
}

void update_particle_color(s_particle *cur, s_particle_src *emiter)
{
    float color_lerp_max = ((float) cur->life / emiter->lerp_div);
    float factor = color_lerp_max / (float) emiter->life_time;

    cur->color = lerp_color(emiter->start_color, emiter->end_color, 1 - factor);

    sfSprite_setColor(cur->model, cur->color);
}

void update_particle_end(s_particle_src *emiter, s_particle *cur)
{
    sfVector2f xoff = emiter->spawn_offset_x;
    sfVector2f yoff = emiter->spawn_offset_y;
    float rand_x = rand_float(xoff.x, xoff.y);
    float rand_y = rand_float(yoff.x, yoff.y);
    sfVector2f new_pos = emiter->emiter_pos;
    sfVector2f vspeed = emiter->vortex_speed;

    new_pos.x += rand_x;
    new_pos.y += rand_y;

    sfSprite_setPosition(cur->model, new_pos);
    sfSprite_setScale(cur->model, emiter->start_size);
    sfSprite_setOrigin(cur->model, emiter->sprite_origin);
    sfSprite_setColor(cur->model, emiter->start_color);

    cur->vortex_speed = rand_float(vspeed.x, vspeed.y);
    cur->angle = rand_float(emiter->cone_range.x, emiter->cone_range.y);
    cur->color = emiter->start_color;
    cur->speed = rand_float(emiter->speed.x, emiter->speed.y);
    cur->life = emiter->life_time;
}

void update_particle_pos(s_particle *cur, float delta)
{
    sfVector2f pos = sfSprite_getPosition(cur->model);
    float dir = cur->angle * (3.14159f / 180);

    pos.x += (float) (cur->speed * delta * cos(dir));
    pos.y += (float) (cur->speed * delta * sin(dir));

    sfSprite_setPosition(cur->model, pos);
}
