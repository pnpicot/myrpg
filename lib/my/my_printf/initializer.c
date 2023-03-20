/*
** EPITECH PROJECT, 2022
** get_elem_nbr
** File description:
** get_elem_nbr
*/

#include "../my.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

void init_container(flag_container *container, char *format)
{
    container->current = 0;
    container->print_count = 0;
    container->counter = 0;
    container->max = get_elem_nbr(format);
    container->flags = malloc(get_elem_nbr(format) * sizeof(flag));
}

void init_flag(flag *ptr_flag)
{
    ptr_flag->type = 0;
    ptr_flag->dbl_data = 0;
    ptr_flag->ln_data = 0;
    ptr_flag->str_data = NULL;
    ptr_flag->spe = 0;
    ptr_flag->need_pre = 0;
    ptr_flag->pre = -1;
    ptr_flag->need_width = 0;
    ptr_flag->width = 0;
    ptr_flag->mod = NULL;
    ptr_flag->rsj = 0;
    ptr_flag->rfs = 0;
    ptr_flag->rzp = 0;
    ptr_flag->rp = 0;
    ptr_flag->rlj = 0;
}
