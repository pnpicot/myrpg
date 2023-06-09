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
#include <stdio.h>

#define TYPE_RECT 1
#define TYPE_CIRCLE 2
#define TYPE_TEXT 3
#define TYPE_VERTEX 4
#define TYPE_SPRITE 5
#define TYPE_BUTTON 6
#define TYPE_LIGHT 7
#define TYPE_EMITER 8
#define TYPE_SLIDER 9
#define TYPE_BAR 10
#define TYPE_INPUT 11

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

#define clockwise 1
#define anticlockwise 2
#define random_dir 3

#define sfPink get_color(224, 40, 215, 255)
#define sfBrown get_color(133, 97, 60, 255)
#define sfDarkGray get_color(110, 110, 110, 255)
#define sfLightGray get_color(200, 200, 200, 255)
#define sfOrange get_color(252, 144, 3, 255)

#define M_PI 3.14159265358979323846

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    int exit_status;
    int min_layer;
    int max_layer;
    int min_depth;
    int max_depth;
    int last_keycode;
    int capital;
    int wall_layer;
    int in_game;
    int light_count;
    int light_change;
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
    sfBool active;
    linked_node *objects;
} s_rtex;

typedef struct {
    sfClock *app_clock;
    sfClock *update_clock;
    sfClock *render_clock;
    sfClock *input_clock;
    sfClock *fps_clock;
    sfClock *fps_display_clock;
    sfClock *movement_clock;
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
    char id;
    sfTexture *tex;
    sfBool wall;
} s_tile;

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
    linked_node *emiters;
    linked_node *gameobjects;
    linked_node *states;
    linked_node *tiles;
} s_linkeds;


typedef struct {
    sfRectangleShape *elem;
    char *id;
    char *rtex_id;
    sfUint8 active;
    sfUint8 hidden;
    sfVector2f pos;
    int layer;
} s_rect;

typedef struct {
    char *id;
    linked_node *entities;
} s_zone;

typedef struct {
    void *ref;
    int type;
} s_ref;

typedef struct {
    char *id;
    sfBool active;
    linked_node *nodes;
} s_container;

typedef struct {
    s_container *container;
    char *id;
    sfBool in_game;
    linked_node *rtexs;
} s_state;

typedef struct {
    sfCircleShape *elem;
    char *id;
    char *rtex_id;
    sfUint8 active;
    sfUint8 hidden;
    sfVector2f pos;
    int layer;
} s_circle;

typedef struct {
    sfVertexArray *elem;
    char *id;
    char *rtex_id;
    sfUint8 active;
    sfUint8 hidden;
    sfVector2f pos;
    int layer;
} s_vertex;

typedef struct {
    sfText *elem;
    char *id;
    char *rtex_id;
    sfUint8 active;
    sfUint8 hidden;
    sfVector2f pos;
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
    sfVector2f pos;
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
    sfBool active;
} s_animation;

typedef struct {
    sfVector2f view_pos;
    sfVector2f map_size;
    sfVector2i col_map_size;
    sfVector2f speed;
    float velocity;
    float speed_max;
    float friction;
    linked_node *entity_models;
    linked_node *entities;
    linked_node *factions;
    linked_node *syringes;
    linked_node *quests;
    linked_node *skill_trees;
    int map_width;
    int map_height;
    char **map;
    struct s_entity_s ***col_map;
    float time;
    sfBool in_inv;
    sfBool show_quest;
    sfBool in_stree;
    sfBool mouse_down;
    sfVector2f mouse_last;
    int nb_zones;
    s_zone **zones;
    sfVector2f size_zone;
    sfClock *wave_clock;
    int faction_index;
    int wave_count;
    linked_node *npc_text;
    sfClock *npc_clock;
} s_game;

typedef struct {
    sfVector2f health;
    sfVector2f transference;
    sfFloatRect hitbox;
    float health_rate;
    float transference_rate;
    sfClock *transference_clock;
    s_sprite *body;
    s_text *info_text;
    s_text *stats;
    float attack;
    float defense;
    int transference_level;
    sfBool solid;
    void *host;
    void *potential_host;
    sfBool transfered;
    int moula;
    sfBool use_syringe;
    sfBool killed_enemy;
} s_player;

typedef struct {
    sfRenderWindow *win;
    sfView *view;
    sfBool fullscreen;
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
    s_game *game_data;
    s_state *current_state;
    s_player *player;
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
    float dist;
    sfVector2f pos;
} s_dist;

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
    sfVector2f rel_pos;
    float inner_radius;
    float outer_radius;
    sfColor color;
    float intensity;
    sfBool active;
    sfBool game_obj;
    sfCircleShape *inner_light;
    sfCircleShape *outer_light;
    sfSprite *cache;
    sfSprite *wall_cache;
    sfBool changed;
} s_light;

typedef struct {
    s_rect *hitbox;
    char *id;
} s_wall;

typedef struct {
    sfSprite *model;
    sfBool rotation_dir;
    sfBool active;
    float angle;
    int life;
    float vortex_speed;
    sfColor color;
    float speed;
} s_particle;

typedef struct {
    char *id;
    s_rtex *render_tex;
    sfVector2f emiter_pos;
    int particle_max;
    int particle_count;
    float spawn_chance;
    sfSprite *particle_model;
    linked_node *particle_pool;
    int rotation_dir;
    float rotation_speed;
    sfVector2f speed;
    sfVector2f start_size;
    sfVector2f end_size;
    int life_time;
    int emiter_life;
    sfVector2f sprite_origin;
    sfVector2f spawn_offset_x;
    sfVector2f spawn_offset_y;
    sfVector2f cone_range;
    sfClock *delta_clock;
    int vortex_dir;
    sfVector2f vortex_speed;
    sfColor start_color;
    sfColor end_color;
    float lerp_div;
    sfBool game_obj;
    sfBool active;
    int layer;
} s_particle_src;

typedef struct {
    char *id;
    void *ref;
    int type;
    s_wall *hitbox;
} s_gameobj;

typedef struct s_syringe_s {
    char *id;
    char *name;
    int count;
    sfTexture *tex;
    sfColor color;
    void (*on_use)(s_appdata *adata, s_ref *ref);
} s_syringe;

typedef struct {
    s_sprite *sprite;
    char *id;
    sfVector2f offset;
    sfVector2f origin;
    int layer;
} s_entity_part;

typedef struct {
    char *id;
    sfVector2f spawn_point;
    float spawn_radius;
    int entity_count;
    int entity_max;
    linked_node *models;
} s_faction;

typedef struct s_entity_s {
    char *id;
    linked_node *parts;
    sfVector2f pos;
    sfFloatRect hitbox;
    float st_hp;
    float hp;
    float scale;
    float spawn_rate;
    s_faction *faction;
    sfClock *clock;
    sfClock *path_clock;
    linked_node *path;
    void (*emiter)(s_appdata *adata, struct s_entity_s *entity);
    void (*behavior)(s_appdata *adata, struct s_entity_s *entity);
    float speed;
    sfBool inhabited;
    sfBool init;
    sfBool dead;
    s_bar *hp_bar;
    linked_node *floats;
    sfBool orientated;
    s_zone *zone;
    float damage;
    float defense;
    int trf_require;
    float agro_length;
    sfVector2f move_now;
    struct s_entity_s *move_now_entity;
    char *name;
} s_entity;

typedef enum {
        TOUCH_WALL,
        TOUCH_ENTITY,
        TOUCH_PARASITE
    } touch_type_t;
typedef struct {
    touch_type_t touch_type;
    s_entity *entity;
} s_touch_t;

typedef struct s_quest_s {
    char *id;
    char *text;
    char *title;
    sfTexture *icon;
    s_rect *popup_rect;
    s_text *popup_text;
    s_button *item;
    void (*completion_check)(s_appdata *adata, struct s_quest_s *quest);
    sfBool completed;
} s_quest;

typedef struct s_skill_node_s {
    char *id;
    sfTexture *icon;
    char *name;
    int level;
    struct s_skill_node_s *parent;
    s_sprite *node_sprite;
    sfVector2f pos;
    int price;
    sfBool unlocked;
    void (*unlock_trigger)(s_appdata *adata, float value);
    float trigger_value;
} s_skill_node;

typedef struct {
    char *id;
    linked_node *nodes;
    float y_end;
} s_skill_tree;

typedef struct {
    char *id;
    int ite;
    s_syringe *cur;
    sfFloatRect inv_bounds;
} s_tmp_invitem;

typedef struct {
    char *id;
    s_quest *cur;
    int ite;
    sfVector2f bg_pos;
} s_tmp_questitem;

typedef struct {
    char *id;
    float size;
    s_skill_node *cur;
    s_skill_tree *tree;
    sfVector2f *start;
    int node_count;
    char *skill_ctn;
    char *game_ctn;
    int y_shift;
    int ite;
} s_tmp_stree;

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
#include "light_render.h"
#include "light.h"
#include "wall.h"
#include "collision.h"
#include "audio.h"
#include "animation.h"
#include "key.h"
#include "particle.h"
#include "control.h"
#include "gameobject.h"
#include "state.h"
#include "setup.h"
#include "ui_main.h"
#include "ui_ingame.h"
#include "ui_settings.h"
#include "map.h"
#include "parasite.h"
#include "world_event.h"
#include "id.h"
#include "public_path_finding.h"
#include "syringe.h"
#include "inventory.h"
#include "entity.h"
#include "faction.h"
#include "map_collision.h"
#include "spawn.h"
#include "destroy.h"
#include "console.h"
#include "quest.h"
#include "skill_tree.h"
#include "linked_add_sorted_layer.h"
#include "save.h"
#include "load.h"
#include "npc.h"
#include "gameover.h"
