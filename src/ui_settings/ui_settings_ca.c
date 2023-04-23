/*
** EPITECH PROJECT, 2023
** src
** File description:
** ui_settings_ca
*/

#include "main.h"

void init_live_load_menu(s_appdata *adata)
{
    char *container = get_str(adata, "ctn_load");
    char *rtex = get_str(adata, "rtex_load");

    init_load_backbtn(adata, container, rtex);
    init_load_input(adata, container, rtex);
    init_load_btn(adata, container, rtex);
}

void change_volume(s_appdata *adata, s_ref *ref)
{
    s_slider *slider = (s_slider *) ref->ref;
    float value = (float) slider->current;
    set_music_volume(adata, "music", value);
}
