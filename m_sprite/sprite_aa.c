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
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sprite->rtex_id = rtex_id;
}

void set_sprite_active(s_appdata *adata, char *id, sfUint8 active)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sprite->active = active;
}

void set_sprite_repeat(s_appdata *adata, char *id, sfBool repeat)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfTexture_setRepeated(sprite->texture, repeat);
    sfSprite_setTexture(sprite->elem, sprite->texture, sfFalse);
}
