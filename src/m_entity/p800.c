/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

static void p800_damage_behavior(s_appdata *adata, s_entity *entity,
float angle)
{
    sfFloatRect hitbox = get_entity_hitbox(adata, entity);

    angle -= 90.0f;
    hitbox.left += cosf(angle * (M_PI / 180.0f)) * hitbox.width / 2;
    hitbox.top += sinf(angle * (M_PI / 180.0f)) * hitbox.height / 2;

    linked_node *touchs_ll = what_is_touching(adata, hitbox);
    linked_node *touchs = touchs_ll;

    while (touchs != NULL) {
        s_touch_t *touch = (s_touch_t *) touchs->data;
        int same_fac = touch->touch_type == TOUCH_ENTITY &&
            !my_strcmp(touch->entity->faction->id, entity->faction->id);
        if (touch->touch_type == TOUCH_ENTITY && touch->entity != entity && !same_fac) {
            touch->entity->hp -= entity->damage * (1 - touch->entity->defense) * 0.01f;
        }
        if (touch->touch_type == TOUCH_PARASITE) {
            adata->player->health.x -= entity->damage;
        }
        touchs = touchs->next;
    }
    free_ll_and_data(&touchs_ll);
}

void behavior_p800(s_appdata *adata, s_entity *entity)
{
    linked_node *parts = entity->parts;

    update_entity_bar(adata, entity);

    sfVector2f path = { 0, 0 };

    if (entity->move_now_entity != NULL) {
        path = entity->move_now;
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
        path = get_way(adata, entity, fvec_to_i(player_pos));

        if (get_clock_seconds(entity->path_clock) > update_rate) {
            free_ll_and_data(&entity->path);
            sfClock_restart(entity->path_clock);
        }
    }

    if (entity->init) {
        char *body_id = ((s_entity_part *) entity->parts->data)->sprite->id;

        add_entity_float(adata, entity, "blade_cycle", 0);
        add_entity_float(adata, entity, "blade_rot", 0);

        animate_sprite(adata, body_id);
        set_animation_cols(adata, body_id, 3);
        set_animation_rows(adata, body_id, 1);
        set_animation_mode(adata, body_id, animation_restart);
        set_animation_speed(adata, body_id, 0.01f);

        entity->init = sfFalse;
    }

    float seconds = get_clock_seconds(entity->clock);

    parts = parts->next;

    char *blade_id = ((s_entity_part *) parts->data)->sprite->id;
    float blade_cycle = get_entity_float(entity, "blade_cycle")->value;
    float blade_rot = get_entity_float(entity, "blade_rot")->value;
    float angle;


    if (!entity->inhabited) {
        sfVector2f add = { path.x * seconds * 100, path.y * seconds * 100 };

        add = is_map_colliding(adata, entity, add);
        angle = (atan2f(add.y, add.x) * (180.0f / M_PI)) + 90.0f;
        if ((entity->move_now.x != 0 && entity->move_now.y != 0) ||
            entity->move_now_entity != NULL) {
            entity->move_now.x = 0;
            entity->move_now.y = 0;
            entity->move_now_entity = NULL;
            angle = sfSprite_getRotation(((s_entity_part *) entity->parts->data)->sprite->elem);
        }

        rotate_entity_abs(adata, entity, angle);
        translate_entity(adata, entity, add);
    } else {
        angle = sfSprite_getRotation(((s_entity_part *) entity->parts->data)->sprite->elem);
    }

    if (entity->move_now_entity != NULL) {
        entity->move_now.x = 0;
        entity->move_now.y = 0;
        entity->move_now_entity = NULL;
    }

    if (blade_cycle) {
        add_to_entity_float(adata, entity, "blade_rot", 0.2f);
        rotate_entity_part_abs(adata, entity, "p800_left_blade", angle - blade_rot);
        rotate_entity_part_abs(adata, entity, "p800_right_blade", angle + blade_rot);
    } else {
        add_to_entity_float(adata, entity, "blade_rot", -2.5f);
        rotate_entity_part_abs(adata, entity, "p800_left_blade", angle - blade_rot);
        rotate_entity_part_abs(adata, entity, "p800_right_blade", angle + blade_rot);
        p800_damage_behavior(adata, entity, angle);
    }

    if ((blade_rot > 50.0f && blade_cycle) || (blade_rot < -20.0f && !blade_cycle)) {
        set_entity_float(adata, entity, "blade_cycle", blade_cycle > 0 ? 0 : 1.0f);
    }

    sfClock_restart(entity->clock);
}
