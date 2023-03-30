/*
** EPITECH PROJECT, 2023
** utils
** File description:
** create_button
*/

#include "map_editor.h"

static int text_button(button_t *button, internal_data_t *const data)
{
    button->text = sfText_create();
    if (button->text == NULL)
        return (-1);
    if (data->font == NULL)
        data->font = sfFont_createFromFile("assets/arial.ttf");
    if (data->font == NULL)
        return (-1);
    sfText_setFont(button->text, data->font);
    sfText_setCharacterSize(button->text, 30);
    sfText_setColor(button->text, sfBlack);
    return (0);
}

static button_t *set_pos(button_t *button, sfFloatRect rect)
{
    button->base = sfColor_fromRGB(50, 200, 50);
    button->hover = sfColor_fromRGB(100, 200, 100);
    button->pressed = sfColor_fromRGB(150, 255, 150);
    button->temp_color = sfRed;
    sfRectangleShape_setPosition(button->rect, (sfVector2f){rect.left,
    rect.top});
    sfRectangleShape_setSize(button->rect, (sfVector2f){rect.width,
    rect.height});
    sfRectangleShape_setFillColor(button->rect, button->base);
    return (button);
}

button_t *create_button(internal_data_t *const data, int sprite_text,
sfFloatRect rect)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return (NULL);
    *button = (button_t){0};
    button->rect = sfRectangleShape_create();
    if (button->rect == NULL)
        return (NULL);
    if (sprite_text == 1) {
        if (text_button(button, data) < 0)
            return (NULL);
    }
    if (sprite_text == 0) {
        button->sprite = sfSprite_create();
        if (button->sprite == NULL)
            return (NULL);
    }
    return (set_pos(button, rect));
}
