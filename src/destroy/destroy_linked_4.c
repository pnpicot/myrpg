/*
** EPITECH PROJECT, 2023
** destroy
** File description:
** destroy_linked_4
*/

#include "main.h"

void linked_destroy_lights(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(save);
    }
}

void linked_destroy_musics(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(save->data);
        free(save);
    }
}

void linked_destroy_objects(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(((s_object *)save->data)->ref);
        free(((s_object *)save->data)->id);
        free(save->data);
        free(save);
    }
}

void linked_destroy_rects(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        sfRectangleShape_destroy(((s_rect *)save->data)->elem);
        free(((s_rect *)save->data)->id);
        free(save->data);
        free(save);
    }
}

void linked_destroy_rtexs(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        sfSprite_destroy(((s_rtex *)save->data)->sprite);
        sfRenderTexture_destroy(((s_rtex *)save->data)->texture);
        free(((s_rtex *)save->data)->state);
        free(((s_rtex *)save->data)->id);
        free(save->data);
        free(save);
    }
}
