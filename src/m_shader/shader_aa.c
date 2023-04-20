/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Shader module
*/

#include "../include/main.h"

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
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    sfShader_setFloatUniform(shader, param, value);
}

void set_shader_vec2(s_appdata *adata, char *id, char *param, sfVector2f value)
{
    sfShader *shader = get_shader(adata, id);

    if (shader == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    sfShader_setVec2Uniform(shader, param, (sfGlslVec2) { value.x, value.y });
}

void set_shader_color(s_appdata *adata, char *id, char *param, sfColor color)
{
    sfShader *shader = get_shader(adata, id);

    if (shader == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    sfShader_setColorUniform(shader, param, color);
}

void set_shader_texture(s_appdata *adata, char *id, char *param, \
const sfTexture *tex)
{
    sfShader *shader = get_shader(adata, id);

    if (shader == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    sfShader_setTextureUniform(shader, param, tex);
}
