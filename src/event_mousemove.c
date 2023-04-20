/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Mouse move event module
*/

#include "main.h"

void register_mousemove(s_appdata *adata, sfMouseMoveEvent mouse)
{
    sfVector2f mouse_pos = get_mouse(adata);
    s_ints *integers = adata->integers;

    object_check_hover(adata);

    if (adata->game_data->in_stree && adata->game_data->mouse_down) {
        sfVector2f delta;
        delta.x = mouse_pos.x - adata->game_data->mouse_last.x;
        delta.y = mouse_pos.y - adata->game_data->mouse_last.y;

        char *skill_ctn = get_str(adata, "ctn_skill");

        translate_container(adata, skill_ctn, delta);

        adata->game_data->mouse_last = mouse_pos;
    }
}
