/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** In-game ui module
*/

#include "main.h"

void init_ingame_waves(s_appdata *adata, char *container, char *rtex)
{
    char *id = get_str(adata, "wave_count");
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");

    add_text(adata, id, 3);
    set_text_rtex(adata, id, rtex);

    s_ref ref = { get_text(adata, id), TYPE_TEXT };

    add_to_container(adata, container, ref);
    set_text_font(adata, id, get_font(adata, "lobster"));
    color_text(adata, id, sfCyan);
    edit_text(adata, id, "wave 1");
    resize_text(adata, id, 34);
    sfFloatRect bounds = get_text_bounds(adata, id);
    sfVector2f pos;
    pos.x = win_w - bounds.width - 25.0f;
    pos.y = win_h - bounds.height - 20.0f;
    move_text(adata, id, pos);
}

void init_stats_title(s_appdata *adata, char *container, char *rtex,
char *rect_id)
{
    char *id = str_add(rect_id, "@[:title]");
    sfFloatRect rect = get_sprite_bounds(adata, rect_id);

    add_text(adata, id, 2);
    edit_text(adata, id, "STATS");
    set_text_font(adata, id, get_font(adata, "courier"));
    set_text_rtex(adata, id, rtex);
    add_to_container(adata, container,
    (s_ref) { get_text(adata, id), TYPE_TEXT });
    color_text(adata, id, sfWhite);
    resize_text(adata, id, 22);
    sfFloatRect bounds = get_text_bounds(adata, id);
    set_text_origin(adata, id,
    (sfVector2f) { bounds.width / 2, bounds.height / 2 });
    sfVector2f pos;
    pos.x = rect.left + (rect.width / 2);
    pos.y = rect.top + 18;
    move_text(adata, id, pos);
}

void init_stats_health(s_appdata *adata, char *container, char *rtex,
char *rect_id)
{
    char *id = str_add(rect_id, "@[:health]");
    sfFloatRect rect = get_sprite_bounds(adata, rect_id);
    s_player *player = adata->player;

    add_bar(adata, id, 2);
    set_bar_rtex(adata, id, rtex);
    set_bar_min(adata, id, 0);
    set_bar_max(adata, id, player->health.y);
    set_bar_current(adata, id, player->health.x);

    sfVector2f pos;
    pos.x = rect.left + 30.0f;
    pos.y = rect.top + 55.0f;

    move_bar(adata, id, pos);
    color_bar(adata, id, get_color(130, 21, 9, 255), sfGreen);
    resize_bar(adata, id, (sfVector2f) { rect.width - 60.0f, 10.0f });
}

void init_stats_transference(s_appdata *adata, char *container, char *rtex,
char *rect_id)
{
    char *id = str_add(rect_id, "@[:transference]");
    sfFloatRect rect = get_sprite_bounds(adata, rect_id);
    s_player *player = adata->player;

    add_bar(adata, id, 2);
    set_bar_rtex(adata, id, rtex);
    set_bar_min(adata, id, 0);
    set_bar_max(adata, id, player->transference.y);
    set_bar_current(adata, id, player->transference.x);

    sfVector2f pos;
    pos.x = rect.left + 30.0f;
    pos.y = rect.top + 75.0f;

    move_bar(adata, id, pos);
    color_bar(adata, id, sfDarkGray, sfWhite);
    resize_bar(adata, id, (sfVector2f) { rect.width - 60.0f, 10.0f });
}

void init_stats_text(s_appdata *adata, char *container, char *rtex,
char *rect_id)
{
    char *id = str_add(rect_id, "@[:text]");
    sfFloatRect rect = get_sprite_bounds(adata, rect_id);
    s_player *player = adata->player;

    add_text(adata, id, 2);
    set_text_font(adata, id, get_font(adata, "courier"));
    color_text(adata, id, sfWhite);
    resize_text(adata, id, 18);
    set_text_rtex(adata, id, rtex);
    add_to_container(adata, container, (s_ref) { get_text(adata, id),
    TYPE_TEXT });
    edit_text(adata, id, "5 Atk / 2 Def / Trans. LV. 1");

    sfVector2f pos;
    pos.x = rect.left + 30.0f;
    pos.y = rect.top + 90.0f;

    move_text(adata, id, pos);

    player->stats = get_text(adata, id);
}
