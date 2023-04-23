/*
** EPITECH PROJECT, 2022
** convert
** File description:
** convert
*/

#include "../my.h"
#include <stdlib.h>

void find_all(char *res, long long nb, int a)
{
    if (nb <= 9) {
        res[a] = '0' + nb;
    } else if (nb > 9) {
        find_all(res, nb / 10, a - 1);
        res[a] = '0' + (nb % 10);
    }
}

char *nbr_to_str(long long nb)
{
    if (!nb) {
        char *res_int = malloc(2);
        res_int[0] = '0';
        res_int[1] = '\0';
        return res_int;
    } long abs = nb < 0 ? -nb : nb;
    char *res_int = malloc(sizeof(char) * (get_nbr_len(abs) + 1));
    res_int[get_nbr_len(abs)] = '\0';
    char *res_final = malloc(sizeof(char) * (get_nbr_len(abs) + 2));
    res_final[get_nbr_len(abs) + 1] = '\0';
    int i = get_nbr_len(abs) - 1;
    find_all(res_int, abs, i);
    if (nb < 0) {
        res_final[0] = '-';
        for (int j = 1; j < get_nbr_len(abs) + 1; j++)
            res_final[j] = res_int[j - 1];
        free(res_int);
        return (res_final);
    } free(res_final);
    return (res_int);
}
