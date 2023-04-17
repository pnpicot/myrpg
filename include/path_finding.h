/*
** EPITECH PROJECT, 2023
** B-CPE-200-NCY-2-1-dante-gaetan.kling
** File description:
** solver
*/

#include <unistd.h>

#include "SFML/Graphics.h"
#include "main.h"

#ifndef _PATH_FINDING_H_
    #define _PATH_FINDING_H_
    #define MY_CHAR ('A')
    #define MY_PATH ('*')
    #define MY_WALL ('X')
    #define IS_WALL(c) ((c) == 'X')
    #define IS_PATH(c) ((c) == '*')

    typedef struct Priority_Queue_Node {
        sfVector2i co;
        size_t g;
        size_t f;
        struct Priority_Queue_Node *prev;
        struct Priority_Queue_Node *next;
        struct Priority_Queue_Node *parent;
    } pqnode_t;

    typedef struct Least_f_Node {
        pqnode_t *node;
        struct Least_f_Node *next;
    } lfn_t;

    typedef struct Queues {
        pqnode_t *open;
        pqnode_t *closed;
        pqnode_t *node;
    } pq_t;

    linked_node *path_finding(char **map, sfVector2i *map_size, sfIntRect hitbox,
    sfVector2i end);
    linked_node *find_path(char **map, sfVector2i *map_size, sfVector2i *start,
    sfVector2i *end);
    int generate_successors(char **map, sfVector2i *map_size, pq_t *pq,
    sfVector2i *end);

    pqnode_t *create_node(sfVector2i *coords, pqnode_t *parent,
    sfVector2i *map_size, int g_offset);
    pqnode_t *pop_node(pqnode_t **queue, pqnode_t *node, char **map,
    sfVector2i *map_size);
    int push_node(pqnode_t **queue, pqnode_t *node, char **map,
    sfVector2i *map_size);
    pqnode_t *get_node_coords(pqnode_t **queue, sfVector2i *coords);
#endif
