/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Light rendering module
*/

#include "../include/main.h"

int get_is_diag(sfVector2f pos, sfVector2f nst, sfVector2f nst_s)
{
    return ((pos.y >= nst.y && pos.y <= nst_s.y)
        || (pos.y <= nst.y && pos.y >= nst_s.y)
        || (pos.x >= nst.x && pos.x <= nst_s.x)
        || (pos.x <= nst.x && pos.x >= nst_s.x));
}

int get_is_diagt(sfVector2f pos, sfVector2f nst_t, sfVector2f nst)
{
    return ((pos.y >= nst.y && pos.y <= nst_t.y)
        || (pos.y <= nst.y && pos.y >= nst_t.y)
        || (pos.x >= nst.x && pos.x <= nst_t.x)
        || (pos.x <= nst.x && pos.x >= nst_t.x));
}

void get_shadow_anchors(sfVector2f pos, linked_node *corners, \
sfVector2f *anchor_a, sfVector2f *anchor_b)
{
    sfVector2f nearest_first = nearest_point(pos, corners, 0);
    sfVector2f nearest_second = nearest_point(pos, corners, 1);
    sfVector2f nearest_third = nearest_point(pos, corners, 2);
    int is_diag = get_is_diag(pos, nearest_first, nearest_second);
    int is_diag_t = get_is_diagt(pos, nearest_third, nearest_first);
    if (is_diag) {
        (*anchor_a) = nearest_first;
        (*anchor_b) = nearest_second;
    } else if (is_diag_t) {
        (*anchor_a) = nearest_first;
        (*anchor_b) = nearest_third;
    } else {
        (*anchor_a) = nearest_second;
        (*anchor_b) = nearest_third;
    }
}

linked_node *get_wall_corners(sfFloatRect wall)
{
    sfVector2f *top_l = malloc(sizeof(sfVector2f));
    top_l->x = wall.left;
    top_l->y = wall.top;
    sfVector2f *top_r = malloc(sizeof(sfVector2f));
    top_r->x = wall.left + wall.width;
    top_r->y = wall.top;
    sfVector2f *bot_l = malloc(sizeof(sfVector2f));
    bot_l->x = wall.left;
    bot_l->y = wall.top + wall.height;
    sfVector2f *bot_r = malloc(sizeof(sfVector2f));
    bot_r->x = wall.left + wall.width;
    bot_r->y = wall.top + wall.height;
    linked_node *corners = linked_new();
    linked_add(corners, top_l);
    linked_add(corners, top_r);
    linked_add(corners, bot_l);
    linked_add(corners, bot_r);
    return (corners);
}

void generate_shadow_base(sfVertexArray *cast, sfColor mask_color, \
sfVector2f anchor_a, sfVector2f anchor_b)
{
    sfVertex *cast_a = sfVertexArray_getVertex(cast, 0);
    sfVertex *cast_b = sfVertexArray_getVertex(cast, 1);
    cast_a->color = mask_color;
    cast_a->position = anchor_a;
    cast_b->color = mask_color;
    cast_b->position = anchor_b;
}
