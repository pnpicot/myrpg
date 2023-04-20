/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Animation module
*/

#include "../include/main.h"

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
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    animation->clock_rate = speed;
    update_sprite_animation(adata, animation, sfTrue);
}

void set_animation_rows(s_appdata *adata, char *sprite_id, int row_count)
{
    s_animation *animation = get_animation(adata, sprite_id);

    if (animation == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    animation->height = row_count;
    update_sprite_animation(adata, animation, sfTrue);
}

void set_animation_cols(s_appdata *adata, char *sprite_id, int col_count)
{
    s_animation *animation = get_animation(adata, sprite_id);

    if (animation == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    animation->width = col_count;
    update_sprite_animation(adata, animation, sfTrue);
}

void shift_animation_row(s_appdata *adata, char *sprite_id, int row_index)
{
    s_animation *animation = get_animation(adata, sprite_id);

    if (animation == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    animation->pos.y = row_index;
    update_sprite_animation(adata, animation, sfTrue);
}
