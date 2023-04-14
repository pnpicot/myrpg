/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Configuration module
*/

#include "../include/main.h"

int get_int(s_appdata *adata, char *id)
{
    linked_node *integers = adata->lists->config_ints;

    while (integers != NULL && integers->data != NULL) {
        s_int *cur = (s_int *) integers->data;

        if (!my_strcmp(cur->id, id)) return (cur->value);

        integers = integers->next;
    }

    return (-1);
}

float get_float(s_appdata *adata, char *id)
{
    linked_node *floats = adata->lists->config_floats;

    while (floats != NULL && floats->data != NULL) {
        s_float *cur = (s_float *) floats->data;

        if (!my_strcmp(cur->id, id)) return (cur->value);

        floats = floats->next;
    }

    return (-1);
}

char *get_str(s_appdata *adata, char *id)
{
    linked_node *strings = adata->lists->config_strings;

    while (strings != NULL && strings->data != NULL) {
        s_str *cur = (s_str *) strings->data;

        if (!my_strcmp(cur->id, id)) return (cur->value);

        strings = strings->next;
    }

    return (NULL);
}

sfColor get_config_color(s_appdata *adata, char *id)
{
    linked_node *colors = adata->lists->config_colors;

    while (colors != NULL && colors->data != NULL) {
        s_color *cur = (s_color *) colors->data;

        if (!my_strcmp(cur->id, id)) return (cur->value);

        colors = colors->next;
    }

    return (sfBlack);
}

void add_config_int(s_appdata *adata, char *type, char *id, char *value)
{
    s_linkeds *lists = adata->lists;
    int converted_value = my_getnbr(value);
    s_int *new_int = malloc(sizeof(s_int));

    if (new_int == NULL) {
        my_printf("[MyRPG] error: memory allocation failed.\n");
        return;
    }

    new_int->id = id;
    new_int->value = converted_value;

    free(value);
    linked_add(lists->config_ints, new_int);
}
