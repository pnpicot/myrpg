/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Print str for %S flag
*/

#include "../my.h"

char *put_oct(char c)
{
    char *res = malloc(6 * sizeof(char));
    res[5] = '\0';
    res[0] = '\\';
    char *oct = convert_base((unsigned char) c, 8);

    for (int i = 1; i < 4 - my_strlen(oct); i++) {
        res[i] = '0';
    }

    int count = 0;

    for (int i = 4 - my_strlen(oct); i < 4; i++) {
        if (i < 0)
            i = 0;
        res[i] = oct[count];
        count++;
    }

    return (res);
}

char *put_printable(const char *str)
{
    int oct_count = 0;
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] > 31 && str[i] < 127) oct_count++;
    }
    int alloc = (my_strlen(str) - oct_count) + (oct_count * 4);
    char *res = malloc(sizeof(char) * (alloc + 1));
    res[alloc + 1] = '\0';
    int index = 0;
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] > 31 && str[i] < 127) {
            res[index] = str[i];
            index++;
            continue;
        }
        for (int j = 0; j < 4; j++) {
            res[index] = put_oct((unsigned char) str[i])[j];
            index++;
        }
    }
    return (res);
}
