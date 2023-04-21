/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Audio module
*/

#include "../include/main.h"

void stop_music(s_appdata *adata, char *id)
{
    s_music *music = get_music(adata, id);

    if (music == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    sfMusic_stop(music->music);
}

void pause_music(s_appdata *adata, char *id)
{
    s_music *music = get_music(adata, id);

    if (music == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    sfMusic_pause(music->music);
}

void set_music_volume(s_appdata *adata, char *id, float volume)
{
    s_music *music = get_music(adata, id);

    if (music == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    sfMusic_setVolume(music->music, volume);
}

void set_music_loop(s_appdata *adata, char *id, sfBool loop)
{
    s_music *music = get_music(adata, id);

    if (music == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    sfMusic_setLoop(music->music, loop);
}

void move_music(s_appdata *adata, char *id, sfVector2f pos)
{
    s_music *music = get_music(adata, id);

    if (music == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    sfVector3f new_pos;
    new_pos.x = pos.x;
    new_pos.y = 0;
    new_pos.z = pos.y;

    sfMusic_setPosition(music->music, new_pos);
}
