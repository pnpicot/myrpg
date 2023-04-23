/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Faction module
*/

#include "main.h"

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

void delete_faction(s_appdata *adata, char *id)
{
    s_faction *faction = get_faction(adata, id);

    if (faction == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    linked_node *factions = adata->game_data->factions;
    int ite = 0;

    while (factions != NULL && factions->data !=  NULL) {
        s_faction *cur = (s_faction *) factions->data;

        if (!my_strcmp(cur->id, id)) break;

        ite++;
        factions = factions->next;
    }
    linked_delete(&adata->game_data->factions, ite);
}

void add_faction_next(s_appdata *adata, char **entry, s_faction *new_faction)
{
    char *faction_id = entry[1];
    float faction_x = str_to_float(entry[2]);
    float faction_y = str_to_float(entry[3]);
    float faction_r = str_to_float(entry[4]);
    int faction_max = my_getnbr(entry[5]);
    new_faction->id = faction_id;
    new_faction->spawn_point = (sfVector2f) { faction_x, faction_y };
    new_faction->spawn_radius = faction_r;
    new_faction->entity_count = 0;
    new_faction->entity_max = faction_max;
    new_faction->models = linked_new();
    free(entry[0]);
    for (int i = 2; entry[i] != NULL; i++)
        free(entry[i]);
    free(entry);
    linked_add(adata->game_data->factions, new_faction);
}

void add_faction(s_appdata *adata, char **entry)
{
    if (count_nil_str(entry) < 6 || !is_format(entry, "sssfffd"))
        return;
    char *faction_id = entry[1];
    s_faction *faction = get_faction(adata, faction_id);
    if (faction != NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "already_exists"));
        return;
    }
    s_faction *new_faction = malloc(sizeof(s_faction));
    if (new_faction == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return;
    }
    add_faction_next(adata, entry, new_faction);
}

void load_entity_config(s_appdata *adata)
{
    char *file_content = file_extract("bonus/entities.myrpg");
    char **entries = str_split(file_content, '\n');
    free(file_content);
    for (int ite = 0;entries[ite] != NULL; ++ite) {
        if (entries[ite][0] == '#') continue;
        char **entry_data = str_split(entries[ite], ' ');
        if (!my_strcmp(entry_data[0], "faction")) {
            add_faction(adata, entry_data);
            continue;
        } if (!my_strcmp(entry_data[0], "entity")) {
            add_entity_model(adata, entry_data);
            continue;
        } if (!my_strcmp(entry_data[0], "part")) {
            add_entity_part(adata, entry_data);
            continue;
        } for (int i = 0; entry_data[i] != NULL; i++) free(entry_data[i]);
        free(entry_data);
    }
    for (int i = 0; entries[i] != NULL; i++) free(entries[i]);
    free(entries);
}
