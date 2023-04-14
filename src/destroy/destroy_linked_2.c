/*
** EPITECH PROJECT, 2023
** destroy
** File description:
** destroy_linked_2
*/

#include "main.h"

void linked_destroy_config_floats(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(((s_float *)save->data)->id);
        free(save->data);
        free(save);
    }
}

void linked_destroy_config_ints(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(((s_int *)save->data)->id);
        free(save->data);
        free(save);
    }
}

void linked_destroy_config_strings(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(((s_str *)save->data)->id);
        #warning "Need to copy value instead of using pointer"
        free(((s_str *)save->data)->value);
        ((s_str *)save->data)->value = NULL;
        free(save->data);
        free(save);
    }
}

void linked_destroy_containers(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        linked_node *node2 = ((s_container *)save->data)->nodes;
        while (node2 != NULL) {
            linked_node *save2 = node2;
            node2 = node2->next;
            free(save2->data);
            free(save2);
        }
        free(save->data);
        free(save);
    }
}

void linked_destroy_emiters(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        sfClock_destroy(((s_particle_src *)save->data)->delta_clock);
        linked_node *node2 = ((s_particle_src *)save->data)->particle_pool;
        while (node2 != NULL) {
            linked_node *save2 = node2;
            node2 = node2->next;
            sfSprite_destroy(((s_particle *)save2->data)->model);
            free(save2->data);
            free(save2);
        }
        sfSprite_destroy(((s_particle_src *)save->data)->particle_model);
        free(((s_particle_src *)save->data)->id);
        free(save->data);
        free(save);
    }
}
