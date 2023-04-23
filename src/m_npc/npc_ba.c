/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** NPC Module
*/

#include "main.h"

void update_npc_bubble(s_appdata *adata, char *text)
{
    char *id = get_str(adata, "npc_tuto");
    char *text_id = str_add(id, "@[:text]");
    char *rect_id = str_add(text_id, "@[:rect]");
    sfVector2f sprite_pos = get_sprite_pos(adata, id);
    edit_text(adata, text_id, text);
    sfFloatRect bounds = get_text_bounds(adata, text_id);
    sfVector2f origin = { bounds.width / 2, bounds.height / 2 };
    set_text_origin(adata, text_id, origin);
    bounds = get_text_bounds(adata, text_id);
    sfVector2f size;
    size.x = bounds.width + 20.0f;
    size.y = bounds.height + 20.0f;
    resize_rect(adata, rect_id, size);
    set_rect_origin(adata, rect_id, (sfVector2f) { size.x / 2, size.y / 2 });
}

void update_npc(s_appdata *adata)
{
    char *id = get_str(adata, "npc_tuto");
    s_sprite *npc = get_sprite(adata, id);
    sfVector2f pos = sfSprite_getPosition(npc->elem);
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    sfVector2f player_pos = { win_w / 2, win_h / 2 };
    s_game *game_data = adata->game_data;
    sfVector2f dist_vec;
    dist_vec.x = player_pos.x - pos.x;
    dist_vec.y = player_pos.y - pos.y;
    float angle = (atan2f(dist_vec.y, dist_vec.x) * (180.0f / M_PI)) + 90.0f;
    rotate_sprite(adata, id, angle);
    if (get_clock_seconds(game_data->npc_clock) >= 3.0f) {
        int text_count = linked_count(game_data->npc_text);
        char *text = (char *) linked_get(game_data->npc_text,
            rand_int(0, f_max(0, text_count - 1)))->data;
        update_npc_bubble(adata, text);
        sfClock_restart(game_data->npc_clock);
    }
}

void init_npc_rect(s_appdata *adata, char *text_id, \
char *rtex, char *container)
{
    char *id = str_add(text_id, "@[:rect]");
    sfFloatRect text_bounds = get_text_bounds(adata, text_id);
    sfVector2f text_pos = get_text_pos(adata, text_id);
    add_rect(adata, id, 6);
    set_rect_rtex(adata, id, rtex);
    s_ref ref = { get_rect(adata, id), TYPE_RECT };
    add_to_container(adata, id, ref);
    sfVector2f size;
    size.x = text_bounds.width + 20.0f;
    size.y = text_bounds.height + 20.0f;
    resize_rect(adata, id, size);
    set_rect_origin(adata, id, (sfVector2f) { size.x / 2, size.y / 2 });
    move_rect(adata, id, text_pos);
    color_rect(adata, id, get_color(0, 0, 0, 230));
    set_rect_outline(adata, id, sfWhite, 1.0f);
    char *obj_id = str_add(id, "@[:object]");
    add_gameobject(adata, obj_id);
    set_gameobject_ref(adata, obj_id, ref.ref, ref.type);
}

void init_npc_text_next(s_appdata *adata, char *id)
{
    set_text_font(adata, id, get_font(adata, "courier"));
    resize_text(adata, id, 22);
    color_text(adata, id, sfWhite);
    edit_text(adata, id, "");
}

void init_npc_text(s_appdata *adata, sfVector2f npc_pos)
{
    char *npc_id = get_str(adata, "npc_tuto");
    char *id = str_add(npc_id, "@[:text]");
    char *rtex = get_str(adata, "rtex_game");
    char *container = get_str(adata, "ctn_game");
    add_text(adata, id, 7);
    set_text_rtex(adata, id, rtex);
    s_ref ref = { get_text(adata, id), TYPE_TEXT };
    add_to_container(adata, container, ref);
    init_npc_text_next(adata, id);
    sfFloatRect bounds = get_text_bounds(adata, id);
    sfVector2f origin = { bounds.width / 2, bounds.height / 2 };
    sfVector2f pos;
    set_text_origin(adata, id, origin);
    pos.x = npc_pos.x;
    pos.y = npc_pos.y - 80.0f;
    move_text(adata, id, pos);
    char *obj_id = str_add(id, "@[:object]");
    add_gameobject(adata, obj_id);
    set_gameobject_ref(adata, obj_id, ref.ref, ref.type);
    init_npc_rect(adata, id, rtex, container);
}
