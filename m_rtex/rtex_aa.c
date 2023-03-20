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
