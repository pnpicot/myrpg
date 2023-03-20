/*
** EPITECH PROJECT, 2022
** Str_filter
** File description:
** Str_filter
*/

#include "../my.h"

char **str_filter(char **arr, int fn(const char *str))
{
    int count = 0;
    int ite = 0;
    while (arr[ite] != NULL) {
        if (fn(arr[ite])) count++;
        ite++;
    }
    char **result = malloc(sizeof(char *) * (count + 1));
    result[count] = NULL;
    ite = 0;
    count = 0;
    while (arr[ite] != NULL) {
        if (fn(arr[ite])) {
            result[count] = arr[ite];
            count++;
        }
        ite++;
    }
    return (result);
}
