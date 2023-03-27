/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Rectangle shape module
*/

#include "../include/main.h"

s_rect *get_rect(s_appdata *adata, char *id)
{
    linked_node *rects = adata->lists->rects;

    while (rects != NULL && rects->data != NULL) {
        s_rect *cur = (s_rect *) rects->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        rects = rects->next;
    }

    return (NULL);
}

void delete_rect(s_appdata *adata, char *id)
{
    s_rect *rect = get_rect(adata, id);
    if (rect == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }
    linked_node *rects = adata->lists->rects;
    int ite = 0;
    while (rects != NULL && rects->data != NULL) {
        s_rect *cur = (s_rect *) rects->data;
        if (!my_strcmp(cur->id, id)) {
            sfRectangleShape_destroy(cur->elem);
            break;
        }
        ite++;
        rects = rects->next;
    }
    linked_delete(&adata->lists->rects, ite);
}

void add_rect(s_appdata *adata, char *id, int layer)
{
    s_rect *rect = get_rect(adata, id);
    if (rect != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }
    s_rect *new_rect = malloc(sizeof(s_rect));
    if (new_rect == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }
    s_ints *integers = adata->integers;
    new_rect->active = sfTrue;
    new_rect->elem = sfRectangleShape_create();
    new_rect->hidden = sfFalse;
    new_rect->id = id;
    new_rect->rtex_id = NULL;
    new_rect->layer = layer;
    if (layer < integers->min_layer) integers->min_layer = layer;
    if (layer > integers->max_layer) integers->max_layer = layer;
    linked_add(adata->lists->rects, new_rect);
}

void resize_rect(s_appdata *adata, char *id, sfVector2f size)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfRectangleShape_setSize(rect->elem, size);
}

void move_rect(s_appdata *adata, char *id, sfVector2f pos)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfRectangleShape_setPosition(rect->elem, pos);
}
