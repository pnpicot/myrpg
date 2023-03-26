/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Window module
*/

#include "include/main.h"

void close_window(s_appdata *adata)
{
    free_sound(adata);
    sfRenderWindow_close(adata->win);
}

void window_loop(s_appdata *adata, float app_rate, \
float update_rate, float render_rate)
{
    sfEvent event;
    s_clocks *clocks = adata->clocks;

    while (sfRenderWindow_pollEvent(adata->win, &event)) {
        register_event(adata, event);
    }

    sfTime elapsed = sfClock_getElapsedTime(clocks->app_clock);
    float seconds = elapsed.microseconds / 1000000.0f;

    if (seconds >= app_rate) {
        update(adata, update_rate);
        render(adata, render_rate);

        sfRenderWindow_display(adata->win);
        sfClock_restart(clocks->app_clock);
    }
}

void run_window(s_appdata *adata)
{
    srand(time(NULL));

    float app_rate = get_float(adata, "app_rate");
    float update_rate = get_float(adata, "update_rate");
    float render_rate = get_float(adata, "render_rate");

    while (sfRenderWindow_isOpen(adata->win)) {
        window_loop(adata, app_rate, update_rate, render_rate);
    }
}

void create_window(s_appdata *adata)
{
    init(adata);
    post_init(adata);
    sfVideoMode mode = { get_int(adata, "win_w"), get_int(adata, "win_h"), 32 };
    sfRenderWindow* window;
    char *title = "MyRPG";
    window = sfRenderWindow_create(mode, title, sfClose | sfResize, NULL);
    if (!window) {
        adata->integers->exit_status = 84;
        return;
    }
    adata->win = window;
    int limit = get_int(adata, "max_frame_rate");
    sfRenderWindow_setFramerateLimit(adata->win, limit);
    run_window(adata);
    sfRenderWindow_destroy(window);
}
