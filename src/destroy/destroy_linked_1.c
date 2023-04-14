/*
** EPITECH PROJECT, 2023
** destroy
** File description:
** destroy_linked_1
*/

#include "main.h"

void linked_destroy_animations(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        sfClock_destroy(((s_animation *)save->data)->anim_clock);
        free(save->data);
        free(save);
    }
}

void linked_destroy_bars(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(((s_bar *)save->data)->id);
        free(save->data);
        free(save);
    }
}

void linked_destroy_buttons(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(((s_button *)save->data)->elem);
        free(((s_button *)save->data)->id);
        free(save->data);
        free(save);
    }
}

void linked_destroy_circles(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        sfCircleShape_destroy(((s_circle *)save->data)->elem);
        free(((s_circle *)save->data)->id);
        free(save->data);
        free(save);
    }
}

void linked_destroy_config_colors(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(((s_color *)save->data)->id);
        free(save->data);
        free(save);
    }
}
