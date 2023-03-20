/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Configuration module
*/

#include "include/main.h"

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

    linked_add(lists->config_ints, new_int);
}

void add_config_float(s_appdata *adata, char *type, char *id, char *value)
{
    s_linkeds *lists = adata->lists;
    float converted_value = str_to_float(value);
    s_float *new_float = malloc(sizeof(s_float));

    if (new_float == NULL) {
        my_printf("[MyRPG] error: memory allocation failed.\n");
        return;
    }

    new_float->id = id;
    new_float->value = converted_value;

    linked_add(lists->config_floats, new_float);
}

void add_config_str(s_appdata *adata, char *type, char *id, char *value)
{
    s_linkeds *lists = adata->lists;
    s_str *new_string = malloc(sizeof(s_str));

    if (new_string == NULL) {
        my_printf("[MyRPG] error: memory allocation failed.\n");
        return;
    }

    new_string->id = id;
    new_string->value = value;

    linked_add(lists->config_strings, new_string);
}

void add_config_color(s_appdata *adata, char *type, char *id, char *value)
{
    s_linkeds *lists = adata->lists;
    s_color *new_color = malloc(sizeof(s_color));

    if (new_color == NULL) {
        my_printf("[MyRPG] error: memory allocation failed.\n");
        return;
    }

    char **channels = str_split(value, ',');

    if (!is_format(channels, "dddd")) {
        my_printf("[MyRPG] error: invalid color configuration.\n");
        return;
    }

    sfColor converted_value;
    converted_value.r = my_getnbr(channels[0]);
    converted_value.g = my_getnbr(channels[1]);
    converted_value.b = my_getnbr(channels[2]);
    converted_value.a = my_getnbr(channels[3]);

    new_color->id = id;
    new_color->value = converted_value;

    linked_add(lists->config_colors, new_color);
}

void add_config(s_appdata *adata, char *type, char *id, char *value)
{
    if (!my_strcmp(type, "int")) {
        add_config_int(adata, type, id, value);
    } else if (!my_strcmp(type, "float")) {
        add_config_float(adata, type, id, value);
    } else if (!my_strcmp(type, "string")) {
        add_config_str(adata, type, id, value);
    } else if (!my_strcmp(type, "color")) {
        add_config_color(adata, type, id, value);
    }
}

void init_config(s_appdata *adata)
{
    char *config_content = file_extract("bonus/config.myrpg");
    char **entries = str_split(config_content, '\n');
    int ite = 0;

    while (entries[ite] != NULL) {
        if (entries[ite][0] == '#') {
            ite++;
            continue;
        }

        char **entry_data = str_m_split(entries[ite], 2, '=', ' ');
        char *type = entry_data[0];
        char *id = entry_data[1];
        char *value = entry_data[2];

        add_config(adata, type, id, value);

        ite++;
    }
}
