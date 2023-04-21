/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Game object module
*/

#include "../include/main.h"

void move_gameobject_lights(s_appdata *adata, sfVector2f pos_ch)
{
    linked_node *lights = adata->lists->lights;

    while (lights != NULL && lights->data != NULL) {
        s_light *cur = (s_light *) lights->data;

        if (!cur->game_obj) {
            lights = lights->next;
            continue;
        }

        translate_light(adata, cur->id, pos_ch);

        lights = lights->next;
    }
}

void translate_emiter_particles(s_appdata *adata, linked_node *pool, \
sfVector2f pos_ch)
{
    while (pool != NULL && pool->data != NULL) {
        s_particle *cur = (s_particle *) pool->data;

        sfVector2f pos = sfSprite_getPosition(cur->model);
        pos.x += pos_ch.x;
        pos.y += pos_ch.y;

        sfSprite_setPosition(cur->model, pos);

        pool = pool->next;
    }
}

void move_gameobject_emiters(s_appdata *adata, sfVector2f pos_ch)
{
    linked_node *emiters = adata->lists->emiters;

    while (emiters != NULL && emiters->data != NULL) {
        s_particle_src *cur = (s_particle_src *) emiters->data;

        if (!cur->game_obj) {
            emiters = emiters->next;
            continue;
        }

        translate_emiter(adata, cur->id, pos_ch);
        translate_emiter_particles(adata, cur->particle_pool, pos_ch);

        emiters = emiters->next;
    }
}

void add_gameobject_hitbox(s_appdata *adata, char *id)
{
    s_gameobj *game_obj = get_gameobject(adata, id);

    if (game_obj == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    char *hitbox_id = str_add(id, "@[:hitbox]");
    sfFloatRect bounds;

    bounds = get_element_bounds(adata, game_obj->ref, game_obj->type);
    bounds.left += 2;
    bounds.top += 2;
    bounds.width -= 4;
    bounds.height -= 4;

    add_wall(adata, hitbox_id, bounds);
}

void move_gameobject_walls(s_appdata *adata, sfVector2f pos_ch)
{
    linked_node *walls = adata->lists->walls;

    while (walls != NULL && walls->data != NULL) {
        s_wall *cur = (s_wall *) walls->data;

        translate_wall(adata, cur->id, pos_ch);

        walls = walls->next;
    }
}
