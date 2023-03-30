/*
** EPITECH PROJECT, 2023
** event
** File description:
** key_event
*/

#include "map_editor.h"

void key_event(internal_data_t *const data)
{
    if (data->event.type == sfEvtKeyPressed && data->event.key.code ==
    sfKeyEnter)
        data->enter = PRESSED;
    if (data->event.type == sfEvtKeyPressed && data->event.key.code ==
    sfKeyEnter)
        data->enter = RELEASED;
    if (sfKeyboard_isKeyPressed(sfKeyR))
        data->actual_texture++;
    if (sfKeyboard_isKeyPressed(sfKeyF))
        data->actual_texture--;
}
