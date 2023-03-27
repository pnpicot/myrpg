/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Utilities module
*/

#include "../include/main.h"

sfColor get_grayscale(sfColor color)
{
    int average = (color.r + color.g + color.b) / 3;
    sfColor grayscale;

    grayscale.r = average;
    grayscale.g = average;
    grayscale.b = average;
    grayscale.a = color.a;

    return (grayscale);
}

float get_vec_dist(sfVector2f vec_a, sfVector2f vec_b)
{
    sfVector2f dist_vec;
    dist_vec.x = vec_a.x - vec_b.x;
    dist_vec.y = vec_a.y - vec_b.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));

    return (dist);
}

sfBool circle_contains(sfVector2f circle_pos, float radius, sfVector2f point)
{
    float dist = get_vec_dist(circle_pos, point);

    return (dist <= radius);
}

sfVector2f ivec_to_f(sfVector2i vec)
{
    return ((sfVector2f) { vec.x, vec.y });
}

sfVector2i fvec_to_i(sfVector2f vec)
{
    return ((sfVector2i) { vec.x, vec.y });
}
