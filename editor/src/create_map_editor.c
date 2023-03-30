/*
** EPITECH PROJECT, 2023
** src
** File description:
** create_map_editor
*/

#include "map_editor.h"

static void draw_map(internal_data_t *const data)
{
    sfSprite *sprite = sfSprite_create();

    if (sprite == NULL)
        return;
    sfSprite_setTexture(sprite, data->texture[0], 1);
    for (int j = 0; j < data->map_size.y; ++j) {
        for (int i = 0; i < data->map_size.x; ++i) {
            sfSprite_setPosition(sprite, (sfVector2f){i * (TEXTURE_SIZE +
            GRID_SIZE), j * (TEXTURE_SIZE + GRID_SIZE)});
            sfRenderTexture_drawSprite(data->workspace, sprite, NULL);
        }
    }
    sfSprite_destroy(sprite);
    sfRenderTexture_display(data->workspace);
}

static int malloc_map(internal_data_t *const data)
{
    data->map = malloc(sizeof(unsigned char *) * data->map_size.y);
    if (data->map == NULL)
        return (-1);
    for (int i = 0; i < data->map_size.y; i++) {
        data->map[i] = malloc(sizeof(unsigned char) * data->map_size.x);
        if (data->map[i] == NULL)
            return (-1);
        for (int j = 0; j < data->map_size.x; j++)
            data->map[i][j] = '\0';
    }
    return (0);
}

static int create_workspace(internal_data_t *const data)
{
    sfVector2f map_size = {data->map_size.x * (TEXTURE_SIZE + GRID_SIZE) -
    GRID_SIZE, data->map_size.y * (TEXTURE_SIZE + GRID_SIZE) - GRID_SIZE};

    data->workspace = sfRenderTexture_create(map_size.x, map_size.y, sfFalse);
    if (data->workspace == NULL)
        return (-1);
    sfRenderTexture_clear(data->workspace, sfWhite);
    data->workspace_sprite = sfSprite_create();
    if (data->workspace_sprite == NULL)
        return (-1);
    sfSprite_setPosition(data->workspace_sprite, (sfVector2f){(1920 -
    map_size.x) / 2, (1080 - map_size.y) / 2});
    data->v_scale = map_size.x / 1920 > map_size.y / 1080 ?
    map_size.x / 1920 * 1.2 : map_size.y / 1080 * 1.2;
    sfView_zoom(data->view, map_size.x / 1920 > map_size.y / 1080 ?
    map_size.x / 1920 * 1.2 : map_size.y / 1080 * 1.2);
    return (0);
}

static int create_textures(internal_data_t *const data)
{
    sfColor color[256] = {0};

    for (int i = 0; i < 256; ++i)
        color[i] = sfColor_fromRGB((i * 16) % 256, (i * 4) % 256, i);
    for (int i = 0; i < 256; ++i) {
        sfImage *image = sfImage_createFromColor(TEXTURE_SIZE, TEXTURE_SIZE,
        color[i]);
        if (image == NULL)
            return (-1);
        data->texture[i] = sfTexture_createFromImage(image, NULL);
        if (data->texture[i] == NULL)
            return (-1);
        sfImage_destroy(image);
    }
    return (0);
}

int create_map_editor(internal_data_t *const data)
{
    if (malloc_map(data) < 0)
        return (-1);
    if (create_workspace(data) < 0)
        return (-1);
    if (create_textures(data) < 0)
        return (-1);
    data->texture_sprite = sfSprite_create();
    if (data->texture_sprite == NULL)
        return (-1);
    sfSprite_setPosition(data->texture_sprite, (sfVector2f){40, 20});
    sfSprite_setScale(data->texture_sprite, (sfVector2f){5, 5});
    data->texture_rect = sfRectangleShape_create();
    if (data->texture_rect == NULL)
        return (-1);
    sfRectangleShape_setSize(data->texture_rect, (sfVector2f){TEXTURE_SIZE
    * 5 + 10, TEXTURE_SIZE * 5 + 10});
    sfRectangleShape_setPosition(data->texture_rect, (sfVector2f){35, 15});
    sfRectangleShape_setFillColor(data->texture_rect, sfBlack);
    draw_map(data);
    return (0);
}
