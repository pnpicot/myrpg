/*
** EPITECH PROJECT, 2022
** get_elem_nbr
** File description:
** get_elem_nbr
*/

#include "../my.h"

char *str_truncate(char *str, int nb)
{
    if (nb > my_strlen(str)) nb = my_strlen(str);
    char *res = malloc(sizeof(char) * (nb + 1));
    res[nb + 1] = '\0';

    for (int i = 0; i < nb; i++) {
        res[i] = str[i];
    }

    return (res);
}
