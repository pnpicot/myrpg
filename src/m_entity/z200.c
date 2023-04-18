/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

// TODO: add clock so we can use a delta in velocity vector formulas
void behavior_z200(s_appdata *adata, s_entity *entity)
{
    update_entity_bar(adata, entity);

    float seconds = get_clock_seconds(entity->clock);

    rotate_entity_part(adata, entity, "blades_1", -5.0f * seconds * 100);
    rotate_entity_part(adata, entity, "blades_2", 5.0f * seconds * 100);
    rotate_entity_part(adata, entity, "rotors", 10.0f * seconds * 100);


    if (!entity->inhabited) {
        sfVector2f add = { 0.3f * seconds * 100, 0.1f * seconds * 100};
        add = is_map_colliding(adata, get_entity_hitbox(adata, entity), add);
        translate_entity(adata, entity, add);
    }

    sfClock_restart(entity->clock);
}
