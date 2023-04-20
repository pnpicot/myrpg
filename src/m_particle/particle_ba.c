/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Particle module
*/

#include "../include/main.h"

s_particle_src *get_emiter(s_appdata *adata, char *id)
{
    linked_node *emiters = adata->lists->emiters;

    while (emiters != NULL && emiters->data != NULL) {
        s_particle_src *cur = (s_particle_src *) emiters->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        emiters = emiters->next;
    }

    return (NULL);
}

void delete_emiter(s_appdata *adata, char *id)
{
    s_particle_src *emiter = get_emiter(adata, id);
    if (emiter == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }
    linked_node *emiters = adata->lists->emiters;
    int ite = 0;
    while (emiters != NULL && emiters->data != NULL) {
        s_particle_src *cur = (s_particle_src *) emiters->data;
        if (!my_strcmp(cur->id, id)) {
            sfSprite_destroy(cur->particle_model);
            free(cur->particle_pool);
            break;
        }
        ite++;
        emiters = emiters->next;
    }
    linked_delete(&adata->lists->emiters, ite);
}

void set_emiter_lifetime(s_appdata *adata, char *id, int life_time)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    emiter->emiter_life = life_time;
}

void move_emiter(s_appdata *adata, char *id, sfVector2f pos)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    emiter->emiter_pos = pos;
}

void translate_emiter(s_appdata *adata, char *id, sfVector2f pos_ch)
{
    s_particle_src *emiter = get_emiter(adata, id);

    if (emiter == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    emiter->emiter_pos.x += pos_ch.x;
    emiter->emiter_pos.y += pos_ch.y;
}
