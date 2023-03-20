/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Sprite module
*/

#include "../include/main.h"

void scale_sprite(s_appdata *adata, char *id, sfVector2f factors)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfSprite_setScale(sprite->elem, factors);
}

void rotate_sprite(s_appdata *adata, char *id, float angle)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfSprite_rotate(sprite->elem, angle);
}

sfFloatRect get_sprite_bounds(s_appdata *adata, char *id)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfFloatRect) { -1, -1, -1, -1 });
    }

    return (sfSprite_getGlobalBounds(sprite->elem));
}

float get_sprite_rotation(s_appdata *adata, char *id)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (-1);
    }

    return (sfSprite_getRotation(sprite->elem));
}

sfVector2f get_sprite_scale(s_appdata *adata, char *id)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (sfSprite_getScale(sprite->elem));
}
