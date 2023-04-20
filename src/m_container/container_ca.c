/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Container module
*/

#include "../include/main.h"

void color_container(s_appdata *adata, char *id, sfColor color)
{
    s_container *container = get_container(adata, id);

    if (container == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    linked_node *nodes = container->nodes;

    while (nodes != NULL && nodes->data != NULL) {
        s_ref *cur = (s_ref *) nodes->data;

        color_element(adata, cur->ref, cur->type, color);

        nodes = nodes->next;
    }
}

void set_container_outline(s_appdata *adata, char *id, \
sfColor color, float thickness)
{
    s_container *container = get_container(adata, id);

    if (container == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
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
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
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
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
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

void get_container_bounds_next(s_appdata *adata, \
linked_node *nodes, sfFloatRect *max)
{
    while (nodes != NULL && nodes->data != NULL) {
        s_ref *cur = (s_ref *) nodes->data;
        sfFloatRect cur_bounds = get_element_bounds(adata, cur->ref, cur->type);
        if (cur_bounds.left < max->left) max->left = cur_bounds.left;
        if (cur_bounds.top < max->top) max->top = cur_bounds.top;
        if (cur_bounds.left + cur_bounds.width > max->left + max->width) {
            max->width += cur_bounds.left + cur_bounds.width;
            max->width -= max->left + max->width;
        }
        if (cur_bounds.top + cur_bounds.height > max->top + max->height) {
            max->height += cur_bounds.top + cur_bounds.height;
            max->height -= max->top + max->height;
        }
        nodes = nodes->next;
    }
}
