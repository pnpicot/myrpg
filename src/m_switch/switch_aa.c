/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Switch module
*/

#include "../include/main.h"

sfVector2f get_switch_origin(s_appdata *adata, char *id)
{
    s_switch *switch_ = get_switch(adata, id);

    if (switch_ == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (get_button_origin(adata, switch_->left_round->id));
}
