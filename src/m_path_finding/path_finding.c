/*
** EPITECH PROJECT, 2023
** m_path_finding
** File description:
** path_finding
*/

#include "path_finding.h"
#include <stdlib.h>

static int verify_map(char **map, sfVector2i *map_size, sfVector2i *start,
sfVector2i *end)
{;
    if (map == NULL || map_size == NULL || start == NULL || end == NULL)
        return (-1);
    if (start->x < 0 || start->y < 0 || end->x < 0 || end->y < 0 ||
    start->x >= map_size->x || start->y >= map_size->y || end->x >= map_size->x
    || end->y >= map_size->y)
        return (-1);
    return (0);
}

static char **malloc_new_map(char **map, sfVector2i *map_size)
{
    char **new_map = malloc(sizeof(char *) * (map_size->y + 1));

    if (new_map == NULL)
        return (NULL);
    for (int i = 0; i < map_size->y; i++) {
        new_map[i] = malloc(sizeof(char) * (map_size->x + 1));
        if (new_map[i] == NULL)
            return (NULL);
        for (int j = 0; j < map_size->x; j++)
            new_map[i][j] = map[i][j];
        new_map[i][map_size->x] = '\0';
    }
    new_map[map_size->y] = NULL;
    return (new_map);
}

static void expand_wall_to_hitbox(char **map, sfVector2i *map_size, int xy)
{
    for (int i = 0; i < map_size->y; i++) {
        for (int j = 0; j < map_size->x; j++) {
            map[i][j] = (((xy == 0 || xy == 2) && (j + 1 >= map_size->x ||
            map[i][j + 1] == MY_WALL)) || ((xy == 1 || xy == 2) &&
            (i + 1 >= map_size->y || map[i + 1][j] == MY_WALL)) || ((xy == 2) &&
            (j + 1 >= map_size->x || i + 1 >= map_size->y ||
            map[i + 1][j + 1] == MY_WALL))) ? MY_WALL : map[i][j];
        }
    }
    for (int i = map_size->y - 1; i >= 0; --i) {
        for (int j = map_size->x - 1; j >= 0; --j) {
            map[i][j] = (((xy == 0 || xy == 2) && (j - 1 < 0 ||
            map[i][j - 1] == MY_WALL)) || ((xy == 1 || xy == 2) &&
            (i - 1 < 0 || map[i - 1][j] == MY_WALL)) || ((xy == 2) &&
            (j - 1 < 0 || i - 1 < 0 ||
            map[i - 1][j - 1] == MY_WALL))) ? MY_WALL : map[i][j];
        }
    }
}

static char **change_wall_and_path(char **map, sfVector2i *map_size,
sfIntRect hitbox)
{
    char **new_map = malloc_new_map(map, map_size);
    if (new_map == NULL)
        return (NULL);
    for (int i = 0; i < map_size->y; i++) {
        for (int j = 0; j < map_size->x; j++) {
            new_map[i][j] = (IS_PATH(new_map[i][j])) ? MY_PATH : new_map[i][j];
            new_map[i][j] = (IS_WALL(new_map[i][j])) ? MY_WALL : new_map[i][j];
        }
    }
    hitbox.width /= 2;
    hitbox.height /= 2;
    for (int i = 0; i <
    ((hitbox.width <= hitbox.height) ? hitbox.width : hitbox.height); i++)
        expand_wall_to_hitbox(new_map, map_size, 2);
    for (int i = 0; i <
    ((hitbox.width <= hitbox.height) ? hitbox.height - hitbox.width :
    hitbox.width - hitbox.height); i++)
        expand_wall_to_hitbox(new_map, map_size, ((hitbox.width <=
        hitbox.height) ? 1 : 0));
    return (new_map);
}

linked_node *path_finding(char **map, sfVector2i *map_size, sfIntRect hitbox,
sfVector2i end)
{
    linked_node *rvalue = NULL;

    if (verify_map(map, map_size, &(sfVector2i){hitbox.left, hitbox.top},
    &end) < 0)
        return (NULL);
    map = change_wall_and_path(map, map_size, hitbox);
    if (map == NULL || map[hitbox.top][hitbox.left] == MY_WALL ||
    map[end.y][end.x] == MY_WALL) {
        write(2, "Error: path_finding: invalid start or end\n", 42);
        return (NULL);
    }
    rvalue = find_path(map, map_size, &(sfVector2i){hitbox.left, hitbox.top},
    &end);
    for (int i = 0; i < map_size->y; i++)
        free(map[i]);
    free(map);
    return (rvalue);
}
