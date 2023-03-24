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

#define trf_move 0x01
#define trf_rot 0x02
#define trf_scale 0x04
#define trf_color 0x08

#define animation_restart 0
#define animation_reverse 1

typedef struct {
    int exit_status;
    int min_layer;
    int max_layer;
    int min_depth;
    int max_depth;
    int last_keycode;
    int capital;
    int wall_layer;
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
    sfColor clear_color;
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
    char *id;
    sfMusic *music;
} s_music;

typedef struct {
    char *id;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
} s_sound;

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
    linked_node *bars;
    linked_node *transforms;
    linked_node *shaders;
    linked_node *lights;
    linked_node *walls;
    linked_node *musics;
    linked_node *sounds;
    linked_node *sound_queue;
    linked_node *animations;
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
    s_sprite *sprite;
    sfClock *anim_clock;
    float clock_rate;
    sfVector2f base_size;
    int width;
    int height;
    sfVector2f pos;
    int mode;
    int reverse_state;
} s_animation;

typedef struct {
    sfRenderWindow *win;
    s_ints *integers;
    s_floats *floats;
    s_clocks *clocks;
    s_linkeds *lists;
    void *last_pressed;
    void *last_slider;
    void *last_input;
    s_rtex *light_rtex;
    s_rtex *wall_rtex;
    s_rtex *mask_rtex;
    s_rtex *light_blend_rtex;
    s_rtex *light_res_rtex;
    char *current_wall;
    int *keys;
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
    int last;
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
    void (*on_change)(s_appdata *adata, s_ref *ref);
} s_slider;

typedef struct {
    sfShader *shader;
    char *id;
} s_shader;

typedef struct {
    char *id;
    char *placeholder;
    s_text *input_text;
    s_rect *input_rect;
    s_rect *input_caret;
    int max_length;
    int align;
    int contains;
    float x_padding;
    sfClock *caret_clock;
    void (*on_input)(s_appdata *adata, const char *str);
} s_input;

typedef struct {
    char *id;
    s_rect *back_rect;
    s_rect *fill_rect;
    s_text *text;
    float min;
    float max;
    float current;
} s_bar;

typedef struct {
    sfVector2f pos;
    sfVector2f scale;
    float rotation;
    sfColor color;
    int flags;
    s_ref *ref;
} s_target;

typedef struct {
    char *id;
    sfVector2f target_pos;
    sfVector2f target_scale;
    float target_rotation;
    sfColor target_color;
    sfVector2f old_pos;
    sfVector2f old_scale;
    float old_rotation;
    sfColor old_color;
    float move_speed;
    float scale_speed;
    float rotation_speed;
    sfVector2f color_red;
    sfVector2f color_green;
    sfVector2f color_blue;
    sfVector2f color_alpha;
    s_ref *ref;
    void (*callback)(s_appdata *adata, s_ref *ref);
    sfClock *move_clock;
    sfClock *color_clock;
    sfClock *rot_clock;
    sfClock *scale_clock;
    sfClock *end_clock;
    float delta_time;
    int flags;
} s_transform;

typedef struct {
    int type;
    int layer;
    char *id;
} s_btn_next;

typedef struct {
    char *id;
    sfVector2f pos;
    float inner_radius;
    float outer_radius;
    sfColor color;
    float intensity;
    sfBool active;
    sfCircleShape *inner_light;
    sfCircleShape *outer_light;
} s_light;

typedef struct {
    s_rect *hitbox;
    char *id;
} s_wall;

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
#include "bar.h"
#include "transform.h"
#include "shader.h"
#include "light.h"
#include "wall.h"
#include "light_render.h"
#include "collision.h"
#include "audio.h"
#include "animation.h"
#include "key.h"
