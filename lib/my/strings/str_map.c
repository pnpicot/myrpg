/*
** EPITECH PROJECT, 2022
** Str_map
** File description:
** Str_map
*/

#include "../my.h"

char **str_map(char **arr, char *fn(const char *str))
{
    int ite = 0;

    while (arr[ite] != NULL) {
        arr[ite] = fn(arr[ite]);
        ite++;
    }

    return (arr);
}
