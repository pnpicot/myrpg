/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Main file of the my_printf
*/

#include "../my.h"
#include <stdio.h>

int my_printf(const char *format, ...)
{
    va_list arg_list;
    va_start(arg_list, format);
    parser((char *) format, &arg_list);
    va_end(arg_list);
}
