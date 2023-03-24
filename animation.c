/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Animation module
*/

#include "include/main.h"

s_animation *get_animation(s_appdata *adata, char *sprite_id)
{
    linked_node *animations = adata->lists->animations;

    while (animations != NULL && animations->data != NULL) {
        s_animation *cur = (s_animation *) animations->data;

        if (!my_strcmp(cur->sprite->id, sprite_id)) return (cur);

        animations = animations->next;
    }

    return (NULL);
}

void set_animation_speed(s_appdata *adata, char *sprite_id, float speed)
{
    s_animation *animation = get_animation(adata, sprite_id);

    if (animation == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    animation->clock_rate = speed;
    update_sprite_animation(adata, animation, sfTrue);
}

void set_animation_rows(s_appdata *adata, char *sprite_id, int row_count)
{
    s_animation *animation = get_animation(adata, sprite_id);

    if (animation == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    animation->height = row_count;
    update_sprite_animation(adata, animation, sfTrue);
}

void set_animation_cols(s_appdata *adata, char *sprite_id, int col_count)
{
    s_animation *animation = get_animation(adata, sprite_id);

    if (animation == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    animation->width = col_count;
    update_sprite_animation(adata, animation, sfTrue);
}

void shift_animation_row(s_appdata *adata, char *sprite_id, int row_index)
{
    s_animation *animation = get_animation(adata, sprite_id);

    if (animation == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    animation->pos.y = row_index;
    update_sprite_animation(adata, animation, sfTrue);
}

void set_animation_mode(s_appdata *adata, char *sprite_id, int mode)
{
    s_animation *animation = get_animation(adata, sprite_id);

    if (animation == NULL) {
        my_printf(get_error(adata, "unknown_id"));
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

    int end_plus = animation->pos.x >= (float) animation->width - 1 && !animation->reverse_state;
    int end_minus = animation->pos.x <= 0 && animation->reverse_state;

    if (end_plus || end_minus) animation->reverse_state = !animation->reverse_state;
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

void update_sprite_animation(s_appdata *adata, s_animation *animation, sfBool force)
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

void update_animations(s_appdata *adata)
{
    linked_node *animations = adata->lists->animations;

    while (animations != NULL && animations->data != NULL) {
        s_animation *cur = (s_animation *) animations->data;

        update_sprite_animation(adata, cur, sfFalse);

        animations = animations->next;
    }
}

void animate_sprite(s_appdata *adata, char *sprite_id)
{
    s_animation *animation = get_animation(adata, sprite_id);

    if (animation != NULL) return;

    s_sprite *sprite = get_sprite(adata, sprite_id);

    if (sprite == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    s_animation *new_animation = malloc(sizeof(s_animation));

    if (new_animation == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    const sfTexture *tex = sfSprite_getTexture(sprite->elem);
    sfVector2u size = sfTexture_getSize(tex);

    new_animation->anim_clock = sfClock_create();
    new_animation->base_size = (sfVector2f) { size.x, size.y };
    new_animation->clock_rate = 0.5f;
    new_animation->height = 1;
    new_animation->width = 1;
    new_animation->pos = (sfVector2f) { 0, 0 };
    new_animation->sprite = sprite;
    new_animation->reverse_state = 0;
    new_animation->mode = animation_restart;

    linked_add(adata->lists->animations, new_animation);
    update_sprite_animation(adata, new_animation, sfTrue);
}
