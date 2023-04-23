/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** NPC Module
*/

#include "main.h"

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
}

void init_npc_text(s_appdata *adata, sfVector2f npc_pos)
{
    char *npc_id = get_str(adata, "npc_tuto");
    char *id = str_add(npc_id, "@[:rect]");
    char *rtex = get_str(adata, "rtex_game");
    char *container = get_str(adata, "ctn_game");

    add_text(adata, id, 6);
    set_text_rtex(adata, id, rtex);

    s_ref ref = { get_text(adata, id), TYPE_TEXT };

    add_to_container(adata, container, ref);
    set_text_font(adata, id, get_font(adata, "courier"));
    resize_text(adata, id, 22);
    color_text(adata, id, sfWhite);
    edit_text(adata, id, "Nique ta mere");

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
}

void init_npc(s_appdata *adata)
{
    char *id = get_str(adata, "npc_tuto");
    char *rtex = get_str(adata, "rtex_game");
    char *container = get_str(adata, "ctn_game");

    add_sprite(adata, id, 5);
    set_sprite_rtex(adata, id, rtex);

    s_ref ref = { get_sprite(adata, id), TYPE_SPRITE };

    add_to_container(adata, container, ref);
    set_sprite_texture(adata, id, get_texture(adata, "parasite"));
    set_sprite_origin(adata, id, (sfVector2f) { 24, 24 });
    animate_sprite(adata, id);
    set_animation_rows(adata, id, 1);
    set_animation_cols(adata, id, 7);
    set_animation_speed(adata, id, 3.0f);
    scale_sprite(adata, id, (sfVector2f) { 4.0f, 4.0f });
    rotate_sprite(adata, id, 90.0f);
    set_sprite_color(adata, id, sfCyan);

    sfVector2f pos;
    pos.x = 32 * get_float(adata, "zoom") * 15;
    pos.y = 32 * get_float(adata, "zoom") * 13;

    move_sprite(adata, id, pos);

    char *obj_id = str_add(id, "@[:object]");

    add_gameobject(adata, id);
    set_gameobject_ref(adata, id, ref.ref, ref.type);
    init_npc_text(adata, pos);
}
