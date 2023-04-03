/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** entity module
*/

#include "main.h"

void load_entity_faction(s_appdata *adata)
{
    char *file_content = file_extract("bonus/entities.myrpg");
    char **entries = str_split(file_content, '\n');
    int ite = 0;

    while (entries[ite] != NULL) {
        if (entries[ite][0] == '#') {
            ite++;
            continue;
        }

        char **entry_data = str_split(entries[ite], ' ');

        if (!my_strcmp(entry_data[0], "faction_spawn")) {
            char *id = entry_data[1];
            add_faction(adata, id);
            sfVector2f pos = {my_getnbr(entry_data[2]), my_getnbr(entry_data[3])};
            set_faction_pos(adata, id, pos);
            set_faction_radius(adata, id, my_getnbr(entry_data[4]));
        }
        ite++;
    }
}

void load_entities(s_appdata *adata)
{
    for (int i = 0; i < 100; i++) {
        char *id = str_add("entity_", nbr_to_str(i));

        add_entity(adata, id);

        set_entity_sprite(adata, id, "ghost");
        set_entity_active(adata, id, sfTrue);
        set_entity_layer(adata, id, 4);
        set_entity_rtex(adata, id, get_str(adata, "rtex_game"));

        set_entity_stats(adata, id);

        sfVector2f pos = {rand() % 1500, rand() % 1500};
        move_entity(adata, id, pos);

        char *gobj_id = str_add(id, "@[:gobj]");

        add_gameobject(adata, gobj_id);


        s_entity *entity = get_entity(adata, id);
        set_gameobject_ref(adata, gobj_id, get_sprite(adata, entity->sprite->id), TYPE_SPRITE);
    }

}
