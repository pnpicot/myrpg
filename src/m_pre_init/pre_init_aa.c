/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Pre-initialization module
*/

#include "../include/main.h"

void init_gamedata(s_appdata *adata)
{
    adata->game_data = malloc(sizeof(s_game));

    if (adata->game_data == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    s_game *game_data = adata->game_data;

    game_data->view_pos = (sfVector2f) { 0, 0 };
    game_data->map_size = (sfVector2f) { 3000, 3000 };
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
