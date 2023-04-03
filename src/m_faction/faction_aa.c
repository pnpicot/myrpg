/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** entity
*/

#include "../include/main.h"

s_faction *get_faction(s_appdata *adata, char *id)
{
    linked_node *factions = adata->game_data->factions;

    while (factions != NULL && factions->data != NULL) {
        s_faction *cur = (s_faction *) factions->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        factions = factions->next;
    }

    return (NULL);
}

void add_faction(s_appdata *adata, char *id)
{
    s_faction *faction = get_faction(adata, id);
    if (faction != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    s_faction *new_faction = malloc(sizeof(s_faction));

    new_faction->id = id;
    new_faction->pos = (sfVector2f) {0, 0};
    new_faction->radius = 1;

    linked_add(adata->game_data->factions, new_faction);
}

void set_faction_pos(s_appdata *adata, char *id, sfVector2f pos)
{
    s_faction *faction = get_faction(adata, id);
    if (faction != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    faction->pos = pos;
}

void set_faction_radius(s_appdata *adata, char *id, float radius)
{
    s_faction *faction = get_faction(adata, id);
    if (faction != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    faction->radius = radius;
}