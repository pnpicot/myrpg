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

void add_light_to_cursor(s_appdata *adata)
{
    if (!get_int(adata, "enable_shader")) return;

    char *light_id = get_random_id(10);
    int win_h = get_int(adata, "win_h");

    add_light(adata, light_id);
    color_light(adata, light_id, rand_light_color(0));
    set_light_inner(adata, light_id, rand_float(90.0f, 130.0f));

    float outer_rad = rand_float(win_h * 0.7f - 200, win_h * 0.7f);

    set_light_outer(adata, light_id, outer_rad);
    set_light_intensity(adata, light_id, rand_float(50.0f, 60.0f));
    set_light_gameobject(adata, light_id, sfTrue);
    move_light(adata, light_id, get_mouse(adata));
}

void post_init(s_appdata *adata)
{
    if (!get_int(adata, "dev_mode")) {
        init_live(adata);
    }
}
