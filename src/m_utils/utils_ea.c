/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Utilities module
*/

#include "../include/main.h"

sfColor lerp_color(sfColor from, sfColor to, float factor)
{
    sfColor res;
    res.r = from.r + (to.r - from.r) * factor;
    res.g = from.g + (to.g - from.g) * factor;
    res.b = from.b + (to.b - from.b) * factor;
    res.a = from.a + (to.a - from.a) * factor;

    return (res);
}

sfVector2f lerp_vec2(sfVector2f from, sfVector2f to, float factor)
{
    sfVector2f dot_from;
    dot_from.x = from.x * factor;
    dot_from.y = from.y * factor;

    sfVector2f dot_to;
    dot_to.x = to.x * (1.0f - factor);
    dot_to.y = to.y * (1.0f - factor);

    return (sfVector2f) { dot_from.x + dot_to.x, dot_from.y + dot_to.y };
}

float f_abs(float value)
{
    if (value < 0) value *= -1;

    return (value);
}
