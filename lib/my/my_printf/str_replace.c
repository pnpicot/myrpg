/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Replace a string with another
*/

#include "../my.h"
#include <stdlib.h>

void str_rep(char **str, char *replace)
{
    *str = malloc(my_strlen(replace) + 1);
    (*str)[my_strlen(replace)] = '\0';

    for (int i = 0; i < my_strlen(replace); i++) {
        (*str)[i] = replace[i];
    }
}
