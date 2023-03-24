/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Mouse pressed event module
*/

#include "include/main.h"

void register_mousepressed(s_appdata *adata, sfMouseButtonEvent mouse)
{
    object_check_pressed(adata);

    if (adata->wall_rtex != NULL) {
        char *id = get_random_id(10);

        add_wall(adata, id, (sfFloatRect) { 0, 0, 0, 0 });
        move_wall(adata, id, get_mouse(adata));
        show_walls(adata);

        adata->current_wall = id;
    }
}
