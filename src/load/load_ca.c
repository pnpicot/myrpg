/*
** EPITECH PROJECT, 2023
** load
** File description:
** load_ca
*/

#include "main.h"

void load_game(s_appdata *adata, s_ref *ref)
{
    char *input_load = get_str(adata, "input_load");
    const char *input_text = get_input_str(adata, input_load);
    char *path = str_add("bonus/saves/", input_text);
    char *content = file_extract(path);
    if (open(path, O_RDONLY) != -1)
        modify_game(adata, content);
    (void)ref;
}

void init_load_input(s_appdata *adata, char *container, char *rtex)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    char *input_load = get_str(adata, "input_load");
    add_input(adata, input_load, 7);
    set_input_font(adata, input_load, get_font(adata, "lobster"));
    set_input_rtex(adata, input_load, rtex);
    set_input_maxlength(adata, input_load, 40);
    set_input_placeholder(adata, input_load, "Enter path...");
    set_input_align(adata, input_load, "center");
    add_to_container(adata, container, (s_ref) {
    get_input(adata, input_load), TYPE_INPUT});
    resize_input(adata, input_load, (sfVector2f) { 400, 60 });
    sfVector2f pos = { win_w / 2 - 200, win_h / 2 - 30};
    move_input(adata, input_load, pos);
}

void init_load_btn(s_appdata *adata, char *container, char *rtex)
{
    char *back_btn = get_str(adata, "btn_load");
    int win_h = get_int(adata, "win_h");
    add_button(adata, back_btn, TYPE_RECT, 1);
    edit_button(adata, back_btn, "Load");
    set_button_font(adata, back_btn, get_font(adata, "lobster"));
    color_button_fg(adata, back_btn, sfWhite);
    color_button_bg(adata, back_btn, get_color(255, 255, 255, 10));
    set_button_rtex(adata, back_btn, rtex);
    add_to_container(adata, container, (s_ref) {
    get_button(adata, back_btn), TYPE_BUTTON });
    resize_button(adata, back_btn, (sfVector2f) { 280, 60 });
    sfVector2f pos = { get_int(adata, "win_w") / 2 - 140, win_h / 2 + 100};
    move_button(adata, back_btn, pos);
    set_button_out(adata, back_btn, sfWhite, 2.0f);
    char *obj = str_add(back_btn, "@[:object]");
    s_ref ref = { get_button(adata, back_btn), TYPE_BUTTON };
    add_object(adata, obj, ref);
    set_object_hover_bg(adata, obj, get_color(255, 255, 255, 30));
    set_object_pressed_bg(adata, obj, get_color(255, 255, 255, 50));
    set_object_onclick(adata, obj, &load_game);
}
