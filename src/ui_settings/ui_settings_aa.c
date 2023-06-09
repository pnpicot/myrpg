/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Settings ui module
*/

#include "main.h"

void trigger_settings_backbtn(s_appdata *adata, s_ref *ref)
{
    close_window(adata);
}

void init_settings_backbtn(s_appdata *adata, char *container, char *rtex)
{
    char *back_btn = get_str(adata, "back_btn");

    add_button(adata, back_btn, TYPE_RECT, 1);
    edit_button(adata, back_btn, "Back");
    set_button_font(adata, back_btn, get_font(adata, "lobster"));
    color_button_fg(adata, back_btn, sfWhite);
    color_button_bg(adata, back_btn, get_color(255, 255, 255, 10));
    set_button_rtex(adata, back_btn, rtex);
    add_to_container(adata, container, (s_ref) {
    get_button(adata, back_btn), TYPE_BUTTON });
    resize_button(adata, back_btn, (sfVector2f) { 280, 60 });
    move_button(adata, back_btn, (sfVector2f) { 20, 20 });
    set_button_out(adata, back_btn, sfWhite, 2.0f);

    char *obj = str_add(back_btn, "@[:object]");

    add_object(adata, obj, (s_ref) { get_button(adata, back_btn), TYPE_BUTTON});
    set_object_hover_bg(adata, obj, get_color(255, 255, 255, 30));
    set_object_pressed_bg(adata, obj, get_color(255, 255, 255, 50));
    set_object_onclick(adata, obj, &trigger_settings_backbtn);
}

void init_load_backbtn(s_appdata *adata, char *container, char *rtex)
{
    char *back_btn = get_str(adata, "back_btn_load");

    add_button(adata, back_btn, TYPE_RECT, 1);
    edit_button(adata, back_btn, "Back");
    set_button_font(adata, back_btn, get_font(adata, "lobster"));
    color_button_fg(adata, back_btn, sfWhite);
    color_button_bg(adata, back_btn, get_color(255, 255, 255, 10));
    set_button_rtex(adata, back_btn, rtex);
    add_to_container(adata, container, (s_ref) {
    get_button(adata, back_btn), TYPE_BUTTON });
    resize_button(adata, back_btn, (sfVector2f) { 280, 60 });
    move_button(adata, back_btn, (sfVector2f) { 20, 20 });
    set_button_out(adata, back_btn, sfWhite, 2.0f);

    char *obj = str_add(back_btn, "@[:object]");

    add_object(adata, obj, (s_ref) { get_button(adata, back_btn), TYPE_BUTTON});
    set_object_hover_bg(adata, obj, get_color(255, 255, 255, 30));
    set_object_pressed_bg(adata, obj, get_color(255, 255, 255, 50));
    set_object_onclick(adata, obj, &trigger_settings_backbtn);
}

void init_settings_volumebtn(s_appdata *adata, char *container, char *rtex)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    char *volume_slider = get_str(adata, "volume_slider");
    add_slider(adata, volume_slider, 1);
    set_slider_rtex(adata, volume_slider, rtex);
    s_slider *slider = get_slider(adata, volume_slider);
    float mid = get_float(adata, "slider_length");
    float rad = get_float(adata, "slider_node_size");
    move_slider(adata, volume_slider, (sfVector2f) { (win_w / 2) -
    (mid / 2) + rad, win_h / 2 });
    add_to_container(adata, container, (s_ref) { get_slider(adata,
    volume_slider), TYPE_SLIDER });
    set_slider_min(adata, volume_slider, 0);
    set_slider_max(adata, volume_slider, 100);
    set_slider_onchange(adata, volume_slider, &change_volume);
}
