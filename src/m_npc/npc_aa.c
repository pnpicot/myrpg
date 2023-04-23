/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** NPC Module
*/

#include "main.h"

void init_npc_texts(s_appdata *adata)
{
    s_game *game_data = adata->game_data;

    linked_add(game_data->npc_text, "Bonjourzdqdzqdqdqd");
    linked_add(game_data->npc_text, "eazeaeaeaze");
    linked_add(game_data->npc_text, "vffergeteterter");
    linked_add(game_data->npc_text, "kikululuikkkuku");
    linked_add(game_data->npc_text, "wxcxwqdaeazruty");
    linked_add(game_data->npc_text, "oooooooooooooooooo");
    linked_add(game_data->npc_text, "zeazeazeaz");
}

void init_npc_next(s_appdata *adata, char *id)
{
    set_sprite_texture(adata, id, get_texture(adata, "parasite"));
    set_sprite_origin(adata, id, (sfVector2f) { 24, 24 });
    animate_sprite(adata, id);
    set_animation_rows(adata, id, 1);
    set_animation_cols(adata, id, 7);
    set_animation_speed(adata, id, 3.0f);
    scale_sprite(adata, id, (sfVector2f) { 4.0f, 4.0f });
    rotate_sprite(adata, id, 90.0f);
    set_sprite_color(adata, id, sfCyan);
}

void init_npc(s_appdata *adata)
{
    char *id = get_str(adata, "npc_tuto");
    char *rtex = get_str(adata, "rtex_game");
    char *container = get_str(adata, "ctn_game");
    init_npc_texts(adata);
    add_sprite(adata, id, 5);
    set_sprite_rtex(adata, id, rtex);
    s_ref ref = { get_sprite(adata, id), TYPE_SPRITE };
    add_to_container(adata, container, ref);
    init_npc_next(adata, id);
    sfVector2f pos;
    pos.x = 32 * get_float(adata, "zoom") * 15;
    pos.y = 32 * get_float(adata, "zoom") * 13;
    move_sprite(adata, id, pos);
    char *obj_id = str_add(id, "@[:object]");
    add_gameobject(adata, id);
    set_gameobject_ref(adata, id, ref.ref, ref.type);
    init_npc_text(adata, pos);
}
