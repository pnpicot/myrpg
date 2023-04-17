/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Lighting module
*/

#include "../include/main.h"

void init_light_gradient(s_appdata *adata, int depth_start)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    sfVector2f res = { win_w, win_h };

    add_rtex(adata, str_add("light_gradient", ""), depth_start + 3);
    set_rtex_inherit(adata, "light_gradient", 1);

    const sfTexture *tex = get_rtex_tex(adata, "light_gradient");

    set_shader_texture(adata, "gradient", "tex", tex);
    set_shader_vec2(adata, "gradient", "resolution", res);
    set_rtex_shader(adata, "light_gradient", get_shader(adata, "gradient"));
    set_rtex_clear(adata, "light_gradient", sfTransparent);
}

void init_light_overlay(s_appdata *adata, int depth_start)
{
    add_rtex(adata, str_add("light_overlay", ""), depth_start + 4);
    set_rtex_inherit(adata, "light_overlay", 1);
    set_rtex_blendmode(adata, "light_overlay", sfBlendAdd);
    set_rtex_clear(adata, "light_overlay", sfTransparent);
    set_lightres_rtex(adata, "light_overlay");
    set_rtex_shader(adata, "light_overlay", get_shader(adata, "mask"));

    const sfTexture *mask_tex = get_rtex_tex(adata, "light_mask");
    const sfTexture *overlay_tex = get_rtex_tex(adata, "light_overlay");

    set_shader_texture(adata, "mask", "texture", mask_tex);
    set_shader_texture(adata, "mask", "add_texture", overlay_tex);
}

void init_light_recommended(s_appdata *adata, int depth_start)
{
    init_light_mask(adata, depth_start);
    init_light_xblur(adata, depth_start);
    init_light_yblur(adata, depth_start);
    init_light_gradient(adata, depth_start);
    init_light_overlay(adata, depth_start);

    add_rtex(adata, str_add("light_blend", ""), depth_start + 5);
    set_rtex_blendmode(adata, "light_blend", sfBlendAlpha);
    set_rtex_clear(adata, "light_blend", sfBlack);
    set_lightblend_rtex(adata, "light_blend");

    add_rtex(adata, str_add("walls", ""), depth_start + 6);
    set_rtex_blendmode(adata, "walls", sfBlendAlpha);
    set_rtex_clear(adata, "walls", sfTransparent);
    set_wall_rtex(adata, "walls", 1);

    s_rtex *light_res = adata->light_res_rtex;
    const sfTexture *tex = sfRenderTexture_getTexture(light_res->texture);
    sfSprite_setTexture(light_res->sprite, tex, sfTrue);
}
