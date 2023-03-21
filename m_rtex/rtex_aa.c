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
