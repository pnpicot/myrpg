/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Compute flags of a containerci
*/

#include "../my.h"
#include <stdarg.h>

void compute_int(flag_container *container, flag element)
{
    if (element.spe == 'c') {
        subcomp_char(container, element);
    } else {
        subcomp_int(container, element);
    }
}

void compute_flag(flag_container *container, flag el, va_list *p_li)
{
    if (el.need_width) el.width = va_arg(*p_li, int);
    if (el.need_pre) el.pre = va_arg(*p_li, int);
    if (el.spe == 'n') {
        *va_arg(*p_li, int *) = container->counter;
        return;
    }
    if (el.spe == 'p') {
        el.str_data = get_pointer(va_arg(*p_li, void *));
        return;
    }
    if (el.type == 1) {
        el.dbl_data = va_arg(*p_li, double);
        subcomp_double(container, el);
    } else if (el.type == 2) {
        el.str_data = el.spe == 'p' ? el.str_data : va_arg(*p_li, char *);
        subcomp_str(container, el);
    } else {
        el.ln_data = va_arg(*p_li, long long int);
        compute_int(container, el);
    }
}
