/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Syringe item module
*/

#include "main.h"

s_syringe *get_syringe(s_appdata *adata, char *id)
{
    linked_node *syringes = adata->game_data->syringes;

    while (syringes != NULL && syringes->data != NULL) {
        s_syringe *cur = (s_syringe *) syringes->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        syringes = syringes->next;
    }

    return (NULL);
}

void delete_syringe(s_appdata *adata, char *id)
{
    s_syringe *syringe = get_syringe(adata, id);

    if (syringe == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    linked_node *syringes = adata->game_data->syringes;
    int ite = 0;

    while (syringes != NULL && syringes->data != NULL) {
        s_syringe *cur = (s_syringe *) syringes->data;

        if (!my_strcmp(cur->id, id)) break;

        ite++;
        syringes = syringes->next;
    }
    linked_delete(&adata->game_data->syringes, ite);
}

void add_syringe(s_appdata *adata, char *id)
{
    s_syringe *syringe = get_syringe(adata, id);

    if (syringe != NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "already_exists"));
        return;
    }
    s_syringe *new_syringe = malloc(sizeof(s_syringe));
    if (new_syringe == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return;
    }
    new_syringe->count = 0;
    new_syringe->id = id;
    new_syringe->on_use = NULL;
    new_syringe->tex = NULL;
    new_syringe->name = "New Syringe";
    new_syringe->color = sfWhite;
    linked_add(adata->game_data->syringes, new_syringe);
}

void set_syringe_color(s_appdata *adata, char *id, sfColor color)
{
    s_syringe *syringe = get_syringe(adata, id);

    if (syringe == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    syringe->color = color;
}

void set_syringe_use(s_appdata *adata, char *id, \
void (*on_use)(s_appdata *adata, s_ref *ref))
{
    s_syringe *syringe = get_syringe(adata, id);

    if (syringe == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    syringe->on_use = on_use;
}
