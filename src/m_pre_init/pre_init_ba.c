/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Pre-initialization module
*/

#include "../include/main.h"

void init_appdata_ints(s_appdata *adata)
{
    adata->integers = malloc(sizeof(s_ints));

    if (adata->integers == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "mem_alloc"));
        return;
    }

    s_ints *integers = adata->integers;

    integers->exit_status = 0;
    integers->min_layer = 0;
    integers->max_layer = 0;
    integers->min_depth = 0;
    integers->max_depth = 0;
    integers->capital = 0;
    integers->last_keycode = -1;
    integers->wall_layer = 0;
    integers->in_game = 0;
    integers->light_count = 0;
    integers->light_change = 1;
}

void init_appdata_floats(s_appdata *adata)
{
    adata->floats = malloc(sizeof(s_floats));

    if (adata->floats == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "mem_alloc"));
        return;
    }
}

void init_appdata_clocks(s_appdata *adata)
{
    adata->clocks = malloc(sizeof(s_clocks));

    if (adata->clocks == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "mem_alloc"));
        return;
    }

    s_clocks *clocks = adata->clocks;

    clocks->app_clock = sfClock_create();
    clocks->update_clock = sfClock_create();
    clocks->render_clock = sfClock_create();
    clocks->input_clock = sfClock_create();
    clocks->fps_clock = sfClock_create();
    clocks->fps_display_clock = sfClock_create();
    clocks->movement_clock = sfClock_create();
}

void init_appdata_linkeds_next(s_linkeds *lists)
{
    lists->fonts = linked_new();
    lists->texts = linked_new();
    lists->vertexes = linked_new();
    lists->containers = linked_new();
    lists->buttons = linked_new();
    lists->objects = linked_new();
    lists->switches = linked_new();
    lists->sliders = linked_new();
    lists->inputs = linked_new();
    lists->keymaps = linked_new();
    lists->bars = linked_new();
    lists->transforms = linked_new();
    lists->shaders = linked_new();
    lists->lights = linked_new();
    lists->walls = linked_new();
    lists->musics = linked_new();
    lists->sounds = linked_new();
    lists->sound_queue = linked_new();
    lists->animations = linked_new();
    lists->emiters = linked_new();
    lists->gameobjects = linked_new();
    lists->states = linked_new();
    lists->tiles = linked_new();
}

void init_appdata_linkeds(s_appdata *adata)
{
    adata->lists = malloc(sizeof(s_linkeds));

    if (adata->lists == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "mem_alloc"));
        return;
    }

    s_linkeds *lists = adata->lists;

    lists->config_ints = linked_new();
    lists->config_floats = linked_new();
    lists->config_strings = linked_new();
    lists->config_colors = linked_new();
    lists->errors = linked_new();
    lists->rects = linked_new();
    lists->rtexs = linked_new();
    lists->textures = linked_new();
    lists->sprites = linked_new();
    lists->circles = linked_new();
    init_appdata_linkeds_next(lists);
}
