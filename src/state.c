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

void set_state_container(s_appdata *adata, char *id, s_container *container)
{
    s_state *state = get_state(adata, id);

    if (state == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    state->container = container;
}

void add_state_rtex(s_appdata *adata, char *id, s_rtex *rtex)
{
    s_state *state = get_state(adata, id);

    if (state == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_add(state->rtexs, rtex);
}

void set_state_ingame(s_appdata *adata, char *id, sfBool in_game)
{
    s_state *state = get_state(adata, id);

    if (state == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    state->in_game = in_game;
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
    new_state->rtexs = linked_new();

    linked_add(adata->lists->states, new_state);
}

void switch_state(s_appdata *adata, char *id)
{
    s_state *state = get_state(adata, id);

    if (state == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    if (adata->current_state != NULL) {
        s_state *cur = adata->current_state;

        if (cur->container != NULL)
            set_container_active(adata, cur->container->id, 0);

        linked_node *rtexs = cur->rtexs;

        while (rtexs != NULL && rtexs->data != NULL) {
            s_rtex *cur_rtex = (s_rtex *) rtexs->data;

            cur_rtex->active = sfFalse;

            rtexs = rtexs->next;
        }
    }

    if (state->container != NULL)
        set_container_active(adata, state->container->id, 1);

    linked_node *rtexs = state->rtexs;

    while (rtexs != NULL && rtexs->data != NULL) {
        s_rtex *cur = (s_rtex *) rtexs->data;

        cur->active = sfTrue;

        rtexs = rtexs->next;
    }

    s_ints *integers = adata->integers;

    adata->current_state = state;

    if (state->in_game && get_int(adata, "enable_shader")) {
        linked_node *l_rtexs = adata->lists->rtexs;

        integers->in_game = 1;

        while (l_rtexs != NULL && l_rtexs->data != NULL) {
            s_rtex *cur = (s_rtex *) l_rtexs->data;
            int light_defined = adata->mask_rtex != NULL && adata->light_blend_rtex != NULL;

            if (light_defined && (cur->depth < adata->mask_rtex->depth || cur->depth > adata->light_blend_rtex->depth)) {
                l_rtexs = l_rtexs->next;
                continue;
            }

            cur->active = sfTrue;
            l_rtexs = l_rtexs->next;
        }
    }

    if (!state->in_game) integers->in_game = 0;
}
