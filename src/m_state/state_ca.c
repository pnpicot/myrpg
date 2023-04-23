/*
** EPITECH PROJECT, 2023
** m_state
** File description:
** state_ca
*/

#include "main.h"

void switch_state(s_appdata *adata, char *id)
{
    s_state *state = get_state(adata, id);

    if (state == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    state_deactivate_all(adata);
    switch_state_activate(adata, state);
    switch_state_rtex(adata, state);

    if (!state->in_game) adata->integers->in_game = 0;
}
