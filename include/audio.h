/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Audio module
*/

#pragma once

#include "main.h"

s_sound *get_sound(s_appdata *adata, char *id);
void move_audio_listener(s_appdata *adata, sfVector2f pos);
void set_audio_volume(s_appdata *adata, float volume);
void update_sound_queue(s_appdata *adata);
void play_sound(s_appdata *adata, char *id, float volume, sfVector2f pos);
void delete_sound(s_appdata *adata, char *id);
s_music *get_music(s_appdata *adata, char *id);
void play_music(s_appdata *adata, char *id);
void stop_music(s_appdata *adata, char *id);
void pause_music(s_appdata *adata, char *id);
void set_music_volume(s_appdata *adata, char *id, float volume);
void set_music_loop(s_appdata *adata, char *id, sfBool loop);
void move_music(s_appdata *adata, char *id, sfVector2f pos);
void delete_music(s_appdata *adata, char *id);
void add_music(s_appdata *adata, char *id, char *filename);
void add_sound(s_appdata *adata, char *id, char *filename);
void load_sounds(s_appdata *adata);
void load_musics(s_appdata *adata);
