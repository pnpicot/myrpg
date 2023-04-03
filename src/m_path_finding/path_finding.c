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
{
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

static char **change_wall_and_path(char **map, sfVector2i *map_size)
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
    return (new_map);
}

sfVector2f path_finding(char **map, sfVector2i *map_size, sfVector2i start,
sfVector2i end)
{
    int fd = 0;
    sfVector2f rvalue = {0, 0};

    if (verify_map(map, map_size, &start, &end) < 0)
        return ((sfVector2f){0, 0});
    map = change_wall_and_path(map, map_size);
    if (map == NULL || map[start.y][start.x] == MY_WALL ||
    map[end.y][end.x] == MY_WALL)
        return ((sfVector2f){0, 0});
    rvalue = find_path(map, map_size, &start, &end);
    for (int i = 0; i < map_size->y; i++)
        free(map[i]);
    free(map);
    return (rvalue);
}
