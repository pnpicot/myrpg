/*
** EPITECH PROJECT, 2022
** Format handling
** File description:
** First file
*/

#include "../my.h"

int is_format(char **arr, const char *format)
{
    int ite = 0;
    int len = my_strlen(format);

    while (arr[ite] != NULL) {
        char type = format[ite % len];

        if (type == 'd' && !is_num(arr[ite], 1)) return (0);
        if (type == 'n' && !is_num(arr[ite], 0)) return (0);
        if (type == 'f' && !is_num(arr[ite], 1) && !is_dec(arr[ite]))
            return (0);

        ite++;
    }

    return (1);
}
