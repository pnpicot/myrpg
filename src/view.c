/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** View module
*/

#include "main.h"

void resize_map(s_appdata *adata, sfVector2f size)
{
    s_game *game_data = adata->game_data;

    game_data->map_size = size;

    linked_node *rtexs = adata->lists->rtexs;

    while (rtexs != NULL && rtexs->data != NULL) {
        s_rtex *cur = (s_rtex *) rtexs->data;

        sfRenderTexture_destroy(cur->texture);
        cur->texture = sfRenderTexture_create(game_data->map_size.x, game_data->map_size.y, sfFalse);

        rtexs = rtexs->next;
    }
}

void update_view(s_appdata *adata)
{
    s_game *game_data = adata->game_data;
    sfView *view = (sfView *) sfRenderWindow_getView(adata->win);

    if (get_key(adata, sfKeyQ)) {
        game_data->view_pos.x -= 15.0f;
    }

    if (get_key(adata, sfKeyD)) {
        game_data->view_pos.x += 15.0f;
    }

    if (get_key(adata, sfKeyZ)) {
        game_data->view_pos.y -= 15.0f;
    }

    if (get_key(adata, sfKeyS)) {
        game_data->view_pos.y += 15.0f;
    }

    sfMouseMoveEvent ms;
    ms.type = sfEvtMouseMoved;
    ms.x = 0;
    ms.y = 0;

    sfView_setCenter(view, game_data->view_pos);
    sfRenderWindow_setView(adata->win, view);
    register_mousemove(adata, ms);
}
