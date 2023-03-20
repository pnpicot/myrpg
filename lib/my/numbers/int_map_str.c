/*
** EPITECH PROJECT, 2022
** Integer list handling
** File description:
** Map int list to str
*/

#include "../my.h"

char **int_map_str(int *list, int count)
{
    char **res = malloc(sizeof(char *) * (count + 1));

    for (int i = 0; i < count; i++) {
        res[i] = nbr_to_str(list[i]);
    }

    res[count] = NULL;

    return (res);
}
