/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Sprite module
*/

#include "../include/main.h"

void set_sprite_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_sprite *sprite = get_sprite(adata, id);
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (sprite == NULL || rtex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    sprite->rtex_id = rtex_id;
    s_ref *ref = get_ref(adata, sprite, TYPE_SPRITE);
    linked_add_sorted_layer(rtex->objects, ref);
}

void set_sprite_active(s_appdata *adata, char *id, sfUint8 active)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    sprite->active = active;
}

void set_sprite_repeat(s_appdata *adata, char *id, sfBool repeat)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    sfTexture_setRepeated(sprite->texture, repeat);
    sfSprite_setTexture(sprite->elem, sprite->texture, sfFalse);
}

void rotate_sprite_add(s_appdata *adata, char *id, float angle_ch)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    sfSprite_rotate(sprite->elem, angle_ch);
}

void set_sprite_color(s_appdata *adata, char *id, sfColor color)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    sfSprite_setColor(sprite->elem, color);
}
