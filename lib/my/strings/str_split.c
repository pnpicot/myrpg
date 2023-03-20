/*
** EPITECH PROJECT, 2022
** Libmy.a
** File description:
** Str_split function
*/

#include "../my.h"

char **str_split_next(int count, const char *str, char delimiter, int len)
{
    char **res = malloc(sizeof(char *) * (count + 1));
    int added = 0;
    char *current = malloc(sizeof(char) * len);
    int cur_len = 0;
    char prev = str[0];
    for (int i = 0; i <= len; i++) {
        if ((str[i] == delimiter && cur_len) || i == len) {
            current[cur_len] = '\0';
            res[added] = current;
            current = malloc(sizeof(char) * len);
            cur_len = 0;
            added++;
            continue;
        }
        prev = str[i];
        if (str[i] != delimiter) current[cur_len] = str[i];
        if (str[i] != delimiter) cur_len++;
    }
    res[count] = NULL;
    return (res);
}

char **str_split(const char *str, char delimiter)
{
    char prev = str[0];
    int len = my_strlen(str);
    int count = 0;
    int swap = 0;

    for (int i = 1; i < len; i++) {
        if (prev != delimiter && !swap) {
            count++;
            swap = 1;
        }

        if (prev == delimiter) swap = 0;

        prev = str[i];
    }

    if (!my_strlen(str)) count = 0;

    return (str_split_next(count, str, delimiter, len));
}
