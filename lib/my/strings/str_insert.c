/*
** EPITECH PROJECT, 2022
** Str_insert
** File description:
** Insert a string inside another string at specified pos
*/

#include "../my.h"

void str_insert_part(int part_len, char **res, char *part, int *res_adv)
{
    for (int j = 0; j < part_len; j++) {
        (*res)[(*res_adv)] = part[j];
        (*res_adv)++;
    }
}

void str_insert_next(int pos, char *part, char **res, char *str)
{
    int offset = 0;
    int res_adv = 0;
    int str_len = my_strlen(str);
    int part_len = my_strlen(part);
    int res_len = str_len + part_len;

    for (int i = 0; i < res_len; i++) {
        if (i == pos) {
            str_insert_part(part_len, res, part, &res_adv);

            offset = part_len;
            i += part_len - 1;
        } else {
            (*res)[res_adv] = str[i - offset];
            res_adv++;
        }
    }
}

char *str_insert(char *str, char *part, int pos)
{
    int str_len = my_strlen(str);
    int part_len = my_strlen(part);

    if (pos < 0 || pos > str_len) return (str);

    int res_len = str_len + part_len;
    char *res = malloc(sizeof(char) * (res_len + 1));
    int res_adv = 0;
    int offset = 0;

    res[res_len] = '\0';
    str_insert_next(pos, part, &res, str);

    return (res);
}
