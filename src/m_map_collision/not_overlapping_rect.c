/*
** EPITECH PROJECT, 2023
** m_map_collision
** File description:
** not_overlapping_rect
*/

#include "main.h"

sfFloatRect not_overlapping_rect(sfFloatRect rect1, sfVector2f movement)
{
    sfFloatRect nor = rect1;
    nor.left += movement.x;
    nor.top += movement.y;

    if (movement.y > 0 && movement.y < rect1.height) {
        nor.top = rect1.top + rect1.height;
        nor.height = movement.y;
    } if (movement.y < 0 && movement.y > -rect1.height) {
        nor.top = rect1.top + movement.y;
        nor.height = -movement.y;
    } if (movement.x > 0 && movement.x < rect1.width) {
        nor.left = rect1.left + rect1.width;
        nor.width = movement.x;
    } if (movement.x < 0 && movement.x > -rect1.width) {
        nor.left = rect1.left + movement.x;
        nor.width = -movement.x;
    }
    return (nor);
}
