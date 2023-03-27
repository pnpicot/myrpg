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

    if (sfShader_isAvailable()) {
        init_light_recommended(adata, 1);

        char *light_id = "mouse_light";

        add_light(adata, light_id);
        color_light(adata, light_id, sfWhite);
        set_light_inner(adata, light_id, rand_float(50.0f, 130.0f));
        set_light_outer(adata, light_id, rand_float(450.0f, 850.0f));
        set_light_intensity(adata, light_id, rand_float(30.0f, 50.0f));
    }

    /* play_music(adata, "theme");
    set_music_loop(adata, "theme", sfTrue);
    set_music_volume(adata, "theme", 5.0f); */

    add_rtex(adata, "game", 9);
    set_rtex_clear(adata, "game", sfTransparent);
    set_rtex_blendmode(adata, "game", sfBlendMultiply);

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
    set_emiter_particle_speed(adata, early_flames, (sfVector2f) { 120.0f, 220.0f });
    set_emiter_spawn_xoffset(adata, early_flames, (sfVector2f) { -(win_w / 2), win_w / 2 });
    set_emiter_spawn_yoffset(adata, early_flames, (sfVector2f) { -5.0f, 10.0f });
    set_emiter_colors(adata, early_flames, sfWhite, sfYellow);
    set_emiter_lerp_factor(adata, early_flames, 1.2f);
    set_emiter_rotation_dir(adata, early_flames, particle_random_dir);
    set_emiter_rotation_speed(adata, early_flames, 45.0f);
    set_emiter_vortex_dir(adata, early_flames, particle_clockwise);
    set_emiter_vortex_speed(adata, early_flames, (sfVector2f) { -10.0f, 10.0f });
}

void add_light_to_cursor(s_appdata *adata)
{
    if (!sfShader_isAvailable()) return;

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
