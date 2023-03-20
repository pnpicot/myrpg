/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Return the number of digits in a number
*/

#include "../my.h"

int get_nbr_len(long long nb)
{
    int count = 0;

    if (nb < 0) {
        count++;
        nb *= -1;
    }

    if (!nb) return 1;

    while (nb > 0) {
        nb /= 10;
        count++;
    }

    return (count);
}
