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
        sfView_setSize(adata->view, (sfVector2f){800, 600});
        sfRenderWindow_setView(adata->win, adata->view);
        return;
    }
    sfView_setSize(adata->view, (sfVector2f){size.width, size.height});
    sfRenderWindow_setView(adata->win, adata->view);
}
