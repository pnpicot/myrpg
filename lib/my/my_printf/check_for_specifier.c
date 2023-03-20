/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Parse elements
*/

#include "../my.h"
#include <stdarg.h>

const char *l_spes[] = {
    "d", "i", "u", "o", "x", "X", "f", "F", "e", "E", "g", "G", "a", "A",
    "c", "s", "p", "n", "b", "S"
};

int check_for_specifier(char *format, int start, flag *ptr_flag)
{
    if (in_list(substr(format, start, start), l_spes, 20)) {
        ptr_flag->spe = format[start];
        return start;
    }

    return -1;
}
