/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Post-initialization module
*/

#include "include/main.h"

void init_tests(s_appdata *adata)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    sfVector2f res = { win_w, win_h };

    init_light_recommended(adata, 1);

    char *light_id = "mouse_light";

    add_light(adata, light_id);
    color_light(adata, light_id, sfWhite);
    set_light_inner(adata, light_id, rand_float(50.0f, 130.0f));
    set_light_outer(adata, light_id, rand_float(450.0f, 850.0f));
    set_light_intensity(adata, light_id, rand_float(30.0f, 50.0f));

    /* add_rtex(adata, "base_game", 9);
    set_rtex_blendmode(adata, "base_game", sfBlendMultiply);
    set_rtex_clear(adata, "base_game", sfTransparent);

    add_sprite(adata, "example", 1);
    set_sprite_rtex(adata, "example", "base_game");
    set_sprite_texture(adata, "example", get_texture(adata, "sheet"));
    scale_sprite(adata, "example", (sfVector2f) { 0.3f, 0.3f });
    animate_sprite(adata, "example");
    set_animation_cols(adata, "example", 4);
    set_animation_rows(adata, "example", 4);
    set_animation_speed(adata, "example", 0.1f);
    shift_animation_row(adata, "example", 1); */

    play_music(adata, "theme");
    set_music_loop(adata, "theme", sfTrue);
    set_music_volume(adata, "theme", 20.0f);

    // -- particles -- begin

    add_rtex(adata, "game", 8);
    set_rtex_clear(adata, "game", sfTransparent);
    set_rtex_blendmode(adata, "game", sfBlendMultiply);

    // -- particles -- end
}

void add_light_to_cursor(s_appdata *adata)
{
    char *light_id = get_random_id(10);

    add_light(adata, light_id);
    color_light(adata, light_id, sfWhite);
    set_light_inner(adata, light_id, rand_float(60.0f, 130.0f));
    set_light_outer(adata, light_id, rand_float(350.0f, 820.0f));
    set_light_intensity(adata, light_id, rand_float(30.0f, 50.0f));
    move_light(adata, light_id, get_mouse(adata));
    play_sound(adata, "bonus", 15.0f, get_mouse(adata));
}

void post_init(s_appdata *adata)
{
    init_tests(adata);
}
