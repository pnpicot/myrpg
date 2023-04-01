/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Collision module
*/

#include "main.h"

sfBool is_colliding(s_wall *wall_a, s_wall *wall_b)
{
    sfFloatRect ra = sfRectangleShape_getGlobalBounds(wall_a->hitbox->elem);
    sfFloatRect rb = sfRectangleShape_getGlobalBounds(wall_b->hitbox->elem);

    return (sfFloatRect_intersects(&ra, &rb, NULL));
}

sfVector2f collide_adjust(s_wall *from, s_wall *to, sfVector2f pos_ch)
{
    sfFloatRect ra = sfRectangleShape_getGlobalBounds(from->hitbox->elem);
    sfFloatRect rb = sfRectangleShape_getGlobalBounds(to->hitbox->elem);

    ra.left += pos_ch.x;
    ra.top += pos_ch.y;

    sfFloatRect intersection = { 0, 0, 0, 0 };
    sfBool res = sfFloatRect_intersects(&ra, &rb, &intersection);

    if (res) {
        pos_ch.x -= (pos_ch.x > 0 ? 1 : -1) * intersection.width;
        pos_ch.y -= (pos_ch.y > 0 ? 1 : -1) * intersection.height;
    }

    return (pos_ch);
}

sfVector2f get_bounce_force(sfVector2f velocity, float mass, \
float deflection_force)
{
    velocity.x *= mass * deflection_force;
    velocity.y *= mass * deflection_force;

    return (velocity);
}

sfBool screen_intersects(s_appdata *adata, sfFloatRect rect)
{
    sfFloatRect win_rect;
    win_rect.left = 0;
    win_rect.top = 0;
    win_rect.width = get_int(adata, "win_w");
    win_rect.height = get_int(adata, "win_h");

    return (sfFloatRect_intersects(&win_rect, &rect, NULL));
}

sfBool screen_contains(s_appdata *adata, sfVector2f pos)
{
    sfFloatRect win_rect;
    win_rect.left = 0;
    win_rect.top = 0;
    win_rect.width = get_int(adata, "win_w");
    win_rect.height = get_int(adata, "win_h");

    return (sfFloatRect_contains(&win_rect, pos.x, pos.y));
}
