/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Game object module
*/

#include "main.h"

s_gameobj *get_gameobject(s_appdata *adata, char *id)
{
    linked_node *gameobjects = adata->lists->gameobjects;

    while (gameobjects != NULL && gameobjects->data != NULL) {
        s_gameobj *cur = (s_gameobj *) gameobjects->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        gameobjects = gameobjects->next;
    }

    return (NULL);
}

void delete_gameobject(s_appdata *adata, char *id)
{
    s_gameobj *gameobject = get_gameobject(adata, id);

    if (gameobject == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *gameobjects = adata->lists->gameobjects;
    int ite = 0;

    while (gameobjects != NULL && gameobjects->data != NULL) {
        s_gameobj *cur = (s_gameobj *) gameobjects->data;

        if (!my_strcmp(cur->id, id)) {
            if (cur->hitbox != NULL) delete_wall(adata, cur->hitbox->id);
            break;
        }

        ite++;
        gameobjects = gameobjects->next;
    }

    linked_delete(&adata->lists->gameobjects, ite);
}

void add_gameobject(s_appdata *adata, char *id)
{
    s_gameobj *gameobject = get_gameobject(adata, id);

    if (gameobject != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    s_gameobj *new_gameobject = malloc(sizeof(s_gameobj));

    if (new_gameobject == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    new_gameobject->hitbox = NULL;
    new_gameobject->id = id;
    new_gameobject->ref = NULL;
    new_gameobject->type = 0;

    linked_add(adata->lists->gameobjects, new_gameobject);
}

void set_gameobject_ref(s_appdata *adata, char *id, void *ref, int type)
{
    s_gameobj *gameobject = get_gameobject(adata, id);

    if (gameobject == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    gameobject->ref = ref;
    gameobject->type = type;
}

void move_gameobject(s_appdata *adata, s_gameobj *gameobject)
{
    s_game *game_data = adata->game_data;
    sfVector2f pos = get_element_rel_pos(adata, gameobject->ref, gameobject->type);

    pos.x -= game_data->view_pos.x;
    pos.y -= game_data->view_pos.y;

    move_element(adata, gameobject->ref, gameobject->type, pos);
}

void move_gameobject_lights(s_appdata *adata, sfVector2f pos_ch)
{
    linked_node *lights = adata->lists->lights;

    while (lights != NULL && lights->data != NULL) {
        s_light *cur = (s_light *) lights->data;

        translate_light(adata, cur->id, pos_ch);

        lights = lights->next;
    }
}

void translate_emiter_particles(s_appdata *adata, linked_node *pool, sfVector2f pos_ch)
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

        translate_emiter(adata, cur->id, pos_ch);
        translate_emiter_particles(adata, cur->particle_pool, pos_ch);

        emiters = emiters->next;
    }
}

void add_gameobject_hitbox(s_appdata *adata, char *id)
{
    s_gameobj *gameobject = get_gameobject(adata, id);

    if (gameobject == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    char *hitbox_id = str_add(id, "@[:hitbox]");

    add_wall(adata, hitbox_id, get_element_bounds(adata, gameobject->ref, gameobject->type));
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

void update_gameobjects(s_appdata *adata)
{
    linked_node *gameobjects = adata->lists->gameobjects;

    while (gameobjects != NULL && gameobjects->data != NULL) {
        s_gameobj *cur = (s_gameobj *) gameobjects->data;

        move_gameobject(adata, cur);

        gameobjects = gameobjects->next;
    }
}
