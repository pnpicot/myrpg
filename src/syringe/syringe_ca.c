/*
** EPITECH PROJECT, 2023
** src
** File description:
** syringe_ca
*/

#include "main.h"

int get_syringe_count(s_appdata *adata, char *id)
{
    s_syringe *syringe = get_syringe(adata, id);

    if (syringe == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return (-1);
    }

    return (syringe->count);
}

sfTexture *get_syringe_texture(s_appdata *adata, char *id)
{
    s_syringe *syringe = get_syringe(adata, id);

    if (syringe == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return (NULL);
    }

    return (syringe->tex);
}
