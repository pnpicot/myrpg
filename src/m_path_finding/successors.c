/*
** EPITECH PROJECT, 2023
** m_path_finding
** File description:
** successors
*/

#include "path_finding.h"
#include <stdlib.h>

static int verify_successor(char **map, sfVector2i *map_size, pq_t *pq,
sfVector2i *node_co)
{
    if (node_co->x < 0 || node_co->x >= map_size->x || node_co->y < 0 ||
    node_co->y >= map_size->y)
        return (1);
    if ((map[node_co->y][node_co->x] != MY_PATH &&
    map[node_co->y][node_co->x] != MY_CHAR) ||
    (pq->node->parent != ((void *)0) && node_co->x == pq->node->parent->co.x &&
    node_co->y == pq->node->parent->co.y))
        return (1);
    return (0);
}

static int verify_if_already_exist(pq_t *pq, char **map, sfVector2i *map_size,
pqnode_t *node)
{
    pqnode_t *tmp = ((void *)0);
    pqnode_t *tmp2 = ((void *)0);

    if (map[node->co.y][node->co.x] == MY_PATH)
        return (1);
    if (tmp = get_node_coords(&pq->open, &node->co), tmp != ((void *)0) &&
    node->f >= tmp->f)
        return (0);
    if (tmp == ((void *)0) && (tmp2 = get_node_coords(&pq->closed, &node->co),
    tmp2 != ((void *)0) && node->f >= tmp2->f))
        return (0);
    free(pop_node(&pq->open, tmp, map, map_size));
    free(pop_node(&pq->closed, tmp2, map, map_size));
    return (1);
}

static int push_if_successor(char **map, sfVector2i *map_size, pq_t *pq,
sfIntRect *off)
{
    pqnode_t *node = ((void *)0);
    sfVector2i node_co = {pq->node->co.x + off->left, pq->node->co.y +
    off->top};

    if (verify_successor(map, map_size, pq, &node_co) == 1)
        return (0);
    if (node = create_node(&node_co, pq->node, map_size), node == ((void *)0))
        return (-1);
    if (node_co.x == off->width && node_co.y == off->height)
        return (push_node(&pq->open, node, map, map_size) < 0 ? -1 : 1);
    if (verify_if_already_exist(pq, map, map_size, node) == 1)
        return (push_node(&pq->open, node, map, map_size));
    free(node);
    return (0);
}

int generate_successors(char **map, sfVector2i *map_size, pq_t *pq,
sfVector2i *end)
{
    int rval = 0;
    sfIntRect succ_co = {-1, -1, end->x, end->y};

    for (; 11; succ_co.left++) {
        if (succ_co.left == 0 && succ_co.top == 0)
            continue;
        if (rval = push_if_successor(map, map_size, pq, &succ_co), rval < 0)
            return (-1);
        if (rval == 1)
            return (1);
        if (succ_co.left >= 1 && succ_co.top >= 1)
            break;
        if (succ_co.left >= 1) {
            succ_co.left = -2;
            succ_co.top++;
        }
    }
    return (0);
}
