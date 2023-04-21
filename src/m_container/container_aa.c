/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Container module
*/

#include "../include/main.h"

sfFloatRect get_container_bounds(s_appdata *adata, char *id)
{
    s_container *container = get_container(adata, id);
    if (container == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return ((sfFloatRect) { -1, -1, -1, -1 });
    }
    if (container->nodes->data == NULL) return ((sfFloatRect) { 0, 0, 0, 0 });
    linked_node *nodes = container->nodes;
    s_ref *first = (s_ref *) nodes->data;
    sfFloatRect max = get_element_bounds(adata, first->ref, first->type);
    nodes = nodes->next;
    get_container_bounds_next(adata, nodes, &max);
    return (max);
}

void set_container_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_container *container = get_container(adata, id);

    if (container == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    linked_node *nodes = container->nodes;

    while (nodes != NULL && nodes->next != NULL) {
        s_ref *cur = (s_ref *) nodes->data;

        set_element_rtex(adata, cur->ref, cur->type, rtex_id);

        nodes = nodes->next;
    }
}

void set_container_active(s_appdata *adata, char *id, sfUint8 active)
{
    s_container *container = get_container(adata, id);

    if (container == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    container->active = active;

    linked_node *nodes = container->nodes;

    while (nodes != NULL && nodes->data != NULL) {
        s_ref *cur = (s_ref *) nodes->data;

        set_element_active(adata, cur->ref, cur->type, active);

        nodes = nodes->next;
    }
}

sfBool is_container_active(s_appdata *adata, char *id)
{
    s_container *container = get_container(adata, id);

    if (container == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return (sfFalse);
    }
    return (container->active);
}
