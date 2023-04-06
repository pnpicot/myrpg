/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** id
*/

#include "../include/main.h"

char *get_id_sub(char *id, int index)
{
    char **blocks = str_m_split(id, 4, '@', ':', '[', ']');

    if (count_nil_str(blocks) - 1 < index) return (NULL);

    return (blocks[index + 1]);
}

char *replace_id(char *complete_id, int index, char *new_id)
{
    char **step = str_m_split(complete_id, 4, '@', ':', '[', ']');
    int i = 0;

    char *res = step[i];
    i++;

    while (step[i] != NULL) {
        res = str_m_add(4, res, "@[:", i == index + 1 ? new_id : step[i], "]");
        i++;
    }

    return (res);
}
