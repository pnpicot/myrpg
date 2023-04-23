/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** In-game ui module
*/

#include "main.h"

void update_ingame_fps(s_appdata *adata)
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
        free(light_c);
        free(fps_c);

        edit_text(adata, get_str(adata, "fps_text"), new_text);
        free(new_text);
        sfClock_restart(clocks->fps_display_clock);
    }
}

void update_ingame_stats(s_appdata *adata)
{
    s_player *player = adata->player;
    char *stats_widget = get_str(adata, "stats_widget");
    char *health_bar = str_add(stats_widget, "@[:health]");

    set_bar_max(adata, health_bar, player->health.y);
    set_bar_current(adata, health_bar, player->health.x);
}

void update_ingame_ui(s_appdata *adata)
{
    update_ingame_fps(adata);
    update_ingame_stats(adata);
}

void init_ingame_fps(s_appdata *adata, char *container, char *rtex)
{
    char *fps = get_str(adata, "fps_text");
    int win_h = get_int(adata, "win_h");

    add_text(adata, fps, 3);
    set_text_rtex(adata, fps, rtex);
    set_text_font(adata, fps, get_font(adata, "courier"));
    color_text(adata, fps, sfYellow);
    edit_text(adata, fps, "? fps");
    move_text(adata, fps, (sfVector2f) { 20, 20 });
    resize_text(adata, fps, 22);
    add_to_container(adata, container,
    (s_ref) { get_text(adata, fps), TYPE_TEXT });
}

void update_wave_count(s_appdata *adata)
{
    char *id = get_str(adata, "wave_count");
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    s_game *game_data = adata->game_data;

    edit_text(adata, id, str_add("wave ", nbr_to_str(game_data->wave_count)));

    sfFloatRect bounds = get_text_bounds(adata, id);
    sfVector2f pos;

    pos.x = win_w - bounds.width - 25.0f;
    pos.y = win_h - bounds.height - 20.0f;

    move_text(adata, id, pos);
}
