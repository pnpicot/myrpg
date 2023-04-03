/*
** EPITECH PROJECT, 2023
** utils
** File description:
** function_pointer
*/

#include "map_editor.h"

int set_tool_move(internal_data_t *const data)
{
    data->tool = MOVE;
    return (0);
}

int set_tool_draw(internal_data_t *const data)
{
    data->tool = DRAW;
    return (0);
}

int set_tool_rectangle(internal_data_t *const data)
{
    data->tool = RECTANGLE;
    return (0);
}

int add_brush_size(internal_data_t *const data)
{
    data->brush_size += 2;
    return (0);
}

int sub_brush_size(internal_data_t *const data)
{
    if (data->brush_size <= 2)
        return (0);
    data->brush_size -= 2;
    return (0);
}
