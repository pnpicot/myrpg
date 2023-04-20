/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Audio module
*/

#include "../include/main.h"

void delete_music(s_appdata *adata, char *id)
{
    s_music *music = get_music(adata, id);

    if (music == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
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
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "already_exists"));
        return;
    }
    struct stat buffer;
    char *path = str_add("bonus/audios/", filename);
    if (stat(path, &buffer) == -1) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "no_file"));
        free(path);
        return;
    }
    s_music *new_music = malloc(sizeof(s_music));
    if (new_music == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "mem_alloc"));
        free(path);
        return;
    }
    new_music->id = id;
    new_music->music = sfMusic_createFromFile((const char *) path);
    linked_add(adata->lists->musics, new_music);
    free(path);
}

void add_sound_next(s_appdata *adata, char *path, char *id)
{
    s_sound *new_sound = malloc(sizeof(s_sound));
    if (new_sound == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "mem_alloc"));
        free(path);
        return;
    }
    new_sound->id = id;
    new_sound->sound = sfSound_create();
    new_sound->sound_buffer = sfSoundBuffer_createFromFile(path);
    sfSound_setBuffer(new_sound->sound, new_sound->sound_buffer);
    linked_add(adata->lists->sounds, new_sound);
    free(path);
}

void add_sound(s_appdata *adata, char *id, char *filename)
{
    s_sound *sound = get_sound(adata, id);
    if (sound != NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "already_exists"));
        return;
    }
    struct stat buffer;
    char *path = str_add("bonus/audios/", filename);
    if (stat(path, &buffer) == -1) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "no_file"));
        free(path);
        return;
    }
    add_sound_next(adata, path, id);
}

void load_sounds(s_appdata *adata)
{
    char *file_content = file_extract("bonus/sounds.myrpg");
    char **entries = str_split(file_content, '\n');
    int ite = 0;

    free(file_content);
    while (entries[ite] != NULL) {
        if (entries[ite][0] == '#') {
            ite++;
            continue;
        }

        char **entry_data = str_m_split(entries[ite], 2, '=', ' ');
        char *id = entry_data[0];
        char *filename = entry_data[1];

        add_sound(adata, id, filename);

        for (int i = 1; entry_data[i] != NULL; i++)
            free(entry_data[i]);
        free(entry_data);
        ite++;
    }
    for (int i = 0; entries[i] != NULL; i++)
        free(entries[i]);
    free(entries);
}
