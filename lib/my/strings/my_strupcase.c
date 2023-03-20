/*
** EPITECH PROJECT, 2022
** my_strlowcase
** File description:
** Puts every letter of a string in uppercase
*/

#include "../my.h"

char *my_strupcase(const char *str)
{
    char *result = my_strdup(str);

    for (int i = 0; i < my_strlen(result); i++) {
        if (result[i] > 96 && result[i] < 123)
            result[i] -= 32;
    }

    return (result);
}
