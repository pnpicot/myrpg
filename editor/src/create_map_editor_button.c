/*
** EPITECH PROJECT, 2023
** src
** File description:
** create_map_editor_button
*/

#include "map_editor.h"
#include <fcntl.h>
#include "unistd.h"

static void write_int(int fd, int nb)
{
    if (nb >= 10)
        write_int(fd, nb / 10);
    nb = nb % 10 + '0';
    if (write(fd, &nb, 1) < 0)
        return;
}

static int save_to_file(internal_data_t *const data)
{
    int fd = open("map.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
        return (-1);
    write_int(fd, data->map_size.x);
    if (write(fd, " ", 1) < 0)
        return (-1);
    write_int(fd, data->map_size.y);
    if (write(fd, "\n", 1) < 0)
        return (-1);
    for (int i = 0; i < data->map_size.y; i++) {
        if (write(fd, data->map[i], data->map_size.x) < 0)
            return (-1);
        if (write(fd, "\n", 1) < 0)
            return (-1);
    }
    close(fd);
    return (0);
}

static int create_map_editor_button_part3(internal_data_t *const data)
{
    button_t *button = create_button(data, 1, (sfFloatRect){150, 500, 50, 50});
    if (button == NULL)
        return (-1);
    button->text_char = "-";
    button->func = &sub_brush_size;
    button->next = data->button;
    data->button = button;
    button = create_button(data, 1, (sfFloatRect){250, 50, 150, 50});
    if (button == NULL)
        return (-1);
    button->text_char = "SAVE";
    button->func = &save_to_file;
    button->next = data->button;
    data->button = button;
    return (0);
}


static int create_map_editor_button_part2(internal_data_t *const data)
{
    button_t *button = create_button(data, 1, (sfFloatRect){20, 400, 200, 50});
    if (button == NULL)
        return (-1);
    button->text_char = "RECTANGLE";
    button->func = &set_tool_rectangle;
    button->next = data->button;
    data->button = button;
    button = create_button(data, 1, (sfFloatRect){40, 500, 50, 50});
    if (button == NULL)
        return (-1);
    button->text_char = "+";
    button->func = &add_brush_size;
    button->next = data->button;
    data->button = button;
    return (create_map_editor_button_part3(data));
}

int create_map_editor_button(internal_data_t *const data)
{
    button_t *button = create_button(data, 1, (sfFloatRect){20, 200, 200, 50});
    if (button == NULL)
        return (-1);
    button->text_char = "MOVE";
    button->func = &set_tool_move;
    button->next = data->button;
    data->button = button;
    button = create_button(data, 1, (sfFloatRect){20, 300, 200, 50});
    if (button == NULL)
        return (-1);
    button->text_char = "DRAW";
    button->func = &set_tool_draw;
    button->next = data->button;
    data->button = button;
    return (create_map_editor_button_part2(data));
}
