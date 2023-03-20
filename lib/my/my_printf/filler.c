/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Returns a string with a specified amount of space
*/

#include <stddef.h>
#include "../my.h"

char *filler(int nb, int mode)
{
    nb = nb < 0 ? 0 : nb;
    char *res = malloc(sizeof(char) * (nb + 1));
    res[nb] = '\0';

    for (int i = 0; i < nb; i++) {
        res[i] = mode ? '0' : ' ';
    }

    return (res);
}
