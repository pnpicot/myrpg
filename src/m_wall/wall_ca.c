/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Wall module
*/

#include "../include/main.h"

void add_wall(s_appdata *adata, char *id, sfFloatRect hitbox)
{
    s_wall *wall = get_wall(adata, id);

    if (wall != NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "already_exists"));
        return;
    }

    s_wall *new_wall = malloc(sizeof(s_wall));

    if (new_wall == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "mem_alloc"));
        return;
    }

    new_wall->id = id;
    new_wall->hitbox = get_wall_hitbox(adata, id, hitbox);

    linked_add(adata->lists->walls, new_wall);
}

void move_wall(s_appdata *adata, char *id, sfVector2f pos)
{
    s_wall *wall = get_wall(adata, id);

    if (wall == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    move_rect(adata, wall->hitbox->id, pos);
}

void resize_wall(s_appdata *adata, char *id, sfVector2f size)
{
    s_wall *wall = get_wall(adata, id);

    if (wall == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    resize_rect(adata, wall->hitbox->id, size);
}

void translate_wall(s_appdata *adata, char *id, sfVector2f pos_ch)
{
    s_wall *wall = get_wall(adata, id);

    if (wall == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    translate_rect(adata, wall->hitbox->id, pos_ch);
}

void set_wall_origin(s_appdata *adata, char *id, sfVector2f origin)
{
    s_wall *wall = get_wall(adata, id);

    if (wall == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    set_rect_origin(adata, wall->hitbox->id, origin);
}
