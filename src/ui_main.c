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

void init_main_playbtn(s_appdata *adata, char *container, char *rtex)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    char *play_btn = get_str(adata, "play_btn");

    add_button(adata, play_btn, TYPE_RECT, 1);
    edit_button(adata, play_btn, "Play");
    set_button_font(adata, play_btn, get_font(adata, "lobster"));
    color_button_fg(adata, play_btn, sfWhite);
    color_button_bg(adata, play_btn, get_color(255, 255, 255, 10));
    set_button_rtex(adata, play_btn, rtex);
    add_to_container(adata, container, (s_ref) { get_button(adata, play_btn), TYPE_BUTTON });
    resize_button(adata, play_btn, (sfVector2f) { 300, 60 });
    set_button_origin(adata, play_btn, (sfVector2f) { 150, 30 });
    move_button(adata, play_btn, (sfVector2f) { win_w / 2, win_h / 2 });
    set_button_out(adata, play_btn, sfWhite, 2.0f);

    char *obj = str_add(play_btn, "@[:object]");

    add_object(adata, obj, (s_ref) { get_button(adata, play_btn), TYPE_BUTTON });
    set_object_hover_bg(adata, obj, get_color(255, 255, 255, 30));
    set_object_pressed_bg(adata, obj, get_color(255, 255, 255, 50));
    set_object_onclick(adata, obj, &trigger_playbtn);
}

void init_live_main_menu(s_appdata *adata)
{
    char *container = get_str(adata, "ctn_main");
    char *rtex = get_str(adata, "rtex_menu");

    init_main_playbtn(adata, container, rtex);
}
