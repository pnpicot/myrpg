/*
** EPITECH PROJECT, 2023
** destroy
** File description:
** destroy_linked_7
*/

#include "main.h"

void linked_destroy_vertexes(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        sfVertexArray_destroy(((s_vertex *)save->data)->elem);
        free(((s_vertex *)save->data)->id);
        free(save->data);
        free(save);
    }
}

void linked_destroy_walls(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(((s_wall *)save->data)->id);
        free(save->data);
        free(save);
    }
}

void linked_destroy_textures(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        sfTexture_destroy(((s_texture *)save->data)->texture);
        free(((s_texture *)save->data)->id);
        free(save->data);
        free(save);
    }
}

void linked_destroy_entity_models(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        linked_node *node2 = ((s_entity *)save->data)->parts;
        while (node2 != NULL) {
            linked_node *save2 = node2;
            node2 = node2->next;
            free(((s_entity_part *)save2->data)->id);
            free(save2->data);
            free(save2);
        }
        sfClock_destroy(((s_entity *)save->data)->clock);
        free(((s_entity *)save->data)->id);
        free(save->data);
        free(save);
    }
}

void linked_destroy_entities(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        linked_node *node2 = (((s_entity *)save->data) != NULL) ?
        ((s_entity *)save->data)->parts : NULL;
        while (node2 != NULL) {
            linked_node *save2 = node2;
            node2 = node2->next;
            free(save2->data);
            free(save2);
        }
        if (((s_entity *)save->data) != NULL) {
            sfClock_destroy(((s_entity *)save->data)->clock);
            free_ll_and_data(&((s_entity *)save->data)->path);
            free(save->data);
        }
        free(save);
    }
}
