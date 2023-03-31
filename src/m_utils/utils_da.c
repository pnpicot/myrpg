/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Utilities module
*/

#include "../include/main.h"

int rand_int(int min, int max)
{
    return ((rand() % (max - min + 1)) + min);
}

float rand_float(float min, float max)
{
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = max - min;
    float factor = random * diff;

    return (min + factor);
}

sfVector2f rand_screen_pos(s_appdata *adata)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    sfVector2f pos;

    pos.x = rand_float(0, (float) win_w);
    pos.y = rand_float(0, (float) win_h);

    return (pos);
}

sfColor rand_color(sfUint8 alpha)
{
    sfColor new_color;
    new_color.r = rand_int(0, 255);
    new_color.g = rand_int(0, 255);
    new_color.b = rand_int(0, 255);
    new_color.a = alpha ? rand_int(0, 255) : 255;

    return (new_color);
}

sfBool rect_intersects_circle(sfFloatRect rect, \
sfVector2f circle_pos, float radius)
{
    float half_x = rect.width / 2;
    float half_y = rect.height / 2;

    sfVector2f dist_vec;
    dist_vec.x = f_abs(circle_pos.x - (rect.left + half_x));
    dist_vec.y = f_abs(circle_pos.y - (rect.top + half_y));

    if (dist_vec.x > (half_x + radius)) return (sfFalse);
    if (dist_vec.y > (half_y + radius)) return (sfFalse);

    if (dist_vec.x <= half_x) return (sfTrue);
    if (dist_vec.y <= half_y) return (sfTrue);

    float corner_dist = pow(dist_vec.x - half_x, 2)
                      + pow(dist_vec.y - half_y, 2);

    return (corner_dist <= pow(radius, 2));
}
