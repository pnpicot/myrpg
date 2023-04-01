/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Wall module
*/

#include "../include/main.h"

void show_walls(s_appdata *adata)
{
    linked_node *walls = adata->lists->walls;

    while (walls != NULL && walls->data != NULL) {
        s_wall *cur = (s_wall *) walls->data;

        cur->hitbox->active = 1;

        walls = walls->next;
    }
}

void hide_walls(s_appdata *adata)
{
    linked_node *walls = adata->lists->walls;

    while (walls != NULL && walls->data != NULL) {
        s_wall *cur = (s_wall *) walls->data;

        cur->hitbox->active = 0;

        walls = walls->next;
    }
}

void update_current_wall(s_appdata *adata)
{
    if (adata->current_wall != NULL) {
        s_wall *wall = get_wall(adata, adata->current_wall);

        sfVector2f wall_size;
        sfVector2f wall_pos = sfRectangleShape_getPosition(wall->hitbox->elem);
        sfVector2f mouse = get_mouse(adata);

        wall_size.x = mouse.x - wall_pos.x;
        wall_size.y = mouse.y - wall_pos.y;

        resize_wall(adata, adata->current_wall, wall_size);
    }
}
