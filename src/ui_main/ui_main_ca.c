/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Main menu module
*/

#include "main.h"

void init_main_particles_n(s_appdata *adata, char *ptc)
{
    set_emiter_colors(adata, ptc, sfGreen, sfBlue);
    set_emiter_lerp_factor(adata, ptc, 1.0f);
    set_emiter_vortex_dir(adata, ptc, clockwise);
    set_emiter_vortex_speed(adata, ptc, (sfVector2f) { -20.0f, 20.0f });
    add_to_container(adata, get_str(adata, "ctn_main"),
    (s_ref) { get_emiter(adata, ptc), TYPE_EMITER });

}

void init_main_particles(s_appdata *adata, char *container, char *rtex)
{
    char *ptc = get_str(adata, "main_part");
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");

    add_emiter(adata, ptc);
    move_emiter(adata, ptc, (sfVector2f) { win_w / 2, win_h + 30.0f });
    set_emiter_rtex(adata, ptc, rtex);
    set_emiter_lifetime(adata, ptc, 150000);
    set_emiter_particle_lifetime(adata, ptc, 800);
    set_emiter_spawnrate(adata, ptc, 0.02f);
    set_emiter_particle_max(adata, ptc, 1300);
    set_emiter_rotation_dir(adata, ptc, random_dir);
    set_emiter_rotation_speed(adata, ptc, 25.0f);
    set_emiter_model(adata, ptc, "gen");
    set_emiter_spawn_xoffset(adata, ptc, (sfVector2f){-(win_w / 2), win_w / 2});
    set_emiter_particle_speed(adata, ptc, (sfVector2f) { 150.0f, 350.0f });
    set_emiter_size_range(adata, ptc, (sfVector2f) { 2.0f, 2.0f },
    (sfVector2f) { 0, 0 });
    init_main_particles_n(adata, ptc);
}

void init_live_main_menu(s_appdata *adata)
{
    char *container = get_str(adata, "ctn_main");
    char *rtex = get_str(adata, "rtex_menu");

    init_main_playbtn(adata, container, rtex);
    init_main_savebtn(adata, container, rtex);
    init_main_loadbtn(adata, container, rtex);
    init_main_settingsbtn(adata, container, rtex);
    init_main_quitbtn(adata, container, rtex);
    init_main_particles(adata, container, rtex);
}
