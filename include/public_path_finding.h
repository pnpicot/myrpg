/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** public_path_finding
*/


#ifndef _PUBLIC_PATH_FINDING_H_
    #define _PUBLIC_PATH_FINDING_H_

    #include "main.h"

    linked_node *path_finding(char **map, sfVector2i *map_size,
    sfIntRect hitbox, sfVector2i end);
#endif
