/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "../include/main.h"

void init_Z200(s_appdata *adata, s_entity *entity)
{
/*     char *sprite_id = get_body_part_sprite(entity, "blades")->id;
    set_sprite_origin(adata, sprite_id, (sfVector2f) {32, 32});
    move_sprite(adata, get_sprite_by_body_part(adata, entity, "blades")->id, (sfVector2f) {32, 32});

    sprite_id = get_body_part_sprite(entity, "rotors")->id;
    set_sprite_origin(adata, sprite_id, (sfVector2f) {32, 32}); */
    //sfSprite_setPosition(get_sprite_by_body_part(adata, entity, "rotors")->elem, (sfVector2f) {32, 32});
}

s_sprite *get_body_part_sprite(s_entity *entity, char *body_part_id)
{
    linked_node *body_part = entity->body_part;

    while (body_part != NULL && body_part->data != NULL) {
        s_sprite *sprite = (s_sprite *) body_part->data;

        if (!my_strcmp(sprite->id, body_part_id)) {
            return (sprite);
        }

        body_part = body_part->next;
    }
}

void Z200_bevahior(s_appdata *adata, s_entity *entity)
{
    float second = get_clock_seconds(entity->clock);

    if (second >= 0.01f) {
        //rotate_sprite_add(adata, get_body_part_sprite(entity, "blades")->id, 10.0f);
        //rotate_sprite_add(adata, get_body_part_sprite(entity, "rotors")->id, 10.0f);
    }

    if (second >= 0.1f) {
        sfVector2f add = { 2.0f, 0.0f };

        add = is_map_colliding(adata, sfSprite_getGlobalBounds(
        ((s_sprite *)entity->body_part->data)->elem), add);

        translate_entity(adata, entity->id, add);

        sfClock_restart(entity->clock);
    }
}
