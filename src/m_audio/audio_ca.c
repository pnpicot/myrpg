/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Audio module
*/

#include "../include/main.h"

void play_sound_next(s_appdata *adata, s_sound *sound_copy, sfVector2f pos, \
float volume)
{
    sfVector3f new_pos;
    new_pos.x = pos.x;
    new_pos.y = 0;
    new_pos.z = pos.y;

    sfSound_setBuffer(sound_copy->sound, sound_copy->sound_buffer);
    linked_add(adata->lists->sound_queue, sound_copy);
    sfSound_setVolume(sound_copy->sound, volume);
    sfSound_play(sound_copy->sound);
    sfSound_setPosition(sound_copy->sound, new_pos);
}

void play_sound(s_appdata *adata, char *id, float volume, sfVector2f pos)
{
    s_sound *sound = get_sound(adata, id);

    if (sound == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }
    s_sound *sound_copy = malloc(sizeof(s_sound));
    if (sound_copy == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return;
    }
    sound_copy->id = id;
    sound_copy->sound = sfSound_copy(sound->sound);
    sound_copy->sound_buffer = sfSoundBuffer_copy(sound->sound_buffer);
    play_sound_next(adata, sound_copy, pos, volume);
}

void delete_sound(s_appdata *adata, char *id)
{
    s_sound *sound = get_sound(adata, id);
    if (sound == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }
    linked_node *sounds = adata->lists->sounds;
    int ite = 0;
    while (sounds != NULL && sounds->data != NULL) {
        s_sound *cur = (s_sound *) sounds->data;
        if (!my_strcmp(cur->id, id)) {
            sfSound_destroy(cur->sound);
            sfSoundBuffer_destroy(cur->sound_buffer);
            break;
        }
        ite++;
        sounds = sounds->next;
    }
    linked_delete(&adata->lists->sounds, ite);
}

s_music *get_music(s_appdata *adata, char *id)
{
    linked_node *musics = adata->lists->musics;

    while (musics != NULL && musics->data != NULL) {
        s_music *cur = (s_music *) musics->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        musics = musics->next;
    }

    return (NULL);
}

void play_music(s_appdata *adata, char *id)
{
    s_music *music = get_music(adata, id);

    if (music == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    sfMusic_play(music->music);
}
