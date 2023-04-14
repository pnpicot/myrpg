/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Configuration module
*/

#include "../include/main.h"

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

    free(value);
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
    for (int i = 0; channels[i] != NULL; i++) free(channels[i]);
    free(channels);
    free(value);
    linked_add(lists->config_colors, new_color);
}

void add_config(s_appdata *adata, char *type, char *id, char *value)
{
    if (!my_strcmp(type, "int")) {
        add_config_int(adata, type, id, value);
        return;
    }

    if (!my_strcmp(type, "float")) {
        add_config_float(adata, type, id, value);
        return;
    }

    if (!my_strcmp(type, "string")) {
        add_config_str(adata, type, id, value);
        return;
    }

    if (!my_strcmp(type, "color")) {
        add_config_color(adata, type, id, value);
        return;
    }
}

void init_config(s_appdata *adata)
{
    char *config_content = file_extract("bonus/config.myrpg");
    char **entries = str_split(config_content, '\n');
    int ite = 0;

    free(config_content);
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

        free(entry_data[0]);
        for (int i = 3; entry_data[i] != NULL; i++)
            free(entry_data[i]);
        free(entry_data);
        ite++;
    }
    for (int i = 0; entries[i] != NULL; i++) free(entries[i]);
    free(entries);
}
