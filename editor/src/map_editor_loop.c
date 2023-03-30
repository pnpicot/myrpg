/*
** EPITECH PROJECT, 2023
** src
** File description:
** map_editor_loop
*/

#include "map_editor.h"

static void draw_on_map(internal_data_t *const data, sfSprite *rsprite,
int y, int x)
{
    if (data->select_rectangle.left + x < 0 ||
    data->select_rectangle.top + y < 0 ||
    data->select_rectangle.left + x >= data->map_size.x ||
    data->select_rectangle.top + y >= data->map_size.y)
        return;
    data->map[data->select_rectangle.top + y]
    [data->select_rectangle.left + x] = data->actual_texture;
    sfSprite_setPosition(rsprite, (sfVector2f){(data->select_rectangle
    .left + x) * (TEXTURE_SIZE + GRID_SIZE), (data->select_rectangle
    .top + y) * (TEXTURE_SIZE + GRID_SIZE)});
    sfRenderTexture_drawSprite(data->workspace, rsprite, NULL);
}

static void set_rectangle(internal_data_t *const data, sfSprite *rsprite,
sfVector2i touch_pos)
{
    if (data->select_rectangle.left == -11) {
        data->select_rectangle.left = touch_pos.x;
        data->select_rectangle.top = touch_pos.y;
        if (data->tool == DRAW) {
            data->select_rectangle.left -= data->brush_size / 2;
            data->select_rectangle.top -= data->brush_size / 2;
            data->select_rectangle.width = data->brush_size;
            data->select_rectangle.height = data->brush_size;
        }
    } if (data->tool == RECTANGLE) {
        data->select_rectangle.width = touch_pos.x -
        data->select_rectangle.left;
        data->select_rectangle.height = touch_pos.y -
        data->select_rectangle.top;
    }
    for (int y = 0; (_REC.height > 0) ? y < _REC.height : y > _REC.height;
    y += (_REC.height > 0 ? 1 : -1))
        for (int x = 0; (_REC.width > 0) ? x < _REC.width : x > _REC.width;
        x += (_REC.width > 0 ? 1 : -1))
            draw_on_map(data, rsprite, y, x);
}

static void detect_click(internal_data_t *const data, sfSprite *rsprite)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(data->workspace_sprite);
    sfVector2f touch_pos = sfRenderWindow_mapPixelToCoords(data->window,
    sf2f2i(data->mouse_pos), data->view);
    if (data->lmb == NOTHING || data->tool == MOVE || data->touched == sfTrue) {
        data->select_rectangle.left = -11;
        return;
    }
    if (sfFloatRect_contains(&rect, touch_pos.x, touch_pos.y) == sfFalse)
        return;
    touch_pos = (sfVector2f){(int)((touch_pos.x - rect.left) / (TEXTURE_SIZE +
    GRID_SIZE)), (int)((touch_pos.y - rect.top) / (TEXTURE_SIZE + GRID_SIZE))};
    if (touch_pos.x < 0 || touch_pos.y < 0 || touch_pos.x >= data->map_size.x
    || touch_pos.y >= data->map_size.y)
        return;
    sfSprite_setTexture(rsprite, data->texture[data->actual_texture], sfTrue);
    set_rectangle(data, rsprite, sf2f2i(touch_pos));
    if (data->tool == DRAW)
        data->select_rectangle.left = -11;
    sfRenderTexture_display(data->workspace);
}

int map_editor_loop(internal_data_t *const data)
{
    sfSprite *rsprite = sfSprite_create();

    if (rsprite == NULL)
        return (-1);
    if (data->workspace == NULL) {
        if (create_map_editor(data) < 0)
            return (-1);
        if (create_map_editor_button(data) < 0)
            return (-1);
    }
    detect_click(data, rsprite);
    sfSprite_destroy(rsprite);
    return (0);
}
