/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Syringe item module
*/

#include "main.h"

void set_syringe_count(s_appdata *adata, char *id, int count)
{
    s_syringe *syringe = get_syringe(adata, id);

    if (syringe == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    syringe->count = count;
}

void set_syringe_name(s_appdata *adata, char *id, char *name)
{
    s_syringe *syringe = get_syringe(adata, id);

    if (syringe == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    syringe->name = name;
}

void syringe_increment(s_appdata *adata, char *id, int amount)
{
    s_syringe *syringe = get_syringe(adata, id);

    if (syringe == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    syringe->count += amount;
}

void syringe_decrement(s_appdata *adata, char *id, int amount)
{
    s_syringe *syringe = get_syringe(adata, id);

    if (syringe == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    syringe->count -= amount;
}

void set_syringe_texture(s_appdata *adata, char *id, sfTexture *texture)
{
    s_syringe *syringe = get_syringe(adata, id);

    if (syringe == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    syringe->tex = texture;
}
