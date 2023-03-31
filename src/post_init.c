/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Post-initialization module
*/

#include "main.h"

void test_switch(s_appdata *adata, s_ref *ref)
{
    switch_state(adata, "main_game_state");
}

// TODO: update les lights que quand il y a une modification, sinon : juste render la texture de blend:
// TODO: - enregistrer chaques textures additives des lights dans un sprite contenu dans la struct des lights
// TODO: - render les sprites en sfBlendAlpha

void init_tests(s_appdata *adata)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    sfVector2f res = { win_w, win_h };

    if (get_int(adata, "enable_shader")) {
        init_light_recommended(adata, 1);

        char *light_id = "mouse_light";

        add_light(adata, light_id);
        color_light(adata, light_id, sfWhite);
        set_light_inner(adata, light_id, rand_float(50.0f, 130.0f));
        set_light_outer(adata, light_id, rand_float(450.0f, 850.0f));
        set_light_intensity(adata, light_id, rand_float(30.0f, 50.0f));
    }

    add_rtex(adata, "game", 9);
    set_rtex_clear(adata, "game", sfTransparent);
    set_rtex_blendmode(adata, "game", get_int(adata, "enable_shader") ? sfBlendMultiply : sfBlendNone);

    add_rtex(adata, "game_ui", 10);
    set_rtex_clear(adata, "game_ui", sfTransparent);
    set_rtex_blendmode(adata, "game_ui", sfBlendAlpha);

    char *sprite = "sprite_0";

    add_sprite(adata, sprite, 1);
    set_sprite_rtex(adata, sprite, "game");
    set_sprite_texture(adata, sprite, get_texture(adata, "sheet"));
    animate_sprite(adata, sprite);
    set_animation_cols(adata, sprite, 4);
    set_animation_rows(adata, sprite, 4);
    set_animation_speed(adata, sprite, 0.15f);

    char *sprite_obj = str_add(sprite, "_obj");

    add_gameobject(adata, sprite_obj);
    set_gameobject_ref(adata, sprite_obj, get_sprite(adata, sprite), TYPE_SPRITE);

    /* char *main = "emiter_0";

    add_emiter(adata, main);
    set_emiter_rtex(adata, main, "game");
    move_emiter(adata, main, (sfVector2f) { win_w / 2, win_h / 2 });
    set_emiter_lifetime(adata, main, 150000);
    set_emiter_particle_lifetime(adata, main, 6500);
    set_emiter_model(adata, main, "star");
    set_emiter_spawnrate(adata, main, 30.0f);
    set_emiter_size_range(adata, main, (sfVector2f) { 0.6f, 0.6f }, (sfVector2f) { -0.7f, -0.7f });
    set_emiter_cone(adata, main, (sfVector2f) { 0, 360.0f });
    set_emiter_colors(adata, main, sfRed, sfBlue);
    set_emiter_lerp_factor(adata, main, 1.3f);
    set_emiter_vortex_dir(adata, main, particle_anticlockwise);
    set_emiter_vortex_speed(adata, main, (sfVector2f) { 50.0f, 210.0f });
    set_emiter_particle_speed(adata, main, (sfVector2f) { 250.0f, 350.0f });
    set_emiter_particle_max(adata, main, rand_int(150, 450));
    set_emiter_gameobject(adata, main, sfTrue); */

    set_friction(adata, 6.0f);
    set_max_speed(adata, 1400.0f);
    set_velocity(adata, 90.0f);

    char *main_state = "main_menu_0";

    add_state(adata, main_state);

    char *main_container = "container_0";

    add_container(adata, main_container);
    set_state_container(adata, main_state, get_container(adata, main_container));

    char *menu_rtex = "rtex_menu_0";

    add_rtex(adata, menu_rtex, 10);
    set_rtex_blendmode(adata, menu_rtex, sfBlendNone);
    set_rtex_clear(adata, menu_rtex, sfTransparent);
    add_state_rtex(adata, main_state, get_rtex(adata, menu_rtex));

    char *play_btn = "button_0";

    add_button(adata, play_btn, TYPE_RECT, 1);
    edit_button(adata, play_btn, "Play");
    set_button_font(adata, play_btn, get_font(adata, "lobster"));
    color_button_fg(adata, play_btn, sfWhite);
    color_button_bg(adata, play_btn, get_color(60, 60, 60, 255));
    set_button_rtex(adata, play_btn, menu_rtex);
    add_to_container(adata, main_container, (s_ref) { get_button(adata, play_btn), TYPE_BUTTON });
    resize_button(adata, play_btn, (sfVector2f) { 250, 60 });
    set_button_origin(adata, play_btn, (sfVector2f) { 125, 30 });
    move_button(adata, play_btn, (sfVector2f) { win_w / 2, win_h / 2 });

    char *obj = str_add(play_btn, "@[:object]");

    add_object(adata, obj, (s_ref) { get_button(adata, play_btn), TYPE_BUTTON });
    set_object_hover_bg(adata, obj, get_color(90, 90, 90, 255));
    set_object_pressed_bg(adata, obj, get_color(120, 120, 120, 255));
    set_object_onclick(adata, obj, &test_switch);

    switch_state(adata, main_state);

    char *game_state = "main_game_state";

    add_state(adata, game_state);
    set_state_ingame(adata, game_state, sfTrue);
    add_state_rtex(adata, game_state, get_rtex(adata, "game"));
    add_state_rtex(adata, game_state, get_rtex(adata, "game_ui"));

    char *game_container = "container_1";

    add_container(adata, game_container);
    set_state_container(adata, game_state, get_container(adata, game_container));

    char *fps = "text_1";

    add_text(adata, fps, 3);
    set_text_rtex(adata, fps, "game_ui");
    set_text_font(adata, fps, get_font(adata, "courier"));
    color_text(adata, fps, sfYellow);
    edit_text(adata, fps, "8000 fps");
    move_text(adata, fps, (sfVector2f) { 20, 20 });
    resize_text(adata, fps, 20);
    add_to_container(adata, game_container, (s_ref) { get_text(adata, fps), TYPE_TEXT });
}

void add_light_to_cursor(s_appdata *adata)
{
    if (!get_int(adata, "enable_shader")) return;

    char *light_id = get_random_id(10);

    add_light(adata, light_id);
    color_light(adata, light_id, rand_light_color(0));
    set_light_inner(adata, light_id, rand_float(60.0f, 130.0f));
    set_light_outer(adata, light_id, rand_float(350.0f, 820.0f));
    set_light_intensity(adata, light_id, rand_float(50.0f, 60.0f));
    set_light_gameobject(adata, light_id, sfTrue);
    move_light(adata, light_id, get_mouse(adata));
    play_sound(adata, "bonus", 15.0f, get_mouse(adata));
}

void post_init(s_appdata *adata)
{
    // init_tests(adata);
    init_live(adata);
}
