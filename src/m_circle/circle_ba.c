/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Circle module
*/

#include "../include/main.h"

s_circle *get_circle(s_appdata *adata, char *id)
{
    linked_node *circles = adata->lists->circles;

    while (circles != NULL && circles->data != NULL) {
        s_circle *cur = (s_circle *) circles->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        circles = circles->next;
    }

    return (NULL);
}

void delete_circle(s_appdata *adata, char *id)
{
    s_circle *circle = get_circle(adata, id);
    if (circle == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }
    linked_node *circles = adata->lists->circles;
    int ite = 0;
    while (circles != NULL && circles->data != NULL) {
        s_circle *cur = (s_circle *) circles->data;
        if (!my_strcmp(cur->id, id)) {
            sfCircleShape_destroy(cur->elem);
            break;
        }
        ite++;
        circles = circles->next;
    }
    linked_delete(&adata->lists->circles, ite);
}

void add_circle(s_appdata *adata, char *id, int layer)
{
    s_circle *circle = get_circle(adata, id);
    if (circle != NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "already_exists"));
        return;
    }
    s_circle *new_circle = malloc(sizeof(s_circle));
    if (new_circle == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return;
    }
    s_ints *integers = adata->integers;
    new_circle->active = 1;
    new_circle->elem = sfCircleShape_create();
    new_circle->hidden = 0;
    new_circle->id = id;
    new_circle->rtex_id = NULL;
    new_circle->layer = layer;
    new_circle->pos = (sfVector2f) { 0, 0 };
    if (layer < integers->min_layer) integers->min_layer = layer;
    if (layer > integers->max_layer) integers->max_layer = layer;
    linked_add(adata->lists->circles, new_circle);
}

void set_circle_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_circle *circle = get_circle(adata, id);
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (circle == NULL || rtex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    circle->rtex_id = rtex_id;
    s_ref *ref = get_ref(adata, circle, TYPE_CIRCLE);
    linked_add_sorted_layer(rtex->objects, ref);
}

void set_circle_active(s_appdata *adata, char *id, sfUint8 active)
{
    s_circle *circle = get_circle(adata, id);

    if (circle == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    circle->active = active;
}
