/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** Reproduce the behavior of strcmp function
*/

#include "../my.h"

int my_strlen4(const char *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }

    return len;
}

int my_strcmp(char const *s1, char const *s2)
{
    if (s1 == NULL || s2 == NULL) return (-1);

    int s1_len = my_strlen4(s1);
    int s2_len = my_strlen4(s2);
    int len = s1_len > s2_len ? s1_len : s2_len;
    int found = 0;

    for (int i = 0; i < len; i++) {
        if (s1[i] == s2[i]) {
            found++;
        } else {
            return s1[i] > s2[i] ? 1 : -1;
        }
    }

    return (found != len);
}
