/*
** EPITECH PROJECT, 2023
** editor
** File description:
** destroy
*/

#include "map_editor.h"

void destroy_buttons(internal_data_t *const data)
{
    for (button_t *tmp = data->button; tmp != NULL;) {
        if (tmp->sprite != NULL)
            sfSprite_destroy(tmp->sprite);
        if (tmp->text != NULL)
            sfText_destroy(tmp->text);
        if (tmp->rect != NULL)
            sfRectangleShape_destroy(tmp->rect);
        if (tmp->texture != NULL)
            sfTexture_destroy(tmp->texture);
        button_t *tmp2 = tmp;
        tmp = tmp->next;
        free(tmp2);
    }
}

void destroy(internal_data_t *const data)
{
    destroy_map_editor(data);
    destroy_buttons(data);
    if (data->window != NULL)
        sfRenderWindow_destroy(data->window);
    if (data->view != NULL)
        sfView_destroy(data->view);
    if (data->font != NULL)
        sfFont_destroy(data->font);
    free(data);
}
