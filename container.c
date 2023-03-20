/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Container module
*/

#include "include/main.h"

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
        my_printf(get_error(adata, "unknown_id"));
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
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    s_container *new_container = malloc(sizeof(s_container));

    if (new_container == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    new_container->id = id;
    new_container->nodes = linked_new();

    linked_add(adata->lists->containers, new_container);
}

void add_to_container(s_appdata *adata, char *id, s_ref ref)
{
    s_container *container = get_container(adata, id);

    if (container == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    s_ref *new_ref = malloc(sizeof(s_ref));

    if (new_ref == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
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
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *nodes = container->nodes;

    while (nodes != NULL && nodes->data != NULL) {
        s_ref *cur = (s_ref *) nodes->data;

        translate_element(adata, cur->ref, cur->type, pos_ch);

        nodes = nodes->next;
    }
}

void color_container(s_appdata *adata, char *id, sfColor color)
{
    s_container *container = get_container(adata, id);

    if (container == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *nodes = container->nodes;

    while (nodes != NULL && nodes->data != NULL) {
        s_ref *cur = (s_ref *) nodes->data;

        color_element(adata, cur->ref, cur->type, color);

        nodes = nodes->next;
    }
}

void set_container_outline(s_appdata *adata, char *id, sfColor color, float thickness)
{
    s_container *container = get_container(adata, id);

    if (container == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *nodes = container->nodes;

    while (nodes != NULL && nodes->data != NULL) {
        s_ref *cur = (s_ref *) nodes->data;

        color_element_out(adata, cur->ref, cur->type, color);
        resize_element_out(adata, cur->ref, cur->type, thickness);

        nodes = nodes->next;
    }
}

void rotate_container(s_appdata *adata, char *id, float angle)
{
    s_container *container = get_container(adata, id);

    if (container == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *nodes = container->nodes;

    while (nodes != NULL && nodes->data != NULL) {
        s_ref *cur = (s_ref *) nodes->data;
        float cur_angle = get_element_rotation(adata, cur->ref, cur->type);

        rotate_element(adata, cur->ref, cur->type, cur_angle + angle);

        nodes = nodes->next;
    }
}

void scale_container(s_appdata *adata, char *id, sfVector2f factors)
{
    s_container *container = get_container(adata, id);

    if (container == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *nodes = container->nodes;

    while (nodes != NULL && nodes->data != NULL) {
        s_ref *cur = (s_ref *) nodes->data;
        sfVector2f cur_scale = get_element_scale(adata, cur->ref, cur->type);

        cur_scale.x *= factors.x;
        cur_scale.y *= factors.y;

        scale_element(adata, cur->ref, cur->type, cur_scale);

        nodes = nodes->next;
    }
}

sfFloatRect get_container_bounds(s_appdata *adata, char *id)
{
    s_container *container = get_container(adata, id);

    if (container == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfFloatRect) { -1, -1, -1, -1 });
    }

    if (container->nodes->data == NULL) {
        my_printf(get_error(adata, "container_empty"));
        return ((sfFloatRect) { -1, -1, -1, -1 });
    }

    linked_node *nodes = container->nodes;
    s_ref *first = (s_ref *) nodes->data;
    sfFloatRect max = get_element_bounds(adata, first->ref, first->type);
    nodes = nodes->next;

    while (nodes != NULL && nodes->data != NULL) {
        s_ref *cur = (s_ref *) nodes->data;
        sfFloatRect cur_bounds = get_element_bounds(adata, cur->ref, cur->type);

        if (cur_bounds.left < max.left) max.left = cur_bounds.left;
        if (cur_bounds.top < max.top) max.top = cur_bounds.top;
        
        if (cur_bounds.left + cur_bounds.width > max.left + max.width)
            max.width += (cur_bounds.left + cur_bounds.width) - (max.left + max.width);

        if (cur_bounds.top + cur_bounds.height > max.top + max.height)
            max.height += (cur_bounds.top + cur_bounds.height) - (max.top + max.height);

        nodes = nodes->next;
    }

    return (max);
}

void set_container_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_container *container = get_container(adata, id);

    if (container == NULL) {
        my_printf(get_error(adata, "unknown_id"));
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
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *nodes = container->nodes;

    while (nodes != NULL && nodes->data != NULL) {
        s_ref *cur = (s_ref *) nodes->data;

        set_element_active(adata, cur->ref, cur->type, active);

        nodes = nodes->next;
    }
}
