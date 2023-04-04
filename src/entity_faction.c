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
            char *id_faction = entry_data[1];
            add_faction(adata, id_faction);
            sfVector2f pos = {my_getnbr(entry_data[2]), my_getnbr(entry_data[3])};
            set_faction_pos(adata, id_faction, pos);
            set_faction_radius(adata, id_faction, str_to_float(entry_data[4]));

            ite++;
            continue;
        }


        char *id_entity = str_add(entry_data[0], nbr_to_str(ite));
        add_entity(adata, id_entity);
        set_entity_sprite(adata, id_entity, entry_data[6]);
        set_entity_active(adata, id_entity, sfTrue);
        set_entity_layer(adata, id_entity, 4);
        set_entity_rtex(adata, id_entity, get_str(adata, "rtex_game"));

        set_entity_spawn(adata, id_entity);

        set_entity_stats(adata, id_entity);
        set_entity_stats_faction(adata, id_entity, entry_data[0]);
        set_entity_stats_type(adata, id_entity, entry_data[1]);
        set_entity_stats_hp(adata, id_entity, my_getnbr(entry_data[2]));
        set_entity_stats_dammage(adata, id_entity, my_getnbr(entry_data[3]));
        set_entity_stats_speed(adata, id_entity, my_getnbr(entry_data[4]));
        set_entity_stats_transference_level(adata, id_entity, my_getnbr(entry_data[5]));

        char *gobj_id = str_add(id_entity, "@[:gobj]");
        add_gameobject(adata, gobj_id);
        s_entity *entity = get_entity(adata, id_entity);
        set_gameobject_ref(adata, gobj_id, get_sprite(adata, entity->sprite->id), TYPE_SPRITE);

        ite++;
    }
}

/* void load_entities(s_appdata *adata)
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
 */