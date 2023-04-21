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
    sfVector2i end;
    end.x = 125;
    end.y = 125;
    sfVector2f agro_path = agro(adata, entity);
    if (agro_path.x == -1.0f && agro_path.y == -1.0f)
        path = get_way(adata, entity, end);
    else {
        path = agro_path;
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

    translate_entity(adata, entity, add);
    rotate_entity_part_abs(adata, entity, "lmx2_body", angle);
    sfClock_restart(entity->clock);
}
