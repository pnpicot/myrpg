/*
** EPITECH PROJECT, 2022
** String to float conversion
** File description:
** String to float conversion
*/

#include "../my.h"

float str_to_float(char *str)
{
    float nb = 0;
    if (!is_dec(str))
        return (0);
    char **parts = str_split(str, '.');
    nb = my_getnbr(parts[0]);
    if (parts[1] != NULL) {
        int dec_len = 0;
        for (int i = 0; parts[1][i] != '\0' && parts[1][i] >= '0' &&
        parts[1][i] <= '9'; i++)
            dec_len++;
        float dec = my_getnbr(parts[1]);
        for (int i = 0; i < dec_len; i++) {
            dec /= 10;
        }
        nb += (parts[0][0] == '-') ? -dec : dec;
    }
    for (int i = 0; parts[i] != NULL; i++)
        free(parts[i]);
    free(parts);
    return (nb);
}
