/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** World event module
*/

#include "main.h"

void cycle_world_time(s_appdata *adata)
{
    if (!get_int(adata, "enable_shader")) return;

    s_game *game_data = adata->game_data;

    game_data->time += get_float(adata, "time_speed");

    if (game_data->time > 2.0f) game_data->time = 0;

    s_rtex *blend = get_rtex(adata, adata->light_blend_rtex->id);
    s_rtex *wall = get_rtex(adata, get_str(adata, "rtex_wall_light"));
    float time = game_data->time;
    float cur_time = time > 1.0f ? 1.0f - (time - 1.0f) : time;
    sfColor day_color = get_config_color(adata, "day_color");
    sfColor night_color = get_config_color(adata, "night_color");
    sfColor lerp = lerp_color(night_color, day_color, cur_time);

    set_rtex_clear(adata, blend->id, lerp);
    set_rtex_clear(adata, wall->id, lerp);
}
