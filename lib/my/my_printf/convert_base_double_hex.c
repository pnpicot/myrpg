/*
** EPITECH PROJECT, 2022
** convert
** File description:
** convert
*/

#include "../my.h"
#include <stdlib.h>

int insert2(char *tab, char *value, int start, int nb)
{
    int a = 0;
    for (int i = start; i < start + nb; i++) {
        tab[i] = value[a];
        a++;
    }
    return (start + nb);
}

char *part_dec(double nb, int mode, int pre)
{
    int a = 0;
    char *dec = malloc(sizeof(char) * pre + 1);
    dec[pre] = '\0';
    int div = nb / pow_2_nb(nb);
    double mult = (nb / pow_2_nb(nb)) - div;
    mult = nb < 2.0 ? nb - (int) nb : mult;
    for (int i = 0; i < pre; i++) {
        int mult_int = 16.0 * mult;
        if (mult_int <= 9 && a == 0)
            dec[i] = '0' + mult_int;
        if (mult_int >= 10 && a == 0)
            dec[i] = mult_int + (mode ? 55 : 87);
        mult = (16.0 * mult) - (double) mult_int;
    }
    return (dec);
}

int rep(char *dec, double nb, int pre)
{
    int i = 0;
    int int_nb = nb;
    if (nb - (double) int_nb != 0.0) return (pre);
    else {
        while (dec[i] != '0') {
            i++;
        }
    }
    return (i);
}

char *convert_base_double_hex_part_2(double nb, int mode, char *res, int index)
{
    int int_nb = nb;
    index = insert2(res, mode ? "P" : "p", index, 1);
    index = insert2(res, nb >= 0.0 ? "+" : "-", index, 1);
    int len_pow_2 = get_nbr_len(pow_2(nb));
    char *char_pow_2 = int_nb == 1 ? "0" : nbr_to_str(pow_2(nb));
    index = insert2(res, char_pow_2, index, int_nb > 1 ? len_pow_2 : 1);
    return (res);
}

char *cv_d_hex(double nb, int mode, int pre)
{
    pre = pre != 0 ? pre : 13;
    int anx = nb != 0 ? 7 : 5;
    char *res = malloc(sizeof(char) * (pre + anx + 1));
    res[pre + anx] = '\0';
    int index = 0;
    if (nb < 0.0) index = insert2(res, "-", index, 1);
    nb = nb < 0.0 ? -nb : nb;
    int int_nb = nb;
    index = insert2(res, mode ? "0X" : "0x", index, 2);
    if (nb != 0.0) index = insert2(res, "1", index, 1);
    if (nb == 0) index = insert2(res, "0", index, 1);
    if (int_nb != pow_2_nb(nb) || nb - int_nb > 0.0) {
        index = insert2(res, ".", index, 1);
        int temp = rep(part_dec(nb, mode, pre), nb, pre);
        char *temp2 = part_dec(nb, mode, pre);
        index = insert2(res, temp2, index, pre);
    }
    return (convert_base_double_hex_part_2(nb, mode, res, index));
}
