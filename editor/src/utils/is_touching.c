/*
** EPITECH PROJECT, 2023
** src
** File description:
** is_touching
*/

#include "map_editor.h"

sfBool is_touching(sfRenderWindow *window, sfFloatRect *rect,
sfVector2f mouse_pos, sfView *view)
{
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(window, sf2f2i(mouse_pos),
    view);

    return (sfFloatRect_contains(rect, pos.x, pos.y));
}
