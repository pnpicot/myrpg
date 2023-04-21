/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Utilities module
*/

#include "main.h"

char *float_to_str(float value, int dec_count, int specifier)
{
    specifier = force_range(specifier, 0, 1);

    int whole, decimals;

    whole = (int) value;
    decimals = (f_abs(value) - f_abs(whole)) * my_pow(10, dec_count);

    char *whole_str = nbr_to_str(whole);
    char *decimals_str = nbr_to_str(decimals);
    char *res = "";

    res = str_m_add(3 + specifier, whole_str, ".", decimals_str, "f");

    return (res);
}
