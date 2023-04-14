/*
** EPITECH PROJECT, 2022
** convert
** File description:
** convert
*/

#include "../my.h"
#include <stdlib.h>

char *str_m_add(int count, ...)
{
    va_list args;
    va_start(args, count);

    char *res = va_arg(args, char *);
    char *save = NULL;

    for (int i = 0; i < count - 1; i++) {
        res = str_add(res, va_arg(args, char *));
        if (save != NULL)
            free(save);
        save = res;
    }

    va_end(args);

    return (res);
}

char *str_add(const char *s1, const char *s2)
{
    int s1_len = my_strlen(s1);
    int s2_len = my_strlen(s2);
    char *res = malloc(sizeof(char) * (s1_len + s2_len + 1));
    res[s1_len + s2_len] = '\0';

    for (int i = 0; i < s1_len; i++) {
        res[i] = s1[i];
    }

    for (int i = s1_len; i < s1_len + s2_len; i++) {
        res[i] = s2[i - s1_len];
    }

    return (res);
}
