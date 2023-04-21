/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Rectangle shape module
*/

#include "../include/main.h"

void set_rect_active(s_appdata *adata, char *id, sfUint8 active)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    rect->active = active;
}

sfUint8 get_rect_active(s_appdata *adata, char *id)
{
    s_rect *rect = get_rect(adata, id);

    if (rect == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return (0);
    }

    return (rect->active);
}
