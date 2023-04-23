/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Main menu module
*/

#pragma once

#include "main.h"

void init_live_main_menu(s_appdata *adata);
void trigger_playbtn(s_appdata *adata, s_ref *ref);
void trigger_settingsbtn(s_appdata *adata, s_ref *ref);
void trigger_quitbtn(s_appdata *adata, s_ref *ref);
void trigger_savebtn(s_appdata *adata, s_ref *ref);
void trigger_loadbtn(s_appdata *adata, s_ref *ref);
void init_main_quitbtn(s_appdata *adata, char *container, char *rtex);
void init_main_settingsbtn(s_appdata *adata, char *container, char *rtex);
void init_main_playbtn(s_appdata *adata, char *container, char *rtex);
void init_main_savebtn(s_appdata *adata, char *container, char *rtex);
void init_main_loadbtn(s_appdata *adata, char *container, char *rtex);
