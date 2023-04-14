/*
** EPITECH PROJECT, 2023
** destroy
** File description:
** destroy_linked_6
*/

#include "main.h"

void linked_destroy_states(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        linked_node *node2 = ((s_state *)save->data)->rtexs;
        while (node2 != NULL) {
            linked_node *save2 = node2;
            node2 = node2->next;
            free(save2);
        }
        free(save->data);
        free(save);
    }
}

void linked_destroy_switches(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(save);
    }
}

void linked_destroy_texts(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        sfText_destroy(((s_text *)save->data)->elem);
        free(((s_text *)save->data)->id);
        free(save->data);
        free(save);
    }
}

void linked_destroy_tiles(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(save->data);
        free(save);
    }
}

void linked_destroy_transforms(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(save);
    }
}
