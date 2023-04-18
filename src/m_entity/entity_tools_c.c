/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

void set_entity_behavior(s_appdata *adata, char *id, \
void (*behavior)(s_appdata *adata, s_entity *s_entity))
{
    s_entity *model = get_entity_model(adata, id);

    if (model == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    model->behavior = behavior;
}

void set_entity_emiter(s_appdata *adata, char *id, \
void (*emiter)(s_appdata *adata, s_entity *s_entity))
{
    s_entity *model = get_entity_model(adata, id);

    if (model == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    model->emiter = emiter;
}

void update_entities(s_appdata *adata)
{
    linked_node *entities = adata->game_data->entities;

    while (entities != NULL && entities->data != NULL) {
        s_entity *cur = (s_entity *) entities->data;

        (*cur->behavior)(adata, cur);

        entities = entities->next;
    }
}

sfFloatRect get_entity_hitbox(s_appdata *adata, s_entity *entity)
{
    sfFloatRect hitbox =
    {.left = entity->pos.x + entity->hitbox.left - adata->game_data->view_pos.x
    - entity->hitbox.width * entity->scale / 2,
    .top = entity->pos.y + entity->hitbox.top - adata->game_data->view_pos.y
    - entity->hitbox.height * entity->scale / 2 ,
    .width = entity->hitbox.width * entity->scale,
    .height = entity->hitbox.height * entity->scale};
    return (hitbox);
}

void update_entity_bar(s_appdata *adata, s_entity *entity)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    sfVector2f pos = sfSprite_getPosition(((s_entity_part *) entity->parts->data)->sprite->elem);

    pos.y -= 120.0f;

    if (entity->hp < 0)
        entity->hp = 0;
    if (entity->hp > entity->st_hp)
        entity->hp = entity->st_hp;

    color_bar(adata, entity->hp_bar->id, get_color(150, 0, 0, 255),
    lerp_color(sfRed, sfGreen, entity->hp / entity->st_hp));
    move_bar(adata, entity->hp_bar->id, pos);
    set_bar_current(adata, entity->hp_bar->id, entity->hp);
}
