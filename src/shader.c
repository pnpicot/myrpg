/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Shader module
*/

#include "main.h"

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

    if (my_strcmp(vert, "NULL")) {
        struct stat buffer;

        vert_path = str_add("bonus/shaders/", vert);

        if (stat(vert_path, &buffer) == -1) {
            my_printf(get_error(adata, "no_file"));
            return;
        }
    } else {
        vert_path = NULL;
    }

    if (my_strcmp(frag, "NULL")) {
        struct stat buffer;

        frag_path = str_add("bonus/shaders/", frag);

        if(stat(frag_path, &buffer) == -1) {
            my_printf(get_error(adata, "no_file"));
            return;
        }
    } else {
        frag_path = NULL;
    }

    s_shader *new_shader = malloc(sizeof(s_shader));

    if (new_shader == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    new_shader->id = id;
    new_shader->shader = sfShader_createFromFile(vert_path, NULL, frag_path);

    linked_add(adata->lists->shaders, new_shader);
}

void load_shaders(s_appdata *adata)
{
    char *file_content = file_extract("bonus/shaders.myrpg");
    char **entries = str_split(file_content, '\n');
    int ite = 0;

    while (entries[ite] != NULL) {
        if (entries[ite][0] == '#') {
            ite++;
            continue;
        }

        char **entry_data = str_m_split(entries[ite], 2, '=', ' ');
        char *id = entry_data[0];
        char *paths = entry_data[1];

        add_shader(adata, id, paths);

        ite++;
    }
}

void set_shader_float(s_appdata *adata, char *id, char *param, float value)
{
    sfShader *shader = get_shader(adata, id);

    if (shader == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfShader_setFloatParameter(shader, param, value);
}

void set_shader_vec2(s_appdata *adata, char *id, char *param, sfVector2f value)
{
    sfShader *shader = get_shader(adata, id);

    if (shader == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfShader_setVector2Parameter(shader, param, value);
}

void set_shader_color(s_appdata *adata, char *id, char *param, sfColor color)
{
    sfShader *shader = get_shader(adata, id);

    if (shader == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfShader_setColorParameter(shader, param, color);
}

void set_shader_texture(s_appdata *adata, char *id, char *param, const sfTexture *tex)
{
    sfShader *shader = get_shader(adata, id);

    if (shader == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfShader_setTextureParameter(shader, param, tex);
}
