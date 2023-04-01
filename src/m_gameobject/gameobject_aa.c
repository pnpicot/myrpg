/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Game object module
*/

#include "../include/main.h"

void update_gameobjects(s_appdata *adata)
{
    linked_node *gameobjects = adata->lists->gameobjects;

    while (gameobjects != NULL && gameobjects->data != NULL) {
        s_gameobj *cur = (s_gameobj *) gameobjects->data;

        move_gameobject(adata, cur);

        gameobjects = gameobjects->next;
    }
}
