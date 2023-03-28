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
    set_emiter_particle_lifetime(adata, main, 7000);
    set_emiter_model(adata, main, "star");
    set_emiter_spawnrate(adata, main, 3.0f);
    set_emiter_size_range(adata, main, (sfVector2f) { 0.6f, 0.6f }, (sfVector2f) { -0.7f, -0.7f });
    set_emiter_cone(adata, main, (sfVector2f) { 0, 360.0f });
    set_emiter_colors(adata, main, sfRed, sfYellow);
    set_emiter_lerp_factor(adata, main, 1.2f);
    set_emiter_vortex_dir(adata, main, particle_anticlockwise);
    set_emiter_vortex_speed(adata, main, (sfVector2f) { -70.0f, 260.0f });
    set_emiter_particle_speed(adata, main, (sfVector2f) { 250.0f, 350.0f });
    set_emiter_particle_max(adata, main, 200);
    set_emiter_gameobject(adata, main, sfTrue);

    set_friction(adata, 0.06f);
    set_max_speed(adata, 9.0f);
    set_velocity(adata, 0.7f);

    /* play_music(adata, "theme");
    set_music_loop(adata, "theme", sfTrue);
    set_music_volume(adata, "theme", 5.0f); */

    /* add_rtex(adata, "game", 9);
    set_rtex_clear(adata, "game", sfTransparent);
    set_rtex_blendmode(adata, "game", get_int(adata, "enable_shader") ? sfBlendMultiply : sfBlendNone);

    char *flame = "emiter_0";

    add_emiter(adata, flame);
    set_emiter_rtex(adata, flame, "game");
    set_emiter_spawnrate(adata, flame, 1.0f);
    set_emiter_lifetime(adata, flame, 150000);
    set_emiter_model(adata, flame, "star");
    set_emiter_particle_max(adata, flame, 1600);
    set_emiter_particle_lifetime(adata, flame, 4000);
    move_emiter(adata, flame, (sfVector2f) { win_w / 2, win_h - 1 });
    set_emiter_size_range(adata, flame, (sfVector2f) { 0.8f, 0.8f }, (sfVector2f) { -0.7f, -0.7f });
    set_emiter_particle_speed(adata, flame, (sfVector2f) { 250.0f, 360.0f });
    set_emiter_spawn_xoffset(adata, flame, (sfVector2f) { -(win_w / 2), win_w / 2 });
    set_emiter_colors(adata, flame, sfYellow, sfRed);
    set_emiter_rotation_dir(adata, flame, particle_random_dir);
    set_emiter_rotation_speed(adata, flame, 45.0f);
    set_emiter_lerp_factor(adata, flame, 1.3f);

    char *smoke = "emiter_1";

    add_emiter(adata, smoke);
    set_emiter_rtex(adata, smoke, "game");
    set_emiter_spawnrate(adata, smoke, 1.0f);
    set_emiter_lifetime(adata, smoke, 150000);
    set_emiter_model(adata, smoke, "star");
    set_emiter_particle_max(adata, smoke, 1200);
    set_emiter_particle_lifetime(adata, smoke, 6500);
    move_emiter(adata, smoke, (sfVector2f) { win_w / 2, win_h - 1 });
    set_emiter_size_range(adata, smoke, (sfVector2f) { 0.5f, 0.5f }, (sfVector2f) { -0.7f, -0.7f });
    set_emiter_particle_speed(adata, smoke, (sfVector2f) { 300.0f, 370.0f });
    set_emiter_spawn_xoffset(adata, smoke, (sfVector2f) { -(win_w / 2), win_w / 2 });
    set_emiter_colors(adata, smoke, sfLightGray, sfBlack);
    set_emiter_lerp_factor(adata, smoke, 1.3f);
    set_emiter_rotation_dir(adata, smoke, particle_random_dir);
    set_emiter_rotation_speed(adata, smoke, 45.0f);
    set_emiter_vortex_dir(adata, smoke, particle_clockwise);
    set_emiter_vortex_speed(adata, smoke, (sfVector2f) { -30.0f, 30.0f });

    char *early_flames = "emiter_2";

    add_emiter(adata, early_flames);
    set_emiter_rtex(adata, early_flames, "game");
    set_emiter_spawnrate(adata, early_flames, 1.0f);
    set_emiter_lifetime(adata, early_flames, 150000);
    set_emiter_model(adata, early_flames, "star");
    set_emiter_particle_max(adata, early_flames, 1300);
    set_emiter_particle_lifetime(adata, early_flames, 1500);
    move_emiter(adata, early_flames, (sfVector2f) { win_w / 2, win_h - 20});
    set_emiter_size_range(adata, early_flames, (sfVector2f) { 0.9f, 0.9f }, (sfVector2f) { -0.7f, -0.7f });
    set_emiter_particle_speed(adata, early_flames, (sfVector2f) { 120.0f, 360.0f });
    set_emiter_spawn_xoffset(adata, early_flames, (sfVector2f) { -(win_w / 2), win_w / 2 });
    set_emiter_spawn_yoffset(adata, early_flames, (sfVector2f) { -5.0f, 10.0f });
    set_emiter_colors(adata, early_flames, sfWhite, sfYellow);
    set_emiter_lerp_factor(adata, early_flames, 1.2f);
    set_emiter_rotation_dir(adata, early_flames, particle_random_dir);
    set_emiter_rotation_speed(adata, early_flames, 45.0f);
    set_emiter_vortex_dir(adata, early_flames, particle_clockwise);
    set_emiter_vortex_speed(adata, early_flames, (sfVector2f) { -10.0f, 10.0f });

    char *rain = "emiter_3";

    add_emiter(adata, rain);
    set_emiter_rtex(adata, rain, "game");
    set_emiter_spawnrate(adata, rain, 1.0f);
    set_emiter_lifetime(adata, rain, 150000);
    set_emiter_model(adata, rain, "square");
    set_emiter_particle_max(adata, rain, 1300);
    set_emiter_particle_lifetime(adata, rain, 3500);
    move_emiter(adata, rain, (sfVector2f) { win_w / 2, 0 });
    set_emiter_size_range(adata, rain, (sfVector2f) { 0.02f, 0.3f }, (sfVector2f) { 0.02f, 0.5f });
    set_emiter_particle_speed(adata, rain, (sfVector2f) { 1600.0f, 1900.0f });
    set_emiter_cone(adata, rain, (sfVector2f) { 95.0f, 95.0f });
    set_emiter_spawn_xoffset(adata, rain, (sfVector2f) { -(win_w / 2) - 250, (win_w / 2) + 250 });
    set_emiter_colors(adata, rain, sfWhite, sfBlack);
    set_emiter_vortex_dir(adata, rain, particle_anticlockwise);
    set_emiter_vortex_speed(adata, rain, (sfVector2f) { 5.0f, 7.0f }); */
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
