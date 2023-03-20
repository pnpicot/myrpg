/*
** EPITECH PROJECT, 2022
** Display functions
** File description:
** List display
*/

#include "../my.h"

void str_ld_cmp(s_str_ld args, char ***s_cols, int x, int **widths)
{
    int v_max = my_strlen(s_cols[0][x]);
    int rows = args.rows;
    int cols = args.cols;
    int arr_size = args.arr_size;

    for (int y = 1; y < rows; y++) {
        if ((y * cols) + x >= arr_size) continue;
        if (my_strlen(s_cols[y][x]) > v_max)
            v_max = my_strlen(s_cols[y][x]);
    }

    (*widths)[x] = v_max;
}

int *str_ld_getwidths(int cols, char ***s_cols, int rows, int arr_size)
{
    int *widths = malloc(sizeof(int) * cols);

    for (int i = 0; i < cols; i++) {
        widths[i] = 0;
    }

    for (int x = 0; x < cols; x++) {
        s_str_ld args = { rows, cols, arr_size, NULL };

        str_ld_cmp(args, s_cols, x, &widths);
    }

    return (widths);
}

char ***str_ld_getcols(int rows, int cols, char **arr)
{
    char ***s_cols = malloc(sizeof(char **) * rows);
    int ite = 0;

    for (int i = 0; i < rows; i++) {
        s_cols[i] = malloc(sizeof(char *) * cols);
    }

    while (arr[ite] != NULL) {
        int row = ite / cols;
        int col = ite % cols;
        s_cols[row][col] = arr[ite];
        ite++;
    }

    return (s_cols);
}

void str_ld_xdisp(s_str_ld args, int side, char ***s_cols, int y)
{
    int cols = args.cols;
    int arr_size = args.arr_size;
    int pad = args.rows;
    int *widths = args.widths;

    for (int x = 0; x < cols; x++) {
        if ((y * cols) + x >= arr_size) continue;
        char *opt = str_add("%", side ? "" : "-");
        char *format = str_m_add(3, opt, nbr_to_str(widths[x] + pad), "s");
        my_printf(format, s_cols[y][x]);
    }
    my_printf("\n");
}

void str_list_display(char **arr, int cols, int pad, int side)
{
    int arr_size = count_nil_str(arr);
    int rows = (arr_size / cols) + 1;
    char ***s_cols = str_ld_getcols(rows, cols, arr);
    int *widths = str_ld_getwidths(cols, s_cols, rows, arr_size);
    for (int y = 0; y < rows; y++) {
        s_str_ld args = { pad, cols, arr_size, widths };

        str_ld_xdisp(args, side, s_cols, y);
    }
}
