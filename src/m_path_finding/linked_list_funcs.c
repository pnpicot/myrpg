/*
** EPITECH PROJECT, 2023
** m_path_finding
** File description:
** linked_list_funcs
*/

#include "path_finding.h"
#include <stdlib.h>

pqnode_t *pop_node(pqnode_t **queue, pqnode_t *node, char **map,
sfVector2i *map_size)
{
    if (node == ((void *)0))
        return (((void *)0));
    if (node->prev != ((void *)0))
        node->prev->next = node->next;
    else
        *queue = node->next;
    if (node->next != ((void *)0))
        node->next->prev = node->prev;
    if (node->co.x >= 0 && node->co.x < map_size->x && node->co.y >= 0 &&
    node->co.y < map_size->y && map[node->co.y][node->co.x] == MY_CHAR)
        map[node->co.y][node->co.x] = MY_PATH;
    return (node);
}

pqnode_t *get_node_coords(pqnode_t **queue, sfVector2i *coords)
{
    pqnode_t *node = *queue;

    while (node != ((void *)0)) {
        if (node->co.x == coords->x && node->co.y == coords->y)
            return (node);
        node = node->next;
    }
    return (((void *)0));
}

int push_node(pqnode_t **queue, pqnode_t *node, char **map,
sfVector2i *map_size)
{
    if (node == ((void *)0))
        return (-1);
    node->next = *queue;
    node->prev = ((void *)0);
    if (*queue != ((void *)0))
        (*queue)->prev = node;
    *queue = node;
    if (node->co.x >= 0 && node->co.x < map_size->x && node->co.y >= 0 &&
    node->co.y < map_size->y && map[node->co.y][node->co.x] == MY_PATH)
        map[node->co.y][node->co.x] = MY_CHAR;
    return (0);
}

pqnode_t *create_node(sfVector2i *coords, pqnode_t *parent,
sfVector2i *map_size, double g_offset)
{
    pqnode_t *node = malloc(sizeof(pqnode_t));

    if (node == ((void *)0))
        return (((void *)0));
    node->co = *coords;
    node->parent = parent;
    if (parent != ((void *)0))
        node->g = parent->g + g_offset;
    else
        node->g = 0;
    node->f = node->g +
    sqrt((map_size->x - coords->x) + (map_size->y - coords->y));
    node->prev = ((void *)0);
    node->next = ((void *)0);
    return (node);
}
