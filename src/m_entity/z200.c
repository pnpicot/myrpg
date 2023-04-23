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
    hitbox.left -= 30;
    hitbox.top -= 30;
    hitbox.width += 45;
    hitbox.height += 45;
    linked_node *touchs_ll = what_is_touching(adata, hitbox);

    for (linked_node *tch = touchs_ll; tch != NULL; tch = tch->next) {
        s_touch_t *touch = (s_touch_t *) tch->data;
        int same_fac = touch->touch_type == TOUCH_ENTITY &&
            !my_strcmp(touch->entity->faction->id, entity->faction->id);
        if (touch->touch_type == TOUCH_ENTITY &&
        touch->entity != entity && !same_fac)
            touch->entity->hp -= entity->damage  *
            (1 - touch->entity->defense);
        if (touch->touch_type == TOUCH_PARASITE)
            adata->player->health.x -= entity->damage  *
            (1 - adata->player->defense);
    }
    free_ll_and_data(&touchs_ll);
}

void get_z200_path(s_appdata *adata, s_entity *entity, sfVector2f *path)
{
    if (entity->move_now_entity != NULL) {
        (*path) = entity->move_now;
        entity->move_now = (sfVector2f){0, 0};
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

void behavior_z200_next(s_appdata *adata, s_entity *entity, sfVector2f path)
{
    float seconds = get_clock_seconds(adata->clocks->update_clock);
    float angle = 5.0f;
    float blade_rot = get_entity_float(entity, "rotation")->value;
    add_to_entity_float(adata, entity, "rotation", 5.0f);
    if (!entity->inhabited) {
        sfVector2f add = { path.x * seconds * entity->speed,
                           path.y * seconds * entity->speed };
        add = is_map_colliding(adata, entity, add);
        translate_entity(adata, entity, add);
    } else {
        angle = sfSprite_getRotation(
            ((s_entity_part *) entity->parts->data)->sprite->elem);
    }
    rotate_entity_part(adata, entity, "blades_1",
        (angle - blade_rot) * seconds * 0.01);
    rotate_entity_part(adata, entity, "blades_2",
        (angle + blade_rot) * seconds * 0.01);
    rotate_entity_part(adata, entity, "rotors",
        (angle - blade_rot) * seconds * 0.1);
}

void behavior_z200(s_appdata *adata, s_entity *entity)
{
    update_entity_bar(adata, entity);
    sfVector2f path = { 0, 0 };
    get_z200_path(adata, entity, &path);
    if (entity->init) {
        add_entity_float(adata, entity, "rotation", 0.0f);

        entity->init = sfFalse;
    }
    if (entity->move_now_entity != NULL) {
        entity->move_now.x = 0;
        entity->move_now.y = 0;
        entity->move_now_entity = NULL;
    }
    behavior_z200_next(adata, entity, path);
    z200_damage_behavior(adata, entity);
    sfClock_restart(entity->clock);
}
