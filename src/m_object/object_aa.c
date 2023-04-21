/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Object module
*/

#include "../include/main.h"

void enable_object_onpressed(s_appdata *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    object->flags |= obj_onpressed;
}

void enable_object_onclick(s_appdata *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    object->flags |= obj_onclick;
}

void enable_object_onhover(s_appdata *adata, char *id)
{
    s_object *object = get_object(adata, id);

    if (object == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    object->flags |= obj_onhover;
}
