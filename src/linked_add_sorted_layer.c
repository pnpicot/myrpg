/*
** EPITECH PROJECT, 2023
** src
** File description:
** linked_add_sorted_layer
*/

#include "main.h"

static int get_layer(s_ref *ref)
{
    if (ref->type == TYPE_RECT)
        return (((s_rect *)ref->ref)->layer);
    if (ref->type == TYPE_SPRITE)
        return (((s_sprite *)ref->ref)->layer);
    if (ref->type == TYPE_TEXT)
        return (((s_text *)ref->ref)->layer);
    if (ref->type == TYPE_CIRCLE)
        return (((s_circle *)ref->ref)->layer);
    if (ref->type == TYPE_EMITER)
        return (((s_particle_src *)ref->ref)->layer);
    if (ref->type == TYPE_VERTEX)
        return (((s_vertex *)ref->ref)->layer);
    return (0);
}

void linked_add_sorted_layer(linked_node *node, s_ref *ref)
{
    int layer = get_layer(ref);
    if (node->data == NULL) {
        node->data = ref;
        return;
    }
    if (get_layer(node->data) > layer) {
        linked_node *new_node = linked_new();
        new_node->data = node->data;
        node->data = ref;
        new_node->next = node->next;
        node->next = new_node;
        return;
    }
    while (node->next != NULL && get_layer(node->next->data) <= layer) {
        node = node->next;
    }
    linked_node *new_node = linked_new();
    new_node->data = ref;
    new_node->next = node->next;
    node->next = new_node;
}
