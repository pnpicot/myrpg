/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Settings ui module
*/

#pragma once

#include "main.h"

void init_live_settings_menu(s_appdata *adata);
void init_live_load_menu(s_appdata *adata);
void init_load_input(s_appdata *adata, char *container, char *rtex);
void trigger_settings_backbtn(s_appdata *adata, s_ref *ref);
void trigger_settings_vol(s_appdata *adata, s_ref *ref);
void init_settings_backbtn(s_appdata *adata, char *container, char *rtex);
void init_load_backbtn(s_appdata *adata, char *container, char *rtex);
void init_settings_volumebtn(s_appdata *adata, char *container, char *rtex);
void trigger_settings_fullscreen(s_appdata *adata, s_ref *ref);
void init_settings_fullscreenbtn_n(s_appdata *adata, char *fullscreen_button);
void init_settings_fullscrenbtn(s_appdata *adata, char *container, char *rtex);
void init_settings_volumetxt(s_appdata *adata, char *container, char *rtex);
