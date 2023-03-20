/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** Allocates memory and copies a string in it
*/

#include "../my.h"

int my_strlen10(const char *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }

    return len;
}

char *my_strdup(char const *src)
{
    char * new = (char *) malloc(my_strlen10(src));

    for (int i = 0; i < my_strlen10(src); i++) {
        new[i] = src[i];
    }

    return new;
}
