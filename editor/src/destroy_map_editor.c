/*
** EPITECH PROJECT, 2023
** src
** File description:
** destroy_map_editor
*/

#include "map_editor.h"

void destroy_map_editor(internal_data_t *const data)
{
    for (int i = 0; i < 256; ++i)
        sfTexture_destroy(data->texture[i]);
    if (data->map != NULL) {
        for (int i = 0; i < data->map_size.y; ++i)
            free(data->map[i]);
        free(data->map);
    }
    if (data->workspace_sprite != NULL)
        sfSprite_destroy(data->workspace_sprite);
    if (data->workspace != NULL)
        sfRenderTexture_destroy(data->workspace);
    if (data->texture_rect != NULL)
        sfRectangleShape_destroy(data->texture_rect);
    if (data->texture_sprite != NULL)
        sfSprite_destroy(data->texture_sprite);
    if (data->left_view != NULL)
        sfView_destroy(data->left_view);
    if (data->text_entered != NULL)
        free(data->text_entered);
}
