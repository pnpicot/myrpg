/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Game object module
*/

#include "../include/main.h"

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
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
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
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "already_exists"));
        return;
    }

    s_gameobj *new_gameobject = malloc(sizeof(s_gameobj));

    if (new_gameobject == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
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
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    gameobject->ref = ref;
    gameobject->type = type;
}

void move_gameobject(s_appdata *adata, s_gameobj *game_obj)
{
    s_game *game_data = adata->game_data;
    sfVector2f pos = get_element_rel_pos(adata, game_obj->ref, game_obj->type);

    pos.x -= game_data->view_pos.x;
    pos.y -= game_data->view_pos.y;

    move_element(adata, game_obj->ref, game_obj->type, pos);
}
