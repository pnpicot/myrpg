/*
** EPITECH PROJECT, 2022
** Pow functions
** File description:
** Pow functions
*/

#include "../my.h"

float my_pow_f_or(float nb, int power)
{
    float res = nb;

    for (int i = 0; i < power - 1; i++) {
        res *= nb;
    }

    return power > 0 ? res : 1;
}

float my_pow_f(float nb, int power)
{
    float res = nb;

    for (int i = 0; i < my_abs(power) - 1; i++) {
        if (power < 0) {
            res = 1.0f / my_pow(nb, my_abs(power));
        } else {
            res *= nb;
        }
    }

    return (res);
}
