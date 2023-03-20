/*
** EPITECH PROJECT, 2022
** get_elem_nbr
** File description:
** get_elem_nbr
*/

#include "../my.h"
#include <stdarg.h>

int in_list(char *value, const char *list[], int end)
{
    for (int i = 0; i < end; i++) {
        if (!my_strcmp(list[i], value)) {
            return (my_strlen(list[i]));
        }
    }

    return (0);
}
