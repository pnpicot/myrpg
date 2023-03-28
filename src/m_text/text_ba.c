/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Text module
*/

#include "../include/main.h"

s_text *get_text(s_appdata *adata, char *id)
{
    linked_node *texts = adata->lists->texts;

    while (texts != NULL && texts->data != NULL) {
        s_text *cur = (s_text *) texts->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        texts = texts->next;
    }

    return (NULL);
}

void delete_text(s_appdata *adata, char *id)
{
    s_text *text = get_text(adata, id);
    if (text == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }
    linked_node *texts = adata->lists->texts;
    int ite = 0;
    while (texts != NULL && texts->data != NULL) {
        s_text *cur = (s_text *) texts->data;
        if (!my_strcmp(cur->id, id)) {
            sfText_destroy(cur->elem);
            break;
        }
        ite++;
        texts = texts->next;
    }
    linked_delete(&adata->lists->texts, ite);
}

void add_text(s_appdata *adata, char *id, int layer)
{
    s_text *text = get_text(adata, id);
    if (text != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }
    s_text *new_text = malloc(sizeof(s_text));
    if (new_text == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }
    s_ints *integers = adata->integers;
    new_text->active = 1;
    new_text->elem = sfText_create();
    new_text->hidden = 0;
    new_text->id = id;
    new_text->rtex_id = NULL;
    new_text->layer = layer;
    new_text->pos = (sfVector2f) { 0, 0 };
    if (layer < integers->min_layer) integers->min_layer = layer;
    if (layer > integers->max_layer) integers->max_layer = layer;
    linked_add(adata->lists->texts, new_text);
}

void set_text_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_text *text = get_text(adata, id);
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (text == NULL || rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    text->rtex_id = rtex_id;
}

void set_text_active(s_appdata *adata, char *id, sfUint8 active)
{
    s_text *text = get_text(adata, id);

    if (text == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    text->active = active;
}
