/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

static void revenant_damage_behavior(s_appdata *adata, s_entity *entity,
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
        if (touch->touch_type == TOUCH_ENTITY && touch->entity != entity) {
            touch->entity->hp -= entity->damage;
        }
        if (touch->touch_type == TOUCH_PARASITE) {
            adata->player->health.x -= entity->damage;
        }
        touchs = touchs->next;
    }
    free_ll_and_data(&touchs_ll);
}

void behavior_revenant(s_appdata *adata, s_entity *entity)
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
        add_entity_float(adata, entity, "arm_cycle", 0);
        add_entity_float(adata, entity, "arm_rot", 0);
        entity->init = sfFalse;
    }

    float seconds = get_clock_seconds(entity->clock);
    float angle = 5.0f;

    if (!entity->inhabited) {
        sfVector2f add = { path.x * seconds * 100, path.y * seconds * 100};
        add = is_map_colliding(adata, entity, add);
        translate_entity(adata, entity, add);
        angle = (atan2f(add.y, add.x) * (180.0f / M_PI)) + 90.0f;

    } else {
        angle = sfSprite_getRotation(((s_entity_part *) entity->parts->data)->sprite->elem);
    }

    rotate_entity_part_abs(adata, entity, "revenant_body", angle);
    rotate_entity_part_abs(adata, entity, "revenant_right_arm", angle);
    rotate_entity_part_abs(adata, entity, "revenant_left_arm", angle);

    float arm_cycle = get_entity_float(entity, "arm_cycle")->value;
    float arm_rot = get_entity_float(entity, "arm_rot")->value;

    if (arm_cycle) {
        add_to_entity_float(adata, entity, "arm_rot", 0.7f);
        rotate_entity_part_abs(adata, entity, "revenant_left_arm", angle - arm_rot);
        rotate_entity_part_abs(adata, entity, "revenant_right_arm", angle + arm_rot);
    } else {
        add_to_entity_float(adata, entity, "arm_rot", -4.5f);
        rotate_entity_part_abs(adata, entity, "revenant_left_arm", angle - arm_rot);
        rotate_entity_part_abs(adata, entity, "revenant_right_arm", angle + arm_rot);
        revenant_damage_behavior(adata, entity, angle);
    }

    if ((arm_rot > 50.0f && arm_cycle) || (arm_rot < -35.0f && !arm_cycle)) {
        set_entity_float(adata, entity, "arm_cycle", arm_cycle > 0 ? 0 : 1.0f);
    }

    sfClock_restart(entity->clock);
}
