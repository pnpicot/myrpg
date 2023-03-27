/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Utilities module
*/

#include "../include/main.h"

sfBool in_range(float value, float min, float max)
{
    if (value >= min && value <= max) return (sfTrue);

    return (sfFalse);
}

float force_range(float value, float min, float max)
{
    if (value > max) value = max;
    else if (value < min) value = min;

    return (value);
}

sfColor lighten(sfColor old, int value)
{
    old.r = force_range(old.r + value, 0, 255);
    old.g = force_range(old.g + value, 0, 255);
    old.b = force_range(old.b + value, 0, 255);

    return (old);
}

sfColor darken(sfColor old, int value)
{
    old.r = force_range(old.r - value, 0, 255);
    old.g = force_range(old.g - value, 0, 255);
    old.b = force_range(old.b - value, 0, 255);

    return (old);
}

sfColor get_color(int r, int g, int b, int a)
{
    return ((sfColor) { r, g, b, a });
}
