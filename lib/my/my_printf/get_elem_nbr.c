/*
** EPITECH PROJECT, 2022
** get_elem_nbr
** File description:
** get_elem_nbr
*/

#include "../my.h"

int get_elem_nbr(char *format)
{
    int i = 0;
    int a = 0;
    int compteur = 0;
    while (format[i] != '\0') {
        if (format[i] != '%' && a == 0) {
            compteur++;
            a = 1;
        }
        if (format[i] == '%') {
            compteur++;
            a = 0;
        }
        i++;
    }
    return (compteur);
}
