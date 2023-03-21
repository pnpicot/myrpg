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
