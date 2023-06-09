/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Render texture module
*/

#include "../include/main.h"

void set_rtex_blendmode(s_appdata *adata, char *id, sfBlendMode mode)
{
    s_rtex *rtex = get_rtex(adata, id);

    if (rtex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    rtex->state->blendMode = mode;
}

void clear_rtex(s_appdata *adata, char *id, sfColor color)
{
    s_rtex *rtex = get_rtex(adata, id);

    if (rtex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    sfRenderTexture_clear(rtex->texture, color);
}

void set_rtex_inherit(s_appdata *adata, char *id, sfUint8 inherit)
{
    s_rtex *rtex = get_rtex(adata, id);

    if (rtex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    rtex->inherit = inherit;
}

sfShader *get_rtex_shader(s_appdata *adata, char *id)
{
    s_rtex *rtex = get_rtex(adata, id);

    if (rtex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return (NULL);
    }

    return (rtex->shader);
}

void set_rtex_active(s_appdata *adata, char *id, sfBool active)
{
    s_rtex *rtex = get_rtex(adata, id);

    if (rtex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    rtex->active = active;
    sfRenderTexture_setActive(rtex->texture, active);
}
