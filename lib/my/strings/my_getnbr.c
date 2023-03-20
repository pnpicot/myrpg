/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** Function that returns a number based on a string
*/

#include "../my.h"

int my_strlen3(const char *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }

    return len;
}

long long my_pow(int nb, int power)
{
    long long res = nb;

    for (int i = 0; i < power - 1; i++) {
        res *= nb;
    }

    return power > 0 ? res : 1;
}

int my_to_int(char const *str)
{
    int neg = str[0] == '-' ? 1 : 0;
    long long res = 0;

    for (int i = neg ? 1 : 0; i < my_strlen3(str); i++) {
        int digit = str[i] - 48;

        res += digit * my_pow(10, my_strlen3(str) - 1 - i);
    }

    res = neg ? -1 * res : res;

    return res < -2147483648 || res > 2147483647 ? 0 : res;
}

int my_get_status(char c, int continue_, int found_int, int minuses)
{
    if (c > 47 && c < 58 && !continue_)
        return 0;
    else if (c == '-' && !minuses && !found_int && !continue_)
        return 1;
    else
        return 2;
}

int my_getnbr(char const *str)
{
    int minuses = 0;
    int found_int = 0;
    int continue_ = 0;
    int alloc_len = 0;
    char filter[my_strlen3(str) + 1];
    filter[my_strlen3(str)] = '\0';
    for (int i = 0; i < my_strlen3(str); i++) {
        int sta = my_get_status(str[i], continue_, found_int, minuses);
        alloc_len += !sta || sta == 1 ? 1 : 0;
        found_int += !sta ? 1 : 0;
        minuses += sta == 1 ? 1 : 0;
        filter[i] = !sta || sta == 1 ? '1' : '0';
    }
    char new_str[alloc_len + 1];
    new_str[alloc_len] = '\0';
    int count = 0;
    for (int i = 0; i < my_strlen3(str); i++) {
        if (filter[i] == '1' && ++count) new_str[count - 1] = str[i];
    }
    return my_to_int(new_str);
}
