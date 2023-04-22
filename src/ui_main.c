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
    set_container_active(adata, get_str(adata, "ctn_inv"), 0);
    set_container_active(adata, get_str(adata, "ctn_quest"), 0);
    set_container_active(adata, get_str(adata, "ctn_skill"), 0);
    set_rect_active(adata, get_str(adata, "skill_tree"), 0);
    set_text_active(adata, str_add(get_str(adata, "skill_tree"),
    "@[:title]"), 0);
}

void trigger_settingsbtn(s_appdata *adata, s_ref *ref)
{
    switch_state(adata, get_str(adata, "state_settings"));
}

void trigger_quitbtn(s_appdata *adata, s_ref *ref)
{
    close_window(adata);
}

void trigger_savebtn(s_appdata *adata, s_ref *ref)
{
    save_game(adata);
}

void trigger_loadbtn(s_appdata *adata, s_ref *ref)
{
    switch_state(adata, get_str(adata, "state_load"));
}

void init_main_quitbtn(s_appdata *adata, char *container, char *rtex)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    char *quit_btn = get_str(adata, "quit_btn");
    add_button(adata, quit_btn, TYPE_RECT, 2);
    edit_button(adata, quit_btn, "Quit");
    set_button_font(adata, quit_btn, get_font(adata, "lobster"));
    color_button_fg(adata, quit_btn, sfWhite);
    color_button_bg(adata, quit_btn, sfBlack);
    set_button_rtex(adata, quit_btn, rtex);
    add_to_container(adata, container,
    (s_ref) { get_button(adata, quit_btn), TYPE_BUTTON });
    resize_button(adata, quit_btn, (sfVector2f) { 450, 60 });
    set_button_origin(adata, quit_btn, (sfVector2f) { 225, 30 });
    move_button(adata, quit_btn, (sfVector2f) { win_w / 2, (win_h / 2) + 160 });
    set_button_out(adata, quit_btn, sfWhite, 2.0f);
    char *obj = str_add(quit_btn, "@[:object]");
    add_object(adata, obj, (s_ref) {get_button(adata, quit_btn), TYPE_BUTTON});
    set_object_hover_bg(adata, obj, get_color(30, 30, 30, 255));
    set_object_pressed_bg(adata, obj, get_color(50, 50, 50, 255));
    set_object_onclick(adata, obj, &trigger_quitbtn);
}

void init_main_settingsbtn(s_appdata *adata, char *container, char *rtex)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    char *set_btn = get_str(adata, "settings_btn");
    add_button(adata, set_btn, TYPE_RECT, 2);
    edit_button(adata, set_btn, "Settings");
    set_button_font(adata, set_btn, get_font(adata, "lobster"));
    color_button_fg(adata, set_btn, sfWhite);
    color_button_bg(adata, set_btn, sfBlack);
    set_button_rtex(adata, set_btn, rtex);
    add_to_container(adata, container,
    (s_ref) {get_button(adata, set_btn), TYPE_BUTTON });
    resize_button(adata, set_btn, (sfVector2f) { 450, 60 });
    set_button_origin(adata, set_btn, (sfVector2f) { 225, 30 });
    move_button(adata, set_btn, (sfVector2f){win_w / 2, (win_h / 2) + 80});
    set_button_out(adata, set_btn, sfWhite, 2.0f);
    char *obj = str_add(set_btn, "@[:object]");
    add_object(adata, obj, (s_ref){get_button(adata, set_btn), TYPE_BUTTON});
    set_object_hover_bg(adata, obj, get_color(30, 30, 30, 255));
    set_object_pressed_bg(adata, obj, get_color(50, 50, 50, 255));
    set_object_onclick(adata, obj, &trigger_settingsbtn);
}

void init_main_playbtn(s_appdata *adata, char *container, char *rtex)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    char *play_btn = get_str(adata, "play_btn");
    add_button(adata, play_btn, TYPE_RECT, 2);
    edit_button(adata, play_btn, "Play");
    set_button_font(adata, play_btn, get_font(adata, "lobster"));
    color_button_fg(adata, play_btn, sfWhite);
    color_button_bg(adata, play_btn, sfBlack);
    set_button_rtex(adata, play_btn, rtex);
    add_to_container(adata, container,
    (s_ref) { get_button(adata, play_btn), TYPE_BUTTON });
    resize_button(adata, play_btn, (sfVector2f) { 450, 60 });
    set_button_origin(adata, play_btn, (sfVector2f) { 225, 30 });
    move_button(adata, play_btn, (sfVector2f) { win_w / 2, (win_h / 2) - 160 });
    set_button_out(adata, play_btn, sfWhite, 2.0f);
    char *obj = str_add(play_btn, "@[:object]");
    add_object(adata, obj, (s_ref) {get_button(adata, play_btn), TYPE_BUTTON});
    set_object_hover_bg(adata, obj, get_color(30, 30, 30, 255));
    set_object_pressed_bg(adata, obj, get_color(50, 50, 50, 255));
    set_object_onclick(adata, obj, &trigger_playbtn);
}

void init_main_savebtn(s_appdata *adata, char *container, char *rtex)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    char *save_btn = get_str(adata, "save_btn");
    add_button(adata, save_btn, TYPE_RECT, 2);
    edit_button(adata, save_btn, "Save");
    set_button_font(adata, save_btn, get_font(adata, "lobster"));
    color_button_fg(adata, save_btn, sfWhite);
    color_button_bg(adata, save_btn, sfBlack);
    set_button_rtex(adata, save_btn, rtex);
    add_to_container(adata, container,
    (s_ref) { get_button(adata, save_btn), TYPE_BUTTON });
    resize_button(adata, save_btn, (sfVector2f) { 450, 60 });
    set_button_origin(adata, save_btn, (sfVector2f) { 225, 30 });
    move_button(adata, save_btn, (sfVector2f) { win_w / 2, win_h / 2 });
    set_button_out(adata, save_btn, sfWhite, 2.0f);
    char *obj = str_add(save_btn, "@[:object]");
    add_object(adata, obj, (s_ref) {get_button(adata, save_btn), TYPE_BUTTON});
    set_object_hover_bg(adata, obj, get_color(30, 30, 30, 255));
    set_object_pressed_bg(adata, obj, get_color(50, 50, 50, 255));
    set_object_onclick(adata, obj, &trigger_savebtn);
}

void init_main_loadbtn(s_appdata *adata, char *container, char *rtex)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    char *save_btn = get_str(adata, "load_btn");
    add_button(adata, save_btn, TYPE_RECT, 2);
    edit_button(adata, save_btn, "Load game");
    set_button_font(adata, save_btn, get_font(adata, "lobster"));
    color_button_fg(adata, save_btn, sfWhite);
    color_button_bg(adata, save_btn, sfBlack);
    set_button_rtex(adata, save_btn, rtex);
    add_to_container(adata, container,
    (s_ref) { get_button(adata, save_btn), TYPE_BUTTON });
    resize_button(adata, save_btn, (sfVector2f) { 450, 60 });
    set_button_origin(adata, save_btn, (sfVector2f) { 225, 30 });
    move_button(adata, save_btn, (sfVector2f) { win_w / 2, (win_h / 2) - 80 });
    set_button_out(adata, save_btn, sfWhite, 2.0f);
    char *obj = str_add(save_btn, "@[:object]");
    add_object(adata, obj, (s_ref) {get_button(adata, save_btn), TYPE_BUTTON});
    set_object_hover_bg(adata, obj, get_color(30, 30, 30, 255));
    set_object_pressed_bg(adata, obj, get_color(50, 50, 50, 255));
    set_object_onclick(adata, obj, &trigger_loadbtn);
}

void init_main_particles_n(s_appdata *adata, char *ptc)
{
    set_emiter_colors(adata, ptc, sfGreen, sfBlue);
    set_emiter_lerp_factor(adata, ptc, 1.0f);
    set_emiter_vortex_dir(adata, ptc, clockwise);
    set_emiter_vortex_speed(adata, ptc, (sfVector2f) { -20.0f, 20.0f });
    add_to_container(adata, get_str(adata, "ctn_main"),
    (s_ref) { get_emiter(adata, ptc), TYPE_EMITER });

}

void init_main_particles(s_appdata *adata, char *container, char *rtex)
{
    char *ptc = get_str(adata, "main_part");
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");

    add_emiter(adata, ptc);
    move_emiter(adata, ptc, (sfVector2f) { win_w / 2, win_h + 30.0f });
    set_emiter_rtex(adata, ptc, rtex);
    set_emiter_lifetime(adata, ptc, 150000);
    set_emiter_particle_lifetime(adata, ptc, 11500);
    set_emiter_spawnrate(adata, ptc, 1.0f);
    set_emiter_particle_max(adata, ptc, 1300);
    set_emiter_rotation_dir(adata, ptc, random_dir);
    set_emiter_rotation_speed(adata, ptc, 25.0f);
    set_emiter_model(adata, ptc, "gen");
    set_emiter_spawn_xoffset(adata, ptc, (sfVector2f){-(win_w / 2), win_w / 2});
    set_emiter_particle_speed(adata, ptc, (sfVector2f) {150.0f, 350.0f});
    set_emiter_size_range(adata, ptc, (sfVector2f) {2.0f, 2.0f },
    (sfVector2f) { 0, 0 });
    init_main_particles_n(adata, ptc);
}

void init_live_main_menu(s_appdata *adata)
{
    char *container = get_str(adata, "ctn_main");
    char *rtex = get_str(adata, "rtex_menu");

    init_main_playbtn(adata, container, rtex);
    init_main_savebtn(adata, container, rtex);
    init_main_loadbtn(adata, container, rtex);
    init_main_settingsbtn(adata, container, rtex);
    init_main_quitbtn(adata, container, rtex);
    init_main_particles(adata, container, rtex);
}
