/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Parse elements
*/

#include "../my.h"
#include <stdarg.h>

const char *ls_flags[] = {
    "0", "#", " ", "+", "-"
};

int check_for_flags(char *format, int start, flag *ptr_flag)
{
    int first = start;
    while (format[start] != '\0') {
        if (format[start] == '0') ptr_flag->rzp = 1;
        if (format[start] == '#') ptr_flag->rp = 1;
        if (format[start] == ' ') ptr_flag->rsj = 1;
        if (format[start] == '+') ptr_flag->rfs = 1;
        if (format[start] == '-') ptr_flag->rlj = 1;
        if (!in_list(substr(format, start, start), ls_flags, 5))
            return (first == start ? -1 : start);

        start++;
    }
    return (first == start ? -1 : start);
}
