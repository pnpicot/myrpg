/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Parse elements
*/

#include "../my.h"
#include <stdarg.h>
#include <stddef.h>

const char *l_mod[] = {
    "hh", "h", "ll", "l", "L"
};

int check_for_modifier(char *format, int start, flag *ptr_flag)
{
    char *str_nbr;
    int count = 0;

    while (format[start] != '\0') {
        char *one_c = substr(format, start, start);
        char *two_c = substr(format, start, start + 1);

        if (in_list(one_c, l_mod, 5) > 0 || in_list(two_c, l_mod, 5) > 0) {
            str_nbr = in_list(two_c, l_mod, 5) > 0 ? two_c : one_c;
            count++;
            break;
        } else {
            return -1;
        }

        start++;
    }

    ptr_flag->mod = count > 0 ? str_nbr : NULL;
    return (count == 0 ? -1 : start + (my_strlen(str_nbr) > 1 ? 1 : 0));
}
