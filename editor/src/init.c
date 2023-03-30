/*
** EPITECH PROJECT, 2023
** editor
** File description:
** init
*/

#include "map_editor.h"

internal_data_t *init(void)
{
    internal_data_t *data = malloc(sizeof(internal_data_t));

    if (data == NULL)
        return (NULL);
    *data = (internal_data_t){0};
    data->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
    "Map Editor", sfClose | sfResize, NULL);
    if (data->window == NULL)
        return (NULL);
    data->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    if (data->view == NULL)
        return (NULL);
    data->left_view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    if (data->left_view == NULL)
        return (NULL);
    data->map = NULL;
    data->v_scale = 1;
    data->brush_size = 1;
    data->select_rectangle.left = -11;
    return (data);
}
