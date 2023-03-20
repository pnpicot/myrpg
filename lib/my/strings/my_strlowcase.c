/*
** EPITECH PROJECT, 2022
** my_strlowcase
** File description:
** Puts every letter of a string in lowercase
*/

#include "../my.h"

char *my_strlowcase(char *str)
{
    int ite = 0;

    while (str[ite] != '\0') {
        if (str[ite] > 64 && str[ite] < 91) str[ite] += 32;
        ite++;
    }

    return str;
}
