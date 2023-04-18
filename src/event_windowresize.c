/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Window resize event module
*/

#include "main.h"

void register_windowresize(s_appdata *adata, sfSizeEvent size)
{
    if (size.width < 800 || size.height < 600) {
        sfRenderWindow_setSize(adata->win, (sfVector2u){800, 600});
        size.width = 800;
        size.height = 600;
    }

    sfVector2f new_size = {size.width, size.height};
    if ((double)1920 / size.width > (double)1080 / size.height) {
        new_size.x *= (double)1080 / size.height;
        new_size.y *= (double)1080 / size.height;
    } else {
        new_size.x *= (double)1920 / size.width;
        new_size.y *= (double)1920 / size.width;
    }
    sfView_setSize(adata->view, new_size);
    sfRenderWindow_setView(adata->win, adata->view);
}
