/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Apply flags
*/

#include "../my.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

void apply_flags_int(flag_container *container, flag el)
{
    char *res = get_value_for_int(container, el);
    if (el.rp) str_rep(&res, flag_prefix_int(res, el));
    int spe = el.spe;
    int is_converted = spe == 'o' || spe == 'x' || spe == 'X' || spe == 'b';
    if (!(is_converted && el.rp)) {
        char *pad_zero = filler(gp_str(res, el.pre), 1);
        if (el.rsj && el.ln_data > 0 && !el.rfs && pad_zero[0] != '0')
            str_rep(&res, str_add(" ", res));
        char *z_ped = str_add(pad_zero, res);
        if (el.rfs && el.ln_data > 0) str_rep(&z_ped, str_add("+", z_ped));
        char *pad_s = filler(gp_str(z_ped, el.width), el.rzp ? 1 : 0);
        if ((el.rlj && el.rzp) || el.rfs)
            str_rep(&pad_s, filler(gp_str(z_ped, el.width), 0));
        str_rep(&res, el.rlj ? str_add(z_ped, pad_s) : str_add(pad_s, z_ped));
    } else {
        char *pad_s = filler(gp_str(res, el.width), 0);
        char *s_ped = el.rlj ? str_add(res, pad_s) : str_add(pad_s, res);
        str_rep(&res, s_ped);
    }
    my_putstr(res, &(container->counter));
}

void apply_flags_str(flag_container *container, flag element)
{
    char *res = get_value_for_str(container, element);
    if (element.pre != -1) str_rep(&res, str_truncate(res, element.pre));
    char *padding = filler(gp_str(res, element.width), 0);
    if (!element.rlj) my_putstr(padding, &(container->counter));
    my_putstr(res, &(container->counter));
    if (element.rlj) my_putstr(padding, &(container->counter));
}

void apply_flags_char(flag_container *container, flag element)
{
    int padding_size = element.width - 1 < 0 ? 0 : element.width - 1;
    char *padding = filler(padding_size, 0);
    if (!element.rlj) my_putstr(padding, &(container->counter));
    my_putchar(element.ln_data, &(container->counter));
    if (element.rlj) my_putstr(padding, &(container->counter));
}

void apply_flags_double(flag_container *container, flag el)
{
    char *res = get_value_for_double(container, el);

    int is_converted = el.spe == 'a' || el.spe == 'A';

    if (!is_converted) {
        if (el.rsj && el.dbl_data > 0 && !el.rfs && !el.rzp)
            str_rep(&res, str_add(" ", res));
        if (el.rfs && el.dbl_data > 0)
            str_rep(&res, str_add("+", res));
    }

    char *pad_space = filler(gp_str(res, el.width), el.rzp ? 1 : 0);
    if ((el.rlj && el.rzp) || el.rfs)
        str_rep(&pad_space, filler(gp_str(res, el.width), 0));
    char *s_pad = el.rlj ? str_add(res, pad_space) : str_add(pad_space, res);
    str_rep(&res, s_pad);

    my_putstr(res, &(container->counter));
}
