/*
** EPITECH PROJECT, 2023
** event
** File description:
** text_event
*/

#include "map_editor.h"

int text_event(internal_data_t *const data)
{
    int i = 0;
    char *save = data->text_entered;
    if (data->event.type != sfEvtTextEntered || data->enter != NOTHING)
        return (0);
    for (; data->text_entered != NULL && data->text_entered[i] != '\0'; ++i);
    if (data->event.text.unicode == 8) {
        if (i > 0)
            data->text_entered[i - 1] = '\0';
        return (0);
    }
    data->text_entered = malloc(i + 2);
    if (data->text_entered == NULL)
        return (-1);
    for (int j = 0; j < i; ++j)
        data->text_entered[j] = save[j];
    if (save != NULL)
        free(save);
    data->text_entered[i] = data->event.text.unicode;
    data->text_entered[i + 1] = '\0';
    return (0);
}
