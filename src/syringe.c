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
        my_printf(get_error(adata, "unknown_id"));
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
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    s_syringe *new_syringe = malloc(sizeof(s_syringe));

    if (new_syringe == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    new_syringe->count = 0;
    new_syringe->id = id;
    new_syringe->on_use = NULL;
    new_syringe->tex = NULL;
}

void set_syringe_use(s_appdata *adata, char *id, \
void (*on_use)(s_appdata *adata, s_syringe *syringe))
{
    s_syringe *syringe = get_syringe(adata, id);

    if (syringe == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    syringe->on_use = on_use;
}

void set_syringe_count(s_appdata *adata, char *id, int count)
{
    s_syringe *syringe = get_syringe(adata, id);

    if (syringe == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    syringe->count = count;
}

void syringe_increment(s_appdata *adata, char *id, int amount)
{
    s_syringe *syringe = get_syringe(adata, id);

    if (syringe == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    syringe->count += amount;
}

void syringe_decrement(s_appdata *adata, char *id, int amount)
{
    s_syringe *syringe = get_syringe(adata, id);

    if (syringe == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    syringe->count -= amount;
}

void set_syringe_texture(s_appdata *adata, char *id, sfTexture *texture)
{
    s_syringe *syringe = get_syringe(adata, id);

    if (syringe == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    syringe->tex = texture;
}

int get_syringe_count(s_appdata *adata, char *id)
{
    s_syringe *syringe = get_syringe(adata, id);

    if (syringe == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (-1);
    }

    return (syringe->count);
}

sfTexture *get_syringe_texture(s_appdata *adata, char *id)
{
    s_syringe *syringe = get_syringe(adata, id);

    if (syringe == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (NULL);
    }

    return (syringe->tex);
}
