/*
** EPITECH PROJECT, 2022
** Linked lists functions
** File description:
** Second file
*/

#include "../my.h"

linked_node *linked_new(void)
{
    linked_node *node = malloc(sizeof(linked_node));

    node->data = NULL;
    node->next = NULL;

    return (node);
}

void linked_add(linked_node *node, void *data)
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

void linked_delete(linked_node **list, int id)
{
    linked_node *node = *list;
    int count = linked_count(node);
    int ite = 0;

    if (count <= 1) {
        node->data = NULL;
        return;
    } else if (!id) {
        (*list) = node->next;
    }

    while (node != NULL) {
        if (ite == id - 1) {
            node->next = node->next->next;
            break;
        }

        ite++;
        node = node->next;
    }
}

int linked_count(linked_node *node)
{
    int count = 0;

    while (node != NULL) {
        if (node->data != NULL) count++;
        node = node->next;
    }

    return (count);
}

linked_node *linked_get(linked_node *node, int id)
{
    int ite = 0;

    while (node != NULL) {
        if (ite == id) return (node);

        ite++;
        node = node->next;
    }
}
