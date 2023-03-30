/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Setup module
*/

#include "main.h"

void move_mouse_light(s_appdata *adata)
{
    sfVector2f mouse = get_mouse(adata);

    move_light(adata, "mouse_light", mouse);
}

void update_live(s_appdata *adata)
{
    move_mouse_light(adata);
}

void init_live_light(s_appdata *adata)
{
    if (get_int(adata, "enable_shader")) {
        init_light_recommended(adata, 1);

        char *light_id = "mouse_light";

        add_light(adata, light_id);
        color_light(adata, light_id, sfWhite);
        set_light_inner(adata, light_id, 60.0f);
        set_light_outer(adata, light_id, 580.0f);
        set_light_intensity(adata, light_id, 38.0f);
    }
}

void init_live_textures(s_appdata *adata)
{
    int shader_enabled = get_int(adata, "enable_shader");
    char *rtex_game = get_str(adata, "rtex_game");
    char *rtex_ui = get_str(adata, "rtex_ui");
    char *rtex_menu = get_str(adata, "rtex_menu");

    add_rtex(adata, rtex_game, 9);
    set_rtex_clear(adata, rtex_game, sfTransparent);

    if (shader_enabled)
        set_rtex_blendmode(adata, rtex_game, sfBlendMultiply);

    add_rtex(adata, rtex_ui, 10);
    set_rtex_clear(adata, rtex_ui, sfTransparent);
    set_rtex_blendmode(adata, rtex_ui, sfBlendAlpha);

    add_rtex(adata, rtex_menu, 10);
    set_rtex_blendmode(adata, rtex_menu, sfBlendNone);
    set_rtex_clear(adata, rtex_menu, sfTransparent);
}

void init_live_states(s_appdata *adata)
{
    char *main_state = get_str(adata, "state_main");
    char *game_state = get_str(adata, "state_game");
    char *main_ctn = get_str(adata, "ctn_main");
    char *game_ctn = get_str(adata, "ctn_game");

    char *rtex_game = get_str(adata, "rtex_game");
    char *rtex_ui = get_str(adata, "rtex_ui");
    char *rtex_menu = get_str(adata, "rtex_menu");

    add_state(adata, main_state);
    add_state(adata, game_state);

    set_state_ingame(adata, game_state, sfTrue);

    add_container(adata, main_ctn);
    set_state_container(adata, main_state, get_container(adata, main_ctn));

    add_container(adata, game_ctn);
    set_state_container(adata, game_state, get_container(adata, game_ctn));

    add_state_rtex(adata, main_state, get_rtex(adata, rtex_menu));
    add_state_rtex(adata, game_state, get_rtex(adata, rtex_game));
    add_state_rtex(adata, game_state, get_rtex(adata, rtex_ui));
}

void init_live_main_menu(s_appdata *adata)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    char *container = get_str(adata, "ctn_main");
    char *rtex = get_str(adata, "rtex_menu");
    char *play_btn = get_str(adata, "play_btn");

    add_button(adata, play_btn, TYPE_RECT, 1);
    edit_button(adata, play_btn, "Play");
    set_button_font(adata, play_btn, get_font(adata, "lobster"));
    color_button_fg(adata, play_btn, sfWhite);
    color_button_bg(adata, play_btn, get_color(60, 60, 60, 255));
    set_button_rtex(adata, play_btn, rtex);
    add_to_container(adata, container, (s_ref) { get_button(adata, play_btn), TYPE_BUTTON });
    resize_button(adata, play_btn, (sfVector2f) { 250, 60 });
    set_button_origin(adata, play_btn, (sfVector2f) { 125, 30 });
    move_button(adata, play_btn, (sfVector2f) { win_w / 2, win_h / 2 });

    char *obj = str_add(play_btn, "@[:object]");

    add_object(adata, obj, (s_ref) { get_button(adata, play_btn), TYPE_BUTTON });
    set_object_hover_bg(adata, obj, get_color(90, 90, 90, 255));
    set_object_pressed_bg(adata, obj, get_color(120, 120, 120, 255));
}

void init_live(s_appdata *adata)
{
    init_live_light(adata);
    init_live_textures(adata);
    init_live_states(adata);
    init_live_main_menu(adata);

    switch_state(adata, get_str(adata, "state_main"));
}
