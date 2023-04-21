/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Animation module
*/

#include "../include/main.h"

void set_animation_mode(s_appdata *adata, char *sprite_id, int mode)
{
    s_animation *animation = get_animation(adata, sprite_id);

    if (animation == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    animation->mode = mode;
    update_sprite_animation(adata, animation, sfTrue);
}

void animate_restart(s_appdata *adata, s_animation *animation)
{
    animation->pos.x++;

    if (animation->pos.x >= animation->width)
        animation->pos.x = 0;
}

void animate_reverse(s_appdata *adata, s_animation *animation)
{
    if (!animation->reverse_state)
        animation->pos.x++;
    else
        animation->pos.x--;

    int width_minus = (float) animation->width - 1;
    int end_plus = animation->pos.x >= width_minus && !animation->reverse_state;
    int end_minus = animation->pos.x <= 0 && animation->reverse_state;

    if (end_plus || end_minus)
        animation->reverse_state = !animation->reverse_state;
}

void set_animation_rect(s_appdata *adata, s_animation *animation)
{
    sfVector2f size;
    size.x = animation->base_size.x / (float) animation->width;
    size.y = animation->base_size.y / (float) animation->height;

    sfIntRect new_rect;
    new_rect.left = animation->pos.x * size.x;
    new_rect.top = animation->pos.y * size.y;
    new_rect.width = size.x;
    new_rect.height = size.y;

    sfSprite_setTextureRect(animation->sprite->elem, new_rect);
}

void update_sprite_animation(s_appdata *adata, s_animation *animation, \
sfBool force)
{
    float seconds = get_clock_seconds(animation->anim_clock);

    if (seconds >= animation->clock_rate || force) {
        if (animation->mode == animation_restart) {
            animate_restart(adata, animation);
        } else if (animation->mode == animation_reverse) {
            animate_reverse(adata, animation);
        }

        set_animation_rect(adata, animation);
        sfClock_restart(animation->anim_clock);
    }
}
