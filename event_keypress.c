/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Key pressed event module
*/

#include "include/main.h"

void register_keypress(s_appdata *adata, int keycode)
{
    s_ints *integers = adata->integers;

    if (keycode == sfKeyLShift) integers->capital = 1;

    integers->last_keycode = keycode;
}
