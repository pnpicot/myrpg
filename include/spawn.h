/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity spawning module
*/

#pragma once

#include "main.h"

s_sprite *copy_entity_part_sprite(s_appdata *adata, s_sprite *sprite);
s_entity_part *copy_entity_part(s_appdata *adata, s_entity_part *part);
linked_node *copy_entity_model_parts(s_appdata *adata, linked_node *parts);
s_entity *copy_entity_model(s_appdata *adata, s_entity *model);
void try_entity_spawn(s_appdata *adata, s_entity *model);
void trigger_spawn_cycle(s_appdata *adata);
s_bar *get_entity_hp_bar(s_appdata *adata, s_entity *entity);
s_zone *fill_zone(s_appdata *adata, s_entity *entity, sfVector2f pos);
