/*
** EPITECH PROJECT, 2023
** editor
** File description:
** map_editor
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>

#ifndef _MAP_EDITOR_H_
    #define _MAP_EDITOR_H_
    #define sf2f2i(sf2f) ((sfVector2i){sf2f.x, sf2f.y})
    #define TEXTURE_SIZE 32
    #define GRID_SIZE 2
    #define _REC (data->select_rectangle)

    typedef enum Menu {
        SIZE_SELECTION,
        MAP_EDITOR
    } menu_t;

    typedef enum Key_State {
        NOTHING,
        PRESSED,
        RELEASED
    } key_state_t;

    typedef struct Button {
        sfRectangleShape *rect;
        sfText *text;
        sfTexture *texture;
        sfSprite *sprite;
        sfColor base;
        sfColor hover;
        sfColor pressed;
        sfColor temp_color;
        int temp_color_time;
        enum state {
            BASE,
            HOVER,
            CLICKED
        } state;
        sfBool is_selected;
        int (*func)();
        char *text_char;
        struct Button *next;
    } button_t;

    typedef struct Internal_Data {
        unsigned char **map;
        sfRenderWindow *window;
        sfView *view;
        sfView *left_view;
        sfFont *font;
        sfRenderTexture *workspace;
        menu_t menu;
        enum tool {
            MOVE,
            DRAW,
            RECTANGLE
        } tool;
        char *text_entered;
        sfEvent event;
        sfBool touched;
        key_state_t enter;
        key_state_t lmb;
        sfVector2f mouse_pos;
        sfVector2f mouse_move;
        size_t brush_size;
        sfIntRect select_rectangle;
        float v_scale;
        button_t *button;
        sfVector2i map_size;
        sfSprite *workspace_sprite;
        unsigned char actual_texture;
        sfSprite *texture_sprite;
        sfRectangleShape *texture_rect;
        sfTexture *texture[256];
    } internal_data_t;


    int set_tool_move(internal_data_t *const data);
    int set_tool_draw(internal_data_t *const data);
    int set_tool_rectangle(internal_data_t *const data);
    int add_brush_size(internal_data_t *const data);
    int sub_brush_size(internal_data_t *const data);

    int map_editor(void);
    void destroy(internal_data_t *const data);
    internal_data_t *init(void);
    void event_handler(internal_data_t *const data);
    void size_selection_event(internal_data_t *const data);
    int text_event(internal_data_t *const data);
    void mouse_event(internal_data_t *const data);
    sfBool is_touching(sfRenderWindow *window, sfFloatRect *rect,
    sfVector2f mouse_pos, sfView *view);
    button_t *create_button(internal_data_t *const data, sfBool sprite_text,
    sfFloatRect rect);
    int actualize_button(internal_data_t *const data);
    void map_editor_event(internal_data_t *const data);
    int size_selection(internal_data_t *const data);
    void key_event(internal_data_t *const data);
    int map_editor_loop(internal_data_t *const data);
    int create_map_editor(internal_data_t *const data);
    void destroy_map_editor(internal_data_t *const data);
    int create_map_editor_button(internal_data_t *const data);
    void destroy_buttons(internal_data_t *const data);
#endif
