/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Render module
*/

#include "include/main.h"

void render_rects(s_appdata *adata, int layer, s_rtex *rtex)
{
    linked_node *rects = adata->lists->rects;

    while (rects != NULL && rects->data != NULL) {
        s_rect *cur = (s_rect *) rects->data;

        if (cur->layer != layer || !cur->active || cur->hidden || my_strcmp(rtex->id, cur->rtex_id)) {
            rects = rects->next;
            continue;
        }

        sfRenderTexture_drawRectangleShape(rtex->texture, cur->elem, NULL);
        rects = rects->next;
    }
}

void render_circles(s_appdata *adata, int layer, s_rtex *rtex)
{
    linked_node *circles = adata->lists->circles;

    while (circles != NULL && circles->data != NULL) {
        s_circle *cur = (s_circle *) circles->data;

        if (cur->layer != layer || !cur->active || cur->hidden || my_strcmp(rtex->id, cur->rtex_id)) {
            circles = circles->next;
            continue;
        }

        sfRenderTexture_drawCircleShape(rtex->texture, cur->elem, NULL);
        circles = circles->next;
    }
}

void render_sprites(s_appdata *adata, int layer, s_rtex *rtex)
{
    linked_node *sprites = adata->lists->sprites;

    while (sprites != NULL && sprites->data != NULL) {
        s_sprite *cur = (s_sprite *) sprites->data;

        if (cur->layer != layer || !cur->active || cur->hidden || my_strcmp(rtex->id, cur->rtex_id)) {
            sprites = sprites->next;
            continue;
        }

        sfRenderTexture_drawSprite(rtex->texture, cur->elem, NULL);
        sprites = sprites->next;
    }
}

void render_texts(s_appdata *adata, int layer, s_rtex *rtex)
{
    linked_node *texts = adata->lists->texts;

    while (texts != NULL && texts->data != NULL) {
        s_text *cur = (s_text *) texts->data;

        if (cur->layer != layer || !cur->active || cur->hidden || my_strcmp(rtex->id, cur->rtex_id)) {
            texts = texts->next;
            continue;
        }

        sfRenderTexture_drawText(rtex->texture, cur->elem, NULL);
        texts = texts->next;
    }
}

void render_vertexes(s_appdata *adata, int layer, s_rtex *rtex)
{
    linked_node *vertexes = adata->lists->vertexes;

    while (vertexes != NULL && vertexes->data != NULL) {
        s_vertex *cur = (s_vertex *) vertexes->data;

        if (cur->layer != layer || !cur->active || cur->hidden || my_strcmp(rtex->id, cur->rtex_id)) {
            vertexes = vertexes->next;
            continue;
        }

        sfRenderTexture_drawVertexArray(rtex->texture, cur->elem, NULL);
        vertexes = vertexes->next;
    }
}

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

        sfRenderTexture_clear(cur->texture, sfTransparent);

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
