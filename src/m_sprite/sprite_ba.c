/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Sprite module
*/

#include "../include/main.h"

s_sprite *get_sprite(s_appdata *adata, char *id)
{
    linked_node *sprites = adata->lists->sprites;

    while (sprites != NULL && sprites->data != NULL) {
        s_sprite *cur = (s_sprite *) sprites->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        sprites = sprites->next;
    }

    return (NULL);
}

void delete_sprite(s_appdata *adata, char *id)
{
    s_sprite *sprite = get_sprite(adata, id);
    if (sprite == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }
    linked_node *sprites = adata->lists->sprites;
    int ite = 0;
    while (sprites != NULL && sprites->data != NULL) {
        s_sprite *cur = (s_sprite *) sprites->data;
        if (!my_strcmp(cur->id, id)) {
            sfSprite_destroy(cur->elem);
            break;
        }
        ite++;
        sprites = sprites->next;
    }
    linked_delete(&adata->lists->sprites, ite);
}

void add_sprite_next(s_appdata *adata, char *id, \
int layer, s_sprite *new_sprite)
{
    s_ints *integers = adata->integers;
    new_sprite->active = 1;
    new_sprite->elem = sfSprite_create();
    new_sprite->texture = NULL;
    new_sprite->hidden = 0;
    new_sprite->rtex_id = NULL;
    new_sprite->id = id;
    new_sprite->layer = layer;
    new_sprite->pos = (sfVector2f) { 0, 0 };
    if (layer < integers->min_layer) integers->min_layer = layer;
    if (layer > integers->max_layer) integers->max_layer = layer;
    linked_add(adata->lists->sprites, new_sprite);
}

void add_sprite(s_appdata *adata, char *id, int layer)
{
    s_sprite *sprite = get_sprite(adata, id);
    if (sprite != NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "already_exists"));
        return;
    }
    s_sprite *new_sprite = malloc(sizeof(s_sprite));
    if (new_sprite == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "mem_alloc"));
        return;
    }
    *new_sprite = (s_sprite){0};
    add_sprite_next(adata, id, layer, new_sprite);
}

void set_sprite_texture(s_appdata *adata, char *id, sfTexture *texture)
{
    s_sprite *sprite = get_sprite(adata, id);

    if (sprite == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    sprite->texture = texture;
    sfSprite_setTexture(sprite->elem, sprite->texture, sfTrue);
}
