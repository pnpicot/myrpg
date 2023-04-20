/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Window module
*/

#include "main.h"

void close_window(s_appdata *adata)
{
    if (adata->integers->in_game && get_int(adata, "dev_mode")) {
        switch_state(adata, "main_menu_0");
        return;
    } else if (my_strcmp(adata->current_state->id, get_str(adata, "state_main"))) {
        switch_state(adata, get_str(adata, "state_main"));
        return;
    }

    free_sound(adata);
    sfView_destroy(adata->view);
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

        // #warning TEMPORARY

        // static sfRenderTexture *rtext = NULL;
        // static sfVertexArray *varray = NULL;
        // static sfSprite *sprite = NULL;
        // static int anti_lag = 0;
        // if (rtext == NULL) {
        //     rtext = sfRenderTexture_create(adata->game_data->col_map_size.x, adata->game_data->col_map_size.y, 0);
        // }
        // if (varray == NULL) {
        //     varray = sfVertexArray_create();
        //     sfVertexArray_setPrimitiveType(varray, sfPoints);
        // }
        // if (sprite == NULL) {
        //     sprite = sfSprite_create();
        // }

        // if (anti_lag == 0) {
        //     sfVertexArray_clear(varray);
        //     for (int i = adata->game_data->col_map_size.y - 1; i >= 0; i--) {
        //         if (i % 8 != 0)
        //             continue;
        //         for (int j = adata->game_data->col_map_size.x - 1; j >= 0; j--) {
        //             if (j % 8 != 0)
        //                 continue;
        //             if (adata->game_data->col_map[i][j] != NULL) {
        //                 sfVertexArray_append(varray, (sfVertex) {
        //                     .position = (sfVector2f) {j, i},
        //                     .color = sfRed
        //                 });
        //             }
        //         }
        //     }

        //     sfRenderTexture_clear(rtext, sfTransparent);
        //     sfRenderTexture_drawVertexArray(rtext, varray, NULL);
        //     sfRenderTexture_display(rtext);
        //     sfSprite_setTexture(sprite, sfRenderTexture_getTexture(rtext), sfTrue);
        // }

        // anti_lag = (anti_lag + 1) % 25;
        // sfSprite_setPosition(sprite, (sfVector2f){-adata->game_data->view_pos.x,
        // -adata->game_data->view_pos.y});
        // sfRenderWindow_drawSprite(adata->win, sprite, NULL);

        // #warning TEMPORARY

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
    adata->fullscreen = 0;
    adata->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    sfRenderWindow_setView(adata->win, adata->view);
    int limit = get_int(adata, "max_frame_rate");
    sfRenderWindow_setFramerateLimit(adata->win, limit);
    run_window(adata);
    sfRenderWindow_destroy(window);
}
