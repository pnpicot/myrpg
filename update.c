/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Update module
*/

#include "include/main.h"

void update(s_appdata *adata, float update_rate)
{
    s_clocks *clocks = adata->clocks;
    sfTime elapsed = sfClock_getElapsedTime(clocks->update_clock);
    float seconds = elapsed.microseconds / 1000000.0f;

    if (seconds >= update_rate) {
        s_ints *integers = adata->integers;
        sfTime input_elapsed = sfClock_getElapsedTime(clocks->input_clock);
        float input_seconds = input_elapsed.microseconds / 1000000.0f;

        slider_update_change(adata);
        input_update(adata);

        int can_input = input_seconds >= get_float(adata, "input_speed");
        int last_key = integers->last_keycode != -1;
        int last_input = adata->last_input != NULL;

        if (can_input && last_key && last_input) {
            input_type(adata, integers->last_keycode);
            sfClock_restart(clocks->input_clock);
        }

        sfClock_restart(clocks->update_clock);
    }
}
