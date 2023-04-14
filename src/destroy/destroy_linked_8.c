/*
** EPITECH PROJECT, 2023
** destroy
** File description:
** destroy_linked_8
*/

#include "main.h"

void linked_destroy_factions(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(((s_faction *)save->data)->id);
        free(save->data);
        free(save);
    }
}
