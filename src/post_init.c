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

    init_light_recommended(adata, 1);

    char *light_id = "mouse_light";

    add_light(adata, light_id);
    color_light(adata, light_id, sfWhite);
    set_light_inner(adata, light_id, rand_float(50.0f, 130.0f));
    set_light_outer(adata, light_id, rand_float(450.0f, 850.0f));
    set_light_intensity(adata, light_id, rand_float(30.0f, 50.0f));

    play_music(adata, "theme");
    set_music_loop(adata, "theme", sfTrue);
    set_music_volume(adata, "theme", 5.0f);

    // -- particles -- begin

    add_rtex(adata, "game", 8);
    set_rtex_clear(adata, "game", sfTransparent);
    set_rtex_blendmode(adata, "game", sfBlendMultiply);

    char *emiter_id = "emiter_0";

    add_emiter(adata, emiter_id);
    set_emiter_rtex(adata, emiter_id, "game");
    move_emiter(adata, emiter_id, (sfVector2f) { win_w / 2, win_h / 2 });
    set_emiter_lifetime(adata, emiter_id, 150000);
    set_emiter_particle_lifetime(adata, emiter_id, 6000);
    set_emiter_particle_max(adata, emiter_id, 600);
    set_emiter_model(adata, emiter_id, "star2");
    set_emiter_rotation_dir(adata, emiter_id, particle_random_dir);
    set_emiter_rotation_speed(adata, emiter_id, 150.0f);
    set_emiter_spawnrate(adata, emiter_id, 1.0f);
    set_emiter_particle_speed(adata, emiter_id, 370.0f);
    set_emiter_cone(adata, emiter_id, (sfVector2f) { 0.0f, 360.0f });
    set_emiter_spawn_offset(adata, emiter_id, (sfVector2f) { -20.0f, 20.0f });
    set_emiter_size_range(adata, emiter_id, (sfVector2f) { 0.4f, 0.4f }, (sfVector2f) { -0.7f, -0.7f });
    set_emiter_vortex_dir(adata, emiter_id, particle_anticlockwise);
    set_emiter_vortex_speed(adata, emiter_id, (sfVector2f) { 60.0f, 120.0f });
    set_emiter_colors(adata, emiter_id, get_color(70, 224, 157, 0), sfMagenta);
    set_emiter_lerp_factor(adata, emiter_id, 1.3f);

    char *flame = "emiter_1";
    char *smoke = "emiter_2";
    char *sparks = "emiter_3";

    add_emiter(adata, smoke);
    add_emiter(adata, sparks);
    add_emiter(adata, flame);

    set_emiter_rtex(adata, flame, "game");
    move_emiter(adata, flame, (sfVector2f) { 200, win_h / 2 });
    set_emiter_lifetime(adata, flame, 150000);
    set_emiter_particle_lifetime(adata, flame, 2200);
    set_emiter_particle_max(adata, flame, 240);
    set_emiter_model(adata, flame, "particle");
    set_emiter_spawnrate(adata, flame, 0.1f);
    set_emiter_particle_speed(adata, flame, 250.0f);
    set_emiter_colors(adata, flame, sfYellow, sfRed);
    set_emiter_cone(adata, flame, (sfVector2f) { 270.0f, 270.0f });
    set_emiter_size_range(adata, flame, (sfVector2f) { 0.8f, 0.8f }, (sfVector2f) { -0.7f, -0.7f });
    set_emiter_spawn_offset(adata, flame, (sfVector2f) { -32.0f, 32.0f });

    set_emiter_rtex(adata, smoke, "game");
    move_emiter(adata, smoke, (sfVector2f) { 200, win_h / 2 });
    set_emiter_lifetime(adata, smoke, 150000);
    set_emiter_particle_lifetime(adata, smoke, 4300);
    set_emiter_particle_max(adata, smoke, 70);
    set_emiter_model(adata, smoke, "particle");
    set_emiter_spawnrate(adata, smoke, 0.1f);
    set_emiter_particle_speed(adata, smoke, 200.0f);
    set_emiter_colors(adata, smoke, get_color(170, 170, 170, 255), sfBlack);
    set_emiter_cone(adata, smoke, (sfVector2f) { 240.0f, 310.0f });
    set_emiter_size_range(adata, smoke, (sfVector2f) { 0.5f, 0.5f }, (sfVector2f) { -0.7f, -0.7f });
    set_emiter_spawn_offset(adata, smoke, (sfVector2f) { -40.0f, 40.0f });
    set_emiter_vortex_dir(adata, smoke, particle_anticlockwise);
    set_emiter_vortex_speed(adata, smoke, (sfVector2f) { -40.0f, 40.0f });

    set_emiter_rtex(adata, sparks, "game");
    move_emiter(adata, sparks, (sfVector2f) { 200, win_h / 2 });
    set_emiter_lifetime(adata, sparks, 150000);
    set_emiter_particle_lifetime(adata, sparks, 1400);
    set_emiter_particle_max(adata, sparks, 50);
    set_emiter_model(adata, sparks, "particle");
    set_emiter_spawnrate(adata, sparks, 0.1f);
    set_emiter_particle_speed(adata, sparks, 400.0f);
    set_emiter_colors(adata, sparks, get_color(247, 245, 188, 255), sfYellow);
    set_emiter_cone(adata, sparks, (sfVector2f) { 180.0f, 360.0f });
    set_emiter_size_range(adata, sparks, (sfVector2f) { 0.5f, 0.5f }, (sfVector2f) { -0.7f, -0.7f });
    set_emiter_spawn_offset(adata, sparks, (sfVector2f) { -40.0f, 40.0f });
    set_emiter_vortex_dir(adata, sparks, particle_anticlockwise);
    set_emiter_vortex_speed(adata, sparks, (sfVector2f) { -150.0f, 150.0f });

    accelerate_emiter(adata, flame, 20000);

    char *rain = "emiter_4";

    add_emiter(adata, rain);
    set_emiter_rtex(adata, rain, "game");
    move_emiter(adata, rain, (sfVector2f) { win_w - 200, 0 });
    set_emiter_lifetime(adata, rain, 150000);
    set_emiter_particle_max(adata, rain, 1300);
    set_emiter_model(adata, rain, "particle");
    set_emiter_spawnrate(adata, rain, 1.0f);
    set_emiter_spawn_offset(adata, rain, (sfVector2f) { -160, 160 });
    set_emiter_size_range(adata, rain, (sfVector2f) { 0.1f, 0.8f }, (sfVector2f) { 0.1f, 0.8f });
    set_emiter_particle_lifetime(adata, rain, 1900);
    set_emiter_cone(adata, rain, (sfVector2f) { 90.0f, 90.0f });
    set_emiter_particle_speed(adata, rain, 2400.0f);

    char *test = "emiter_5";

    add_emiter(adata, test);
    set_emiter_rtex(adata, test, "game");
    move_emiter(adata, test, (sfVector2f) { 300, 300 });
    set_emiter_lifetime(adata, test, 150000);
    set_emiter_particle_lifetime(adata, test, 9000);
    set_emiter_particle_max(adata, test, 250);
    set_emiter_model(adata, test, "star");
    set_emiter_spawnrate(adata, test, 2.0f);
    set_emiter_size_range(adata, test, (sfVector2f) { 0.4f, 0.4f }, (sfVector2f) { -0.7f, -0.7f });
    set_emiter_particle_speed(adata, test, 280.0f);
    set_emiter_vortex_dir(adata, test, particle_clockwise);
    set_emiter_vortex_speed(adata, test, (sfVector2f) { 100.0f, 350.0f });
    set_emiter_cone(adata, test, (sfVector2f) { 0, 360.0f });
    set_emiter_colors(adata, test, sfGreen, sfRed);
    set_emiter_lerp_factor(adata, test, 1.85f);

    add_sprite(adata, "example", 1);
    set_sprite_rtex(adata, "example", "game");
    set_sprite_texture(adata, "example", get_texture(adata, "sheet"));
    scale_sprite(adata, "example", (sfVector2f) { 0.3f, 0.3f });
    animate_sprite(adata, "example");
    set_animation_cols(adata, "example", 4);
    set_animation_rows(adata, "example", 4);
    set_animation_speed(adata, "example", 0.1f);
    shift_animation_row(adata, "example", 1);

    // -- particles -- end
}

void add_light_to_cursor(s_appdata *adata)
{
    char *light_id = get_random_id(10);

    add_light(adata, light_id);
    color_light(adata, light_id, rand_light_color(0));
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
