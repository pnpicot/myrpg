/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** id
*/

#include "../include/main.h"

char *replace_id(char *complete_id, int index, char *new_id)
{
    char **step = str_m_split(complete_id, 4, '@', ':', '[', ']');
    int i = 0;

    char *res = step[i];
    i++;

    while (step[i] != NULL) {
        res = str_m_add(4, res, "@[:", i == index ? new_id : step[i], "]");
        i++;
    }

    return (res);
}