/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Get the number of whitespaces for a field width
*/

#include "../my.h"

int gp_int(int nb, int field_width)
{
    return (field_width - get_nbr_len(nb));
}

int gp_str(const char *str, int field_width)
{
    return (field_width - my_strlen(str));
}

int gp_dec(double value, int field_width, int pre)
{
    double dec = value - (int) value;
    dec *= my_pow(10, pre);
    int length = get_nbr_len((int) value) + get_nbr_len((int) dec) + 1;
    if (dec == 0) return (field_width - (3 + (pre - 1)));
    return (field_width - length);
}
