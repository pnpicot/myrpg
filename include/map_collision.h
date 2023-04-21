/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** map_collision
*/


#ifndef _MAP_COLLISION_H_
    #define _MAP_COLLISION_H_

    #include "main.h"

    sfVector2f is_map_colliding(s_appdata *adata, s_entity *entity,
    sfVector2f movement);
    linked_node *what_is_touching(s_appdata *adata, sfFloatRect hitbox);
    sfFloatRect not_overlapping_rect(sfFloatRect rect1, sfVector2f movement);
#endif
