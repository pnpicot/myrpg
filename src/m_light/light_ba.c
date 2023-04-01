/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Lighting module
*/

#include "../include/main.h"

void set_lightblend_rtex(s_appdata *adata, char *rtex_id)
{
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    adata->light_blend_rtex = rtex;
}

void set_light_rtex(s_appdata *adata, char *rtex_id)
{
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    adata->light_rtex = rtex;
}

void set_lightres_rtex(s_appdata *adata, char *rtex_id)
{
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    adata->light_res_rtex = rtex;
}

s_light *get_light(s_appdata *adata, char *id)
{
    linked_node *lights = adata->lists->lights;

    while (lights != NULL && lights->data != NULL) {
        s_light *cur = (s_light *) lights->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        lights = lights->next;
    }

    return (NULL);
}

void delete_light(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *lights = adata->lists->lights;
    int ite = 0;

    while (lights != NULL && lights->data != NULL) {
        s_light *cur = (s_light *) lights->data;

        if (!my_strcmp(cur->id, id)) break;

        ite++;
        lights = lights->next;
    }

    linked_delete(&adata->lists->lights, ite);
}
