/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Audio module
*/

#include "../include/main.h"

void load_musics(s_appdata *adata)
{
    char *file_content = file_extract("bonus/musics.myrpg");
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

        add_music(adata, id, filename);

        for (int i = 0; entry_data[i] != NULL; ++i)
            free(entry_data[i]);
        free(entry_data);

        ite++;
    }
    for (int i = 0; entries[i] != NULL; ++i)
        free(entries[i]);
    free(entries);
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
