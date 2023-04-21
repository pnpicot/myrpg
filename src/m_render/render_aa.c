/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Render module
*/

#include "../include/main.h"

void render_elements(s_appdata *adata, s_rtex *rtex)
{
    linked_node *node = rtex->objects;

    while (node != NULL && node->data != NULL) {
        s_ref *ref = (s_ref *) node->data;
        if (ref->type == TYPE_RECT)
            render_rects(adata, rtex, ref);
        if (ref->type == TYPE_SPRITE)
            render_sprites(adata, rtex, ref);
        if (ref->type == TYPE_TEXT)
            render_texts(adata, rtex, ref);
        if (ref->type == TYPE_CIRCLE)
            render_circles(adata, rtex, ref);
        if (ref->type == TYPE_EMITER)
            update_emiters(adata, ref);
        if (ref->type == TYPE_VERTEX)
            render_vertexes(adata, rtex, ref);
        node = node->next;
    }
}

void render_textures(s_appdata *adata, int depth)
{
    linked_node *rtexs = adata->lists->rtexs;
    s_ints *integers = adata->integers;
    while (rtexs != NULL && rtexs->data != NULL) {
        s_rtex *cur = (s_rtex *) rtexs->data;
        if (cur->depth != depth || !cur->active) {
            rtexs = rtexs->next;
            continue;
        }
        int in_light_range = adata->mask_rtex != NULL && cur->depth >= adata->mask_rtex->depth && cur->depth <= adata->light_res_rtex->depth;
        if (in_light_range && integers->in_game) {
            rtexs = rtexs->next;
            continue;
        }
        if (get_int(adata, "enable_shader") && integers->in_game && cur->depth == adata->light_blend_rtex->depth + 1) render_lights(adata);
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

        if (!cur->active) {
            rtexs = rtexs->next;
            continue;
        }

        sfRenderTexture_clear(cur->texture, cur->clear_color);

        rtexs = rtexs->next;
    }
}

void display_rtexs(s_appdata *adata)
{
    linked_node *rtexs = adata->lists->rtexs;

    while (rtexs != NULL && rtexs->data != NULL) {
        s_rtex *cur = (s_rtex *) rtexs->data;

        if (!cur->active) {
            rtexs = rtexs->next;
            continue;
        }

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
