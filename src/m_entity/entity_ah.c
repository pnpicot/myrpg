/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

void set_entity_model_origin(s_appdata *adata, char *id, \
char *part_id, sfVector2f origin)
{
    s_entity *model = get_entity_by_model(adata, id, 0);

    if (model == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *parts = model->body_part;

    while (parts != NULL && parts->data != NULL) {
        s_sprite *cur = (s_sprite *) parts->data;
        char *cur_id = get_id_sub(cur->id, 2);

        if (!my_strcmp(cur_id, part_id))
            set_sprite_origin(adata, cur->id, origin);

        parts = parts->next;
    }
}
