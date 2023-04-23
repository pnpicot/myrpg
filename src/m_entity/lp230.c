/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** LP230 Entity module
*/

#include "main.h"

void get_lp230_path(s_appdata *adata, s_entity *entity, sfVector2f *path)
{
    if (entity->move_now_entity != NULL) {
        (*path) = entity->move_now;
        entity->move_now = (sfVector2f){ 0, 0 };
    } else {
        s_game *game_data = adata->game_data;
        int win_w = get_int(adata, "win_w");
        int win_h = get_int(adata, "win_h");
        float tile_size = 32 * get_float(adata, "zoom");
        sfVector2f player_pos;
        float update_rate = get_float(adata, "path_update");
        player_pos.x = (game_data->view_pos.x + (win_w / 2)) / tile_size;
        player_pos.y = (game_data->view_pos.y + (win_h / 2)) / tile_size;
        if (get_clock_seconds(entity->path_clock) > update_rate) {
            (*path) = actualize_path(adata, entity, fvec_to_i(player_pos));
            sfClock_restart(entity->path_clock);
        } else {
            (*path) = get_way(adata, entity, fvec_to_i(player_pos));
        }
    }
}

void behavior_lp230_next(s_appdata *adata, s_entity *entity, sfVector2f path, \
float *angle)
{
    float seconds = get_clock_seconds(adata->clocks->update_clock);
    s_entity_part *body = (s_entity_part *) linked_get(entity->parts, 2)->data;
    if (!entity->inhabited) {
        sfVector2f add = { path.x * seconds * entity->speed,
            path.y * seconds * entity->speed };
        add = is_map_colliding(adata, entity, add);
        (*angle) = (atan2f(add.y, add.x) * (180.0f / M_PI)) + 90.0f;
        translate_entity(adata, entity, add);
    } else {
        (*angle) = sfSprite_getRotation(body->sprite->elem);
    }
    if (entity->move_now_entity != NULL) {
        entity->move_now.x = 0;
        entity->move_now.y = 0;
        entity->move_now_entity = NULL;
        (*angle) = sfSprite_getRotation(body->sprite->elem);
    }
}

void behavior_lp230_legs(s_appdata *adata, s_entity *entity, float angle)
{
    float leg_cycle = get_entity_float(entity, "leg_cycle")->value;
    float leg_rot = get_entity_float(entity, "leg_rot")->value;
    int walking = get_key(adata, sfKeyQ) || get_key(adata, sfKeyZ)
    || get_key(adata, sfKeyD) || get_key(adata, sfKeyS);
    if (!entity->inhabited || walking) {
        if (leg_cycle) {
            add_to_entity_float(adata, entity, "leg_rot", entity->speed);
            rotate_entity_part_abs(adata, entity, "lpleg1", angle - leg_rot);
            rotate_entity_part_abs(adata, entity, "lpleg2", angle + leg_rot);
        } else {
            add_to_entity_float(adata, entity, "leg_rot", -entity->speed);
            rotate_entity_part_abs(adata, entity, "lpleg1", angle - leg_rot);
            rotate_entity_part_abs(adata, entity, "lpleg2", angle + leg_rot);
        }
        if ((leg_rot > 40.0f && leg_cycle)
            || (leg_rot < -40.0f && !leg_cycle)) {
            set_entity_float(adata, entity, "cycle", leg_cycle > 0 ? 0 : 1.0f);
        }
    }
}

void behavior_lp230_canon(s_appdata *adata, s_entity *entity, \
s_entity_part *body, float angle)
{
    if (entity->inhabited) {
        sfVector2f mouse_offset;
        sfVector2f mouse = get_mouse(adata);
        sfFloatRect abs_bounds = sfSprite_getGlobalBounds(body->sprite->elem);
        mouse_offset.x = mouse.x - (abs_bounds.left + (abs_bounds.width / 2));
        mouse_offset.y = mouse.y - (abs_bounds.top + (abs_bounds.height / 2));
        float mouse_angle = (atan2f(mouse_offset.y, mouse_offset.x)
            * (180.0f / M_PI)) + 90.0f;
        rotate_entity_part_abs(adata, entity, "lp230_canon", mouse_angle);
    } else {
        rotate_entity_part_abs(adata, entity, "lp230_canon", angle);
    }
}

void behavior_lp230(s_appdata *adata, s_entity *entity)
{
    update_entity_bar(adata, entity);
    sfVector2f path = { 0, 0 };
    get_lp230_path(adata, entity, &path);
    if (entity->init) {
        add_entity_float(adata, entity, "cycle", 0);
        add_entity_float(adata, entity, "leg_rot", 0);
        entity->init = sfFalse;
    }
    float angle;
    s_entity_part *body = (s_entity_part *) linked_get(entity->parts, 2)->data;
    behavior_lp230_next(adata, entity, path, &angle);
    rotate_entity_part_abs(adata, entity, "lp230_body", angle);
    behavior_lp230_legs(adata, entity, angle);
    behavior_lp230_canon(adata, entity, body, angle);
    sfClock_restart(entity->clock);
}
