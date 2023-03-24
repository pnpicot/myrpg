/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Mouse move event module
*/

#include "include/main.h"

void register_mousemove(s_appdata *adata, sfMouseMoveEvent mouse)
{
    object_check_hover(adata);
    move_light(adata, "mouse_light", get_mouse(adata));
}
