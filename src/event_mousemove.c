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

    if (integers->in_game && get_int(adata, "dev_mode"))
        move_light(adata, "mouse_light", mouse_pos);
}
