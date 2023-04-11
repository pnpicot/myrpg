/*
** EPITECH PROJECT, 2023
** m_path_finding
** File description:
** find_path
*/

#include "path_finding.h"
#include <stdlib.h>

static sfVector2f print_path_and_free(pq_t *pq, char **map,
sfVector2i *map_size)
{
    pqnode_t *node = pq->open;

    if (node == ((void *)0))
        return ((sfVector2f){0, 0});
    while (node->parent != ((void *)0)) {
        map[node->co.y][node->co.x] = 'o';
        node = node->parent;
    }
    map[node->co.y][node->co.x] = 'o';
    while (pq->open != ((void *)0))
        free(pop_node(&pq->open, pq->open, map, map_size));
    while (pq->closed != ((void *)0))
        free(pop_node(&pq->closed, pq->closed, map, map_size));
    for (int i = 0; i < map_size->y; ++i) {
        if (write(1, map[i], map_size->x) < 0)
            return ((sfVector2f){0, 0});
        if (write(1, "\n", 1) < 0)
            return ((sfVector2f){0, 0});
    }
    return ((sfVector2f){0, 0});
}

static pqnode_t *least_f(pq_t *pq)
{
    pqnode_t *node = pq->open;
    pqnode_t *least_f = pq->open;
    size_t nb = 0;
    static size_t last_least_f = 0;

    while (node != ((void *)0)) {
        if (node->f < least_f->f)
            least_f = node;
        ++nb;
        if (nb >= 8 && least_f->f <= last_least_f)
            break;
        node = node->next;
    }
    last_least_f = least_f->f;
    return (least_f);
}

static int solve_maze_loop(char **map, sfVector2i *map_size, pq_t *pq,
sfVector2i *end)
{
    int rvalue = 0;

    if (pq->node = pop_node(&pq->open, least_f(pq), map, map_size),
    pq->node == ((void *)0))
        return (-1);
    if (rvalue = generate_successors(map, map_size, pq, end), rvalue < 0)
        return (-1);
    if (push_node(&pq->closed, pq->node, map, map_size) < 0)
        return (-1);
    return (rvalue);
}

sfVector2f find_path(char **map, sfVector2i *map_size, sfVector2i *start,
sfVector2i *end)
{
    pq_t pq = {((void *)0), ((void *)0), ((void *)0)};
    int rvalue = 0;

    if (push_node(&pq.open, create_node(start, ((void *)0), map_size), map,
    map_size) < 0)
        return ((sfVector2f){0, 0});
    while (pq.open != ((void *)0)) {
        if (rvalue = solve_maze_loop(map, map_size, &pq, end), rvalue < 0)
            return ((sfVector2f){0, 0});
        if (rvalue == 1)
            return (print_path_and_free(&pq, map, map_size));
    }
    while (pq.open != ((void *)0))
        free(pop_node(&pq.open, pq.open, map, map_size));
    while (pq.closed != ((void *)0))
        free(pop_node(&pq.closed, pq.closed, map, map_size));
    return ((sfVector2f){0, 0});
}