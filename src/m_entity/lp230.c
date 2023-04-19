/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** LP230 Entity module
*/

#include "main.h"

void behavior_lp230(s_appdata *adata, s_entity *entity)
{
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
        add_entity_float(adata, entity, "leg_cycle", 0);
        add_entity_float(adata, entity, "leg_rot", 0);

        entity->init = sfFalse;
    }

    float seconds = get_clock_seconds(entity->clock);
    float angle;
    s_entity_part *body = (s_entity_part *) linked_get(entity->parts, 2)->data;

    if (!entity->inhabited) {
        sfVector2f add = { path.x * seconds * 100, path.y * seconds * 100};

        add = is_map_colliding(adata, get_entity_hitbox(adata, entity), add);
        angle = (atan2f(add.y, add.x) * (180.0f / M_PI)) + 90.0f;

        translate_entity(adata, entity, add);
    } else {
        angle = sfSprite_getRotation(body->sprite->elem);
    }

    rotate_entity_part_abs(adata, entity, "lp230_body", angle);

    float leg_cycle = get_entity_float(entity, "leg_cycle")->value;
    float leg_rot = get_entity_float(entity, "leg_rot")->value;
    int walking = get_key(adata, sfKeyQ)
               || get_key(adata, sfKeyZ)
               || get_key(adata, sfKeyD)
               || get_key(adata, sfKeyS);

    if (!entity->inhabited || walking) {
        if (leg_cycle) {
            add_to_entity_float(adata, entity, "leg_rot", entity->speed);
            rotate_entity_part_abs(adata, entity, "lp230_legs_first", angle - leg_rot);
            rotate_entity_part_abs(adata, entity, "lp230_legs_second", angle + leg_rot);
        } else {
            add_to_entity_float(adata, entity, "leg_rot", -entity->speed);
            rotate_entity_part_abs(adata, entity, "lp230_legs_first", angle - leg_rot);
            rotate_entity_part_abs(adata, entity, "lp230_legs_second", angle + leg_rot);
        }

        if ((leg_rot > 40.0f && leg_cycle) || (leg_rot < -40.0f && !leg_cycle)) {
            set_entity_float(adata, entity, "leg_cycle", leg_cycle > 0 ? 0 : 1.0f);
        }
    }

    if (entity->inhabited) {
        sfVector2f mouse_offset;
        sfVector2f mouse = get_mouse(adata);
        sfFloatRect abs_bounds = sfSprite_getGlobalBounds(body->sprite->elem);

        mouse_offset.x = mouse.x - (abs_bounds.left + (abs_bounds.width / 2));
        mouse_offset.y = mouse.y - (abs_bounds.top + (abs_bounds.height / 2));

        float mouse_angle = (atan2f(mouse_offset.y, mouse_offset.x) * (180.0f / M_PI)) + 90.0f;

        rotate_entity_part_abs(adata, entity, "lp230_canon", mouse_angle);
    } else {
        rotate_entity_part_abs(adata, entity, "lp230_canon", angle);
    }

    sfClock_restart(entity->clock);
}
