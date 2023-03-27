/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Vertex module
*/

#include "../include/main.h"

void resize_vertex(s_appdata *adata, char *id, int vertex_count)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfVertexArray_resize(vertex->elem, vertex_count);
}

void move_vertex(s_appdata *adata, char *id, int index, sfVector2f pos)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    int array_size = sfVertexArray_getVertexCount(vertex->elem);

    if (!in_range(index, 0, array_size - 1)) {
        my_printf(get_error(adata, "vertex_unknown"));
        return;
    }

    sfVertex *vertex_unit = sfVertexArray_getVertex(vertex->elem, index);
    vertex_unit->position = pos;
}

void color_vertex(s_appdata *adata, char *id, int index, sfColor color)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    int array_size = sfVertexArray_getVertexCount(vertex->elem);

    if (!in_range(index, 0, array_size - 1)) {
        my_printf(get_error(adata, "vertex_unknown"));
        return;
    }

    sfVertex *vertex_unit = sfVertexArray_getVertex(vertex->elem, index);
    vertex_unit->color = color;
}

void set_vertex_type(s_appdata *adata, char *id, sfPrimitiveType type)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfVertexArray_setPrimitiveType(vertex->elem, type);
}

void translate_vertex(s_appdata *adata, char *id, int index, sfVector2f pos_ch)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    int array_size = sfVertexArray_getVertexCount(vertex->elem);

    if (!in_range(index, 0, array_size - 1)) {
        my_printf(get_error(adata, "unknown_vertex"));
        return;
    }

    sfVertex *vertex_unit = sfVertexArray_getVertex(vertex->elem, index);
    vertex_unit->position.x += pos_ch.x;
    vertex_unit->position.y += pos_ch.y;
}
