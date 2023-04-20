/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Switch module
*/

#include "../include/main.h"

void update_switch(s_appdata *adata, s_switch *switch_)
{
    sfFloatRect left_bounds = get_button_bounds(adata, switch_->left_round->id);
    sfVector2f left_pos = { left_bounds.left, left_bounds.top };
    float radius = get_float(adata, "switch_size");
    float padding = get_float(adata, "switch_padding");
    sfVector2f middle_pos;
    middle_pos.x = left_pos.x + radius;
    middle_pos.y = left_pos.y;
    move_button(adata, switch_->middle_rect->id, middle_pos);
    sfVector2f right_pos;
    right_pos.x = middle_pos.x + get_float(adata, "switch_length") - radius;
    right_pos.y = left_pos.y;
    move_button(adata, switch_->right_round->id, right_pos);
    sfVector2f indicator_pos;
    indicator_pos.x = left_pos.x + padding;
    indicator_pos.y = left_pos.y + padding;
    move_button(adata, switch_->indicator->id, indicator_pos);
}

void add_switch_next(s_appdata *adata, char *id, \
int layer, s_switch *new_switch)
{
    new_switch->id = id;
    new_switch->state = sfFalse;
    char *left_round_id = str_add(id, "@[:left_round]");
    char *right_round_id = str_add(id, "@[:right_round]");
    char *middle_rect_id = str_add(id, "@[:middle_rect]");
    char *indicator_id = str_add(id, "@[:indicator]");
    char *hitbox_id = str_add(id, "@[:hitbox]");
    new_switch->left_round = get_switch_left(adata, left_round_id, layer);
    new_switch->right_round = get_switch_right(adata, right_round_id, layer);
    new_switch->middle_rect = get_switch_middle(adata, middle_rect_id, layer);
    new_switch->indicator = get_switch_indicator(adata, indicator_id, layer);
    update_switch(adata, new_switch);
    linked_add(adata->lists->switches, new_switch);
}

void add_switch(s_appdata *adata, char *id, int layer)
{
    s_switch *switch_ = get_switch(adata, id);
    if (switch_ != NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "already_exists"));
        return;
    }
    s_switch *new_switch = malloc(sizeof(s_switch));
    if (new_switch == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "mem_alloc"));
        return;
    }
    add_switch_next(adata, id, layer, new_switch);
}

void set_switch_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_switch *switch_ = get_switch(adata, id);
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (switch_ == NULL || rtex == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    set_button_rtex(adata, switch_->indicator->id, rtex_id);
    set_button_rtex(adata, switch_->left_round->id, rtex_id);
    set_button_rtex(adata, switch_->middle_rect->id, rtex_id);
    set_button_rtex(adata, switch_->right_round->id, rtex_id);
}

void set_switch_ontoggle(s_appdata *adata, char *id, \
void (*on_toggle)(s_appdata *adata, s_ref *ref))
{
    s_switch *switch_ = get_switch(adata, id);

    if (switch_ == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__, get_error(adata, "unknown_id"));
        return;
    }

    char *indicator_obj = str_add(switch_->indicator->id, ":object");
    char *left_obj = str_add(switch_->left_round->id, ":object");
    char *middle_obj = str_add(switch_->middle_rect->id, ":object");
    char *right_obj = str_add(switch_->right_round->id, ":object");

    set_object_onclick(adata, indicator_obj, on_toggle);
    set_object_onclick(adata, left_obj, on_toggle);
    set_object_onclick(adata, middle_obj, on_toggle);
    set_object_onclick(adata, right_obj, on_toggle);
}
