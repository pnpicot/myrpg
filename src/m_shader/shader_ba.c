/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Shader module
*/

#include "../include/main.h"

sfShader *get_shader(s_appdata *adata, char *id)
{
    linked_node *shaders = adata->lists->shaders;

    while (shaders != NULL && shaders->data != NULL) {
        s_shader *cur = (s_shader *) shaders->data;

        if (!my_strcmp(cur->id, id)) return (cur->shader);

        shaders = shaders->next;
    }

    return (NULL);
}

void delete_shader(s_appdata *adata, char *id)
{
    sfShader *shader = get_shader(adata, id);
    if (shader == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }
    linked_node *shaders = adata->lists->shaders;
    int ite = 0;
    while (shaders != NULL && shaders->data != NULL) {
        s_shader *cur = (s_shader *) shaders->data;
        if (!my_strcmp(cur->id, id)) {
            sfShader_destroy(cur->shader);
            break;
        }
        ite++;
        shaders = shaders->next;
    }
    linked_delete(&adata->lists->shaders, ite);
}

int add_shader_vert(s_appdata *adata, char *vert, char **vert_path)
{
    int is_nil = 1;

    if (my_strcmp(vert, "NULL")) {
        (*vert_path) = str_add("bonus/shaders/", vert);

        is_nil = 0;
    } else {
        (*vert_path) = NULL;
        return (1);
    }

    struct stat buffer;

    if (stat(*vert_path, &buffer) == -1 && !is_nil) {
        my_printf(get_error(adata, "no_file"));
        return (0);
    }

    return (1);
}

int add_shader_frag(s_appdata *adata, char *frag, char **frag_path)
{
    int is_nil = 1;

    if (my_strcmp(frag, "NULL")) {
        (*frag_path) = str_add("bonus/shaders/", frag);

        is_nil = 0;
    } else {
        (*frag_path) = NULL;
        return (1);
    }

    struct stat buffer;

    if(stat(*frag_path, &buffer) == -1 && !is_nil) {
        my_printf(get_error(adata, "no_file"));
        return (0);
    }

    return (1);
}

void add_shader(s_appdata *adata, char *id, char *paths)
{
    sfShader *shader = get_shader(adata, id);
    if (shader != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }
    char **path_split = str_split(paths, ',');
    char *vert = path_split[0];
    char *frag = path_split[1];
    char *vert_path;
    char *frag_path;
    if (!add_shader_vert(adata, vert, &vert_path)) return;
    if (!add_shader_frag(adata, frag, &frag_path)) return;
    s_shader *new_shader = malloc(sizeof(s_shader));
    if (new_shader == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }
    new_shader->id = id;
    new_shader->shader = sfShader_createFromFile(vert_path, NULL, frag_path);
    linked_add(adata->lists->shaders, new_shader);
}
