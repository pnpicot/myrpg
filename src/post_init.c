/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Post-initialization module
*/

#include "main.h"

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

    char *main = "emiter_0";

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
    set_emiter_gameobject(adata, main, sfTrue);

    set_friction(adata, 0.06f);
    set_max_speed(adata, 9.0f);
    set_velocity(adata, 0.7f);
}

void add_light_to_cursor(s_appdata *adata)
{
    if (!get_int(adata, "enable_shader")) return;

    char *light_id = get_random_id(10);

    add_light(adata, light_id);
    color_light(adata, light_id, rand_light_color(0));
    set_light_inner(adata, light_id, rand_float(60.0f, 130.0f));
    set_light_outer(adata, light_id, rand_float(350.0f, 820.0f));
    set_light_intensity(adata, light_id, rand_float(30.0f, 50.0f));
    set_light_gameobject(adata, light_id, sfTrue);
    move_light(adata, light_id, get_mouse(adata));
    play_sound(adata, "bonus", 15.0f, get_mouse(adata));
}

void post_init(s_appdata *adata)
{
    init_tests(adata);
}
