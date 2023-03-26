/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Audio module
*/

#include "include/main.h"

s_sound *get_sound(s_appdata *adata, char *id)
{
    linked_node *sounds = adata->lists->sounds;

    while (sounds != NULL && sounds->data != NULL) {
        s_sound *cur = (s_sound *) sounds->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        sounds = sounds->next;
    }

    return (NULL);
}

void move_audio_listener(s_appdata *adata, sfVector2f pos)
{
    sfVector3f new_pos;
    new_pos.x = pos.x;
    new_pos.y = 0;
    new_pos.z = pos.y;

    sfListener_setPosition(new_pos);
}

void set_audio_volume(s_appdata *adata, float volume)
{
    sfListener_setGlobalVolume(volume);
}

void update_sound_queue(s_appdata *adata)
{
    linked_node *queue = adata->lists->sound_queue;
    linked_node *indexes = linked_new();
    int ite = 0;

    while (queue != NULL && queue->data != NULL) {
        s_sound *cur = (s_sound *) queue->data;

        if (sfSound_getStatus(cur->sound) == sfStopped) {
            queue = queue->next;

            s_int *ind = malloc(sizeof(s_int));
            ind->id = NULL;
            ind->value = ite;

            linked_add(indexes, ind);
            sfSound_destroy(cur->sound);
            sfSoundBuffer_destroy(cur->sound_buffer);

            ite++;
            continue;
        }

        ite++;
        queue = queue->next;
    }

    while (indexes != NULL && indexes->data != NULL) {
        s_int *cur = (s_int *) indexes->data;

        linked_delete(&adata->lists->sound_queue, cur->value);

        indexes = indexes->next;
    }

    free(indexes);
}

void play_sound(s_appdata *adata, char *id, float volume, sfVector2f pos)
{
    s_sound *sound = get_sound(adata, id);

    if (sound == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    s_sound *sound_copy = malloc(sizeof(s_sound));

    if (sound_copy == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    sound_copy->id = id;
    sound_copy->sound = sfSound_copy(sound->sound);
    sound_copy->sound_buffer = sfSoundBuffer_copy(sound->sound_buffer);

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

void delete_sound(s_appdata *adata, char *id)
{
    s_sound *sound = get_sound(adata, id);

    if (sound == NULL) {
        my_printf(get_error(adata, "unknown_id"));
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
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfMusic_play(music->music);
}

void stop_music(s_appdata *adata, char *id)
{
    s_music *music = get_music(adata, id);

    if (music == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfMusic_stop(music->music);
}

void pause_music(s_appdata *adata, char *id)
{
    s_music *music = get_music(adata, id);

    if (music == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfMusic_pause(music->music);
}

void set_music_volume(s_appdata *adata, char *id, float volume)
{
    s_music *music = get_music(adata, id);

    if (music == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfMusic_setVolume(music->music, volume);
}

void set_music_loop(s_appdata *adata, char *id, sfBool loop)
{
    s_music *music = get_music(adata, id);

    if (music == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfMusic_setLoop(music->music, loop);
}

void move_music(s_appdata *adata, char *id, sfVector2f pos)
{
    s_music *music = get_music(adata, id);

    if (music == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    sfVector3f new_pos;
    new_pos.x = pos.x;
    new_pos.y = 0;
    new_pos.z = pos.y;

    sfMusic_setPosition(music->music, new_pos);
}

void delete_music(s_appdata *adata, char *id)
{
    s_music *music = get_music(adata, id);

    if (music == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *musics = adata->lists->musics;
    int ite = 0;


    while (musics != NULL && musics->data != NULL) {
        s_music *cur = (s_music *) musics->data;

        if (!my_strcmp(cur->id, id)) {
            sfMusic_destroy(cur->music);
            break;
        }

        ite++;
        musics = musics->next;
    }

    linked_delete(&adata->lists->musics, ite);
}

void add_music(s_appdata *adata, char *id, char *filename)
{
    s_music *music = get_music(adata, id);

    if (music != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    struct stat buffer;
    char *path = str_add("bonus/audios/", filename);

    if (stat(path, &buffer) == -1) {
        my_printf(get_error(adata, "no_file"));
        return;
    }

    s_music *new_music = malloc(sizeof(s_music));

    if (new_music == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    new_music->id = id;
    new_music->music = sfMusic_createFromFile((const char *) path);

    linked_add(adata->lists->musics, new_music);
}

void add_sound(s_appdata *adata, char *id, char *filename)
{
    s_sound *sound = get_sound(adata, id);

    if (sound != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    struct stat buffer;
    char *path = str_add("bonus/audios/", filename);

    if (stat(path, &buffer) == -1) {
        my_printf(get_error(adata, "no_file"));
        return;
    }

    s_sound *new_sound = malloc(sizeof(s_sound));

    if (new_sound == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    new_sound->id = id;
    new_sound->sound = sfSound_create();
    new_sound->sound_buffer = sfSoundBuffer_createFromFile(path);

    sfSound_setBuffer(new_sound->sound, new_sound->sound_buffer);
    linked_add(adata->lists->sounds, new_sound);
}

void load_sounds(s_appdata *adata)
{
    char *file_content = file_extract("bonus/sounds.myrpg");
    char **entries = str_split(file_content, '\n');
    int ite = 0;

    while (entries[ite] != NULL) {
        if (entries[ite][0] == '#') {
            ite++;
            continue;
        }

        char **entry_data = str_m_split(entries[ite], 2, '=', ' ');
        char *id = entry_data[0];
        char *filename = entry_data[1];

        add_sound(adata, id, filename);

        ite++;
    }
}

void load_musics(s_appdata *adata)
{
    char *file_content = file_extract("bonus/musics.myrpg");
    char **entries = str_split(file_content, '\n');
    int ite = 0;

    while (entries[ite] != NULL) {
        if (entries[ite][0] == '#') {
            ite++;
            continue;
        }

        char **entry_data = str_m_split(entries[ite], 2, '=', ' ');
        char *id = entry_data[0];
        char *filename = entry_data[1];

        add_music(adata, id, filename);

        ite++;
    }
}

void free_sound(s_appdata *adata)
{
    linked_node *sounds = adata->lists->sounds;

    while (sounds != NULL && sounds->data != NULL) {
        s_sound *cur = (s_sound *) sounds->data;

        sfSound_destroy(cur->sound);
        sfSoundBuffer_destroy(cur->sound_buffer);

        sounds = sounds->next;
    }

    linked_node *musics = adata->lists->musics;

    while (musics != NULL && musics->data != NULL) {
        s_music *cur = (s_music *) musics->data;

        sfMusic_stop(cur->music);
        sfMusic_destroy(cur->music);

        musics = musics->next;
    }
}
