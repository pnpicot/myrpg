/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Main menu module
*/

#include "main.h"

void trigger_playbtn(s_appdata *adata, s_ref *ref)
{
    switch_state(adata, get_str(adata, "state_game"));
    set_container_active(adata, get_str(adata, "ctn_inv"), 0);
    show_quests(adata, NULL);
    set_container_active(adata, get_str(adata, "ctn_skill"), 0);
    set_rect_active(adata, get_str(adata, "skill_tree"), 0);
    set_text_active(adata, str_add(get_str(adata, "skill_tree"),
    "@[:title]"), 0);
}

void trigger_settingsbtn(s_appdata *adata, s_ref *ref)
{
    switch_state(adata, get_str(adata, "state_settings"));
}

void trigger_quitbtn(s_appdata *adata, s_ref *ref)
{
    close_window(adata);
}

void trigger_savebtn(s_appdata *adata, s_ref *ref)
{
    save_game(adata);
}

void trigger_loadbtn(s_appdata *adata, s_ref *ref)
{
    switch_state(adata, get_str(adata, "state_load"));
}
