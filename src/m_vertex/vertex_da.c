/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Vertex module
*/

#include "../include/main.h"

void translate_vertex_all(s_appdata *adata, char *id, sfVector2f pos_ch)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    int array_size = sfVertexArray_getVertexCount(vertex->elem);

    for (int i = 0; i < array_size; i++) {
        sfVertex *vertex_unit = sfVertexArray_getVertex(vertex->elem, i);
        vertex_unit->position.x += pos_ch.x;
        vertex_unit->position.y += pos_ch.y;
    }
}

void color_vertex_all(s_appdata *adata, char *id, sfColor color)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    int array_size = sfVertexArray_getVertexCount(vertex->elem);

    for (int i = 0; i < array_size; i++) {
        sfVertex *vertex_unit = sfVertexArray_getVertex(vertex->elem, i);
        vertex_unit->color = color;
    }
}

int get_vertex_size(s_appdata *adata, char *id)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return (-1);
    }

    return (sfVertexArray_getVertexCount(vertex->elem));
}

sfVector2f get_vertex_pos(s_appdata *adata, char *id, int index)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    int array_size = sfVertexArray_getVertexCount(vertex->elem);

    if (!in_range(index, 0, array_size - 1)) {
        my_printf(get_error(adata, "unknown_vertex"));
        return ((sfVector2f) { -1, -1 });
    }

    sfVertex *vertex_unit = sfVertexArray_getVertex(vertex->elem, index);

    return (vertex_unit->position);
}

sfColor get_vertex_color(s_appdata *adata, char *id, int index)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return (sfBlack);
    }

    int array_size = sfVertexArray_getVertexCount(vertex->elem);

    if (!in_range(index, 0, array_size - 1)) {
        my_printf(get_error(adata, "unknown_vertex"));
        return (sfBlack);
    }

    sfVertex *vertex_unit = sfVertexArray_getVertex(vertex->elem, index);

    return (vertex_unit->color);
}
