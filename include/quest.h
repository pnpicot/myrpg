/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Quest module
*/

#pragma once

#include "main.h"

s_quest *get_quest(s_appdata *adata, char *id);
void delete_quest(s_appdata *adata, char *id);
void add_quest(s_appdata *adata, char *id);
void set_quest_completed(s_appdata *adata, char *id, sfBool completed);
void set_quest_check(s_appdata *adata, char *id, \
void (*completion_check)(s_appdata *adata, s_quest *quest));
void set_quest_title(s_appdata *adata, char *id, char *title);
void set_quest_text(s_appdata *adata, char *id, char *text);
void set_quest_icon(s_appdata *adata, char *id, sfTexture *texture);
void update_quest_ui(s_appdata *adata, s_quest *quest);
void check_first_quest(s_appdata *adata, s_quest *quest);
void init_quets_n(s_appdata *adata);
void init_quests(s_appdata *adata);
void init_quest_item_icon_n(s_appdata *adata, s_quest *cur);
void init_quest_item_icon(s_appdata *adata, s_quest *cur, \
sfVector2f item_size, sfVector2f item_pos);
s_text *get_quest_popup_text_n(s_appdata *adata, s_quest *cur);
s_text *get_quest_popup_text(s_appdata *adata, s_quest *cur, \
sfVector2f bg_size, sfVector2f bg_pos);
void get_quest_popup_rect_n(s_appdata *adata, s_quest *cur, sfVector2f size,
sfFloatRect bounds);
s_rect *get_quest_popup_rect(s_appdata *adata, s_quest *cur);
void toggle_quest(s_appdata *adata, s_ref *ref);
void init_quest_item_object(s_appdata *adata, char *id, s_ref ref);
void init_quest_item_next(s_appdata *adata, s_tmp_questitem tmp);
void init_quest_items(s_appdata *adata, char *bg_id, sfVector2f bg_size,
sfVector2f bg_pos);
void init_quest_title_n(s_appdata *adata, char *bg_id, sfVector2f bg_size,
sfVector2f bg_pos);
void init_quest_title(s_appdata *adata, char *bg_id, sfVector2f bg_size,
sfVector2f bg_pos);
void init_quest_ui_n(s_appdata *adata, char *id);
void init_quest_ui(s_appdata *adata);
void update_quests(s_appdata *adata);
