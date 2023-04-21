/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Vertex module
*/

#include "../include/main.h"

s_vertex *get_vertex(s_appdata *adata, char *id)
{
    linked_node *vertexes = adata->lists->vertexes;

    while (vertexes != NULL && vertexes->data != NULL) {
        s_vertex *cur = (s_vertex *) vertexes->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        vertexes = vertexes->next;
    }

    return (NULL);
}

void delete_vertex(s_appdata *adata, char *id)
{
    s_vertex *vertex = get_vertex(adata, id);
    if (vertex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }
    linked_node *vertexes = adata->lists->vertexes;
    int ite = 0;
    while (vertexes != NULL && vertexes->data != NULL) {
        s_vertex *cur = (s_vertex *) vertexes->data;
        if (!my_strcmp(cur->id, id)) {
            sfVertexArray_destroy(cur->elem);
            break;
        }
        ite++;
        vertexes = vertexes->next;
    }
    linked_delete(&adata->lists->vertexes, ite);
}

void add_vertex(s_appdata *adata, char *id, int layer)
{
    s_vertex *vertex = get_vertex(adata, id);
    if (vertex != NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "already_exists"));
        return;
    }
    s_vertex *new_vertex = malloc(sizeof(s_vertex));
    if (new_vertex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "mem_alloc"));
        return;
    }
    s_ints *integers = adata->integers;
    new_vertex->active = 1;
    new_vertex->elem = sfVertexArray_create();
    new_vertex->hidden = 0;
    new_vertex->id = id;
    new_vertex->rtex_id = NULL;
    new_vertex->layer = layer;
    new_vertex->pos = (sfVector2f) { 0, 0 };
    if (layer < integers->min_layer) integers->min_layer = layer;
    if (layer > integers->max_layer) integers->max_layer = layer;
    linked_add(adata->lists->vertexes, new_vertex);
}

void set_vertex_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_vertex *vertex = get_vertex(adata, id);
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (vertex == NULL || rtex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    vertex->rtex_id = rtex_id;
    s_ref *ref = get_ref(adata, vertex, TYPE_VERTEX);
    linked_add_sorted_layer(rtex->objects, ref);
}

void set_vertex_active(s_appdata *adata, char *id, sfUint8 active)
{
    s_vertex *vertex = get_vertex(adata, id);

    if (vertex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    vertex->active = active;
}
