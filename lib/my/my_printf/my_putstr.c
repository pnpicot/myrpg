/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** Function that displays a string
*/

#include "../my.h"
#include <unistd.h>

void my_putchar4(char c, int *counter)
{
    (*counter)++;
    ssize_t wr = write(1, &c, 1);
}

int my_putstr(char const *str, int *counter)
{
    int len = 0;

    while (str[len] != '\0') {
        my_putchar4(str[len], counter);
        len++;
    }
}
