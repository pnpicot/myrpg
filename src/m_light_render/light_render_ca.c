/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Light rendering module
*/

#include "../include/main.h"

void generate_shadow_projection(sfVertexArray *cast, sfColor mask_color, \
sfVector2f a_projected, sfVector2f b_projected)
{
    sfVertex *cast_c = sfVertexArray_getVertex(cast, 2);
    sfVertex *cast_e = sfVertexArray_getVertex(cast, 4);
    cast_c->color = mask_color;
    cast_c->position = a_projected;
    cast_e->color = mask_color;
    cast_e->position = b_projected;
}

void generate_shadow_median(sfVertexArray *cast, sfColor mask_color, \
sfVector2f median, sfVector2f anchor_b)
{
    sfVertex *cast_d = sfVertexArray_getVertex(cast, 3);
    sfVertex *cast_f = sfVertexArray_getVertex(cast, 5);
    cast_d->color = mask_color;
    cast_d->position = median;
    cast_f->color = mask_color;
    cast_f->position = anchor_b;
}

sfVertexArray *get_shadow_base(void)
{
    sfVertexArray *cast = sfVertexArray_create();

    sfVertexArray_setPrimitiveType(cast, sfTrianglesStrip);
    sfVertexArray_resize(cast, 6);

    return (cast);
}

sfVector2f get_shadow_median(sfVector2f a_projected, sfVector2f b_projected)
{
    sfVector2f median;

    median.x = (a_projected.x + b_projected.x) / 2;
    median.y = (a_projected.y + b_projected.y) / 2;

    return (median);
}

void create_shadow_mask(s_appdata *adata, sfVector2f pos, s_wall *wall_el, \
sfVector2f shift)
{
    sfFloatRect wall = sfRectangleShape_getGlobalBounds(wall_el->hitbox->elem);
    wall.left += shift.x;
    wall.top += shift.y;
    float shadow_dist = get_float(adata, "shadow_dist");
    sfColor mask_color = get_config_color(adata, "shadow_mask");
    linked_node *corners = get_wall_corners(wall);
    sfVector2f anchor_a;
    sfVector2f anchor_b;
    get_shadow_anchors(pos, corners, &anchor_a, &anchor_b);
    sfVector2f a_projected = get_projected(pos, anchor_a, shadow_dist);
    sfVector2f b_projected = get_projected(pos, anchor_b, shadow_dist);
    sfVector2f median = get_shadow_median(a_projected, b_projected);
    median = get_projected(pos, median, get_float(adata, "shadow_median"));
    sfVertexArray *cast = get_shadow_base();
    generate_shadow_base(cast, mask_color, anchor_a, anchor_b);
    generate_shadow_projection(cast, mask_color, a_projected, b_projected);
    generate_shadow_median(cast, mask_color, median, anchor_b);
    sfRenderTexture_drawVertexArray(adata->mask_rtex->texture, cast, NULL);
    force_rtex(adata, adata->mask_rtex->id);
}
