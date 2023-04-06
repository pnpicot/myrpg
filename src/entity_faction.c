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
            set_faction_spawn_rate(adata, id_faction, str_to_float(entry_data[5]));

            ite++;
            continue;
        }

        char *entity_id = str_m_add(4, entry_data[0], "@[:", get_random_id(8), "]");

        add_entity(adata, entity_id, 0);

        int path_rank = 7;
        while (entry_data[path_rank] != NULL) {

            char **body_part = str_split(entry_data[path_rank], '-');

            char *entity_sprite_id = str_add(entity_id,"@[:sprite]");
            entity_sprite_id = str_m_add(4, entity_sprite_id, "@[:", body_part[1], "]");

            set_entity_sprite(adata, entity_id, body_part[0], entity_sprite_id);
            set_entity_layer(adata, entity_id, path_rank - 7, path_rank - 3);

            char *gobj_id = str_add(entity_sprite_id, "@[:gobj]");
            add_gameobject(adata, gobj_id);

            set_gameobject_ref(adata, gobj_id, get_sprite(adata, entity_sprite_id), TYPE_SPRITE);

            path_rank++;
        }

        set_entity_active(adata, entity_id, sfFalse);
        set_entity_rtex(adata, entity_id, get_str(adata, "rtex_game"));

        set_entity_stats(adata, entity_id);
        set_entity_stats_faction(adata, entity_id, entry_data[0]);
        set_entity_stats_type(adata, entity_id, entry_data[1]);
        set_entity_stats_hp(adata, entity_id, my_getnbr(entry_data[2]));
        set_entity_stats_dammage(adata, entity_id, my_getnbr(entry_data[3]));
        set_entity_stats_speed(adata, entity_id, my_getnbr(entry_data[4]));
        set_entity_stats_transference_level(adata, entity_id, my_getnbr(entry_data[5]));
        set_entity_spawn_rate(adata, entity_id, my_getnbr(entry_data[6]));

        ite++;
    }
}
