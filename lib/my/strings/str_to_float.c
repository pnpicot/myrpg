/*
** EPITECH PROJECT, 2022
** String to float conversion
** File description:
** String to float conversion
*/

#include "../my.h"

float str_to_float(char *str)
{
    if (!is_dec(str)) return (0);

    int str_len = my_strlen(str);

    if (str[str_len - 1] == 'f') {
        str = substr(str, 0, str_len - 2);
        str_len--;
    }

    char **parts = str_split(str, '.');

    if (parts[1] == NULL) return (my_getnbr(parts[0]));
    char *whole = parts[0];
    char *dec = parts[1];
    int dec_len = my_strlen(dec);
    float res = 0.0f;
    res += my_getnbr(parts[0]);
    int ml = parts[0][0] == '-' ? -1 : 1;
    res += ((float) my_getnbr(dec) * my_pow_f(10.0f, -1 * dec_len)) * ml;
    return (res);
}
