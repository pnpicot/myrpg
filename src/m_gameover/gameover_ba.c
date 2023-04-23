/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Gameover module
*/

#include "main.h"

void trigger_respawn_next(s_appdata *adata)
{
    s_player *player = adata->player;
    s_game *game_data = adata->game_data;
    player->moula = 3000;
    player->attack = 5.0f;
    player->defense = 0;
    player->health = (sfVector2f) { 1000, 1000 };
    player->transference_level = 1;
    linked_node *trees = game_data->skill_trees;
    while (trees != NULL && trees->data != NULL) {
        s_skill_tree *cur = (s_skill_tree *) trees->data;
        linked_node *nodes = cur->nodes;
        while (nodes != NULL && nodes->data != NULL) {
            s_skill_node *cur_node = (s_skill_node *) nodes->data;
            cur_node->unlocked = !cur_node->level;
            set_sprite_color(adata, cur_node->node_sprite->id,
                cur_node->level ? sfRed : sfWhite);
            nodes = nodes->next;
        }
        trees = trees->next;
    }
}

void trigger_respawn(s_appdata *adata, s_ref *ref)
{
    trigger_playbtn(adata, NULL);
    s_game *game_data = adata->game_data;
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    sfVector2f pos_ch;
    pos_ch.x = -game_data->view_pos.x + (win_w / 2);
    pos_ch.y = -game_data->view_pos.y + (win_h / 2);
    trigger_respawn_next(adata);
    translate_player(adata, pos_ch);
}

void init_gameover_button_next(s_appdata *adata, char *id)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    sfVector2f size = { 350, 60 };
    sfVector2f origin = { size.x / 2, size.y / 2 };
    sfVector2f pos = { win_w / 2, (win_h / 2) + 30.0f };
    resize_button(adata, id, size);
    set_button_origin(adata, id, origin);
    move_button(adata, id, pos);
    set_button_font(adata, id, get_font(adata, "lobster"));
    color_button_fg(adata, id, sfWhite);
    color_button_bg(adata, id, sfBlack);
    set_button_out(adata, id, sfWhite, 2.0f);
}

void init_gameover_button(s_appdata *adata, char *rtex, char *ctn)
{
    char *id = "gameover_button";
    add_button(adata, id, TYPE_RECT, 2);
    edit_button(adata, id, "Respawn");
    set_button_rtex(adata, id, rtex);
    s_ref ref = { get_button(adata, id), TYPE_BUTTON };
    add_to_container(adata, ctn, ref);
    init_gameover_button_next(adata, id);
    char *obj_id = str_add(id, "@[:object]");
    add_object(adata, obj_id, ref);
    set_object_hover_bg(adata, obj_id, get_color(15, 15, 15, 255));
    set_object_pressed_bg(adata, obj_id, get_color(30, 30, 30, 255));
    set_object_onclick(adata, obj_id, &trigger_respawn);
}

void init_gameover_text(s_appdata *adata, char *rtex, char *ctn)
{
    char *id = "gameover_text";
    add_text(adata, id, 1);
    set_text_rtex(adata, id, rtex);
    s_ref ref = { get_text(adata, id), TYPE_TEXT };
    add_to_container(adata, ctn, ref);
    set_text_font(adata, id, get_font(adata, "lobster"));
    color_text(adata, id, sfWhite);
    edit_text(adata, id, "Game over");
    resize_text(adata, id, 50);
    sfFloatRect bounds = get_text_bounds(adata, id);
    sfVector2f origin = { bounds.width / 2, bounds.height / 2 };
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    set_text_origin(adata, id, origin);
    move_text(adata, id, (sfVector2f) { win_w / 2, (win_h / 2) - 80.0f });
    init_gameover_button(adata, rtex, ctn);
}
