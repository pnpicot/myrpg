/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Light rendering module
*/

#include "main.h"

void set_lightmask_rtex(s_appdata *adata, char *rtex_id)
{
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    adata->mask_rtex = rtex;
}

int dist_cmp(linked_node *first_node, linked_node *second_node)
{
    s_dist *dist_a = (s_dist *) first_node->data;
    s_dist *dist_b = (s_dist *) second_node->data;

    return (dist_a->dist > dist_b->dist);
}

sfVector2f nearest_point(sfVector2f pos, linked_node *points, int index)
{
    linked_node *dists = linked_new();

    while (points != NULL && points->data != NULL) {
        sfVector2f *cur = (sfVector2f *) points->data;
        float dist = get_vec_dist(pos, (sfVector2f) { cur->x, cur->y });
        s_dist *new_dist = malloc(sizeof(s_dist));

        new_dist->dist = dist;
        new_dist->pos = (sfVector2f) { cur->x, cur->y };

        linked_add(dists, new_dist);

        points = points->next;
    }

    linked_sort(&dists, &dist_cmp);
    s_dist *res = (s_dist *) linked_get(dists, index)->data;

    return (res->pos);
}

int get_is_diag(sfVector2f pos, sfVector2f nst, sfVector2f nst_s)
{
    return ((pos.y >= nst.y && pos.y <= nst_s.y)
        || (pos.y <= nst.y && pos.y >= nst_s.y)
        || (pos.x >= nst.x && pos.x <= nst_s.x)
        || (pos.x <= nst.x && pos.x >= nst_s.x));
}

int get_is_diagt(sfVector2f pos, sfVector2f nst_t, sfVector2f nst)
{
    return ((pos.y >= nst.y && pos.y <= nst_t.y)
        || (pos.y <= nst.y && pos.y >= nst_t.y)
        || (pos.x >= nst.x && pos.x <= nst_t.x)
        || (pos.x <= nst.x && pos.x >= nst_t.x));
}

void create_shadow_mask(s_appdata *adata, s_light *light, s_wall *wall_el)
{
    sfFloatRect wall = sfRectangleShape_getGlobalBounds(wall_el->hitbox->elem);
    float shadow_dist = get_float(adata, "shadow_dist");
    sfColor mask_color = get_config_color(adata, "shadow_mask");
    sfColor cast_color = get_config_color(adata, "shadow_cast");
    sfVector2f pos = light->pos;
    sfVector2f top_l = { wall.left, wall.top };
    sfVector2f top_r = { wall.left + wall.width, wall.top };
    sfVector2f bot_l = { wall.left, wall.top + wall.height};
    sfVector2f bot_r = { wall.left + wall.width, wall.top + wall.height };

    linked_node *corners = linked_new();
    linked_add(corners, &top_l);
    linked_add(corners, &top_r);
    linked_add(corners, &bot_l);
    linked_add(corners, &bot_r);

    sfVector2f anchor_a;
    sfVector2f anchor_b;
    sfVector2f nearest_first = nearest_point(pos, corners, 0);
    sfVector2f nearest_second = nearest_point(pos, corners, 1);
    sfVector2f nearest_third = nearest_point(pos, corners, 2);

    int is_diag = get_is_diag(pos, nearest_first, nearest_second);
    int is_diag_t = get_is_diagt(pos, nearest_third, nearest_first);

    if (is_diag) {
        anchor_a = nearest_first;
        anchor_b = nearest_second;
    } else if (is_diag_t) {
        anchor_a = nearest_first;
        anchor_b = nearest_third;
    } else {
        anchor_a = nearest_second;
        anchor_b = nearest_third;
    }

    sfVector2f a_projected = get_projected(pos, anchor_a, shadow_dist);
    sfVector2f b_projected = get_projected(pos, anchor_b, shadow_dist);
    sfVector2f median;

    median.x = (anchor_a.x + anchor_b.x) / 2;
    median.y = (anchor_a.y + anchor_b.y) / 2;
    median = get_projected(pos, median, get_float(adata, "shadow_median"));

    sfVertexArray *cast = sfVertexArray_create();

    sfVertexArray_setPrimitiveType(cast, sfTrianglesStrip);
    sfVertexArray_resize(cast, 6);

    sfVertex *cast_a = sfVertexArray_getVertex(cast, 0);
    sfVertex *cast_b = sfVertexArray_getVertex(cast, 1);
    sfVertex *cast_c = sfVertexArray_getVertex(cast, 2);
    sfVertex *cast_d = sfVertexArray_getVertex(cast, 3);
    sfVertex *cast_e = sfVertexArray_getVertex(cast, 4);
    sfVertex *cast_f = sfVertexArray_getVertex(cast, 5);

    cast_a->color = mask_color;
    cast_a->position = anchor_a;

    cast_b->color = mask_color;
    cast_b->position = anchor_b;

    cast_c->color = mask_color;
    cast_c->position = a_projected;

    cast_d->color = mask_color;
    cast_d->position = median;

    cast_e->color = mask_color;
    cast_e->position = b_projected;

    cast_f->color = mask_color;
    cast_f->position = anchor_b;

    if (adata->mask_rtex != NULL) {
        sfRenderTexture_drawVertexArray(adata->mask_rtex->texture, cast, NULL);
        force_rtex(adata, adata->mask_rtex->id);
    }
}

void draw_light(s_appdata *adata, s_light *light)
{
    sfRenderTexture_drawCircleShape(adata->light_rtex->texture, light->outer_light, NULL);
    sfRenderTexture_drawCircleShape(adata->light_rtex->texture, light->inner_light, NULL);
    force_rtex(adata, adata->light_rtex->id);

    for (int i = adata->light_rtex->depth; i <= adata->light_res_rtex->depth; i++) {
        s_rtex *rtex = get_rtex_d(adata, i);

        force_rtex(adata, rtex->id);
    }

    s_rtex *blend = get_rtex(adata, adata->light_blend_rtex->id);
    s_rtex *light_rtex = get_rtex(adata, adata->light_res_rtex->id);
    const sfTexture *cur_tex = sfRenderTexture_getTexture(adata->light_res_rtex->texture);

    sfSprite *tmp = sfSprite_create();
    sfSprite_setTexture(tmp, cur_tex, sfTrue);

    sfRenderStates *state = light_rtex->state;
    state->blendMode = sfBlendAlpha;

    sfRenderTexture_drawSprite(blend->texture, tmp, light_rtex->state);
}

void shadow_cast(s_appdata *adata, s_light *light)
{
    linked_node *walls = adata->lists->walls;

    while (walls != NULL && walls->data != NULL) {
        s_wall *cur = (s_wall *) walls->data;

        create_shadow_mask(adata, light, cur);

        walls = walls->next;
    }

    set_shader_vec2(adata, "gradient", "pos", light->pos);
    set_shader_float(adata, "gradient", "max_dist", light->outer_radius);
    draw_light(adata, light);
}

void render_lights(s_appdata *adata)
{
    if (adata->mask_rtex == NULL || adata->light_rtex == NULL) return;

    linked_node *lights = adata->lists->lights;

    while (lights != NULL && lights->data != NULL) {
        s_light *cur = (s_light *) lights->data;

        shadow_cast(adata, cur);
        clear_rtex(adata, adata->mask_rtex->id, adata->mask_rtex->clear_color);
        clear_rtex(adata, adata->light_rtex->id, adata->light_rtex->clear_color);

        for (int i = adata->light_rtex->depth; i <= adata->light_res_rtex->depth; i++) {
            s_rtex *rtex = get_rtex_d(adata, i);

            clear_rtex(adata, rtex->id, rtex->clear_color);
        }

        lights = lights->next;
    }

    force_rtex(adata, adata->light_blend_rtex->id);
}
