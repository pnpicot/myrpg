/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Entity module
*/

#include "main.h"

s_entity *get_entity_model(s_appdata *adata, char *id)
{
    linked_node *models = adata->game_data->entity_models;

    while (models != NULL && models->data != NULL) {
        s_entity *cur = (s_entity *) models->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        models = models->next;
    }

    return (NULL);
}

void delete_entity_model(s_appdata *adata, char *id)
{
    s_entity *model = get_entity_model(adata, id);

    if (model == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *models = adata->game_data->entity_models;
    int ite = 0;

    while (models != NULL && models->data != NULL) {
        s_entity *cur = (s_entity *) models->data;

        if (!my_strcmp(cur->id, id)) break;

        ite++;
        models = models->next;
    }

    linked_delete(&adata->game_data->entity_models, ite);
}

s_entity_part *get_entity_model_part(s_appdata *adata, char *model_id, \
char *part_id)
{
    s_entity *model = get_entity_model(adata, model_id);

    if (model == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (NULL);
    }

    linked_node *parts = model->parts;

    while (parts != NULL && parts->data != NULL) {
        s_entity_part *cur = (s_entity_part *) parts->data;

        if (!my_strcmp(cur->id, part_id)) return (cur);

        parts = parts->next;
    }

    return (NULL);
}

s_sprite *get_entity_part_model(s_appdata *adata, \
s_entity_part *model, sfTexture *tex, float scale)
{
    char *id = str_add(model->id, "@[:part]");
    char *rtex = get_str(adata, "rtex_game");
    char *container = get_str(adata, "ctn_game");

    add_sprite(adata, id, model->layer);
    set_sprite_texture(adata, id, tex);
    set_sprite_active(adata, id, 0);
    set_sprite_origin(adata, id, model->origin);
    move_sprite(adata, id, model->offset);
    scale_sprite(adata, id, (sfVector2f) { scale, scale });
    set_sprite_rtex(adata, id, rtex);

    s_sprite *sprite = get_sprite(adata, id);
    return (sprite);
}
