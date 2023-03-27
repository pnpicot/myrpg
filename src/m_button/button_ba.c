/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Button module
*/

#include "../include/main.h"

s_button *get_button(s_appdata *adata, char *id)
{
    linked_node *buttons = adata->lists->buttons;

    while (buttons != NULL && buttons->data != NULL) {
        s_button *cur = (s_button *) buttons->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        buttons = buttons->next;
    }

    return (NULL);
}

void add_button_switch(s_appdata *adata, s_btn_next args, s_button *new_button)
{
    char *id = str_add(args.id, "@[:elem]");
    switch (args.type) {
        case TYPE_TEXT:
            {
            add_text(adata, id, args.layer);
            new_button->elem = get_ref(adata, get_text(adata, id), TYPE_TEXT);
            break;
            }
        case TYPE_VERTEX:
            {
            add_vertex(adata, id, args.layer);
            s_vertex *vertex = get_vertex(adata, id);
            new_button->elem = get_ref(adata, vertex, TYPE_VERTEX);
            }
    }
}

void add_button_next(s_appdata *adata, s_btn_next args, s_button *new_button)
{
    char *id = str_add(args.id, "@[:elem]");
    switch (args.type) {
        case TYPE_RECT:
            {
            add_rect(adata, id, args.layer);
            new_button->elem = get_ref(adata, get_rect(adata, id), TYPE_RECT);
            break;
            }
        case TYPE_CIRCLE:
            {
            add_circle(adata, id, args.layer);
            s_circle *circle = get_circle(adata, id);
            new_button->elem = get_ref(adata, circle, TYPE_CIRCLE);
            break;
            }
        case TYPE_SPRITE:
            {
            add_sprite(adata, id, args.layer);
            s_sprite *sprite = get_sprite(adata, id);
            new_button->elem = get_ref(adata, sprite, TYPE_SPRITE);
            break;
            }
        default:
            {
            add_button_switch(adata, args, new_button);
            }
    }
}

void add_button(s_appdata *adata, char *id, int type, int layer)
{
    s_button *button = get_button(adata, id);
    if (button != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }
    s_button *new_button = malloc(sizeof(s_button));
    if (new_button == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }
    new_button->id = id;
    char *text_id = str_add(id, "@[:text]");
    add_text(adata, text_id, layer);
    new_button->text = get_text(adata, text_id);
    add_button_next(adata, (s_btn_next) { type, layer, id }, new_button);
    linked_add(adata->lists->buttons, new_button);
}

void delete_button(s_appdata *adata, char *id)
{
    s_button *button = get_button(adata, id);
    if (button == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }
    linked_node *buttons = adata->lists->buttons;
    int ite = 0;
    while (buttons != NULL && buttons->data != NULL) {
        s_button *cur = (s_button *) buttons->data;
        if (!my_strcmp(cur->id, id)) {
            delete_element(adata, cur->elem->ref, cur->elem->type);
            delete_text(adata, cur->text->id);
            break;
        }
        ite++;
        buttons = buttons->next;
    }
    linked_delete(&adata->lists->buttons, ite);
}
