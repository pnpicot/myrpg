/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Pre-initialization module
*/

#include "../include/main.h"

void init_zones(s_appdata *adata, int size)
{
    adata->game_data->nb_zones = size;
    float zoom = get_float(adata, "zoom");
    adata->game_data->size_zone.x = (adata->game_data->map_width * 32 * zoom) /
    size;
    adata->game_data->size_zone.y = (adata->game_data->map_height * 32 * zoom) /
    size;
    s_zone **zones = malloc(sizeof(s_zone) * size * size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            s_zone *zone = malloc(sizeof(s_zone));
            char *str_i = nbr_to_str(i);
            char *str_j = nbr_to_str(j);
            zone->id = str_m_add(3, "zone", str_i, str_j);
            free(str_i);
            free(str_j);
            zone->entities = linked_new();
            zones[i * size + j] = zone;
        }
    }
    adata->game_data->zones = zones;
}

void init_gamedata(s_appdata *adata)
{
    adata->game_data = malloc(sizeof(s_game));

    if (adata->game_data == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return;
    }

    s_game *game_data = adata->game_data;
    *game_data = (s_game) {.view_pos = (sfVector2f) { 0, 0 },
    .map_size = (sfVector2f) { 0, 0 }, .friction = 0, .speed = (sfVector2f) { 0,
    0 }, .speed_max = 0, .velocity = 0, .map_width = 0, .map_height = 0,
    .time = 0, .entities = linked_new(), .entity_models = linked_new(),
    .factions = linked_new(), .syringes = linked_new(), .quests =
    linked_new(), .skill_trees = linked_new(), .in_inv = sfFalse,
    .show_quest = sfFalse, .in_stree = sfFalse, .mouse_down = sfFalse,
    .zones = NULL, .nb_zones = 0, .size_zone = (sfVector2f) { 0, 0 },
    .mouse_last = (sfVector2f) { 0, 0 }, .wave_clock = sfClock_create(),
    .faction_index = 0, .wave_count = 0
    };
}

void init_appdata_misc(s_appdata *adata)
{
    adata->win = NULL;
    adata->last_pressed = NULL;
    adata->last_slider = NULL;
    adata->last_input = NULL;
    adata->light_rtex = NULL;
    adata->wall_rtex = NULL;
    adata->mask_rtex = NULL;
    adata->light_res_rtex = NULL;
    adata->light_blend_rtex = NULL;
    adata->current_wall = NULL;
    adata->current_state = NULL;
    adata->player = NULL;

    init_gamedata(adata);
    init_keys(adata);
}

void pre_init(s_appdata *adata)
{
    srand(time(NULL));
    init_appdata_ints(adata);
    init_appdata_floats(adata);
    init_appdata_clocks(adata);
    init_appdata_linkeds(adata);
    init_appdata_misc(adata);
    init_errors(adata);
    init_config(adata);
}
