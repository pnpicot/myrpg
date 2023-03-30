/*
** EPITECH PROJECT, 2023
** src
** File description:
** size_selection
*/

#include "map_editor.h"

static int my_atoi(const char *str)
{
    int i = 0;
    int nb = 0;

    if (str == NULL)
        return (-1);
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (-1);
        nb = nb * 10 + str[i] - '0';
        i++;
    }
    if (i < 1 || nb < 20)
        return (-1);
    return (nb);
}

static int enter_size(internal_data_t *const data)
{
    int x = my_atoi(sfText_getString(data->button->next->text));
    int y = my_atoi(sfText_getString(data->button->next->next->text));

    if (x < 0 || (x * (TEXTURE_SIZE + GRID_SIZE) - GRID_SIZE) > 32768)
        data->button->next->temp_color_time = 10000;
    if (y < 0 || (y * (TEXTURE_SIZE + GRID_SIZE) - GRID_SIZE) > 32768)
        data->button->next->next->temp_color_time = 10000;
    if (x < 0 || y < 0 || (x * (TEXTURE_SIZE + GRID_SIZE) - GRID_SIZE) > 32768
    || (y * (TEXTURE_SIZE + GRID_SIZE) - GRID_SIZE) > 32768)
        return (0);
    data->map_size = (sfVector2i){x, y};
    data->menu = MAP_EDITOR;
    destroy_buttons(data);
    data->button = NULL;
    return (1);
}

static int create_menu(internal_data_t *const data)
{
    button_t *button = NULL;

    button = create_button(data, 1, (sfFloatRect){585, 400, 300, 100});
    if (button == NULL)
        return (-1);
    button->next = data->button;
    data->button = button;
    button = create_button(data, 1, (sfFloatRect){1050, 400, 300, 100});
    if (button == NULL)
        return (-1);
    button->next = data->button;
    data->button = button;
    return (0);
}

int size_selection(internal_data_t *const data)
{
    button_t *button = NULL;

    if (data->button != NULL)
        return (0);
    if (create_menu(data) < 0)
        return (-1);
    button = create_button(data, 0, (sfFloatRect){810, 600, 300, 100});
    if (button == NULL)
        return (-1);
    button->texture = sfTexture_createFromFile("assets/enter.gif", NULL);
    if (button->texture == NULL)
        return (-1);
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setScale(button->sprite, (sfVector2f){0.6, 0.6});
    button->func = &enter_size;
    button->next = data->button;
    data->button = button;
    return (0);
}
