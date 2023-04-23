/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Map module
*/

#include "main.h"

void load_map(s_appdata *adata, char *map)
{
    char **entries = str_split(map, '\n');
    int max_x = 0;
    int max_y = 0;
    for (int ite = 0; entries[ite] != NULL; ++ite) {
        char **entry_data = str_split(entries[ite], ' ');
        if (count_nil_str(entry_data) < 5) continue;
        int x = my_getnbr(entry_data[1]);
        int y = my_getnbr(entry_data[2]);
        int width = my_getnbr(entry_data[3]);
        int height = my_getnbr(entry_data[4]);
        if (x + width > max_x) max_x = x + width;
        if (y + height > max_y) max_y = y + height;
        add_tile_to_map(adata, entry_data[0][0], (sfVector2f) { x, y },
        (sfVector2f) { width, height });
        for (int i = 0; entry_data[i] != NULL; i++) free(entry_data[i]);
        free(entry_data);
    }
    init_map_path_finding(adata, entries, max_x, max_y);
    for (int i = 0; entries[i] != NULL; i++) free(entries[i]);
    free(entries);
}

void init_map(s_appdata *adata, char *filename)
{
    load_tiles(adata);

    char *path = str_add("bonus/maps/", filename);
    char *map = file_extract(path);
    free(path);

    if (map == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "no_file"));
        return;
    }

    load_map(adata, map);
    free(map);
}
