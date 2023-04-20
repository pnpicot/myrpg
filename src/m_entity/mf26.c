/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

void init_mf26_emiter(s_appdata *adata, s_entity *entity)
{
    char *emiter_id = str_add(entity->id, "@[:emiter]");
    add_emiter(adata, emiter_id);
    set_emiter_model(adata, emiter_id, "bullet");
    set_emiter_active(adata, emiter_id, sfTrue);
    set_emiter_colors(adata, emiter_id, sfCyan, sfWhite);
    set_emiter_lerp_factor(adata, emiter_id, 1.5f);
    s_sprite *body = (s_sprite *) entity->parts->data;
    set_emiter_gameobject(adata, emiter_id, sfTrue);
    set_emiter_layer(adata, emiter_id, 5);
    set_emiter_lifetime(adata, emiter_id, 150000);
    set_emiter_particle_lifetime(adata, emiter_id, 1500);
    set_emiter_particle_max(adata, emiter_id, 50);
    set_emiter_particle_speed(adata, emiter_id, (sfVector2f) {3000, 3000});
    set_emiter_rtex(adata, emiter_id, get_str(adata, "rtex_game"));
    add_to_container(adata, get_str(adata, "ctn_game"), (s_ref) { get_emiter(adata, emiter_id), TYPE_EMITER });
    sfVector2f scale = { 3.0f, 3.0f };
    move_emiter(adata, emiter_id, (sfVector2f) {140, 60});
    set_emiter_size_range(adata, emiter_id, scale, (sfVector2f) { 3.0f, 3.0f });
    set_emiter_spawnrate(adata, emiter_id, 100.0f);
}

static void mf26_particles_behavior(s_appdata *adata,
s_entity *entity, s_particle *particle, linked_node *touchs)
{
    while (touchs != NULL) {
        s_touch_t *touch = (s_touch_t *) touchs->data;
        if (touch->touch_type == TOUCH_WALL) {
            particle->active = sfFalse;
            return;
        }
        if (touch->touch_type == TOUCH_ENTITY && touch->entity != entity) {
            touch->entity->hp -= entity->damage;
            particle->active = sfFalse;
        }
        if (touch->touch_type == TOUCH_PARASITE) {
            adata->player->health.x -= entity->damage;
            particle->active = sfFalse;
        }
        touchs = touchs->next;
    }
}

void behavior_mf26(s_appdata *adata, s_entity *entity)
{
    update_entity_bar(adata, entity);

    if (entity->inhabited) return;

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

    float seconds = get_clock_seconds(entity->clock);
    sfVector2f add = { path.x * seconds * 100, path.y * seconds * 100 };
    float angle = (atan2f(add.y, add.x) * (180 / M_PI)) + 90.0f;
    float last_angle = sfSprite_getRotation(((s_entity_part *) entity->parts->data)->sprite->elem);
    char *emiter_id = str_add(entity->id, "@[:emiter]");

    if (angle != last_angle) {
        sfVector2f origin = { 140, 60 };
        float ang_rad = (angle - 90.0f) * (M_PI / 180.0f);
        sfVector2f o_pos = ((s_entity_part *) entity->parts->data)->sprite->pos;
        o_pos.x -= adata->game_data->view_pos.x;
        o_pos.y -= adata->game_data->view_pos.y;
        sfVector2f rotated;
        rotated.x = (origin.x * cos(ang_rad)) - (origin.y * sin(ang_rad));
        rotated.y = (origin.x * sin(ang_rad)) + (origin.y * cos(ang_rad));

        move_emiter(adata, emiter_id, o_pos);
        translate_emiter(adata, emiter_id, rotated);
    }

    rotate_entity_part_abs(adata, entity, "body", angle);
    add = is_map_colliding(adata, entity, add);
    sfFloatRect hitbox = get_entity_hitbox(adata, entity);
    translate_entity(adata, entity, add);

    if (entity->emiter != NULL) {
        sfVector2f emiter_add = { entity->pos.x * entity->pos.x * cos(angle), entity->pos.y * entity->pos.y * sin(angle) };
        translate_emiter(adata, emiter_id, add);
        angle -= 90.0f;
        set_emiter_cone(adata, emiter_id, (sfVector2f) { angle, angle });
    }

    s_particle_src *src = get_emiter(adata, emiter_id);
    do_particle_behavior(adata, src, entity, mf26_particles_behavior);

    sfClock_restart(entity->clock);
}
