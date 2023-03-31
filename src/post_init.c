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
    // ...
}

void add_light_to_cursor(s_appdata *adata)
{
    if (!get_int(adata, "enable_shader")) return;

    char *light_id = get_random_id(10);

    add_light(adata, light_id);
    color_light(adata, light_id, rand_light_color(0));
    set_light_inner(adata, light_id, rand_float(90.0f, 130.0f));
    set_light_outer(adata, light_id, rand_float(650.0f, 820.0f));
    set_light_intensity(adata, light_id, rand_float(50.0f, 60.0f));
    set_light_gameobject(adata, light_id, sfTrue);
    move_light(adata, light_id, get_mouse(adata));
}

void post_init(s_appdata *adata)
{
    if (get_int(adata, "dev_mode")) {
        init_tests(adata);
    } else {
        init_live(adata);
    }
}
