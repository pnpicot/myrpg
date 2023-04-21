/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Container module
*/

#include "../include/main.h"

s_container *get_container(s_appdata *adata, char *id)
{
    linked_node *containers = adata->lists->containers;

    while (containers != NULL && containers->data != NULL) {
        s_container *cur = (s_container *) containers->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        containers = containers->next;
    }

    return (NULL);
}

void delete_container(s_appdata *adata, char *id)
{
    s_container *container = get_container(adata, id);

    if (container == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    linked_node *containers = adata->lists->containers;
    int ite = 0;

    while (containers != NULL && containers->data != NULL) {
        s_container *cur = (s_container *) containers->data;

        if (!my_strcmp(cur->id, id)) break;

        ite++;
        containers = containers->next;
    }

    linked_delete(&adata->lists->containers, ite);
}

void add_container(s_appdata *adata, char *id)
{
    s_container *container = get_container(adata, id);

    if (container != NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "already_exists"));
        return;
    }

    s_container *new_container = malloc(sizeof(s_container));

    if (new_container == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return;
    }

    new_container->active = 1;
    new_container->id = id;
    new_container->nodes = linked_new();

    linked_add(adata->lists->containers, new_container);
}

void add_to_container(s_appdata *adata, char *id, s_ref ref)
{
    s_container *container = get_container(adata, id);

    if (container == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    s_ref *new_ref = malloc(sizeof(s_ref));

    if (new_ref == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return;
    }

    new_ref->ref = ref.ref;
    new_ref->type = ref.type;

    linked_add(container->nodes, new_ref);
}

void translate_container(s_appdata *adata, char *id, sfVector2f pos_ch)
{
    s_container *container = get_container(adata, id);

    if (container == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    linked_node *nodes = container->nodes;

    while (nodes != NULL && nodes->data != NULL) {
        s_ref *cur = (s_ref *) nodes->data;

        translate_element(adata, cur->ref, cur->type, pos_ch);

        nodes = nodes->next;
    }
}
