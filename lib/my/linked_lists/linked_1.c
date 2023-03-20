/*
** EPITECH PROJECT, 2022
** Linked lists functions
** File description:
** First file
*/

#include "../my.h"

void linked_reverse(linked_node **list)
{
    linked_node *node = *list;
    linked_node *new_linked = linked_new();
    int count = linked_count(node);

    for (int i = count - 1; i >= 0; i--) {
        linked_add(new_linked, linked_get(node, i)->data);
    }

    (*list) = new_linked;
}

void linked_fuse(linked_node *list1, linked_node *list2)
{
    while (list1->next != NULL && list1->data != NULL) {
        list1 = list1->next;
    }

    list1->next = list2;
}
