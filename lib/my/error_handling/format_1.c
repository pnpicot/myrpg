/*
** EPITECH PROJECT, 2022
** Format handling
** File description:
** First file
*/

#include "../my.h"

int is_num(const char *str, int dec)
{
    int len = my_strlen(str);
    int neg = 0;

    if (str[0] == '-' && dec) neg = 1;

    for (int i = neg; i < len; i++) {
        if (str[i] < 48 || str[i] > 57) return (0);
    }

    return (1);
}

int is_num_ch(char ch)
{
    if (ch < 48 || ch > 57) return (0);
    return (1);
}

int count_nil_str(char **arr)
{
    int ite = 0;

    while (arr[ite] != NULL) {
        ite++;
    }

    return (ite);
}

int count_ch(const char *str, char ch)
{
    int len = my_strlen(str);
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == ch) count++;
    }

    return (count);
}

int is_dec(const char *str)
{
    int len = my_strlen(str);
    int neg = 0;
    int dec = 0;
    int dec_count = 0;

    if (str[0] == '-')
        neg = 1;
    for (int i = neg; i < len; i++) {
        if (str[i] == '.') {
            dec = 1;
            dec_count++;
            continue;
        }
        if (dec && str[i] != 'f' && !is_num_ch(str[i]))
            return (0);
    }
    if (dec_count > 1)
        return (0);
    return (1);
}
