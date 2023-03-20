/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Separation for get_dbl() function
*/

#include "../my.h"

void get_dbl_next(char **res, hd hld)
{
    (*res)[hld.wh_len + hld.dc_l + 1] = '\0';
    for (int i = 0; i < my_strlen(hld.wh_str); i++) {
        (*res)[i] = hld.wh_str[i];
    }
    (*res)[hld.wh_len] = '.';
    for (int i = hld.wh_len + 1; i <= hld.wh_len + my_strlen(hld.dc_s); i++) {
        (*res)[i] = hld.dc_s[i - (hld.wh_len + 1)];
    }
}
