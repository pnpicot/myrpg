/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Switch module
*/

#include "../include/main.h"

void toggle_switch_final(s_appdata *adata, s_switch *switch_, \
s_target color_target, s_target indicator_target)
{
    float anim_speed = get_float(adata, "switch_animation_speed");
    s_button *middle_rect = get_button(adata, switch_->middle_rect->id);
    s_ref *middle_ref = get_ref(adata, middle_rect, TYPE_BUTTON);
    color_target.ref = middle_ref;
    transform(adata, anim_speed * 2, color_target);
    s_button *right_round = get_button(adata, switch_->right_round->id);
    s_ref *right_ref = get_ref(adata, right_round, TYPE_BUTTON);
    color_target.ref = right_ref;
    transform(adata, anim_speed, indicator_target);
    transform(adata, anim_speed * 2, color_target);
}

void toggle_switch_next(s_appdata *adata, sfVector2f new_pos, \
sfColor on_color, s_switch *switch_)
{
    sfColor off_color = get_config_color(adata, "switch_off");
    s_button *indicator = get_button(adata, switch_->indicator->id);
    s_ref *indicator_ref = get_ref(adata, indicator, TYPE_BUTTON);
    s_target indicator_target;
    indicator_target.pos = new_pos;
    indicator_target.flags = trf_move;
    indicator_target.ref = indicator_ref;
    s_button *left_round = get_button(adata, switch_->left_round->id);
    s_ref *left_ref = get_ref(adata, left_round, TYPE_BUTTON);
    s_target color_target;
    color_target.color = switch_->state ? on_color : off_color;
    color_target.flags = trf_color;
    color_target.ref = left_ref;
    float anim_speed = get_float(adata, "switch_animation_speed");
    transform(adata, anim_speed * 2, color_target);
    toggle_switch_final(adata, switch_, color_target, indicator_target);
}

void toggle_switch(s_appdata *adata, char *id)
{
    s_switch *switch_ = get_switch(adata, id);
    if (switch_ == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }
    switch_->state = switch_->state ? sfFalse : sfTrue;
    float length = get_float(adata, "switch_length");
    sfColor on_color = get_config_color(adata, "switch_on");
    if (!switch_->state) length *= -1;
    sfVector2f new_pos = get_button_pos(adata, switch_->indicator->id);
    new_pos.x += length;
    toggle_switch_next(adata, new_pos, on_color, switch_);
}

sfBool get_switch_state(s_appdata *adata, char *id)
{
    s_switch *switch_ = get_switch(adata, id);

    if (switch_ == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return (sfFalse);
    }

    return (switch_->state);
}

void delete_switch(s_appdata *adata, char *id)
{
    s_switch *switch_ = get_switch(adata, id);
    if (switch_ == NULL) {
        my_printf("Line: %d File: %s %s", __LINE__, __FILE__,
        get_error(adata, "unknown_id"));
        return;
    }
    linked_node *switches = adata->lists->switches;
    int ite = 0;
    while (switches != NULL && switches->data != NULL) {
        s_switch *cur = (s_switch *) switches->data;
        if (!my_strcmp(cur->id, id)) {
            delete_button(adata, cur->indicator->id);
            delete_button(adata, cur->left_round->id);
            delete_button(adata, cur->middle_rect->id);
            delete_button(adata, cur->right_round->id);
            break;
        }
        ite++;
        switches = switches->next;
    }
    linked_delete(&adata->lists->switches, ite);
}
