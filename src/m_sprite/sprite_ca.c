/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Sprite module
*/

#include "../include/main.h"

void move_sprite(s_appdata *adata, char *id, sfVector2f pos)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    sprite->pos = pos;

    sfSprite_setPosition(sprite->elem, sprite->pos);
}

void set_sprite_origin(s_appdata *adata, char *id, sfVector2f origin)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    sfSprite_setOrigin(sprite->elem, origin);
}

void set_sprite_rect(s_appdata *adata, char *id, sfIntRect rect)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    sfSprite_setTextureRect(sprite->elem, rect);
}

sfVector2f get_sprite_pos(s_appdata *adata, char *id)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (sfSprite_getPosition(sprite->elem));
}

void translate_sprite(s_appdata *adata, char *id, sfVector2f pos_ch)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    sfVector2f pos = sfSprite_getPosition(sprite->elem);

    pos.x += pos_ch.x;
    pos.y += pos_ch.y;

    sfSprite_setPosition(sprite->elem, pos);
}
