/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Render module
*/

#include "../include/main.h"

void render_rects(s_appdata *adata, s_rtex *rtex, s_ref *ref)
{
    s_rect *cur = (s_rect *) ref->ref;

    if (!cur->active || cur->hidden) {
        return;
    }

    sfRenderTexture_drawRectangleShape(rtex->texture, cur->elem, NULL);
}

void render_circles(s_appdata *adata, s_rtex *rtex, s_ref *ref)
{
    s_circle *cur = (s_circle *) ref->ref;

    if (!cur->active || cur->hidden) {
        return;
    }

    sfRenderTexture_drawCircleShape(rtex->texture, cur->elem, NULL);
}

void render_sprites(s_appdata *adata, s_rtex *rtex, s_ref *ref)
{
    s_sprite *cur = (s_sprite *) ref->ref;

    if (!cur->active || cur->hidden) {
        return;
    }

    sfRenderTexture_drawSprite(rtex->texture, cur->elem, NULL);
}

void render_texts(s_appdata *adata, s_rtex *rtex, s_ref *ref)
{
    s_text *cur = (s_text *) ref->ref;

    if (!cur->active || cur->hidden) {
        return;
    }

    sfRenderTexture_drawText(rtex->texture, cur->elem, NULL);
}

void render_vertexes(s_appdata *adata, s_rtex *rtex, s_ref *ref)
{
    s_vertex *cur = (s_vertex *) ref->ref;

    if (!cur->active || cur->hidden) {
        return;
    }

    sfRenderTexture_drawVertexArray(rtex->texture, cur->elem, NULL);
}
