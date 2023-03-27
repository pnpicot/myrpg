/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Wall module
*/

#include "main.h"

s_wall *get_wall(s_appdata *adata, char *id)
{
    linked_node *walls = adata->lists->walls;

    while (walls != NULL && walls->data != NULL) {
        s_wall *cur = (s_wall *) walls->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        walls = walls->next;
    }

    return (NULL);
}

void delete_wall(s_appdata *adata, char *id)
{
    s_wall *wall = get_wall(adata, id);

    if (wall == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *walls = adata->lists->walls;
    int ite = 0;

    while (walls != NULL && walls->data != NULL) {
        s_wall *cur = (s_wall *) walls->data;

        if (!my_strcmp(cur->id, id)) {
            delete_rect(adata, cur->hitbox->id);
            break;
        }

        ite++;
        walls = walls->next;
    }

    linked_delete(&adata->lists->walls, ite);
}

void set_wall_rtex(s_appdata *adata, char *rtex_id, int layer)
{
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    s_ints *integers = adata->integers;

    adata->wall_rtex = rtex;
    integers->wall_layer = layer;

    if (layer < integers->min_layer) integers->min_layer = layer;
    if (layer > integers->max_layer) integers->max_layer = layer;

    linked_node *walls = adata->lists->walls;

    while (walls != NULL && walls->data != NULL) {
        s_wall *cur = (s_wall *) walls->data;

        set_rect_rtex(adata, cur->hitbox->id, rtex_id);
        cur->hitbox->layer = layer;

        walls = walls->next;
    }
}

s_rect *get_wall_hitbox(s_appdata *adata, char *wall_id, sfFloatRect hitbox)
{
    char *id = str_add(wall_id, "@[:hitbox]");

    add_rect(adata, id, adata->integers->wall_layer);
    set_rect_rtex(adata, id, adata->wall_rtex->id);
    resize_rect(adata, id, (sfVector2f) { hitbox.width, hitbox.height });
    move_rect(adata, id, (sfVector2f) { hitbox.left, hitbox.top });
    color_rect(adata, id, get_color(20, 20, 20, 255));
    set_rect_outline(adata, id, sfBlack, 2.0f);
    set_rect_active(adata, id, 0);

    return (get_rect(adata, id));
}

void add_wall(s_appdata *adata, char *id, sfFloatRect hitbox)
{
    if (adata->wall_rtex == NULL) return;

    s_wall *wall = get_wall(adata, id);

    if (wall != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    s_wall *new_wall = malloc(sizeof(s_wall));

    if (new_wall == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
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
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    move_rect(adata, wall->hitbox->id, pos);
}

void resize_wall(s_appdata *adata, char *id, sfVector2f size)
{
    s_wall *wall = get_wall(adata, id);

    if (wall == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    resize_rect(adata, wall->hitbox->id, size);
}

void translate_wall(s_appdata *adata, char *id, sfVector2f pos_ch)
{
    s_wall *wall = get_wall(adata, id);

    if (wall == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    translate_rect(adata, wall->hitbox->id, pos_ch);
}

void set_wall_origin(s_appdata *adata, char *id, sfVector2f origin)
{
    s_wall *wall = get_wall(adata, id);

    if (wall == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    set_rect_origin(adata, wall->hitbox->id, origin);
}

void show_walls(s_appdata *adata)
{
    linked_node *walls = adata->lists->walls;

    while (walls != NULL && walls->data != NULL) {
        s_wall *cur = (s_wall *) walls->data;

        cur->hitbox->active = 1;

        walls = walls->next;
    }
}

void hide_walls(s_appdata *adata)
{
    linked_node *walls = adata->lists->walls;

    while (walls != NULL && walls->data != NULL) {
        s_wall *cur = (s_wall *) walls->data;

        cur->hitbox->active = 0;

        walls = walls->next;
    }
}

void update_current_wall(s_appdata *adata)
{
    if (adata->current_wall != NULL) {
        s_wall *wall = get_wall(adata, adata->current_wall);

        sfVector2f wall_size;
        sfVector2f wall_pos = sfRectangleShape_getPosition(wall->hitbox->elem);
        sfVector2f mouse = get_mouse(adata);

        wall_size.x = mouse.x - wall_pos.x;
        wall_size.y = mouse.y - wall_pos.y;

        resize_wall(adata, adata->current_wall, wall_size);
    }
}
