/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Update module
*/

#include "main.h"

void update_fps(s_appdata *adata)
{
    s_clocks *clocks = adata->clocks;
    sfTime elapsed = sfClock_getElapsedTime(clocks->fps_clock);
    int fps = 1 / (elapsed.microseconds * 0.000001);
    sfTime disp_elapsed = sfClock_getElapsedTime(clocks->fps_display_clock);

    sfClock_restart(clocks->fps_clock);

    if (get_clock_seconds(clocks->fps_display_clock) >= 1.0f) {
        char *fps_c = nbr_to_str(fps);
        char *light_c = nbr_to_str(adata->integers->light_count);
        char *new_text = str_m_add(4, fps_c, " fps, ", light_c, " lights");
        edit_text(adata, "text_1", new_text);
        sfClock_restart(clocks->fps_display_clock);
    }
}

void update_next(s_appdata *adata, float update_rate, float input_seconds)
{
    if (adata->integers->in_game) {
        update_controls(adata);
        update_gameobjects(adata);
    }
    int can_input = input_seconds >= get_float(adata, "input_speed");
    int last_key = adata->integers->last_keycode != -1;
    int last_input = adata->last_input != NULL;
    if (can_input && last_key && last_input) {
        input_type(adata, adata->integers->last_keycode);
        sfClock_restart(adata->clocks->input_clock);
    }

    update_live(adata);

    if (get_int(adata, "dev_mode")) {
        update_current_wall(adata);
        update_fps(adata);
    }
}

void update(s_appdata *adata, float update_rate)
{
    float seconds = get_clock_seconds(adata->clocks->update_clock);

    if (seconds >= update_rate) {
        float input_seconds = get_clock_seconds(adata->clocks->input_clock);

        slider_update_change(adata);
        input_update(adata);
        transform_update(adata);
        update_animations(adata);
        update_player(adata);
        update_player_ui(adata);

        update_next(adata, update_rate, input_seconds);

        sfClock_restart(adata->clocks->update_clock);
    }
}
