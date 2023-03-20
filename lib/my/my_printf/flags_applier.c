/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Returns a string with a specified amount of space
*/

#include <stddef.h>
#include "../my.h"

char *flag_prefix_int(char *res, flag element)
{
    char *final;
    int conv = 0;
    switch (element.spe) {
        case 'o':
            final = str_add("0", res);
            conv = 1;
            break;
        case 'x':
            final = str_add("0x", res);
            conv = 1;
            break;
        case 'X':
            final = str_add("0X", res);
            conv = 1;
            break;
        case 'b':
            final = str_add("b", res);
            conv = 1;
    }
    return conv ? final : res;
}
