/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Main file
*/

#include "include/main.h"

int main(int argc, char **argv)
{
    s_appdata *adata = malloc(sizeof(s_appdata));

    if (adata == NULL) {
        my_printf("[MyRPG] error: memory allocation failed.\n");
        return (84);
    }

    pre_init(adata);
    create_window(adata);

    return (adata->integers->exit_status);
}
