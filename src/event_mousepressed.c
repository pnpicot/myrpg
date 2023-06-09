/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Mouse pressed event module
*/

#include "main.h"

void register_mousepressed(s_appdata *adata, sfMouseButtonEvent mouse)
{
    object_check_pressed(adata);

    adata->game_data->mouse_down = sfTrue;
    adata->game_data->mouse_last = get_mouse(adata);
}
