/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Render module
*/

#include "../include/main.h"

void render_elements(s_appdata *adata, s_rtex *rtex)
{
    s_ints *ints = adata->integers;

    for (int i = ints->min_layer; i <= ints->max_layer; i++) {
        render_rects(adata, i, rtex);
        render_circles(adata, i, rtex);
        render_sprites(adata, i, rtex);
        render_texts(adata, i, rtex);
        render_vertexes(adata, i, rtex);
    }
}

void render_textures(s_appdata *adata, int depth)
{
    linked_node *rtexs = adata->lists->rtexs;
    while (rtexs != NULL && rtexs->data != NULL) {
        s_rtex *cur = (s_rtex *) rtexs->data;
        if (cur->depth != depth) {
            rtexs = rtexs->next;
            continue;
        }
        if (cur->depth >= adata->mask_rtex->depth && cur->depth <= adata->light_res_rtex->depth) {
            rtexs = rtexs->next;
            continue;
        }
        if (!my_strcmp(cur->id, adata->wall_rtex->id)) render_lights(adata);
        render_elements(adata, cur);
        s_rtex *next = get_rtex_d(adata, depth + 1);
        const sfTexture *cur_tex = sfRenderTexture_getTexture(cur->texture);
        sfSprite_setTexture(cur->sprite, cur_tex, sfFalse);
        if (next == NULL || !next->inherit) {
            sfRenderWindow_drawSprite(adata->win, cur->sprite, cur->state);
        } else {
            sfRenderTexture_drawSprite(next->texture, cur->sprite, cur->state);
        }
        rtexs = rtexs->next;
    }
}

void clear_rtexs(s_appdata *adata)
{
    linked_node *rtexs = adata->lists->rtexs;

    while (rtexs != NULL && rtexs->data != NULL) {
        s_rtex *cur = (s_rtex *) rtexs->data;

        sfRenderTexture_clear(cur->texture, cur->clear_color);

        rtexs = rtexs->next;
    }
}

void display_rtexs(s_appdata *adata)
{
    linked_node *rtexs = adata->lists->rtexs;

    while (rtexs != NULL && rtexs->data != NULL) {
        s_rtex *cur = (s_rtex *) rtexs->data;

        sfRenderTexture_display(cur->texture);

        rtexs = rtexs->next;
    }
}

void render(s_appdata *adata, float render_rate)
{
    s_clocks *clocks = adata->clocks;
    sfTime elapsed = sfClock_getElapsedTime(clocks->render_clock);
    s_ints *ints = adata->integers;
    float seconds = elapsed.microseconds / 1000000.0f;

    if (seconds >= render_rate) {
        sfRenderWindow_clear(adata->win, sfBlack);
        clear_rtexs(adata);

        for (int depth = ints->min_depth; depth <= ints->max_depth; depth++) {
            render_textures(adata, depth);
        }

        display_rtexs(adata);
        sfClock_restart(clocks->render_clock);
    }
}
