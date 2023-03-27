/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Key pressed event module
*/

#include "main.h"

void register_keypress(s_appdata *adata, int keycode)
{
    s_ints *integers = adata->integers;
    s_clocks *clocks = adata->clocks;

    if (keycode == sfKeyLShift) integers->capital = 1;

    integers->last_keycode = keycode;

    if (adata->last_input != NULL) {
        input_type(adata, keycode);
        sfClock_restart(clocks->input_clock);
    }

    adata->keys[keycode] = 1;
}
