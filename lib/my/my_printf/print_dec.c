/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Reproduce the behavior of %.[num]f flag
*/

#include "../my.h"

void print_dec(double value, int places)
{
    int placeholder = 0;
    double dec = value - (int) value;
    my_put_nbr((int) value, &placeholder);
    my_putchar('.', &placeholder);
    my_put_nbr(dec * my_pow(10, places), &placeholder);
}
