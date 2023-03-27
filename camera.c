/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Camera module
*/

#include "include/main.h"

void translate_views(s_appdata *adata, sfVector2f pos_ch)
{
    sfView *view = sfRenderWindow_getView(adata->win);

    sfView_move(view, pos_ch);
    sfRenderWindow_setView(adata->win, view);
}

void init_view(s_appdata *adata)
{
    sfView *view = sfRenderWindow_getView(adata->win);
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");

    sfRenderWindow_setView(adata->win, view);
}

void update_view(s_appdata *adata)
{
    s_game *game_data = adata->game_data;

    if (get_key(adata, sfKeyQ)) {
        translate_views(adata, (sfVector2f) { -10.0f, 0 });
        game_data->view_pos.x -= 10.0f;
    }

    if (get_key(adata, sfKeyZ)) {
        translate_views(adata, (sfVector2f) { 0, -10.0f });
        game_data->view_pos.y -= 10.0f;
    }

    if (get_key(adata, sfKeyD)) {
        translate_views(adata, (sfVector2f) { 10.0f, 0 });
        game_data->view_pos.x += 10.0f;
    }

    if (get_key(adata, sfKeyS)) {
        translate_views(adata, (sfVector2f) { 0, 10.0f });
        game_data->view_pos.y += 10.0f;
    }

    sfMouseMoveEvent ms;
    register_mousemove(adata, ms);
}
