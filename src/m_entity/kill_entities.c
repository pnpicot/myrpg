/*
** EPITECH PROJECT, 2023
** m_entity
** File description:
** kill_entities
*/

#include "main.h"

static void kill_by_us(s_appdata *adata, s_entity *entity)
{
    adata->player->killed_enemy = 1;
    adata->player->moula += 50;
    if (rand() % 5 == 0) {
        char *id = NULL;
        int r = rand() % 4;

        if (r == 0)
            id = get_str(adata, "attack_syr");
        if (r == 1)
            id = get_str(adata, "trf_syr");
        if (r == 2)
            id = get_str(adata, "health_syr");
        if (r == 3)
            id = get_str(adata, "defense_syr");
        get_syringe(adata, id)->count++;
    }
}

void kill_entities(s_appdata *adata, s_entity *entity, int ite)
{
    entity->dead = 1;
    if ((fabs(entity->pos.x - adata->player->hitbox.left) +
    fabs(entity->pos.y - adata->player->hitbox.top)) <= 1000)
        kill_by_us(adata, entity);
    update_entity_collision_map(adata, entity, NULL);
    if (entity->emiter != NULL) {
        char *emiter_id = str_add(entity->id, "@[:emiter]");
        set_emiter_active(adata, emiter_id, sfFalse);
    }
    set_bar_active(adata, entity->hp_bar->id, sfFalse);
    linked_node *parts = entity->parts;
    while (parts != NULL && parts->data != NULL) {
        s_entity_part *part = (s_entity_part *) parts->data;
        sfSprite_setColor(part->sprite->elem, sfColor_fromRGB(50, 50, 50));
        parts = parts->next;
    } if (entity->inhabited) try_transference(adata);
    linked_delete(&adata->game_data->entities, ite);
    free(entity);

}
