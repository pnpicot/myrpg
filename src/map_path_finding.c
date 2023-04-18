/*
** EPITECH PROJECT, 2023
** src
** File description:
** map_path_finding
*/

#include "main.h"

// static void fill_with_type(s_appdata *adata, s_entity ***map, char **entry_data)
// {
//     char type = entry_data[0][0];
//     int x = my_getnbr(entry_data[1]) * 32;
//     int y = my_getnbr(entry_data[2]) * 32;
//     int width = my_getnbr(entry_data[3]) * 32;
//     int height = my_getnbr(entry_data[4]) * 32;

//     for (int i = x; i < x + width; i++) {
//         for (int j = y; j < y + height; j++) {
//             map[j][i] = get_tile(adata, type)->wall ? (s_entity *)1 : NULL;
//         }
//     }
// }

// // ! Collision map, not sure to keep
// static void init_col_map(s_appdata *adata, char **entries)
// {
//     adata->game_data->col_map = malloc(sizeof(s_entity **) *
//     (adata->game_data->col_map_size.y + 1));
//     for (int i = 0; i < adata->game_data->col_map_size.y; i++) {
//         adata->game_data->col_map[i] = malloc(sizeof(s_entity *) *
//         (adata->game_data->col_map_size.x + 1));
//         for (int j = 0; j < adata->game_data->col_map_size.x; j++) {
//             adata->game_data->col_map[i][j] = NULL;
//         }
//         adata->game_data->col_map[i][adata->game_data->col_map_size.x] = NULL;
//     }
//     adata->game_data->col_map[adata->game_data->col_map_size.y] = NULL;

//     for (int ite = 0; entries[ite] != NULL; ++ite) {
//         char **entry_data = str_split(entries[ite], ' ');
//         if (count_nil_str(entry_data) < 5)
//             continue;
//         fill_with_type(adata, adata->game_data->col_map ,entry_data);
//         for (int i = 0; entry_data[i] != NULL; i++)
//             free(entry_data[i]);
//         free(entry_data);
//     }
// }

static void fill_map_path_finding(s_appdata *adata, char **lignes)
{
    int i = 0;

    while (lignes[i] != NULL) {
        char **ligne = str_split(lignes[i], ' ');
        char c = get_tile(adata, ligne[0][0])->wall ? 'X' : '*';
        int origin_y = my_getnbr(ligne[2]);
        int origin_x = my_getnbr(ligne[1]);
        int len_tile_x = my_getnbr(ligne[3]);
        int len_tile_y = my_getnbr(ligne[4]);

        int y = my_getnbr(ligne[2]);
        for (y; y < len_tile_y + origin_y; y++) {
            int x = my_getnbr(ligne[1]);
            for (x; x < len_tile_x + origin_x; x++) {
                adata->game_data->map[y][x] = c;
            }
        }
        i++;
    }
}

void init_map_path_finding(s_appdata *adata, char **entries, int size_x,
int size_y)
{
    adata->game_data->map_width = size_x;
    adata->game_data->map_height = size_y;
    adata->game_data->col_map_size = (sfVector2i){size_x * 32, size_y * 32};

    adata->game_data->map = malloc(sizeof(char *) * (size_y + 1));
    for (int i = 0; i < size_y; i++) {
        adata->game_data->map[i] = malloc(sizeof(char) * (size_x + 1));
        for (int j = 0; j < size_x; j++)
            adata->game_data->map[i][j] = '*';
        adata->game_data->map[i][size_x] = '\0';
    }
    adata->game_data->map[size_y] = NULL;

    fill_map_path_finding(adata, entries);
    // init_col_map(adata, entries);
}
