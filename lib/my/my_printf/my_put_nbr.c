/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** Print a given number
*/

#include "../my.h"
#include <unistd.h>

void my_putchar3(char c, int *counter)
{
    (*counter)++;
    write(1, &c, 1);
}

void my_put_str2(const char *str, int *counter)
{
    int count = 0;

    while (str[count] != '\0') {
        my_putchar3(str[count], counter);
        count++;
    }
}

int get_first_digit(int nb)
{
    while (nb > 10) {
        nb /= 10;
    }

    return nb;
}

int get_number_length(int nb)
{
    int count = 0;

    if (nb < 0) {
        count++;
        nb *= -1;
    }

    if (!nb) return 1;

    while (nb > 0) {
        nb /= 10;
        count++;
    }

    return (count);
}

int my_put_nbr(int nb, int *counter)
{
    if (nb < 0)
        my_putchar3('-', counter);
    else if (nb == -2147483648) {
        my_put_str2("2147483648", counter);
        return 0;
    }
    nb = nb < 0 ? -1 * nb : nb;
    int nb_len = get_number_length(nb);
    for (int i = 0; i < nb_len; i++) {
        my_putchar3(48 + get_first_digit(nb), counter);
        int mod = 1;

        for (int j = 0; j < get_number_length(nb) - 1; j++) {
            mod *= 10;
        }

        nb %= mod;
    }
    return 0;
}
