/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Setup module
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

void init_live_textures(s_appdata *adata)
{
    int shader_enabled = get_int(adata, "enable_shader");
    char *rtex_game = get_str(adata, "rtex_game");
    char *rtex_ui = get_str(adata, "rtex_ui");
    char *rtex_menu = get_str(adata, "rtex_menu");
    char *rtex_wall = get_str(adata, "rtex_wall");
    char *rtex_wall_light = get_str(adata, "rtex_wall_light");
    char *rtex_settings = get_str(adata, "rtex_settings");
    char *rtex_bloom = get_str(adata, "rtex_bloom");
    char *rtex_bloom_x = get_str(adata, "rtex_bloom_x");
    char *rtex_bloom_y = get_str(adata, "rtex_bloom_y");
    char *rtex_bloom_int = get_str(adata, "rtex_bloom_int");
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");

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

    set_shader_texture(adata, "rgb_multiply", "tex", get_rtex_tex(adata, rtex_wall));
    set_shader_texture(adata, "rgb_multiply", "add", get_rtex_tex(adata, rtex_wall_light));
    set_shader_vec2(adata, "rgb_multiply", "resolution", (sfVector2f) { win_w, win_h });

    /* add_rtex(adata, rtex_bloom, 11);
    set_rtex_clear(adata, rtex_bloom, sfBlack);
    set_rtex_blendmode(adata, rtex_bloom, sfBlendAdd);
    set_shader_vec2(adata, "rr_bloom", "resolution", (sfVector2f) { win_w, win_h });
    set_shader_texture(adata, "rr_bloom", "tex", get_rtex_tex(adata, rtex_game));
    set_shader_float(adata, "rr_bloom", "threshold", get_float(adata, "bloom_threshold"));
    set_rtex_shader(adata, rtex_bloom, get_shader(adata, "rr_bloom"));

    add_rtex(adata, rtex_bloom_x, 12);
    set_rtex_inherit(adata, rtex_bloom_x, 1);
    set_rtex_clear(adata, rtex_bloom_x, sfBlack);
    set_rtex_blendmode(adata, rtex_bloom_x, sfBlendAdd);
    set_shader_texture(adata, "rr_bloom_x", "texture", get_rtex_tex(adata, rtex_bloom_x));

    float bloom_intensity = get_float(adata, "bloom_intensity");
    sfVector2f bloomx_rad = { bloom_intensity, 0 };

    set_shader_vec2(adata, "rr_bloom_x", "blur_radius", bloomx_rad);
    set_rtex_shader(adata, rtex_bloom_x, get_shader(adata, "rr_bloom_x"));

    add_rtex(adata, rtex_bloom_y, 13);
    set_rtex_inherit(adata, rtex_bloom_y, 1);
    set_rtex_clear(adata, rtex_bloom_y, sfBlack);
    set_rtex_blendmode(adata, rtex_bloom_y, sfBlendAdd);
    set_shader_texture(adata, "rr_bloom_y", "texture", get_rtex_tex(adata, rtex_bloom_y));

    sfVector2f bloomy_rad = { 0, bloom_intensity * 2 };

    set_shader_vec2(adata, "rr_bloom_y", "blur_radius", bloomy_rad);
    set_rtex_shader(adata, rtex_bloom_y, get_shader(adata, "rr_bloom_y")); */

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
}

void init_live_states(s_appdata *adata)
{
    char *main_state = get_str(adata, "state_main");
    char *game_state = get_str(adata, "state_game");
    char *settings_state = get_str(adata, "state_settings");

    char *main_ctn = get_str(adata, "ctn_main");
    char *game_ctn = get_str(adata, "ctn_game");
    char *settings_ctn = get_str(adata, "ctn_settings");

    char *rtex_game = get_str(adata, "rtex_game");
    char *rtex_ui = get_str(adata, "rtex_ui");
    char *rtex_menu = get_str(adata, "rtex_menu");
    char *rtex_wall = get_str(adata, "rtex_wall");
    char *rtex_wall_light = get_str(adata, "rtex_wall_light");
    char *rtex_settings = get_str(adata, "rtex_settings");

    add_state(adata, main_state);
    add_state(adata, game_state);
    add_state(adata, settings_state);

    set_state_ingame(adata, game_state, sfTrue);

    add_container(adata, main_ctn);
    set_state_container(adata, main_state, get_container(adata, main_ctn));

    add_container(adata, game_ctn);
    set_state_container(adata, game_state, get_container(adata, game_ctn));

    add_container(adata, settings_ctn);
    set_state_container(adata, settings_state, get_container(adata, settings_ctn));

    add_container(adata, get_str(adata, "ctn_quest"));
    add_container(adata, get_str(adata, "ctn_skill"));

    add_state_rtex(adata, main_state, get_rtex(adata, rtex_menu));
    add_state_rtex(adata, game_state, get_rtex(adata, rtex_game));
    add_state_rtex(adata, game_state, get_rtex(adata, rtex_ui));
    add_state_rtex(adata, game_state, get_rtex(adata, rtex_wall));
    add_state_rtex(adata, game_state, get_rtex(adata, rtex_wall_light));
    add_state_rtex(adata, settings_state, get_rtex(adata, rtex_settings));
}

void init_live(s_appdata *adata)
{
    init_live_light(adata);
    init_live_textures(adata);
    init_live_states(adata);
    init_live_main_menu(adata);
    init_live_settings_menu(adata);
    init_player(adata);
    init_live_ingame_ui(adata);
    init_map(adata, get_str(adata, "default_map"));
    load_entity_config(adata);
    init_entity_emiters(adata);
    init_entity_behaviors(adata);
    init_console(adata);
    init_ingame_inventory(adata, get_str(adata, "ctn_game"), get_str(adata, "rtex_ui"));
    init_quests(adata);
    init_quest_ui(adata);
    init_zones(adata, 5);
    init_skill_tree(adata);

    switch_state(adata, get_str(adata, "state_main"));

    set_friction(adata, 18.0f);
    set_max_speed(adata, 1600.0f);
    set_velocity(adata, 80.0f);

    translate_player(adata, (sfVector2f) { 600.0f, 600.0f });
}
