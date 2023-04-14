/*
** EPITECH PROJECT, 2023
** destroy
** File description:
** destroy_linked_3
*/

#include "main.h"

void linked_destroy_errors(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(((s_str *)save->data)->value);
        free(((s_str *)save->data)->id);
        free(save->data);
        free(save);
    }
}

void linked_destroy_fonts(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        sfFont_destroy(((s_font *)save->data)->font);
        free(((s_font *)save->data)->id);
        free(save->data);
        free(save);
    }
}

void linked_destroy_gameobjects(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(((s_gameobj *)save->data)->id);
        free(save->data);
        free(save);
    }
}

void linked_destroy_inputs(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(save);
    }
}

void linked_destroy_keymaps(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(save->data);
        free(save);
    }
}
