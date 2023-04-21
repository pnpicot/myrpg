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

void update_ingame_ui(s_appdata *adata)
{
    update_ingame_fps(adata);
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
    add_to_container(adata, container, (s_ref) { get_text(adata, fps), TYPE_TEXT });
}

void init_stats_title(s_appdata *adata, char *container, char *rtex, char *rect_id)
{
    char *id = str_add(rect_id, "@[:title]");
    sfFloatRect rect = get_sprite_bounds(adata, rect_id);

    add_text(adata, id, 2);
    edit_text(adata, id, "STATS");
    set_text_font(adata, id, get_font(adata, "courier"));
    set_text_rtex(adata, id, rtex);
    add_to_container(adata, container, (s_ref) { get_text(adata, id), TYPE_TEXT });
    color_text(adata, id, sfWhite);
    resize_text(adata, id, 22);

    sfFloatRect bounds = get_text_bounds(adata, id);

    set_text_origin(adata, id, (sfVector2f) { bounds.width / 2, bounds.height / 2 });

    sfVector2f pos;
    pos.x = rect.left + (rect.width / 2);
    pos.y = rect.top + 18;

    move_text(adata, id, pos);
}

void init_stats_health(s_appdata *adata, char *container, char *rtex, char *rect_id)
{
    char *id = str_add(rect_id, "@[:health]");
    sfFloatRect rect = get_sprite_bounds(adata, rect_id);
    s_player *player = adata->player;

    add_bar(adata, id, 2);
    set_bar_rtex(adata, id, rtex);
    set_bar_min(adata, id, 0);
    set_bar_max(adata, id, player->health.y);
    set_bar_current(adata, id, player->health.x);

    sfVector2f pos;
    pos.x = rect.left + 30.0f;
    pos.y = rect.top + 55.0f;

    move_bar(adata, id, pos);
    color_bar(adata, id, get_color(130, 21, 9, 255), sfGreen);
    resize_bar(adata, id, (sfVector2f) { rect.width - 60.0f, 10.0f });
}

void init_stats_transference(s_appdata *adata, char *container, char *rtex, char *rect_id)
{
    char *id = str_add(rect_id, "@[:transference]");
    sfFloatRect rect = get_sprite_bounds(adata, rect_id);
    s_player *player = adata->player;

    add_bar(adata, id, 2);
    set_bar_rtex(adata, id, rtex);
    set_bar_min(adata, id, 0);
    set_bar_max(adata, id, player->transference.y);
    set_bar_current(adata, id, player->transference.x);

    sfVector2f pos;
    pos.x = rect.left + 30.0f;
    pos.y = rect.top + 75.0f;

    move_bar(adata, id, pos);
    color_bar(adata, id, sfDarkGray, sfWhite);
    resize_bar(adata, id, (sfVector2f) { rect.width - 60.0f, 10.0f });
}

void init_stats_text(s_appdata *adata, char *container, char *rtex, char *rect_id)
{
    char *id = str_add(rect_id, "@[:text]");
    sfFloatRect rect = get_sprite_bounds(adata, rect_id);
    s_player *player = adata->player;

    add_text(adata, id, 2);
    set_text_font(adata, id, get_font(adata, "courier"));
    color_text(adata, id, sfWhite);
    resize_text(adata, id, 18);
    set_text_rtex(adata, id, rtex);
    add_to_container(adata, container, (s_ref) { get_text(adata, id), TYPE_TEXT });
    edit_text(adata, id, "5 Atk / 2 Def / Trans. LV. 1");

    sfVector2f pos;
    pos.x = rect.left + 30.0f;
    pos.y = rect.top + 90.0f;

    move_text(adata, id, pos);

    player->stats = get_text(adata, id);
}

void init_ingame_stats(s_appdata *adata, char *container, char *rtex)
{
    char *id = get_str(adata, "stats_widget");
    float zoom = 4.0f;

    add_sprite(adata, id, 1);
    set_sprite_texture(adata, id, get_texture(adata, "stats_w"));
    set_sprite_rtex(adata, id, rtex);
    add_to_container(adata, container, (s_ref) { get_sprite(adata, id), TYPE_SPRITE });
    scale_sprite(adata, id, (sfVector2f) { zoom, zoom });

    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    sfFloatRect bounds = get_sprite_bounds(adata, id);

    move_sprite(adata, id, (sfVector2f) { 20.0f, win_h - 20.0f - bounds.height });
    init_stats_title(adata, container, rtex, id);
    init_stats_health(adata, container, rtex, id);
    init_stats_transference(adata, container, rtex, id);
    init_stats_text(adata, container, rtex, id);
}

void init_live_ingame_ui(s_appdata *adata)
{
    char *container = get_str(adata, "ctn_game");
    char *rtex = get_str(adata, "rtex_ui");

    init_ingame_fps(adata, container, rtex);
    init_ingame_stats(adata, container ,rtex);
}
