/*
** EPITECH PROJECT, 2022
** convert
** File description:
** convert
*/

#include "../my.h"
#include <stddef.h>

char *convert_base(int nb, int base)
{
    int reste = 0;
    char *result;
    int i = 0;
    int temp = nb;
    while (temp > 0) {
        temp /= base;
        i++;
    }
    result = malloc(i + 1);
    result[i + 1] = '\0';
    i--;
    while (nb > 0) {
        if (nb % base >= 10 && base == 16)
            result[i] = nb % base + 55;
        else
            result[i] = nb % base + 48;
        nb /= base;
        i--;
    }
    return (result);
}
