/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

void behavior_mf26(s_appdata *adata, s_entity *entity)
{
    update_entity_bar(adata, entity);
    sfVector2f path = { 0, 0 };
    get_mf26_path(adata, entity, &path);
    float seconds = get_clock_seconds(adata->clocks->update_clock);
    sfVector2f add = { path.x * seconds * entity->speed,
                       path.y * seconds * entity->speed };
    float angle = (atan2f(add.y, add.x) * (180 / M_PI)) + 90.0f;
    s_sprite *sprite = ((s_entity_part *) entity->parts->data)->sprite;
    float last_angle = sfSprite_getRotation(sprite->elem);
    if (entity->inhabited) {
        add = (sfVector2f) { 0, 0 };
        angle = sfSprite_getRotation(sprite->elem);
        last_angle = angle - 1.0f;
    }
    behavior_mf26_next(adata, entity, angle, last_angle);
    rotate_entity_part_abs(adata, entity, "body", angle);
    add = is_map_colliding(adata, entity, add);
    sfFloatRect hitbox = get_entity_hitbox(adata, entity);
    translate_entity(adata, entity, add);
    behavior_mf26_emiter(adata, entity, add, angle);
    sfClock_restart(entity->clock);
}
