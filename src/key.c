/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Key module
*/

#include "main.h"

int get_key(s_appdata *adata, int keycode)
{
    if (keycode <= sfKeyUnknown || keycode >= sfKeyCount)
        return (0);
    return (adata->keys[keycode]);
}

void set_key(s_appdata *adata, int keycode, int value)
{
    if (keycode <= sfKeyUnknown || keycode >= sfKeyCount)
        return;
    adata->keys[keycode] = value;
}

void init_keys(s_appdata *adata)
{
    adata->keys = malloc(sizeof(int) * sfKeyCount);

    for (int i = 0; i < sfKeyCount; i++) {
        adata->keys[i] = 0;
    }
}
