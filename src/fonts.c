/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Fonts module
*/

#include "main.h"

sfFont *get_font(s_appdata *adata, char *id)
{
    linked_node *fonts = adata->lists->fonts;

    while (fonts != NULL && fonts->data != NULL) {
        s_font *cur = (s_font *) fonts->data;

        if (!my_strcmp(cur->id, id)) return (cur->font);

        fonts = fonts->next;
    }

    return (NULL);
}

void add_font(s_appdata *adata, char *id, char *filename)
{
    sfFont *font = get_font(adata, id);
    if (font != NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "already_exists"));
        return;
    } char *path = str_m_add(3, "bonus/fonts/", filename, ".ttf");
    struct stat buffer = {0};
    if (stat(path, &buffer) == -1) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "no_file"));
        return;
    } s_font *new_font = malloc(sizeof(s_font));
    if (new_font == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return;
    }
    *new_font = (s_font) {.font = sfFont_createFromFile(path), .id = id};
    free(path);
    linked_add(adata->lists->fonts, new_font);
}

void load_fonts(s_appdata *adata)
{
    char *file_content = file_extract("bonus/fonts.myrpg");
    char **entries = str_split(file_content, '\n');
    free(file_content);
    for (int ite = 0; entries[ite] != NULL; ++ite) {
        if (entries[ite][0] == '#') {
            continue;
        }
        char **entry_data = str_m_split(entries[ite], 2, '=', ' ');
        char *id = entry_data[0];
        char *filename = entry_data[1];
        add_font(adata, id, filename);
        for (int i = 1; entry_data[i] != NULL; i++)
            free(entry_data[i]);
        free(entry_data);
    }
    for (int i = 0; entries[i] != NULL; i++)
        free(entries[i]);
    free(entries);
}
