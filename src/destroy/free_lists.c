/*
** EPITECH PROJECT, 2023
** destroy
** File description:
** destroy_linked_1
*/

#include "main.h"

static void free_lists_2(s_linkeds *lists)
{
    // linked_destroy_rtexs(lists->rtexs);
    linked_destroy_shaders(lists->shaders);
    linked_destroy_sliders(lists->sliders);
    linked_destroy_sound_queue(lists->sound_queue);
    linked_destroy_sounds(lists->sounds);
    linked_destroy_sprites(lists->sprites);
    linked_destroy_states(lists->states);
    linked_destroy_switches(lists->switches);
    linked_destroy_texts(lists->texts);
    linked_destroy_tiles(lists->tiles);
    linked_destroy_transforms(lists->transforms);
    linked_destroy_vertexes(lists->vertexes);
    linked_destroy_walls(lists->walls);
    linked_destroy_textures(lists->textures);
    // linked_destroy_config_strings(lists->config_strings);
    free(lists);
}

void free_lists(s_linkeds *lists)
{
    linked_destroy_animations(lists->animations);
    linked_destroy_bars(lists->bars);
    linked_destroy_buttons(lists->buttons);
    linked_destroy_circles(lists->circles);
    linked_destroy_config_colors(lists->config_colors);
    linked_destroy_config_floats(lists->config_floats);
    linked_destroy_config_ints(lists->config_ints);
    linked_destroy_containers(lists->containers);
    linked_destroy_emiters(lists->emiters);
    linked_destroy_errors(lists->errors);
    linked_destroy_fonts(lists->fonts);
    linked_destroy_gameobjects(lists->gameobjects);
    linked_destroy_inputs(lists->inputs);
    linked_destroy_keymaps(lists->keymaps);
    linked_destroy_lights(lists->lights);
    linked_destroy_musics(lists->musics);
    linked_destroy_objects(lists->objects);
    linked_destroy_rects(lists->rects);
    free_lists_2(lists);
}
