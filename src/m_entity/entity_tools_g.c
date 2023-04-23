/*
** EPITECH PROJECT, 2023
** m_entity
** File description:
** entity_tools_g
*/

#include "main.h"

void update_entity_collision_map(s_appdata *adata, s_entity *entity, void *ptr)
{
    sfFloatRect hitbox = get_entity_hitbox(adata, entity);

    for (int i = hitbox.top; i < (hitbox.top + hitbox.height) && i >= 0 &&
    i < adata->game_data->col_map_size.y; i++) {
        for (int j = hitbox.left; j < (hitbox.left + hitbox.width) && j >= 0 &&
        j < adata->game_data->col_map_size.x; j++) {
            adata->game_data->col_map[i][j] = ptr;
        }
    }
}
