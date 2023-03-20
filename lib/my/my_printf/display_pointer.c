/*
** EPITECH PROJECT, 2022
** display
** File description:
** display
*/

#include <stddef.h>
#include "../my.h"

void display_pointer(void *ptr)
{
    int placehold = 0;
    my_putstr("0x", &placehold);
    long long nb = (long long) ptr;
    my_putstr(my_strlowcase(my_strdup(convert_base(nb, 16))), &placehold);
}

char *get_pointer(void *ptr)
{
    long long nb = (long long) ptr;
    char *address = my_strlowcase(my_strdup(convert_base(nb, 16)));
    int len = my_strlen(address) + 2;
    char *res = malloc(len + 1);
    res[len + 1] = '\0';

    res[0] = '0';
    res[1] = 'x';

    for (int i = 0; i < len - 2; i++) {
        res[i + 2] = address[i];
    }

    return res;
}
