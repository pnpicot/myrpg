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

// int is_dec(const char *str)
// {
//     char **split = str_split(str, '.');
//     int len = my_strlen(str);
//     int sgl_dec = count_nil_str(split) == 1 && is_num(split[0], 1);
//     char last = str[len - 1];
//     int dbl_dec = count_nil_str(split) == 2 && (is_num_ch(last) || last == 'f');

//     if ((!sgl_dec && !dbl_dec) || (count_ch(str, '.') != 1 && !sgl_dec))
//             return (0);

//     if (!sgl_dec) {
//         char *dec_part = split[1];

//         if (last == 'f')
//             dec_part = substr(dec_part, 0, my_strlen(dec_part) - 2);

//         if (!is_num(dec_part, 0)) return (0);
//     }

//     if (!is_num(split[0], 1)) return (0);
//     return (1);
// }
