/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Post-initialization module
*/

#include "include/main.h"

void sl_trig(s_appdata *adata, s_ref *ref)
{
    slider_change(adata, "test");
}

void init_tests(s_appdata *adata)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    sfVector2f res = { win_w, win_h };

    // -- light - begin
    add_rtex(adata, "light_mask", 1);
    set_lightmask_rtex(adata, "light_mask");
    set_rtex_blendmode(adata, "light_mask", sfBlendNone);
    set_rtex_clear(adata, "light_mask", sfWhite);

    add_rtex(adata, "light_blur_x", 2);
    set_rtex_blendmode(adata, "light_blur_x", sfBlendAdd);
    set_shader_texture(adata, "bloom_blur_x", "texture", get_rtex_tex(adata, "light_blur_x"));
    set_shader_vec2(adata, "bloom_blur_x", "blur_radius", (sfVector2f) { 0.004f, 0 });
    set_rtex_shader(adata, "light_blur_x", get_shader(adata, "bloom_blur_x"));
    set_light_rtex(adata, "light_blur_x");

    add_rtex(adata, "light_blur_y", 3);
    set_rtex_inherit(adata, "light_blur_y", 1);
    set_rtex_blendmode(adata, "light_blur_y", sfBlendAlpha);
    set_shader_texture(adata, "bloom_blur_y", "texture", get_rtex_tex(adata, "light_blur_y"));
    set_shader_vec2(adata, "bloom_blur_y", "blur_radius", (sfVector2f) { 0, 0.008f });
    set_rtex_shader(adata, "light_blur_y", get_shader(adata, "bloom_blur_y"));
    set_rtex_clear(adata, "light_blur_y", sfTransparent);

    add_rtex(adata, "light_post_blur_y", 4);
    set_rtex_inherit(adata, "light_post_blur_y", 1);
    set_shader_texture(adata, "post_blur_y", "texture", get_rtex_tex(adata, "light_post_blur_y"));
    set_shader_vec2(adata, "post_blur_y", "blur_radius", (sfVector2f) { 0, 0.008f });
    set_rtex_shader(adata, "light_post_blur_y", get_shader(adata, "post_blur_y"));
    set_rtex_clear(adata, "light_post_blur_y", sfTransparent);

    add_rtex(adata, "light_gradient", 5);
    set_rtex_inherit(adata, "light_gradient", 1);
    set_shader_texture(adata, "gradient", "tex", get_rtex_tex(adata, "light_gradient"));
    set_shader_vec2(adata, "gradient", "resolution", res);
    set_rtex_shader(adata, "light_gradient", get_shader(adata, "gradient"));
    set_rtex_clear(adata, "light_gradient", sfTransparent);

    add_rtex(adata, "light_overlay", 6);
    set_rtex_inherit(adata, "light_overlay", 1);
    set_rtex_blendmode(adata, "light_overlay", sfBlendAdd);
    set_rtex_clear(adata, "light_overlay", sfTransparent);
    set_lightres_rtex(adata, "light_overlay");
    set_rtex_shader(adata, "light_overlay", get_shader(adata, "mask"));
    set_shader_texture(adata, "mask", "texture", get_rtex_tex(adata, "light_mask"));
    set_shader_texture(adata, "mask", "add_texture", get_rtex_tex(adata, "light_overlay"));

    add_rtex(adata, "light_blend", 7);
    set_rtex_blendmode(adata, "light_blend", sfBlendAlpha);
    set_rtex_clear(adata, "light_blend", get_color(10, 10, 10, 255));
    set_lightblend_rtex(adata, "light_blend");

    add_rtex(adata, "walls", 8);
    set_rtex_blendmode(adata, "walls", sfBlendAlpha);
    set_rtex_clear(adata, "walls", sfTransparent);
    set_wall_rtex(adata, "walls", 1);

    char *light_id = "mouse_light";

    add_light(adata, light_id);
    color_light(adata, light_id, sfWhite);
    set_light_inner(adata, light_id, rand_float(50.0f, 130.0f));
    set_light_outer(adata, light_id, rand_float(450.0f, 850.0f));
    set_light_intensity(adata, light_id, rand_float(30.0f, 50.0f));
    // -- light -- end

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
