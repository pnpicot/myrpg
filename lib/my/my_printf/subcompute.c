/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Continue flag computing
*/

#include "../my.h"
#include <stdarg.h>

void subcomp_part_2(flag *l)
{
    l->ln_data = l->ln_data < 0 ? -1 * (long long) l->ln_data : l->ln_data;
    if (l->mod && !my_strcmp(l->mod, "h")) {
        l->ln_data = l->ln_data > 65535 ? 65535 : l->ln_data;
    } else if (l->mod && !my_strcmp(l->mod, "l")) {
        l->ln_data = l->ln_data > 4294967295 ? 4294967295 : l->ln_data;
    }
    if (l->mod && !my_strcmp(l->mod, "hh")) {
        l->ln_data = l->ln_data > 255 ? 255 : l->ln_data;
        l->ln_data = l->ln_data < 0 ? 0 : l->ln_data;
    }
}

void subcomp_int(flag_container *container, flag l)
{
    if (l.spe == 'd' || l.spe == 'i') {
        if (l.mod && !my_strcmp(l.mod, "h")) {
            l.ln_data = l.ln_data < -32768 ? -32768 : l.ln_data;
            l.ln_data = l.ln_data > 32767 ? 32767 : l.ln_data;
        }
        if (l.mod && !my_strcmp(l.mod, "l")) {
            l.ln_data = l.ln_data < -2147483648 ? -2147483648 : l.ln_data;
            l.ln_data = l.ln_data > 2147483647 ? 2147483647 : l.ln_data;
        }
        if (l.mod && !my_strcmp(l.mod, "hh")) {
            l.ln_data = l.ln_data > 128 ? 128 : l.ln_data;
            l.ln_data = l.ln_data < -127 ? -127 : l.ln_data;
        }
    } else {
        subcomp_part_2(&l);
    }
    apply_flags_int(container, l);
}

void subcomp_str(flag_container *container, flag element)
{
    apply_flags_str(container, element);
}

void subcomp_char(flag_container *container, flag element)
{
    apply_flags_char(container, element);
}

void subcomp_double(flag_container *container, flag element)
{
    if (element.mod && my_strcmp(element.mod, "L"))
        element.dbl_data = (double) element.dbl_data;
    apply_flags_double(container, element);
}
