/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Setup module
*/

#include "main.h"

void init_live_states_n(s_appdata *adata, char *game_state, char *main_state,
char *settings_state)
{
    char *rtex_load = get_str(adata, "rtex_load");
    char *load_ctn = get_str(adata, "ctn_load");
    char *load_state = get_str(adata, "state_load");
    add_container(adata, load_ctn);
    add_state_rtex(adata, load_state, get_rtex(adata, rtex_load));
    set_state_container(adata, load_state, get_container(adata, load_ctn));
    char *rtex_game = get_str(adata, "rtex_game");
    char *rtex_ui = get_str(adata, "rtex_ui");
    char *rtex_wall = get_str(adata, "rtex_wall");
    char *rtex_wall_light = get_str(adata, "rtex_wall_light");
    char *game_ctn = get_str(adata, "ctn_game");
    set_state_ingame(adata, game_state, sfTrue);
    add_container(adata, game_ctn);
    set_state_container(adata, game_state, get_container(adata, game_ctn));
    add_container(adata, get_str(adata, "ctn_quest"));
    add_container(adata, get_str(adata, "ctn_skill"));
    add_state_rtex(adata, game_state, get_rtex(adata, rtex_game));
    add_state_rtex(adata, game_state, get_rtex(adata, rtex_ui));
    add_state_rtex(adata, game_state, get_rtex(adata, rtex_wall));
    add_state_rtex(adata, game_state, get_rtex(adata, rtex_wall_light));
}

void init_live_states(s_appdata *adata)
{
    char *main_state = get_str(adata, "state_main");
    char *game_state = get_str(adata, "state_game");
    char *settings_state = get_str(adata, "state_settings");
    char *main_ctn = get_str(adata, "ctn_main");
    char *settings_ctn = get_str(adata, "ctn_settings");
    char *rtex_settings = get_str(adata, "rtex_settings");
    char *rtex_menu = get_str(adata, "rtex_menu");
    char *load_state = get_str(adata, "state_load");
    add_state(adata, main_state);
    add_state(adata, game_state);
    add_state(adata, settings_state);
    add_container(adata, main_ctn);
    set_state_container(adata, main_state, get_container(adata, main_ctn));
    add_container(adata, settings_ctn);
    set_state_container(adata, settings_state,
    get_container(adata,settings_ctn));
    add_state_rtex(adata, main_state, get_rtex(adata, rtex_menu));
    add_state_rtex(adata, settings_state, get_rtex(adata, rtex_settings));
    add_state(adata, load_state);
    init_gameover(adata);
    init_live_states_n(adata, game_state, main_state, settings_state);
}

void init_live_n(s_appdata *adata)
{
    init_ingame_inventory(adata, get_str(adata, "ctn_game"),
    get_str(adata, "rtex_ui"));
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

void init_live(s_appdata *adata)
{
    init_live_light(adata);
    init_live_textures(adata);
    init_live_states(adata);
    init_live_main_menu(adata);
    init_live_settings_menu(adata);
    init_live_load_menu(adata);
    init_player(adata);
    init_live_ingame_ui(adata);
    init_map(adata, get_str(adata, "default_map"));
    load_entity_config(adata);
    init_entity_emiters(adata);
    init_entity_behaviors(adata);
    init_console(adata);
    init_npc(adata);
    init_live_n(adata);
}
