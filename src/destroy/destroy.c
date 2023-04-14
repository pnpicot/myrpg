/*
** EPITECH PROJECT, 2023
** destroy
** File description:
** destroy
*/

#include "main.h"

void free_linked(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(save);
    }
}

void destroy_clocks(s_clocks *clocks)
{
    sfClock_destroy(clocks->app_clock);
    sfClock_destroy(clocks->update_clock);
    sfClock_destroy(clocks->render_clock);
    sfClock_destroy(clocks->input_clock);
    sfClock_destroy(clocks->fps_clock);
    sfClock_destroy(clocks->fps_display_clock);
    sfClock_destroy(clocks->movement_clock);
    free(clocks);
}

void destroy(s_appdata *adata)
{
    free(adata->floats);
    free(adata->integers);
    sfClock_destroy(adata->player->transference_clock);
    free(adata->player);
    destroy_clocks(adata->clocks);
    free(adata->keys);
    linked_destroy_entity_models(adata->game_data->entity_models);
    linked_destroy_entities(adata->game_data->entities);
    linked_destroy_factions(adata->game_data->factions);
    free_linked(adata->game_data->syringes);
    free(adata->game_data);
    free_lists(adata->lists);
    free(adata);
}
