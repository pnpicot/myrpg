/*
** EPITECH PROJECT, 2023
** editor
** File description:
** map_editor
*/

#include "map_editor.h"

static int render_window(internal_data_t *const data)
{
    sfRenderWindow_clear(data->window, sfColor_fromRGB(64, 64, 64));
    sfRenderWindow_setView(data->window, data->view);
    if (data->workspace != NULL && data->menu == MAP_EDITOR) {
        sfSprite_setTexture(data->workspace_sprite,
        sfRenderTexture_getTexture(data->workspace), sfTrue);
        sfRenderWindow_drawSprite(data->window, data->workspace_sprite, NULL);
    }
    if (data->menu == MAP_EDITOR)
        sfRenderWindow_setView(data->window, data->left_view);
    if (actualize_button(data) < 0)
        return (-1);
    if (data->texture_sprite != NULL) {
        sfSprite_setTexture(data->texture_sprite,
        data->texture[data->actual_texture], sfTrue);
        sfRenderWindow_drawRectangleShape(data->window, data->texture_rect,
        NULL);
        sfRenderWindow_drawSprite(data->window, data->texture_sprite, NULL);
    }
    sfRenderWindow_display(data->window);
    return (0);
}

static int game_loop(internal_data_t *const data)
{
    while (sfRenderWindow_isOpen(data->window)) {
        event_handler(data);
        if (data->menu == SIZE_SELECTION)
            size_selection(data);
        if (data->menu == MAP_EDITOR)
            map_editor_loop(data);
        data->touched = 0;
        if (render_window(data) < 0)
            return (-1);
    }
    return (0);
}

int map_editor(void)
{
    internal_data_t *data = init();
    int rvalue = 0;

    if (data == NULL)
        return (84);
    rvalue = game_loop(data);
    destroy(data);
    return (rvalue);
}
