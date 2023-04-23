/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Gameover module
*/

#include "main.h"

void init_gameover(s_appdata *adata)
{
    char *rtex = "rtex_gameover";
    char *ctn = "ctn_gameover";
    char *state = "state_gameover";

    add_rtex(adata, rtex, 15);
    set_rtex_blendmode(adata, rtex, sfBlendNone);
    set_rtex_clear(adata, rtex, sfBlack);
    add_container(adata, ctn);
    add_state(adata, state);
    set_state_container(adata, state, get_container(adata, ctn));
    add_state_rtex(adata, state, get_rtex(adata, rtex));
    init_gameover_text(adata, rtex, ctn);
}
