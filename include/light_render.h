/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Light rendering module
*/

#pragma once

#include "main.h"

void draw_cached_lights_next(s_appdata *adata, sfFloatRect screen, \
sfRenderStates *state);
void draw_cached_lights(s_appdata *adata);
void draw_light_base(s_appdata *adata, s_light *light, int is_obj);
void draw_light_over_walls(s_appdata *adata, int is_obj, \
s_light *light, s_rtex *wall);
void draw_light(s_appdata *adata, s_light *light);
void generate_shadow_projection(sfVertexArray *cast, sfColor mask_color, \
sfVector2f a_projected, sfVector2f b_projected);
void generate_shadow_median(sfVertexArray *cast, sfColor mask_color, \
sfVector2f median, sfVector2f anchor_b);
sfVertexArray *get_shadow_base(void);
sfVector2f get_shadow_median(sfVector2f a_projected, sfVector2f b_projected);
void create_shadow_mask(s_appdata *adata, sfVector2f pos, s_wall *wall_el, \
sfVector2f shift);
int get_is_diag(sfVector2f pos, sfVector2f nst, sfVector2f nst_s);
int get_is_diagt(sfVector2f pos, sfVector2f nst_t, sfVector2f nst);
void get_shadow_anchors(sfVector2f pos, linked_node *corners, \
sfVector2f *anchor_a, sfVector2f *anchor_b);
linked_node *get_wall_corners(sfFloatRect wall);
void generate_shadow_base(sfVertexArray *cast, sfColor mask_color, \
sfVector2f anchor_a, sfVector2f anchor_b);
sfBool in_light_range(s_appdata *adata, int depth);
void set_lightmask_rtex(s_appdata *adata, char *rtex_id);
int dist_cmp(linked_node *first_node, linked_node *second_node);
void vec2_sort(sfVector2f *list, int count, sfVector2f pos);
sfVector2f nearest_point(sfVector2f pos, linked_node *points, int index);
void shadow_cast(s_appdata *adata, s_light *light);
void render_light_cycle(s_appdata *adata, s_rtex *mask_rtex, \
s_rtex *light_rtex, s_light *cur);
void render_lights_next(s_appdata *adata, sfBool obj);
void render_lights(s_appdata *adata);
