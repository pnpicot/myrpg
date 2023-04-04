/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** Function that returns a number based on a string
*/

#include "../my.h"

int in_str(const char *parent, const char *child)
{
    int streak = 0;
    int parent_size = my_strlen(parent);
    int child_size = my_strlen(child);

    for (int i = 0; i < parent_size; i++) {
        if (parent[i] == child[streak]) {
            streak++;
        } else {
            streak = 0;
        }

        if (streak == child_size) return (1);
    }

    return (0);
}