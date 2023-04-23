/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Parasite (player) module
*/

#include "main.h"

void update_host_controls(s_appdata *adata)
{
    s_player *player = adata->player;
    s_entity *host = (s_entity *) player->host;
    sfVector2f add = { 0, 0 };
    float seconds = get_clock_seconds(adata->clocks->update_clock);
    if (get_key(adata, sfKeyQ))
        add.x -= host->speed * seconds;
    if (get_key(adata, sfKeyZ))
        add.y -= host->speed * seconds;
    if (get_key(adata, sfKeyD))
        add.x += host->speed * seconds;
    if (get_key(adata, sfKeyS))
        add.y += host->speed * seconds;
    add = is_map_colliding(adata, host, add);
    translate_entity(adata, host, add);
    if ((add.x != 0 || add.y != 0) && host->orientated) {
        float angle = (atan2f(add.y, add.x) * (180 / M_PI)) + 90.0f;
        rotate_entity_abs(adata, host, angle);
    }
}
