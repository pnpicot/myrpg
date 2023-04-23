/*
** EPITECH PROJECT, 2023
** m_setup
** File description:
** setup_ba
*/

#include "main.h"


void update_live(s_appdata *adata)
{
    update_ingame_ui(adata);
    cycle_world_time(adata);
    trigger_spawn_cycle(adata);
    update_entities(adata);
    update_player_info_text(adata);
    update_quests(adata);
    update_skill_tree(adata);
    update_wave_count(adata);
}

void init_live_light(s_appdata *adata)
{
    if (get_int(adata, "enable_shader")) {
        init_light_recommended(adata, 1);

        char *light_id = "mouse_light";
        int win_w = get_int(adata, "win_w");
        int win_h = get_int(adata, "win_h");

        add_light(adata, light_id);
        color_light(adata, light_id, sfWhite);
        set_light_inner(adata, light_id, 0);
        set_light_outer(adata, light_id, 450.0f);
        set_light_intensity(adata, light_id, 20.0f);
        set_light_gameobject(adata, light_id, sfFalse);
        move_light(adata, light_id, (sfVector2f) { win_w / 2, win_h / 2 });
    }
}

void init_live_textures_n(s_appdata *adata)
{
    char *rtex_settings = get_str(adata, "rtex_settings");
    char *rtex_ui = get_str(adata, "rtex_ui");
    char *rtex_menu = get_str(adata, "rtex_menu");
    char *rtex_load = get_str(adata, "rtex_load");
    add_rtex(adata, rtex_ui, 11);
    set_rtex_clear(adata, rtex_ui, sfTransparent);
    set_rtex_blendmode(adata, rtex_ui, sfBlendAlpha);
    add_rtex(adata, rtex_menu, 12);
    set_rtex_blendmode(adata, rtex_menu, sfBlendNone);
    set_rtex_clear(adata, rtex_menu, sfTransparent);
    add_rtex(adata, rtex_settings, 13);
    set_rtex_blendmode(adata, rtex_settings, sfBlendNone);
    set_rtex_clear(adata, rtex_settings, sfTransparent);
    set_rtex_active(adata, rtex_settings, sfFalse);
    add_rtex(adata, rtex_load, 14);
    set_rtex_blendmode(adata, rtex_load, sfBlendNone);
    set_rtex_clear(adata, rtex_load, sfTransparent);
    set_rtex_active(adata, rtex_load, sfFalse);
    set_shader_vec2(adata, "rgb_multiply", "resolution",
    (sfVector2f) { get_int(adata, "win_w"), get_int(adata, "win_h") });
}

void init_live_textures(s_appdata *adata)
{
    int shader_enabled = get_int(adata, "enable_shader");
    char *rtex_game = get_str(adata, "rtex_game");
    char *rtex_wall = get_str(adata, "rtex_wall");
    char *rtex_wall_light = get_str(adata, "rtex_wall_light");
    add_rtex(adata, rtex_game, 9);
    set_rtex_clear(adata, rtex_game, sfTransparent);
    if (shader_enabled)
        set_rtex_blendmode(adata, rtex_game, sfBlendMultiply);
    add_rtex(adata, rtex_wall, 10);
    set_rtex_clear(adata, rtex_wall, sfTransparent);
    set_rtex_blendmode(adata, rtex_wall, sfBlendAlpha);
    set_rtex_shader(adata, rtex_wall, get_shader(adata, "rgb_multiply"));
    add_rtex(adata, rtex_wall_light, 0);
    set_rtex_clear(adata, rtex_wall_light, sfBlack);
    set_rtex_blendmode(adata, rtex_wall_light, sfBlendNone);
    set_shader_texture(adata, "rgb_multiply", "tex",
    get_rtex_tex(adata, rtex_wall));
    set_shader_texture(adata, "rgb_multiply", "add",
    get_rtex_tex(adata, rtex_wall_light));
    init_live_textures_n(adata);
}
