/*
** EPITECH PROJECT, 2023
** utils
** File description:
** actualize_button
*/

#include "map_editor.h"

char *my_strcopy(char const *str)
{
    char *new;
    int i = 0;
    int strlen = 0;

    if (str == NULL)
        return (NULL);
    for (; str[strlen] != '\0'; strlen++);
    if (strlen == 0)
        return (NULL);
    new = malloc(strlen + 1);
    if (new == NULL)
        return (NULL);
    for (; str[i] != '\0'; i++)
        new[i] = str[i];
    new[i] = '\0';
    return (new);
}

static void button_touched(internal_data_t *const data, button_t *button)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    button->state = BASE;
    if (data->enter == RELEASED)
        button->is_selected = sfFalse;
    if (is_touching(data->window, &rect, data->mouse_pos, ((data->menu ==
    MAP_EDITOR) ? data->left_view : data->view)) == 0)
        return;
    data->touched = sfTrue;
    if (data->lmb == RELEASED) {
        for (button_t *tmp = data->button; tmp != NULL; tmp = tmp->next)
            tmp->is_selected = (tmp == button) ? !button->is_selected : sfFalse;
        if (data->text_entered != NULL)
            free(data->text_entered);
        data->text_entered = my_strcopy((button->text == NULL) ? NULL :
        sfText_getString(button->text));
    }
    if (data->lmb == NOTHING)
        button->state = HOVER;
    if (data->lmb == PRESSED)
        button->state = CLICKED;
}

static void draw_it(internal_data_t *const data, button_t *button)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    sfRenderWindow_drawRectangleShape(data->window, button->rect, NULL);
    if (button->sprite != NULL) {
        sfFloatRect rect2 = sfSprite_getGlobalBounds(button->sprite);
        sfSprite_setPosition(button->sprite, (sfVector2f){rect.left + (rect.
        width - rect2.width) / 2, rect.top + (rect.height - rect2.height) / 2});
        sfRenderWindow_drawSprite(data->window, button->sprite, NULL);
    }
    if (button->text != NULL) {
        sfFloatRect rect2 = sfText_getGlobalBounds(button->text);
        sfText_setPosition(button->text, (sfVector2f){rect.left + (rect.width -
        rect2.width) / 2, rect.top + (rect.height - rect2.height) / 2});
        sfRenderWindow_drawText(data->window, button->text, NULL);
    }

}

static int actualize_it(internal_data_t *const data, button_t *button)
{
    if (button->state == BASE)
        sfRectangleShape_setFillColor(button->rect, button->base);
    if (button->state == HOVER)
        sfRectangleShape_setFillColor(button->rect, button->hover);
    if (button->state == CLICKED || button->is_selected == sfTrue)
        sfRectangleShape_setFillColor(button->rect, button->pressed);
    if (button->temp_color_time > 0) {
        sfRectangleShape_setFillColor(button->rect, button->temp_color);
        button->temp_color_time--;
    } if (button->is_selected == sfTrue && button->text != NULL &&
    data->text_entered != NULL && button->text_char == NULL)
        sfText_setString(button->text, data->text_entered);
    if (button->text_char != NULL && button->text != NULL)
        sfText_setString(button->text, button->text_char);
    draw_it(data, button);
    if (button->is_selected && button->func != NULL) {
        button->is_selected = sfFalse;
        return (button->func(data));
    }
    return (0);
}

int actualize_button(internal_data_t *const data)
{
    button_t *button = data->button;

    while (button != NULL) {
        button_touched(data, button);
        int rvalue = actualize_it(data, button);
        if (rvalue != 0)
            return (rvalue == 1 ? 0 : rvalue);
        button = button->next;
    }
    return (0);
}
