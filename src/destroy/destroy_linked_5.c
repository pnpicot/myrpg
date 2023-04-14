/*
** EPITECH PROJECT, 2023
** destroy
** File description:
** destroy_linked_5
*/

#include "main.h"

void linked_destroy_shaders(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(save);
    }
}

void linked_destroy_sliders(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(((s_slider *)save->data)->id);
        free(save->data);
        free(save);
    }
}

void linked_destroy_sound_queue(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(save->data);
        free(save);
    }
}

void linked_destroy_sounds(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(((s_sound *)save->data)->id);
        free(save->data);
        free(save);
    }
}

void linked_destroy_sprites(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        sfSprite_destroy(((s_sprite *)save->data)->elem);
        free(((s_sprite *)save->data)->id);
        free(save->data);
        free(save);
    }
}
