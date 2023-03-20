/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Parse elements
*/

#include "../my.h"
#include <stdlib.h>
#include <stdarg.h>

const char *l_spe_dbl[] = {
    "f", "F", "e", "E", "g", "G", "a", "A"
};

void set_element_type(flag *ptr_flag)
{
    char *to_str = malloc(sizeof(char) * 2);
    char spe = ptr_flag->spe;
    to_str[0] = spe;
    to_str[1] = '\0';
    if (in_list(to_str, l_spe_dbl, 8)) ptr_flag->type = 1;
    else if (spe == 's' || spe == 'S') ptr_flag->type = 2;
}

void parse_continue(flag *nf, flag_container *ctn, parse_ptr_holder hd, int st)
{
    set_element_type(nf);
    ctn->flags[ctn->current] = *nf;
    ctn->current++;
    compute_flag(ctn, *nf, hd.ptr_list);
    (*hd.last_flag_index) = st;
}

void parse_elements(flag_container *ctn, char *frm, int st, parse_ptr_holder hd)
{
    if (frm[st] == '%') {
        my_putchar('%', &(ctn->counter));
        (*hd.last_flag_index) = st;
        return;
    }
    flag new_flag;
    init_flag(&new_flag);
    int have_flags = check_for_flags(frm, st, &new_flag);
    st = have_flags > 0 ? have_flags : st;
    int have_width = check_for_width(frm, st, &new_flag);
    st = have_width == -2 ? st + 1 : (have_width > 0 ? have_width : st);
    int have_pre = check_for_precision(frm, st, &new_flag);
    st = have_pre == -2 ? st + 2 : (have_pre > 0 ? have_pre : st);
    int have_modifier = check_for_modifier(frm, st, &new_flag);
    st = have_modifier > 0 ? have_modifier + 1 : st;
    int have_specifier = check_for_specifier(frm, st, &new_flag);
    st = have_specifier > 0 ? have_specifier : st;
    if (have_specifier != -1) parse_continue(&new_flag, ctn, hd, st);
}

void parser(char *format, va_list *ptr_list)
{
    flag_container container;
    parse_ptr_holder holder;
    init_container(&container, format);
    int lei = -1;
    int count = 0;

    for (int i = 0; i < my_strlen(format); i++) {
        if (i > lei && format[i] == '%' && format[i + 1] != '\0') {
            int lei_before = lei;
            holder.last_flag_index = &lei;
            holder.ptr_list = ptr_list;
            parse_elements(&container, format, i + 1, holder);
            count += lei != lei_before ? (format[i + 1] != '%' ? 1 : 0) : 0;
        }
        if (i > lei && format[i] != '%') {
            my_putchar(format[i], &container.counter);
        }
    }
    container.current = 0;
    container.max = count;
}
