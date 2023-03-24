/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Utilities module
*/

#pragma once

#include "main.h"

sfBool in_range(float value, float min, float max);
float force_range(float value, float min, float max);
sfColor lighten(sfColor old, int value);
sfColor darken(sfColor old, int value);
sfColor get_color(int r, int g, int b, int a);
sfColor get_grayscale(sfColor color);
float get_vec_dist(sfVector2f vec_a, sfVector2f vec_b);
sfBool circle_contains(sfVector2f circle_pos, float radius, sfVector2f point);
sfVector2f ivec_to_f(sfVector2i vec);
sfVector2i fvec_to_i(sfVector2f vec);
int rand_int(int min, int max);
float rand_float(float min, float max);
sfVector2f rand_screen_pos(s_appdata *adata);
sfColor rand_color(sfUint8 alpha);
sfBool rect_intersects_circle(sfFloatRect rect, \
sfVector2f circle_pos, float radius);
sfVector2f get_mouse(s_appdata *adata);
float get_clock_seconds(sfClock *clock);
char *get_random_id(int len);
sfVector2f get_projected(sfVector2f origin, sfVector2f point, float dist);
sfColor rand_light_color(sfUint8 alpha);
