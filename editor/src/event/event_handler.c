/*
** EPITECH PROJECT, 2023
** editor
** File description:
** event_handler
*/

#include "map_editor.h"

static void view_zoom(internal_data_t *const data)
{
    if (data->event.type != sfEvtMouseWheelScrolled ||
    data->event.mouseWheelScroll.wheel != sfMouseVerticalWheel)
        return;
    if (data->event.mouseWheelScroll.delta > 0 && sfView_getSize(data->view).x
    > (data->map_size.x * (TEXTURE_SIZE + GRID_SIZE) - GRID_SIZE) * 10)
        return;
    if (data->event.mouseWheelScroll.delta < 0 && sfView_getSize(data->view).x
    < 500)
        return;
    sfView_zoom(data->view, 1 + data->event.mouseWheelScroll.delta / 10);
    data->v_scale *= 1 + data->event.mouseWheelScroll.delta / 10;
}

void move_view(internal_data_t *const data)
{
    sfFloatRect workspace = sfSprite_getGlobalBounds(data->workspace_sprite);

    if (data->lmb != PRESSED || data->tool != MOVE ||
    is_touching(data->window, &workspace, data->mouse_pos, data->view) == 0
    || (data->mouse_move.x == 0 && data->mouse_move.y == 0))
        return;
    sfView_move(data->view, (sfVector2f){
    -(data->mouse_move.x * data->v_scale),
    -(data->mouse_move.y * data->v_scale)});
}

static void resize_handler(internal_data_t *const data)
{
    if (data->event.type != sfEvtResized)
        return;
    if (data->event.size.width < 800 || data->event.size.height < 600) {
        sfRenderWindow_setSize(data->window, (sfVector2u){800, 600});
        sfView_setSize(data->view, (sfVector2f){800 * data->v_scale, 600 *
        data->v_scale});
        return;
    }
    sfView_setSize(data->view, (sfVector2f){data->event.size.width *
    data->v_scale, data->event.size.height * data->v_scale});
    if (data->left_view != NULL) {
        sfView_setSize(data->left_view, (sfVector2f){data->event.size.width,
        data->event.size.height});
        sfView_setCenter(data->left_view, (sfVector2f){data->event.size.width /
        2, data->event.size.height / 2});
    }
}

static void function_caller(internal_data_t *const data)
{
    if (data->event.type == sfEvtClosed)
        sfRenderWindow_close(data->window);
    mouse_event(data);
    text_event(data);
    key_event(data);
    resize_handler(data);
    if (data->menu == MAP_EDITOR)
        view_zoom(data);
    else if (data->menu == MAP_EDITOR)
        map_editor_event(data);
}

void event_handler(internal_data_t *const data)
{
    if (data->enter == RELEASED)
        data->enter = NOTHING;
    if (data->lmb == RELEASED)
        data->lmb = NOTHING;

    sfVector2f save = data->mouse_pos;
    while (sfRenderWindow_pollEvent(data->window, &data->event))
        function_caller(data);
    data->mouse_move = (sfVector2f){data->mouse_pos.x - save.x,
    data->mouse_pos.y - save.y};
    if (data->menu == MAP_EDITOR && data->workspace_sprite != NULL)
        move_view(data);
}
