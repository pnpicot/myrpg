/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Switch module
*/

#pragma once

#include "main.h"

s_switch *get_switch(s_appdata *adata, char *id);
s_button *get_switch_left(s_appdata *adata, char *id, int layer);
s_button *get_switch_right(s_appdata *adata, char *id, int layer);
s_button *get_switch_middle(s_appdata *adata, char *id, int layer);
s_button *get_switch_indicator(s_appdata *adata, char *id, int layer);
void update_switch(s_appdata *adata, s_switch *switch_);
void add_switch(s_appdata *adata, char *id, int layer);
void set_switch_rtex(s_appdata *adata, char *id, char *rtex_id);
void set_switch_ontoggle(s_appdata *adata, char *id, void (*on_toggle)(s_appdata *adata, s_ref *ref));
void toggle_switch(s_appdata *adata, char *id);
sfBool get_switch_state(s_appdata *adata, char *id);
void delete_switch(s_appdata *adata, char *id);
void move_switch(s_appdata *adata, char *id, sfVector2f pos);
void translate_switch(s_appdata *adata, char *id, sfVector2f pos_ch);
void set_switch_active(s_appdata *adata, char *id, sfUint8 active);
void set_switch_origin(s_appdata *adata, char *id, sfVector2f origin);
sfVector2f get_switch_pos(s_appdata *adata, char *id);
sfVector2f get_switch_origin(s_appdata *adata, char *id);
