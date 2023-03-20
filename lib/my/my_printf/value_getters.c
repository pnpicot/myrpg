/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Return the value to print for an element
*/

#include "../my.h"
#include <stdarg.h>

hd in_d_hd(double value, int pre, int round)
{
    hd hd;
    hd.wh = (int) value;
    hd.dec = (value - hd.wh) * my_pow(10, pre >= 0 ? pre : 6);
    hd.wh_tmp = (int) value;
    hd.dc_tmp = (value - hd.wh_tmp) * my_pow(10, pre >= 0 ? pre + 1 : 7);
    hd.wh_len = get_nbr_len(hd.wh);
    hd.dc_l = get_nbr_len(hd.dec);
    hd.w_tmp = nbr_to_str(hd.wh_tmp);
    hd.d_tmp = nbr_to_str(hd.dc_tmp);
    hd.wh_str = nbr_to_str(hd.wh);
    hd.dc_s = nbr_to_str(hd.dec);
    return (hd);
}

char *get_dbl(double vl, int pre, int round, hd hld)
{
    if (round && !pre && hld.w_tmp[my_strlen(hld.w_tmp) - 1] > 52) hld.wh++;
    if (round && pre == 1 && hld.dc_s[0] > 52) hld.wh++;
    if (round && pre > 1 && hld.d_tmp[my_strlen(hld.d_tmp) - 1] > 52) {
        hld.dc_s[hld.dc_l - 1]++;
        if (hld.dc_s[hld.dc_l - 1] > 57)
            return get_dbl(vl, pre - 1, 1, in_d_hd(vl, pre - 1, 1));
    }
    round = 0;
    str_rep(&hld.wh_str, nbr_to_str(hld.wh));
    hld.wh_len = get_nbr_len(hld.wh);
    char *res = malloc(sizeof(char) * hld.wh_len + hld.dc_l + 2);
    get_dbl_next(&res, hld);
    if (!pre) str_rep(&res, hld.wh_str);
    if (!round) return (res);
}

char *get_value_for_int(flag_container *container, flag el)
{
    if (el.spe == 'u') el.ln_data = (unsigned long long int) el.ln_data;
    if (el.spe == 'd' || el.spe == 'i' || el.spe == 'u')
        return (nbr_to_str(el.ln_data));
    if (el.spe == 'o') return convert_base(el.ln_data, 8);
    if (el.spe == 'x') return my_strlowcase(convert_base(el.ln_data, 16));
    if (el.spe == 'X') return convert_base(el.ln_data, 16);
    if (el.spe == 'b') return convert_base(el.ln_data, 2);
}

char *get_value_for_str(flag_container *container, flag element)
{
    if (element.spe == 'S') return put_printable(element.str_data);
    return element.str_data;
}

char *get_value_for_double(flag_container *container, flag el)
{
    if (el.spe == 'e')
        return print_sci(el.dbl_data, 0, el.pre);
    if (el.spe == 'E')
        return print_sci(el.dbl_data, 1, el.pre);
    if (el.spe == 'a' || el.spe == 'A')
        return cv_d_hex(el.dbl_data, el.spe == 'a' ? 0 : 1, el.pre);

    int is_g_flag = el.spe == 'g' || el.spe == 'G';
    hd hld_n = in_d_hd(el.dbl_data, el.pre, 1);

    if (is_g_flag) {
        el.pre = !el.pre ? 6 : el.pre;
        el.pre -= get_nbr_len((int) el.dbl_data);
        el.pre = el.pre < 0 ? 0 : el.pre;
        hd hld = in_d_hd(el.dbl_data, el.pre, 1);
        char *sci = print_sci(el.dbl_data, el.spe == 'g' ? 0 : 1, el.pre);
        char *dbl = get_dbl(el.dbl_data, el.pre, 1, hld);
        return my_strlen(sci) < my_strlen(dbl) ? sci : dbl;
    }
    return get_dbl(el.dbl_data, el.pre, 0, hld_n);
}
