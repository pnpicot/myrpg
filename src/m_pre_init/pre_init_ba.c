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
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
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
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return;
    }
}

void init_appdata_clocks(s_appdata *adata)
{
    adata->clocks = malloc(sizeof(s_clocks));

    if (adata->clocks == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
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

void init_appdata_linkeds(s_appdata *adata)
{
    adata->lists = malloc(sizeof(s_linkeds));
    if (adata->lists == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "mem_alloc"));
        return;
    }
    s_linkeds *lists = adata->lists;
    *lists = (s_linkeds){.config_ints = linked_new(), .config_floats =
    linked_new(), .config_strings = linked_new(), .config_colors = linked_new(),
    .errors = linked_new(), .rects = linked_new(), .rtexs = linked_new(),
    .textures = linked_new(), .sprites = linked_new(), .circles = linked_new(),
    .fonts = linked_new(), .texts = linked_new(), .vertexes = linked_new(),
    .containers = linked_new(), .buttons = linked_new(), .objects =
    linked_new(), .switches = linked_new(), .sliders = linked_new(), .inputs =
    linked_new(), .keymaps = linked_new(), .bars = linked_new(), .transforms =
    linked_new(), .shaders = linked_new(), .lights = linked_new(), .walls =
    linked_new(), .musics = linked_new(), .sounds = linked_new(), .sound_queue
    = linked_new(), .animations = linked_new(), .emiters = linked_new(),
    .gameobjects = linked_new(), .states = linked_new(), .tiles = linked_new()
    };
}
