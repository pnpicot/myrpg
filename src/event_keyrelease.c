/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Key release event module
*/

#include "main.h"

void register_keyrelease(s_appdata *adata, int keycode)
{
    s_ints *integers = adata->integers;

    if (keycode == sfKeyEscape) {
        close_window(adata);
        return;
    }

    if (keycode == sfKeyLShift) integers->capital = 0;

    if (adata->last_input != NULL) {
        integers->last_keycode = -1;
        return;
    }

    adata->keys[keycode] = 0;
}
