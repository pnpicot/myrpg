/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** State module
*/

#include "../include/main.h"

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
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
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

void set_state_container(s_appdata *adata, char *id, s_container *container)
{
    s_state *state = get_state(adata, id);

    if (state == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    state->container = container;
}

void add_state_rtex(s_appdata *adata, char *id, s_rtex *rtex)
{
    s_state *state = get_state(adata, id);

    if (state == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    linked_add(state->rtexs, rtex);
}

void set_state_ingame(s_appdata *adata, char *id, sfBool in_game)
{
    s_state *state = get_state(adata, id);

    if (state == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    state->in_game = in_game;
}
