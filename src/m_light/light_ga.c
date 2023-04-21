/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Lighting module
*/

#include "../include/main.h"

sfBool get_light_active(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return (sfFalse);
    }

    return (light->active);
}

void toggle_light(s_appdata *adata, char *id)
{
    s_light *light = get_light(adata, id);

    if (light == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    sfBool active = light->active;

    light->active = active ? sfFalse : sfTrue;
}

void init_light_mask(s_appdata *adata, int depth_start)
{
    add_rtex(adata, str_add("light_mask", ""), depth_start);
    set_lightmask_rtex(adata, "light_mask");
    set_rtex_blendmode(adata, "light_mask", sfBlendNone);
    set_rtex_clear(adata, "light_mask", sfWhite);
}

void init_light_xblur(s_appdata *adata, int depth_start)
{
    add_rtex(adata, str_add("light_blur_x", ""), depth_start + 1);
    set_rtex_blendmode(adata, "light_blur_x", sfBlendAdd);

    const sfTexture *tex = get_rtex_tex(adata, "light_blur_x");

    set_shader_texture(adata, "bloom_blur_x", "texture", tex);

    sfVector2f blur_rad = { 0.004f, 0 };

    set_shader_vec2(adata, "bloom_blur_x", "blur_radius", blur_rad);
    set_rtex_shader(adata, "light_blur_x", get_shader(adata, "bloom_blur_x"));
    set_light_rtex(adata, "light_blur_x");
}

void init_light_yblur(s_appdata *adata, int depth_start)
{
    add_rtex(adata, str_add("light_blur_y", ""), depth_start + 2);
    set_rtex_inherit(adata, "light_blur_y", 1);
    set_rtex_blendmode(adata, "light_blur_y", sfBlendAlpha);

    const sfTexture *tex = get_rtex_tex(adata, "light_blur_y");

    set_shader_texture(adata, "bloom_blur_y", "texture", tex);

    sfVector2f blur_rad = { 0, 0.008f };

    set_shader_vec2(adata, "bloom_blur_y", "blur_radius", blur_rad);
    set_rtex_shader(adata, "light_blur_y", get_shader(adata, "bloom_blur_y"));
    set_rtex_clear(adata, "light_blur_y", sfTransparent);
}
