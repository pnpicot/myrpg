/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Key module
*/

#include "include/main.h"

int get_key(s_appdata *adata, int keycode)
{
    return (adata->keys[keycode]);
}

void init_keys(s_appdata *adata)
{
    adata->keys = malloc(sizeof(int) * (sfKeyZ - sfKeyA));

    for (int i = 0; i < sfKeyZ; i++) {
        adata->keys[i] = 0;
    }
}
