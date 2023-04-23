/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Parasite (player) module
*/

#include "main.h"

void init_player(s_appdata *adata)
{
    adata->player = malloc(sizeof(s_player));
    if (adata->player == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return;
    }
    *adata->player = (s_player) { 0 };
    s_player *player = adata->player;
    char *sprite_id = get_str(adata, "player_body");
    char *rtex = get_str(adata, "rtex_game");
    char *container = get_str(adata, "ctn_game");
    init_player_next(adata, player);
    add_sprite(adata, sprite_id, 5);
    set_sprite_rtex(adata, sprite_id, rtex);
    s_sprite *body = get_sprite(adata, sprite_id);
    player->body = body;
    add_to_container(adata, container, (s_ref) { body, TYPE_SPRITE });
    set_sprite_texture(adata, sprite_id, get_texture(adata, "parasite"));
    init_player_final(adata, player, sprite_id);
}

void try_transference_n(s_appdata *adata, char *emiter_id)
{
    s_entity *host = (s_entity *) adata->player->host;
    char *host_emiter_id = str_add(host->id, "@[:emiter]");
    s_game *game_data = adata->game_data;
    host->inhabited = sfFalse;
    adata->player->host = NULL;
    adata->player->body->active = 1;
    game_data->speed = (sfVector2f) { 0, 0 };
    linked_node *paths = host->path;
    while (paths != NULL) {
        linked_node *save = paths;
        paths = paths->next;
        free(save->data);
        free(save);
    }
    host->path = NULL;
    sfClock_restart(host->clock);
    sfClock_restart(adata->player->transference_clock);
    set_emiter_active(adata, emiter_id, sfTrue);
    set_emiter_active(adata, host_emiter_id, sfTrue);
}

void try_transference(s_appdata *adata)
{
    s_player *player = adata->player;
    char *emiter_id = get_str(adata, "player_particles");
    if (player->host != NULL) {
        try_transference_n(adata, emiter_id);
        return;
    }
    if (player->transference.x != player->transference.y
        || ((s_entity *) player->potential_host)->trf_require
        > player->transference_level) return;
    player->host = player->potential_host;
    if (player->host != NULL) {
        s_entity *host = (s_entity *) player->host;
        char *host_emiter_id = str_add(host->id, "@[:emiter]");
        host->inhabited = sfTrue;
        player->transfered = sfTrue;
        player->body->active = 0;
        player->transference.x = 0;
        set_emiter_active(adata, emiter_id, sfFalse);
        set_emiter_active(adata, host_emiter_id, sfFalse);
    }
}

void check_game_keys_n(s_appdata *adata, int keycode)
{
    if (keycode == sfKeyA) {
        adata->game_data->show_quest = !adata->game_data->show_quest;
        char *ctn = get_str(adata, "ctn_quest");
        set_container_active(adata, ctn, adata->game_data->show_quest ? 1 : 0);
        linked_node *quests = adata->game_data->quests;
        while (quests != NULL && quests->data != NULL) {
            s_quest *cur = (s_quest *) quests->data;
            cur->popup_rect->active = 0;
            cur->popup_text->active = 0;
            quests = quests->next;
        }
    } if (keycode == sfKeyT) {
        adata->game_data->in_stree = !adata->game_data->in_stree;
        sfUint8 active = adata->game_data->in_stree ? 1 : 0;
        adata->integers->in_game = adata->game_data->in_stree ? 0 : 1;
        char *ctn = get_str(adata, "ctn_skill");
        set_container_active(adata, ctn, active);
        set_rect_active(adata, get_str(adata, "skill_tree"), active);
        set_text_active(adata, str_add(get_str(adata, "skill_tree"),
        "@[:title]"), active);
    }
}

void check_game_keys(s_appdata *adata, int keycode)
{
    if (keycode == sfKeyE)
        try_transference(adata);
    if (keycode == sfKeyC) {
        sfBool active = is_container_active(adata,
        get_str(adata, "console_id"));
        active = active == sfTrue ? sfFalse : sfTrue;
        set_container_active(adata, get_str(adata, "console_id"), active);
    }
    if (keycode == sfKeyI || keycode == sfKeyTab) {
        adata->game_data->in_inv = !adata->game_data->in_inv;
        char *ctn = get_str(adata, "ctn_inv");
        set_container_active(adata, ctn, adata->game_data->in_inv ? 1 : 0);
        adata->integers->in_game = adata->game_data->in_inv ? 0 : 1;
    }
    check_game_keys_n(adata, keycode);
}
