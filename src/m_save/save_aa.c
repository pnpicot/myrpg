/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Save module
*/

#include "main.h"

void save_fill_gamedata(s_appdata *adata, linked_node *lines)
{
    s_game *game_data = adata->game_data;

    save_fill_syringes(adata, lines);
    save_fill_quests(adata, lines);
    linked_add(lines, float_to_str(game_data->view_pos.x, 2, 0));
    linked_add(lines, float_to_str(game_data->view_pos.y, 2, 0));
    linked_add(lines, float_to_str(game_data->velocity, 2, 0));
    linked_add(lines, float_to_str(game_data->speed_max, 2, 0));
    linked_add(lines, float_to_str(game_data->speed.x, 2, 0));
    linked_add(lines, float_to_str(game_data->speed.y, 2, 0));
    save_fill_skill_trees(adata, lines);
    save_fill_entities(adata, lines);
    linked_add(lines, nbr_to_str(game_data->wave_count));
}

void save_fill(s_appdata *adata, linked_node *lines)
{
    save_fill_player(adata, lines);
    save_fill_gamedata(adata, lines);
}

void save_to_file(s_appdata *adata, char *save)
{
    linked_node *files = linked_new();

    get_files("bonus/saves", 0, files);

    int count = linked_count(files);
    char *filename = str_add("save", nbr_to_str(count + 1));
    FILE *new_fp = fopen(str_add("bonus/saves/", filename), "w");

    if (new_fp == NULL) {
        my_printf("error\n");
        return;
    }

    size_t size = (size_t) my_strlen(save);
    size_t nmemb = (size_t) sizeof(*save);

    fwrite((const char *) save, size, nmemb, new_fp);
}

void save_game(s_appdata *adata)
{
    char *save = "";
    linked_node *lines = linked_new();
    int ite = 0;

    save_fill(adata, lines);

    int count = linked_count(lines);

    while (lines != NULL && lines->data != NULL) {
        char *cur = (char *) lines->data;

        save = str_m_add(3, save, cur, ite < count - 1 ? "#" : "");

        ite++;
        lines = lines->next;
    }

    save_to_file(adata, save);
}
