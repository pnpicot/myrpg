/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Parse elements
*/

#include "../my.h"
#include <stdarg.h>

const char *l_digits[] = {
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
};

int check_for_width(char *format, int start, flag *ptr_flag)
{
    char *str_nbr = malloc(my_strlen(format) + 1);
    str_nbr[my_strlen(format)] = '\0';
    int first = start;
    while (format[start] != '\0') {
        if (format[start] == '*') {
            ptr_flag->need_width = 1;
            return -2;
        }

        if (in_list(substr(format, start, start), l_digits, 10)) {
            str_nbr[start - first] = format[start];
        } else {
            str_nbr[start - first] = '\0';
            ptr_flag->width = my_strlen(str_nbr) > 0 ? my_getnbr(str_nbr) : 0;
            return (first == start ? -1 : start);
        }
        start++;
    }
    return (first == start ? -1 : start);
}
