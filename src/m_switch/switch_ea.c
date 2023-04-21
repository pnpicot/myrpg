/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Switch module
*/

#include "../include/main.h"

void move_switch(s_appdata *adata, char *id, sfVector2f pos)
{
    s_switch *switch_ = get_switch(adata, id);

    if (switch_ == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    move_button(adata, switch_->left_round->id, pos);
    update_switch(adata, switch_);
}

void translate_switch(s_appdata *adata, char *id, sfVector2f pos_ch)
{
    s_switch *switch_ = get_switch(adata, id);

    if (switch_ == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    translate_button(adata, switch_->left_round->id, pos_ch);
    update_switch(adata, switch_);
}

void set_switch_active(s_appdata *adata, char *id, sfUint8 active)
{
    s_switch *switch_ = get_switch(adata, id);

    if (switch_ == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    set_button_active(adata, switch_->indicator->id, active);
    set_button_active(adata, switch_->left_round->id, active);
    set_button_active(adata, switch_->middle_rect->id, active);
    set_button_active(adata, switch_->right_round->id, active);
}

void set_switch_origin(s_appdata *adata, char *id, sfVector2f origin)
{
    s_switch *switch_ = get_switch(adata, id);

    if (switch_ == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }

    set_button_origin(adata, switch_->left_round->id, origin);
    update_switch(adata, switch_);
}

sfVector2f get_switch_pos(s_appdata *adata, char *id)
{
    s_switch *switch_ = get_switch(adata, id);

    if (switch_ == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (get_button_pos(adata, switch_->left_round->id));
}
