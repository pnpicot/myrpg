/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Particle module
*/

#include "../include/main.h"

void set_emiter_particle_lifetime(s_appdata *adata, char *id, int life_time)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    emiter->life_time = life_time;
}

void set_emiter_particle_max(s_appdata *adata, char *id, int max)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    emiter->particle_max = max;
}

void set_emiter_gameobject(s_appdata *adata, char *id, sfBool game_obj)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    emiter->game_obj = game_obj;
}

void set_emiter_model(s_appdata *adata, char *id, char *texture_id)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    sfSprite *particle_model = sfSprite_create();
    sfSprite_setTexture(particle_model, get_texture(adata, texture_id), sfTrue);

    emiter->particle_model = particle_model;

    const sfTexture *tex = sfSprite_getTexture(particle_model);
    sfVector2u size = sfTexture_getSize(tex);

    emiter->sprite_origin = (sfVector2f) { size.x / 2, size.y / 2 };
}

void set_emiter_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_particle_src *emiter = get_emiter(adata, id);
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (emiter == NULL || rtex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    emiter->render_tex = rtex;
}
