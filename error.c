/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Error module
*/

#include "include/main.h"

char *get_error(s_appdata *adata, char *id)
{
    linked_node *errors = adata->lists->errors;

    while (errors != NULL && errors->data != NULL) {
        s_str *cur = (s_str *) errors->data;

        if (!my_strcmp(cur->id, id)) return (cur->value);

        errors = errors->next;
    }

    return (NULL);
}

void add_error(s_appdata *adata, char *id, char *format)
{
    char *error = get_error(adata, id);

    if (error != NULL) {
        my_printf("[MyRPG] error: can't add new error (id already exists).\n");
        return;
    }

    s_str *new_error = malloc(sizeof(s_str));

    if (new_error == NULL) {
        my_printf("[MyRPG] error: memory allocation failed.\n");
        return;
    }

    new_error->id = id;
    new_error->value = format;

    linked_add(adata->lists->errors, new_error);
}

void init_errors(s_appdata *adata)
{
    char *errors_content = file_extract("bonus/errors.myrpg");
    char **entries = str_split(errors_content, '\n');
    int ite = 0;

    while (entries[ite] != NULL) {
        if (entries[ite][0] == '#') {
            ite++;
            continue;
        }

        char **entry_data = str_split(entries[ite], '=');
        char *id = substr(entry_data[0], 0, my_strlen(entry_data[0]) - 2);
        char *format = substr(entry_data[1], 1, my_strlen(entry_data[1]) - 1);

        add_error(adata, id, str_add(format, "\n"));

        ite++;
    }
}
