/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Print double in scientific notation
*/

#include "../my.h"

int put_multiply_10(int nb)
{
    if (nb == 0) nb = 6;
    int res = 1;
    for (int i = 0; i <= nb; i++) {
        res *= 10;
    }
    return (res);
}

char *put_0(int nb)
{
    if (nb == 0) nb = 6;
    char *res = malloc(sizeof(char) * get_nbr_len(nb) + 1);
    res[get_nbr_len(nb)] = '\0';
    for (int i = 0; i < nb; i++) {
        res[i] = '0';
    }
    return (res);
}
