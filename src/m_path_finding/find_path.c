/*
** EPITECH PROJECT, 2023
** m_path_finding
** File description:
** find_path
*/

#include "path_finding.h"
#include <stdlib.h>

static linked_node *create_ll(pq_t *pq, char **map)
{
    pqnode_t *node = pq->open;
    linked_node *path = linked_new();
    if (node == ((void *)0))
        return (NULL);
    while (node->parent != ((void *)0)) {
        map[node->co.y][node->co.x] = 'o';
        sfIntRect *co = malloc(sizeof(sfIntRect));
        if (co == NULL) return (NULL);
        co->left = node->co.x - node->parent->co.x;
        co->top = node->co.y - node->parent->co.y;
        co->width = node->co.x;
        co->height = node->co.y;
        linked_node *new = linked_new();
        new->data = co;
        new->next = path;
        path = new;
        node = node->parent;
    }
    map[node->co.y][node->co.x] = 'o';
    return (path);
}

static linked_node *print_path_and_free(pq_t *pq, char **map,
sfVector2i *map_size)
{
    linked_node *path = create_ll(pq, map);

    if (path == NULL)
        return (NULL);
    while (pq->open != ((void *)0))
        free(pop_node(&pq->open, pq->open, map, map_size));
    while (pq->closed != ((void *)0))
        free(pop_node(&pq->closed, pq->closed, map, map_size));
    /* for (int i = 0; i < map_size->y; ++i) {
        if (write(1, map[i], map_size->x) < 0)
            return (NULL);
        if (write(1, "\n", 1) < 0)
            return (NULL);
    } */
    return (path);
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

linked_node *find_path(char **map, sfVector2i *map_size, sfVector2i *start,
sfVector2i *end)
{
    pq_t pq = {((void *)0), ((void *)0), ((void *)0)};
    int rvalue = 0;

    if (push_node(&pq.open, create_node(start, ((void *)0), map_size, 1), map,
    map_size) < 0)
        return (NULL);
    while (pq.open != ((void *)0)) {
        if (rvalue = solve_maze_loop(map, map_size, &pq, end), rvalue < 0)
            return (NULL);
        if (rvalue == 1)
            return (print_path_and_free(&pq, map, map_size));
    }
    write(2, "Path Finding: No path found\n", 28);
    while (pq.open != ((void *)0))
        free(pop_node(&pq.open, pq.open, map, map_size));
    while (pq.closed != ((void *)0))
        free(pop_node(&pq.closed, pq.closed, map, map_size));
    return (NULL);
}