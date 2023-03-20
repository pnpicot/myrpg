/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** Print a single char
*/

#include "../my.h"
#include <unistd.h>

void my_putchar(char c, int *counter)
{
    (*counter)++;
    write(1, &c, 1);
}
