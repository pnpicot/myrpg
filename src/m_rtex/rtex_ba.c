/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Render texture module
*/

#include "../include/main.h"

s_rtex *get_rtex(s_appdata *adata, char *id)
{
    linked_node *rtexs = adata->lists->rtexs;

    while (rtexs != NULL && rtexs->data != NULL) {
        s_rtex *cur = (s_rtex *) rtexs->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        rtexs = rtexs->next;
    }

    return (NULL);
}

sfRenderStates *get_default_rstate(void)
{
    sfRenderStates *state = malloc(sizeof(sfRenderStates));

    state->blendMode = sfBlendNone;
    state->shader = NULL;
    state->texture = NULL;
    state->transform = sfTransform_Identity;

    return (state);
}

void add_rtex_next(s_appdata *adata, char *id, int depth, s_rtex *new_rtex)
{
    s_ints *ints = adata->integers;
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    new_rtex->depth = depth;
    new_rtex->id = id;
    new_rtex->inherit = sfFalse;
    new_rtex->mode = sfBlendNone;
    new_rtex->shader = NULL;
    new_rtex->sprite = sfSprite_create();
    new_rtex->clear_color = sfBlack;
    new_rtex->state = get_default_rstate();
    new_rtex->texture = sfRenderTexture_create(win_w, win_h, sfFalse);
    if (depth < ints->min_depth) ints->min_depth = depth;
    if (depth > ints->max_depth) ints->max_depth = depth;
    linked_add(adata->lists->rtexs, new_rtex);
}

void add_rtex(s_appdata *adata, char *id, int depth)
{
    s_rtex *rtex = get_rtex(adata, id);
    if (rtex != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }
    s_rtex *new_rtex = malloc(sizeof(s_rtex));
    if (new_rtex == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }
    add_rtex_next(adata, id, depth, new_rtex);
}

void delete_rtex(s_appdata *adata, char *id)
{
    s_rtex *rtex = get_rtex(adata, id);
    if (rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }
    linked_node *rtexs = adata->lists->rtexs;
    int ite = 0;
    while (rtexs != NULL && rtexs->data != NULL) {
        s_rtex *cur = (s_rtex *) rtexs->data;
        if (!my_strcmp(cur->id, id)) {
            sfRenderTexture_destroy(cur->texture);
            sfSprite_destroy(cur->sprite);
            free(cur->state);
            break;
        }
        ite++;
        rtexs = rtexs->next;
    }
    linked_delete(&adata->lists->rtexs, ite);
}
