/*
** EPITECH PROJECT, 2022
** Str join function
** File description:
** First file
*/

#include "../my.h"

void str_join_next(int d_len, char **res, char *delimiter, int a_len)
{
    for (int i = 0; i < d_len; i++) {
        (*res)[a_len] = delimiter[i];
        a_len++;
    }
}

void str_join_fill(char **words, char *delimiter, char **res)
{
    int ite = 0;
    int a_len = 0;
    int d_len = my_strlen(delimiter);

    while (words[ite] != NULL) {
        int w_len = my_strlen(words[ite]);

        for (int i = 0; i < w_len; i++) {
            (*res)[a_len] = words[ite][i];
            a_len++;
        }

        if (words[ite + 1] != NULL) {
            str_join_next(d_len, res, delimiter, a_len);
        }

        ite++;
    }
}

char *str_join(char **words, char *delimiter)
{
    int len = 0;
    int ite = 0;

    while (words[ite] != NULL) {
        len += my_strlen(words[ite]);
        ite++;
    }

    int d_len = my_strlen(delimiter);
    int res_len = len + ((ite - 1) * d_len);
    char *res = malloc(sizeof(char) * (res_len + 1));
    res[res_len] = '\0';

    str_join_fill(words, delimiter, &res);

    return (res);
}
