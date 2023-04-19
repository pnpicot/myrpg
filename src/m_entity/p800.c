/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

void behavior_p800(s_appdata *adata, s_entity *entity)
{
    linked_node *parts = entity->parts;

    update_entity_bar(adata, entity);

    sfVector2f path = { 0, 0 };
    sfVector2i end;
    end.x = 33;
    end.y = 33;
    sfVector2f agro_path = agro(adata, entity);
    if (agro_path.x == -1.0f && agro_path.y == -1.0f)
        path = get_way(adata, entity, end);
    else {
        path = agro_path;
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
        sfVector2f add = { path.x * seconds * 100, path.y * seconds * 100};

        add = is_map_colliding(adata, get_entity_hitbox(adata, entity), add);
        angle = (atan2f(add.y, add.x) * (180.0f / M_PI)) + 90.0f;

        rotate_entity_abs(adata, entity, angle);
        translate_entity(adata, entity, add);
    } else {
        angle = sfSprite_getRotation(((s_entity_part *) entity->parts->data)->sprite->elem);
    }

    if (blade_cycle) {
        add_to_entity_float(adata, entity, "blade_rot", 0.2f);
        rotate_entity_part_abs(adata, entity, "p800_left_blade", angle - blade_rot);
        rotate_entity_part_abs(adata, entity, "p800_right_blade", angle + blade_rot);
    } else {
        add_to_entity_float(adata, entity, "blade_rot", -2.5f);
        rotate_entity_part_abs(adata, entity, "p800_left_blade", angle - blade_rot);
        rotate_entity_part_abs(adata, entity, "p800_right_blade", angle + blade_rot);
    }

    if ((blade_rot > 50.0f && blade_cycle) || (blade_rot < -20.0f && !blade_cycle)) {
        set_entity_float(adata, entity, "blade_cycle", blade_cycle > 0 ? 0 : 1.0f);
    }

    sfClock_restart(entity->clock);
}
