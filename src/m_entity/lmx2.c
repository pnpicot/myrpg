/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

void behavior_lmx2(s_appdata *adata, s_entity *entity)
{
    update_entity_bar(adata, entity);

    sfVector2f path = { 0.0f, 0.0f };
    s_game *game_data = adata->game_data;
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    float tile_size = 32 * get_float(adata, "zoom");
    sfVector2f player_pos;
    float update_rate = get_float(adata, "path_update");

    player_pos.x = (game_data->view_pos.x + (win_w / 2)) / tile_size;
    player_pos.y = (game_data->view_pos.y + (win_h / 2)) / tile_size;

    if (get_clock_seconds(entity->path_clock) > update_rate) {
        path = actualize_path(adata, entity, fvec_to_i(player_pos));
        sfClock_restart(entity->path_clock);
    } else {
        path = get_way(adata, entity, fvec_to_i(player_pos));
    }


    if (entity->init) {
        char *body_id = ((s_entity_part *) entity->parts->data)->sprite->id;

        animate_sprite(adata, body_id);
        set_animation_cols(adata, body_id, 4);
        set_animation_rows(adata, body_id, 1);
        set_animation_mode(adata, body_id, animation_restart);
        set_animation_speed(adata, body_id, 0.1f);

        entity->init = sfFalse;
    }

    if (entity->inhabited) return;

    float seconds = get_clock_seconds(entity->clock);

    sfVector2f add = { path.x * seconds * 100, path.y * seconds * 100};

    add = is_map_colliding(adata, entity, add);

    float angle = (atan2f(add.y, add.x) * (180.0f / M_PI)) + 90.0f;

    if (entity->move_now_entity != NULL) {
        entity->move_now.x = 0;
        entity->move_now.y = 0;
        entity->move_now_entity = NULL;
        angle = sfSprite_getRotation(((s_entity_part *) entity->parts->data)->sprite->elem);
    }

    translate_entity(adata, entity, add);
    rotate_entity_part_abs(adata, entity, "lmx2_body", angle);
    sfClock_restart(entity->clock);
}
