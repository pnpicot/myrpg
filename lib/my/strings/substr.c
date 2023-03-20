/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Returns a substring
*/

#include "../my.h"

char *substr(const char *str, int start, int end)
{
    char *res = malloc(((end - start) + 2) * sizeof(char));
    res[(end - start) + 1] = '\0';
    int count = 0;

    for (int i = start; i <= end; i++) {
        res[count] = str[i];
        count++;
    }

    return res;
}
