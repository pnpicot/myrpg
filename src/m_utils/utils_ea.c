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

float f_abs(float value)
{
    if (value < 0) value *= -1;

    return (value);
}
