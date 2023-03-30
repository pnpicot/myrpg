/*
** EPITECH PROJECT, 2023
** event
** File description:
** mouse_event
*/

#include "map_editor.h"

static void set_pos(internal_data_t *const data)
{
    if (data->event.type == sfEvtMouseMoved) {
        data->mouse_pos = (sfVector2f){data->event.mouseMove.x,
        data->event.mouseMove.y};

    }
}

static void set_lmb(internal_data_t *const data)
{
    if (data->event.type == sfEvtMouseButtonPressed && data->event.mouseButton.
    button == sfMouseLeft)
        data->lmb = PRESSED;
    if (data->event.type == sfEvtMouseButtonReleased && data->event.mouseButton.
    button == sfMouseLeft)
        data->lmb = RELEASED;
}

void mouse_event(internal_data_t *const data)
{
    set_pos(data);
    set_lmb(data);
}
