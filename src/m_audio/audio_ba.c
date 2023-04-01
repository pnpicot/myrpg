/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Audio module
*/

#include "../include/main.h"

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

void update_sound_queue_next(s_appdata *adata, linked_node *indexes)
{
    while (indexes != NULL && indexes->data != NULL) {
        s_int *cur = (s_int *) indexes->data;
        linked_delete(&adata->lists->sound_queue, cur->value);
        indexes = indexes->next;
    }
    free(indexes);
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
    update_sound_queue_next(adata, indexes);
}
