/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Animation module
*/

#include "../include/main.h"

void update_animations(s_appdata *adata)
{
    linked_node *animations = adata->lists->animations;

    while (animations != NULL && animations->data != NULL) {
        s_animation *cur = (s_animation *) animations->data;

        if (!cur->active) {
            animations = animations->next;
            continue;
        }

        update_sprite_animation(adata, cur, sfFalse);

        animations = animations->next;
    }
}

void animate_sprite_next(s_appdata *adata, s_animation *new_animation, \
s_sprite *sprite)
{
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
    new_animation->active = sfTrue;

    linked_add(adata->lists->animations, new_animation);
    update_sprite_animation(adata, new_animation, sfTrue);
}

void animate_sprite(s_appdata *adata, char *sprite_id)
{
    s_animation *animation = get_animation(adata, sprite_id);

    if (animation != NULL) return;

    s_sprite *sprite = get_sprite(adata, sprite_id);

    if (sprite == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    s_animation *new_animation = malloc(sizeof(s_animation));

    if (new_animation == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "mem_alloc"));
        return;
    }

    animate_sprite_next(adata, new_animation, sprite);
}

void pause_animation(s_appdata *adata, char *sprite_id)
{
    s_animation *animation = get_animation(adata, sprite_id);

    if (animation == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    animation->active = sfFalse;
}

void start_animation(s_appdata *adata, char *sprite_id)
{
    s_animation *animation = get_animation(adata, sprite_id);

    if (animation == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    animation->active = sfTrue;
}
