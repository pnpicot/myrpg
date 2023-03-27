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
    sfVector2f top_left_pos;
    top_left_pos.x = rect.left;
    top_left_pos.y = rect.top;
    sfVector2f top_right_pos;
    top_right_pos.x = rect.left + rect.width;
    top_right_pos.y = rect.top;
    sfVector2f bottom_left_pos;
    bottom_left_pos.x = rect.left;
    bottom_left_pos.y = rect.top + rect.height;
    sfVector2f bottom_right_pos;
    bottom_right_pos.x = rect.left + rect.width;
    bottom_right_pos.y = rect.top + rect.height;
    sfBool top_left = circle_contains(circle_pos, radius, top_left_pos);
    sfBool top_right = circle_contains(circle_pos, radius, top_right_pos);
    sfBool bottom_left = circle_contains(circle_pos, radius, bottom_left_pos);
    sfBool bottom_right = circle_contains(circle_pos, radius, bottom_right_pos);
    return (top_left || top_right || bottom_left || bottom_right);
}
