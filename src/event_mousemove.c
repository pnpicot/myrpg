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

    object_check_hover(adata);
    move_light(adata, "mouse_light", mouse_pos);
}
