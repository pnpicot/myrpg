/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** State module
*/

#include "main.h"

s_state *get_state(s_appdata *adata, char *id)
{
    linked_node *states = adata->lists->states;

    while (states != NULL && states->data != NULL) {
        s_state *cur = (s_state *) states->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        states = states->next;
    }

    return (NULL);
}

void delete_state(s_appdata *adata, char *id)
{
    s_state *state = get_state(adata, id);

    if (state == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *states = adata->lists->states;
    int ite = 0;

    while (states != NULL && states->data != NULL) {
        s_state *cur = (s_state *) states->data;

        if (!my_strcmp(cur->id, id)) break;

        ite++;
        states = states->next;
    }

    linked_delete(&adata->lists->states, ite);
}

void add_state(s_appdata *adata, char *id)
{
    s_state *state = get_state(adata, id);

    if (state != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    s_state *new_state = malloc(sizeof(s_state));

    if (new_state == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    new_state->id = id;
    new_state->container = NULL;
    new_state->in_game = sfFalse;
    new_state->rtexs = NULL;
}
