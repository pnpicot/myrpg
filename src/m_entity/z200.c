/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

static void z200_damage_behavior(s_appdata *adata, s_entity *entity)
{
    sfFloatRect hitbox = get_entity_hitbox(adata, entity);
    hitbox.left -= 15;
    hitbox.top -= 15;
    hitbox.width += 30;
    hitbox.height += 30;
    linked_node *touchs = what_is_touching(adata, hitbox);

    while (touchs != NULL) {
        s_touch_t *touch = (s_touch_t *) touchs->data;
        if (touch->touch_type == TOUCH_ENTITY && touch->entity != entity) {
            touch->entity->hp -= 1;
        }
        if (touch->touch_type == TOUCH_PARASITE) {
            adata->player->health.x -= 1;
        }
        touchs = touchs->next;
    }
    free_ll_and_data(&touchs);
}

// TODO: add clock so we can use a delta in velocity vector formulas
void behavior_z200(s_appdata *adata, s_entity *entity)
{
    update_entity_bar(adata, entity);

    sfVector2f path = { 0, 0 };
    sfVector2i end;
    end.x = 33;
    end.y = 33;
    path = get_way(adata, entity, end);

    if (entity->init) {
        add_entity_float(adata, entity, "rotation", 0.0f);

        entity->init = sfFalse;
    }

    float seconds = get_clock_seconds(entity->clock);
    float angle = 5.0f;
    float blade_rot = get_entity_float(entity, "rotation")->value;
    add_to_entity_float(adata, entity, "rotation", 5.0f);

    if (!entity->inhabited) {
        sfVector2f add = { path.x * seconds * 100, path.y * seconds * 100};
        add = is_map_colliding(adata, get_entity_hitbox(adata, entity), add);
        translate_entity(adata, entity, add);
    } else {
        angle = sfSprite_getRotation(((s_entity_part *) entity->parts->data)->sprite->elem);
    }

    rotate_entity_part(adata, entity, "blades_1", (angle - blade_rot) * seconds * 0.01);
    rotate_entity_part(adata, entity, "blades_2", (angle + blade_rot) * seconds * 0.01);
    rotate_entity_part(adata, entity, "rotors", (angle - blade_rot) * seconds * 0.1);

    z200_damage_behavior(adata, entity);

    sfClock_restart(entity->clock);
}
