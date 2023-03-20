/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Vertex module
*/

#include "../include/main.h"

void clear_vertex(s_appdata *adata, char *id)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfVertexArray_clear(vertex->elem);
}

sfFloatRect get_vertex_bounds(s_appdata *adata, char *id)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfFloatRect) { -1, -1, -1, -1 });
    }

    return (sfVertexArray_getBounds(vertex->elem));
}
