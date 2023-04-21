/*
** EPITECH PROJECT, 2023
** src
** File description:
** front_linked_add
*/

#include "main.h"

void front_linked_add(linked_node *node, void *data)
{
    if (node->data == NULL) {
        node->data = data;
        return;
    }

    linked_node *new_node = linked_new();
    new_node->data = node->data;
    node->data = data;
    new_node->next = node->next;
    node->next = new_node;
}

void back_linked_add(linked_node *node, void *data)
{
    if (node->data == NULL) {
        node->data = data;
        return;
    }

    while (node->next != NULL) {
        node = node->next;
    }

    linked_node *new_node = linked_new();
    new_node->data = data;
    node->next = new_node;
}