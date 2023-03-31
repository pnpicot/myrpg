/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Main menu module
*/

#include "main.h"

void trigger_playbtn(s_appdata *adata, s_ref *ref)
{
    switch_state(adata, get_str(adata, "state_game"));
}

void trigger_settingsbtn(s_appdata *adata, s_ref *ref)
{
    switch_state(adata, get_str(adata, "state_settings"));
}

void trigger_quitbtn(s_appdata *adata, s_ref *ref)
{
    close_window(adata);
}

void init_main_quitbtn(s_appdata *adata, char *container, char *rtex)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    char *quit_btn = get_str(adata, "quit_btn");

    add_button(adata, quit_btn, TYPE_RECT, 1);
    edit_button(adata, quit_btn, "Quit");
    set_button_font(adata, quit_btn, get_font(adata, "lobster"));
    color_button_fg(adata, quit_btn, sfWhite);
    color_button_bg(adata, quit_btn, sfBlack);
    set_button_rtex(adata, quit_btn, rtex);
    add_to_container(adata, container, (s_ref) { get_button(adata, quit_btn), TYPE_BUTTON });
    resize_button(adata, quit_btn, (sfVector2f) { 450, 60 });
    set_button_origin(adata, quit_btn, (sfVector2f) { 225, 30 });
    move_button(adata, quit_btn, (sfVector2f) { win_w / 2, (win_h / 2) + 80 });
    set_button_out(adata, quit_btn, sfWhite, 2.0f);

    char *obj = str_add(quit_btn, "@[:object]");

    add_object(adata, obj, (s_ref) { get_button(adata, quit_btn), TYPE_BUTTON });
    set_object_hover_bg(adata, obj, get_color(30, 30, 30, 255));
    set_object_pressed_bg(adata, obj, get_color(50, 50, 50, 255));
    set_object_onclick(adata, obj, &trigger_quitbtn);
}

void init_main_settingsbtn(s_appdata *adata, char *container, char *rtex)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    char *settings_btn = get_str(adata, "settings_btn");

    add_button(adata, settings_btn, TYPE_RECT, 1);
    edit_button(adata, settings_btn, "Settings");
    set_button_font(adata, settings_btn, get_font(adata, "lobster"));
    color_button_fg(adata, settings_btn, sfWhite);
    color_button_bg(adata, settings_btn, sfBlack);
    set_button_rtex(adata, settings_btn, rtex);
    add_to_container(adata, container, (s_ref) { get_button(adata, settings_btn), TYPE_BUTTON });
    resize_button(adata, settings_btn, (sfVector2f) { 450, 60 });
    set_button_origin(adata, settings_btn, (sfVector2f) { 225, 30 });
    move_button(adata, settings_btn, (sfVector2f) { win_w / 2, win_h / 2 });
    set_button_out(adata, settings_btn, sfWhite, 2.0f);

    char *obj = str_add(settings_btn, "@[:object]");

    add_object(adata, obj, (s_ref) { get_button(adata, settings_btn), TYPE_BUTTON });
    set_object_hover_bg(adata, obj, get_color(30, 30, 30, 255));
    set_object_pressed_bg(adata, obj, get_color(50, 50, 50, 255));
    set_object_onclick(adata, obj, &trigger_settingsbtn);
}

void init_main_playbtn(s_appdata *adata, char *container, char *rtex)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    char *play_btn = get_str(adata, "play_btn");

    add_button(adata, play_btn, TYPE_RECT, 1);
    edit_button(adata, play_btn, "Play");
    set_button_font(adata, play_btn, get_font(adata, "lobster"));
    color_button_fg(adata, play_btn, sfWhite);
    color_button_bg(adata, play_btn, sfBlack);
    set_button_rtex(adata, play_btn, rtex);
    add_to_container(adata, container, (s_ref) { get_button(adata, play_btn), TYPE_BUTTON });
    resize_button(adata, play_btn, (sfVector2f) { 450, 60 });
    set_button_origin(adata, play_btn, (sfVector2f) { 225, 30 });
    move_button(adata, play_btn, (sfVector2f) { win_w / 2, (win_h / 2) - 80 });
    set_button_out(adata, play_btn, sfWhite, 2.0f);

    char *obj = str_add(play_btn, "@[:object]");

    add_object(adata, obj, (s_ref) { get_button(adata, play_btn), TYPE_BUTTON });
    set_object_hover_bg(adata, obj, get_color(30, 30, 30, 255));
    set_object_pressed_bg(adata, obj, get_color(50, 50, 50, 255));
    set_object_onclick(adata, obj, &trigger_playbtn);
}

void init_main_particles(s_appdata *adata, char *container, char *rtex)
{
    char *particles = get_str(adata, "main_part");
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");

    add_emiter(adata, particles);
    move_emiter(adata, particles, (sfVector2f) { win_w / 2, win_h / 2 });
    set_emiter_rtex(adata, particles, rtex);
    set_emiter_lifetime(adata, particles, 150000);
    set_emiter_particle_lifetime(adata, particles, 10500);
    set_emiter_spawnrate(adata, particles, 1.0f);
    set_emiter_particle_max(adata, particles, 1300);
    set_emiter_model(adata, particles, "gen");
    set_emiter_cone(adata, particles, (sfVector2f) { 0, 360.0f });
    set_emiter_particle_speed(adata, particles, (sfVector2f) { 530.0f, 950.0f });
    set_emiter_size_range(adata, particles, (sfVector2f) { 1.0f, 1.0f }, (sfVector2f) { -0.6f, -0.6f });
    set_emiter_colors(adata, particles, sfBlack, sfWhite);
    set_emiter_lerp_factor(adata, particles, 1.2f);
    set_emiter_vortex_dir(adata, particles, particle_clockwise);
    set_emiter_vortex_speed(adata, particles, (sfVector2f) { -30.0f, 150.0f });
    add_to_container(adata, get_str(adata, "ctn_main"), (s_ref) { get_emiter(adata, particles), TYPE_EMITER });
}

void init_live_main_menu(s_appdata *adata)
{
    char *container = get_str(adata, "ctn_main");
    char *rtex = get_str(adata, "rtex_menu");

    init_main_playbtn(adata, container, rtex);
    init_main_settingsbtn(adata, container, rtex);
    init_main_quitbtn(adata, container, rtex);
    init_main_particles(adata, container, rtex);
}
