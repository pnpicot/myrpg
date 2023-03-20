/*
** EPITECH PROJECT, 2022
** my_str_isprintable
** File description:
** Returns if a string only contains printable chars
*/

#include "../my.h"

int my_str_isprintable(char const *str)
{
    int ite = 0;

    while (str[ite] != '\0') {
        if (!(str[ite] > 31 && str[ite] < 126)) return 0;
        ite++;
    }

    return 1;
}
