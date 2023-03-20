/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Main header file
*/

#pragma once

#include "my.h"
#include <math.h>
#include <time.h>

#define TYPE_RECT 1
#define TYPE_CIRCLE 2
#define TYPE_TEXT 3
#define TYPE_VERTEX 4
#define TYPE_SPRITE 5
#define TYPE_BUTTON 6

#define obj_hover 0x01
#define obj_pressed 0x02
#define obj_onpressed 0x04
#define obj_onclick 0x08
#define obj_onhover 0x10

typedef struct {
    int exit_status;
    int min_layer;
    int max_layer;
    int min_depth;
    int max_depth;
    int last_keycode;
    int capital;
} s_ints;

typedef struct {
    int value;
    char *id;
} s_int;

typedef struct {
    float value;
    char *id;
} s_float;

typedef struct {
    sfColor value;
    char *id;
} s_color;

typedef struct {
    char *value;
    char *id;
} s_str;

typedef struct {
    char *id;
    sfRenderTexture *texture;
    sfBlendMode mode;
    sfShader *shader;
    sfRenderStates *state;
    sfSprite *sprite;
    sfUint8 inherit;
    int depth;
} s_rtex;

typedef struct {
    sfClock *app_clock;
    sfClock *update_clock;
    sfClock *render_clock;
    sfClock *input_clock;
} s_clocks;

typedef struct {
} s_floats;

typedef struct {
    sfTexture *texture;
    char *id;
} s_texture;

typedef struct {
    int keycode;
    char ch;
} s_keymap;

typedef struct {
    linked_node *config_ints;
    linked_node *config_floats;
    linked_node *config_strings;
    linked_node *config_colors;
    linked_node *errors;
    linked_node *rects;
    linked_node *rtexs;
    linked_node *textures;
    linked_node *sprites;
    linked_node *circles;
    linked_node *fonts;
    linked_node *texts;
    linked_node *vertexes;
    linked_node *containers;
    linked_node *buttons;
    linked_node *objects;
    linked_node *switches;
    linked_node *sliders;
    linked_node *inputs;
    linked_node *keymaps;
} s_linkeds;

typedef struct {
    sfRectangleShape *elem;
    char *id;
    char *rtex_id;
    sfUint8 active;
    sfUint8 hidden;
    int layer;
} s_rect;

typedef struct {
    void *ref;
    int type;
} s_ref;

typedef struct {
    char *id;
    linked_node *nodes;
} s_container;

typedef struct {
    sfCircleShape *elem;
    char *id;
    char *rtex_id;
    sfUint8 active;
    sfUint8 hidden;
    int layer;
} s_circle;

typedef struct {
    sfVertexArray *elem;
    char *id;
    char *rtex_id;
    sfUint8 active;
    sfUint8 hidden;
    int layer;
} s_vertex;

typedef struct {
    sfText *elem;
    char *id;
    char *rtex_id;
    sfUint8 active;
    sfUint8 hidden;
    int layer;
} s_text;

typedef struct {
    sfFont *font;
    char *id;
} s_font;

typedef struct {
    sfSprite *elem;
    sfTexture *texture;
    char *id;
    char *rtex_id;
    sfUint8 active;
    sfUint8 hidden;
    int layer;
} s_sprite;

typedef struct {
    sfRenderWindow *win;
    s_ints *integers;
    s_floats *floats;
    s_clocks *clocks;
    s_linkeds *lists;
    void *last_pressed;
    void *last_slider;
    void *last_input;
} s_appdata;

typedef struct {
    char *id;
    s_ref *ref;
    sfColor off_bg;
    sfColor off_fg;
    sfColor off_out;
    sfColor pressed_bg;
    sfColor pressed_fg;
    sfColor pressed_out;
    sfColor hover_bg;
    sfColor hover_fg;
    sfColor hover_out;
    int flags;
    void (*on_pressed)(s_appdata *adata, s_ref *ref);
    void (*on_click)(s_appdata *adata, s_ref *ref);
    void (*on_hover)(s_appdata *adata, s_ref *ref);
} s_object;

typedef struct s_button_s {
    char *id;
    s_ref *elem;
    s_text *text;
} s_button;

typedef struct {
    char *id;
    s_button *left_round;
    s_button *right_round;
    s_button *middle_rect;
    s_button *indicator;
    sfBool state;
} s_switch;

typedef struct {
    char *id;
    int min;
    int max;
    int current;
    s_button *left_round;
    s_button *right_round;
    s_button *middle_rect;
    s_circle *left_hover;
    s_circle *right_hover;
    s_rect *middle_hover;
    s_circle *node;
    s_vertex *indicator_triangle;
    s_rect *indicator_rect;
    s_text *indicator_text;
} s_slider;

typedef struct {
    char *id;
    int max_length;
    s_text *input_text;
    s_rect *input_rect;
    s_rect *input_caret;
    int align;
    float x_padding;
    sfClock *caret_clock;
    int contains;
    char *placeholder;
} s_input;

#include "pre_init.h"
#include "error.h"
#include "config.h"
#include "init.h"
#include "post_init.h"
#include "window.h"
#include "event.h"
#include "update.h"
#include "render.h"
#include "rect.h"
#include "rtex.h"
#include "utils.h"
#include "texture.h"
#include "sprite.h"
#include "circle.h"
#include "fonts.h"
#include "text.h"
#include "vertex.h"
#include "element_utils.h"
#include "container.h"
#include "button.h"
#include "event_keypress.h"
#include "event_keyrelease.h"
#include "event_mousemove.h"
#include "event_mousepressed.h"
#include "event_mouserelease.h"
#include "event_windowresize.h"
#include "object.h"
#include "switch.h"
#include "slider.h"
#include "input.h"
#include "keymap.h"
