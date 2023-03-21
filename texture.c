/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Texture module
*/

#include "include/main.h"

sfTexture *get_texture(s_appdata *adata, char *id)
{
    linked_node *textures = adata->lists->textures;

    while (textures != NULL && textures->data != NULL) {
        s_texture *cur = (s_texture *) textures->data;

        if (!my_strcmp(cur->id, id)) return (cur->texture);

        textures = textures->next;
    }

    return (NULL);
}

void delete_texture(s_appdata *adata, char *id)
{
    sfTexture *texture = get_texture(adata, id);
    if (texture == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }
    linked_node *textures = adata->lists->textures;
    int ite = 0;
    while (textures != NULL && textures->data != NULL) {
        s_texture *cur = (s_texture *) textures->data;
        if (!my_strcmp(cur->id, id)) {
            sfTexture_destroy(cur->texture);
            break;
        }
        ite++;
        textures = textures->next;
    }
    linked_delete(&adata->lists->textures, ite);
}

void add_texture_next(s_appdata *adata, char *id, \
s_texture *new_texture, char *path)
{
    new_texture->id = id;
    new_texture->texture = sfTexture_createFromFile(path, NULL);
    if (new_texture->texture == NULL) {
        my_printf(get_error(adata, "tex_load_fail"));
        return;
    }
    linked_add(adata->lists->textures, new_texture);
}

void add_texture(s_appdata *adata, char *id, char *filename)
{
    char *path = str_add("bonus/textures/", filename);
    struct stat buffer;
    if (stat(path, &buffer) == -1) {
        my_printf(get_error(adata, "no_file"));
        return;
    }
    sfTexture *texture = get_texture(adata, id);
    if (texture != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }
    s_texture *new_texture = malloc(sizeof(s_texture));
    if (new_texture == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }
    add_texture_next(adata, id, new_texture, path);
}

void load_textures(s_appdata *adata)
{
    char *file_content = file_extract("bonus/textures.myrpg");
    char **entries = str_split(file_content, '\n');
    int ite = 0;

    while (entries[ite] != NULL) {
        if (entries[ite][0] == '#') {
            ite++;
            continue;
        }

        char **entry_data = str_m_split(entries[ite], 2, '=', ' ');
        char *id = entry_data[0];
        char *filename = entry_data[1];

        add_texture(adata, id, filename);

        ite++;
    }
}
