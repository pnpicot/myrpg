/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Render module
*/

#include "../include/main.h"

void render_rects(s_appdata *adata, int layer, s_rtex *rtex)
{
    linked_node *rects = adata->lists->rects;

    while (rects != NULL && rects->data != NULL) {
        s_rect *cur = (s_rect *) rects->data;
        int no_render = cur->hidden || my_strcmp(rtex->id, cur->rtex_id);

        if (cur->layer != layer || !cur->active || no_render) {
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
        int no_render = cur->hidden || my_strcmp(rtex->id, cur->rtex_id);

        if (cur->layer != layer || !cur->active || no_render) {
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
        int no_render = cur->hidden || my_strcmp(rtex->id, cur->rtex_id);

        if (cur->layer != layer || !cur->active || no_render) {
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
        int no_render = cur->hidden || my_strcmp(rtex->id, cur->rtex_id);

        if (cur->layer != layer || !cur->active || no_render) {
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
        int no_render = cur->hidden || my_strcmp(rtex->id, cur->rtex_id);

        if (cur->layer != layer || !cur->active || no_render) {
            vertexes = vertexes->next;
            continue;
        }

        sfRenderTexture_drawVertexArray(rtex->texture, cur->elem, NULL);
        vertexes = vertexes->next;
    }
}
