/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Utilities module
*/

#include "../include/main.h"

sfVector2f get_mouse(s_appdata *adata)
{
    sfVector2i m_abs = sfMouse_getPositionRenderWindow(adata->win);
    const sfView *view = sfRenderWindow_getView(adata->win);
    sfVector2f m_rel = sfRenderWindow_mapPixelToCoords(adata->win, m_abs, view);
    s_game *game_data = adata->game_data;

    m_rel.x -= game_data->view_pos.x;
    m_rel.y -= game_data->view_pos.y;

    return (m_rel);
}

float get_clock_seconds(sfClock *clock)
{
    sfTime elapsed = sfClock_getElapsedTime(clock);
    float seconds = elapsed.microseconds / 1000000.0f;

    return (seconds);
}

char *get_random_id(int len)
{
    char *id = malloc(sizeof(char) * (len + 1));
    id[len] = '\0';

    for (int i = 0; i < len; i++) {
        id[i] = rand_int(0, 1) ? rand_int(65, 90) : rand_int(97, 122);
    }

    return (id);
}

sfVector2f get_projected(sfVector2f origin, sfVector2f point, float dist)
{
    sfVector2f dv_b;
    dv_b.x = origin.x - point.x;
    dv_b.y = origin.y - point.y;

    float dn_b = sqrt(pow(dv_b.x, 2) + pow(dv_b.y, 2));
    sfVector2f proj = { point.x, point.y };

    proj.x += (dist / dn_b) * dv_b.x;
    proj.y += (dist / dn_b) * dv_b.y;

    return (proj);
}

sfColor rand_light_color(sfUint8 alpha)
{
    sfColor new_color;
    new_color.r = rand_int(170, 255);
    new_color.g = rand_int(170, 255);
    new_color.b = rand_int(170, 255);
    new_color.a = alpha ? rand_int(0, 255) : 255;

    return (new_color);
}