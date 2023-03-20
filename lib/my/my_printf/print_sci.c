/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Print double in scientific notation
*/

#include "../my.h"

int insert(char *tab, char *value, int start, int nb)
{
    int a = 0;
    for (int i = start; i < start + nb; i++) {
        tab[i] = value[a];
        a++;
    }
    return (start + nb);
}

char *sci_2(char *res, int mode, int pre)
{
    int index = 0;
    index = insert(res, "0", index, 1);
    index = insert(res, ".", index, 1);
    char *temp = put_0(pre);
    index = insert(res, temp, index, pre);
    char *char_mode = malloc(sizeof(char) * 3);
    char_mode = mode ? "E+" : "e+";
    index = insert(res, char_mode, index, 2);
    index = insert(res, "0", index, 1);
    return (res);
}

char *mallocage(double value, int mode, int pre)
{
    char *res = malloc(sizeof(char) * (pre + 7));
    res[pre + 6] = '\0';
    return (res);
}

char *print_sci(double value, int mode, int pre)
{
    if (pre == 0) pre = 6;
    char *res = mallocage(value, mode, pre);
    int minus = get_nbr_len((int) value) - 1 == 0 ? 0 : 1;
    if (value > 0) {
        int exp = get_nbr_len((int) value) - minus;
        value /= my_pow(10, get_nbr_len((int) value) - 1);
        double dec = value - (int) value;
        int index = 0;
        index = insert(res, nbr_to_str((int) value), index, exp);
        index = insert(res, ".", index, 1);
        int temp = (int) (dec * put_multiply_10(pre));
        index = insert(res, nbr_to_str(temp), index, pre);
        char *char_mode = malloc(sizeof(char) * 3);
        char_mode = mode ? "E+" : "e+";
        index = insert(res, char_mode, index, 2);
        if ((int) value < 10) index = insert(res, "0", index, 1);
        index = insert(res, nbr_to_str(exp), index, get_nbr_len(exp));
    }
    if ((int) value == 0) res = sci_2(res, mode, pre);
    return (res);
}
