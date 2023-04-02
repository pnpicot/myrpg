/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** State module
*/

#include "../include/main.h"

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

void switch_state_deactivate(s_appdata *adata)
{
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
}

void switch_state_activate(s_appdata *adata, s_state *state)
{
    if (state->container != NULL)
        set_container_active(adata, state->container->id, 1);

    linked_node *rtexs = state->rtexs;

    while (rtexs != NULL && rtexs->data != NULL) {
        s_rtex *cur = (s_rtex *) rtexs->data;

        cur->active = sfTrue;

        rtexs = rtexs->next;
    }

    adata->current_state = state;
    if (state->in_game) adata->integers->in_game = 1;
}

void switch_state_rtex(s_appdata *adata, s_state *state)
{
    if (!state->in_game || !get_int(adata, "enable_shader")) return;
    s_ints *integers = adata->integers;
    linked_node *l_rtexs = adata->lists->rtexs;
    s_rtex *mask_rtex = adata->mask_rtex;
    s_rtex *light_blend = adata->light_blend_rtex;
    while (l_rtexs != NULL && l_rtexs->data != NULL) {
        s_rtex *cur = (s_rtex *) l_rtexs->data;
        int light_defined = mask_rtex != NULL && light_blend != NULL;
        int over_mask = cur->depth < mask_rtex->depth;
        int below_res = cur->depth > light_blend->depth;
        int in_light = over_mask || below_res;
        if (light_defined && in_light) {
            l_rtexs = l_rtexs->next;
            continue;
        }
        cur->active = sfTrue;
        l_rtexs = l_rtexs->next;
    }
}

void switch_state(s_appdata *adata, char *id)
{
    s_state *state = get_state(adata, id);

    if (state == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    switch_state_deactivate(adata);
    switch_state_activate(adata, state);
    switch_state_rtex(adata, state);

    if (!state->in_game) adata->integers->in_game = 0;
}
