/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Render texture module
*/

#include "../include/main.h"

s_rtex *get_rtex_d(s_appdata *adata, int depth)
{
    linked_node *rtexs = adata->lists->rtexs;

    while (rtexs != NULL && rtexs->data != NULL) {
        s_rtex * cur = (s_rtex *) rtexs->data;

        if (cur->depth == depth) return (cur);

        rtexs = rtexs->next;
    }

    return (NULL);
}

void set_rtex_shader(s_appdata *adata, char *id, sfShader *shader)
{
    s_rtex *rtex = get_rtex(adata, id);

    if (rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    rtex->state->shader = shader;
    rtex->shader = shader;
}

const sfTexture *get_rtex_tex(s_appdata *adata, char *id)
{
    s_rtex *rtex = get_rtex(adata, id);

    if (rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (NULL);
    }

    return (sfRenderTexture_getTexture(rtex->texture));
}

void set_rtex_clear(s_appdata *adata, char *id, sfColor color)
{
    s_rtex *rtex = get_rtex(adata, id);

    if (rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    rtex->clear_color = color;
}

void force_rtex(s_appdata *adata, char *id)
{
    s_rtex *rtex = get_rtex(adata, id);
    s_rtex *next = get_rtex_d(adata, rtex->depth + 1);
    const sfTexture *cur_tex = sfRenderTexture_getTexture(rtex->texture);

    sfSprite_setTexture(rtex->sprite, cur_tex, sfFalse);

    if (next == NULL || !next->inherit) {
        sfRenderWindow_drawSprite(adata->win, rtex->sprite, rtex->state);
    } else {
        sfRenderTexture_drawSprite(next->texture, rtex->sprite, rtex->state);
    }
}
