/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Post-initialization module
*/

#include "include/main.h"

void button_trigger(s_appdata *adata, s_ref *ref)
{
    if (get_switch_state(adata, "switch_0")) {
        color_circle(adata, "circle_0", rand_color(0));
        color_circle(adata, "circle_1", rand_color(0));
        color_text(adata, "text_0", rand_color(0));
    }
}

void switch_tog(s_appdata *adata, s_ref *ref)
{
    toggle_switch(adata, "switch_0");
}

void slider_ch(s_appdata *adata, s_ref *ref)
{
    slider_change(adata, "slider_0");
    set_bar_current(adata, "bar_0", get_slider_value(adata, "slider_0"));
}

void slider_ch2(s_appdata *adata, s_ref *ref)
{
    slider_change(adata, "slider_1");
}

void input_trigger(s_appdata *adata, const char *str)
{
    edit_text(adata, "text_0", str);

    sfVector2f circle_pos = get_circle_pos(adata, "circle_0");
    float circle_radius = get_circle_radius(adata, "circle_0");
    sfFloatRect text_bounds = get_text_bounds(adata, "text_0");
    sfVector2f text_pos;

    text_pos.x = (circle_pos.x + circle_radius) - (text_bounds.width / 2);
    text_pos.y = (circle_pos.y + circle_radius) - (text_bounds.height / 2);

    move_text(adata, "text_0", text_pos);
}

void init_tests(s_appdata *adata)
{
    char *rtex_first = "rtex_0";
    char *rtex_second = "rtex_1";
    char *rtex_third = "rtex_2";
    char *rtex_fourth = "rtex_3";

    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");

    add_rtex(adata, rtex_first, 1);
    add_rtex(adata, rtex_second, 2);
    add_rtex(adata, rtex_third, 3);
    add_rtex(adata, rtex_fourth, 4);
    set_rtex_blendmode(adata, rtex_first, sfBlendNone);
    set_rtex_blendmode(adata, rtex_second, sfBlendAdd);
    set_rtex_blendmode(adata, rtex_third, sfBlendMultiply);
    set_rtex_blendmode(adata, rtex_fourth, sfBlendAdd);

    char *first = "car_0";

    add_sprite(adata, first, 1);
    set_sprite_texture(adata, first, get_texture(adata, "vroum"));
    move_sprite(adata, first, (sfVector2f) { 50, 50 });
    set_sprite_rtex(adata, first, rtex_first);

    char *second = "car_1";

    add_sprite(adata, second, 1);
    set_sprite_texture(adata, second, get_texture(adata, "vroum2"));
    move_sprite(adata, second, (sfVector2f) { 400, 360 });
    set_sprite_rtex(adata, second, rtex_second);

    char *third = "circle_0";

    add_circle(adata, third, 1);
    resize_circle(adata, third, 350.0f);
    color_circle(adata, third, get_color(240, 50, 150, 255));
    move_circle(adata, third, (sfVector2f) { 200, 140 });
    set_circle_rtex(adata, third, rtex_third);

    char *fourth = "text_0";

    add_text(adata, fourth, 2);
    set_text_font(adata, fourth, get_font(adata, "lobster"));
    resize_text(adata, fourth, 100);
    color_text(adata, fourth, get_color(240, 255, 50, 255));
    edit_text(adata, fourth, "Hello World");
    set_text_rtex(adata, fourth, rtex_fourth);

    sfVector2f circle_pos = get_circle_pos(adata, third);
    float circle_radius = get_circle_radius(adata, third);
    sfFloatRect text_bounds = get_text_bounds(adata, fourth);
    sfVector2f text_pos;

    text_pos.x = (circle_pos.x + circle_radius) - (text_bounds.width / 2);
    text_pos.y = (circle_pos.y + circle_radius) - (text_bounds.height / 2);

    move_text(adata, fourth, text_pos);

    char *fifth = "circle_1";

    add_circle(adata, fifth, 2);
    resize_circle(adata, fifth, 250.0f);
    color_circle(adata, fifth, get_color(30, 180, 56, 255));
    move_circle(adata, fifth, (sfVector2f) { 250, 210 });
    set_circle_rtex(adata, fifth, rtex_third);

    char *sixth = "vertex_0";

    add_vertex(adata, sixth, 3);
    resize_vertex(adata, sixth, 4);
    set_vertex_type(adata, sixth, sfQuads);
    set_vertex_rtex(adata, sixth, rtex_third);
    move_vertex(adata, sixth, 1, (sfVector2f) { 0, 0 });
    move_vertex(adata, sixth, 2, (sfVector2f) { 500, 0 });
    move_vertex(adata, sixth, 0, (sfVector2f) { 50, 110 });
    move_vertex(adata, sixth, 3, (sfVector2f) { 550, 110 });
    translate_vertex_all(adata, sixth, (sfVector2f) { 400, 630 });
    color_vertex(adata, sixth, 1, sfBlack);
    color_vertex(adata, sixth, 2, get_color(111, 232, 216, 255));
    color_vertex(adata, sixth, 0, sfYellow);
    color_vertex(adata, sixth, 3, get_color(200, 90, 0, 255));

    char *container = "container_0";

    add_container(adata, container);
    add_to_container(adata, container, (s_ref) { get_sprite(adata, first), TYPE_SPRITE });
    add_to_container(adata, container, (s_ref) { get_sprite(adata, second), TYPE_SPRITE });
    add_to_container(adata, container, (s_ref) { get_circle(adata, third), TYPE_CIRCLE });
    add_to_container(adata, container, (s_ref) { get_text(adata, fourth), TYPE_TEXT });
    add_to_container(adata, container, (s_ref) { get_circle(adata, fifth), TYPE_CIRCLE });
    add_to_container(adata, container, (s_ref) { get_vertex(adata, sixth), TYPE_VERTEX });
    translate_container(adata, container, (sfVector2f) { 400, 70 });

    char *button = "button_0";
    sfColor button_bg = get_color(135, 8, 57, 255);

    add_button(adata, button, TYPE_RECT, 2);
    set_button_rtex(adata, button, rtex_fourth);
    set_button_font(adata, button, get_font(adata, "lobster"));
    color_button_fg(adata, button, sfWhite);
    edit_button(adata, button, "A generic button");
    resize_button_text(adata, button, 22);
    resize_button(adata, button, (sfVector2f) { 250, 60 });
    color_button_bg(adata, button, button_bg);
    move_button(adata, button, (sfVector2f) { (win_w / 2) - 125, win_h - 230 });

    char *button_obj = "button_0@[:object]";

    add_object(adata, button_obj, (s_ref) { get_button(adata, button), TYPE_BUTTON });
    set_object_hover_bg(adata, button_obj, lighten(button_bg, 20));
    set_object_pressed_bg(adata, button_obj, lighten(button_bg, 50));
    set_object_onclick(adata, button_obj, &button_trigger);

    char *switch_id = "switch_0";

    add_switch(adata, switch_id, 3);
    set_switch_rtex(adata, switch_id, rtex_fourth);
    set_switch_ontoggle(adata, switch_id, &switch_tog);
    move_switch(adata, switch_id, (sfVector2f) { (win_w / 2) - 290, (win_h / 2) + 175 });

    char *slider_id = "slider_0";

    add_slider(adata, slider_id, 4);
    set_slider_rtex(adata, slider_id, rtex_fourth);
    move_slider(adata, slider_id, (sfVector2f) { (win_w / 2) - (get_float(adata, "slider_length") / 2) - 15.0f, 150 });
    set_slider_onchange(adata, slider_id, &slider_ch);

    char *slider_next = "slider_1";

    add_slider(adata, slider_next, 4);
    set_slider_rtex(adata, slider_next, rtex_fourth);
    move_slider(adata, slider_next, (sfVector2f) { 50, 200 });
    set_slider_onchange(adata, slider_next, &slider_ch2);
    set_slider_min(adata, slider_next, -100);
    set_slider_max(adata, slider_next, 152);

    char *input_id = "input_0";

    add_input(adata, input_id, 5);
    set_input_rtex(adata, input_id, rtex_fourth);
    move_input(adata, input_id, (sfVector2f) { 30, 30 });
    set_input_maxlength(adata, input_id, 32);

    char *input_two = "input_1";

    add_input(adata, input_two, 5);
    set_input_rtex(adata, input_two, rtex_fourth);
    move_input(adata, input_two, (sfVector2f) { 30, 85 });
    set_input_placeholder(adata, input_two, "Example placeholder");
    set_input_align(adata, input_two, "center");
    set_input_oninput(adata, input_two, &input_trigger);
    set_input_maxlength(adata, input_two, 32);

    char *bar_id = "bar_0";

    add_bar(adata, bar_id, 5);
    set_bar_rtex(adata, bar_id, rtex_fourth);
    set_bar_display(adata, bar_id, sfTrue);
    set_bar_min(adata, bar_id, 0);
    set_bar_max(adata, bar_id, 100);
    set_bar_current(adata, bar_id, 50);
    move_bar(adata, bar_id, (sfVector2f) { 700, 980 });
}

void post_init(s_appdata *adata)
{
    init_tests(adata);
}
