/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Switch module
*/

#include "include/main.h"

s_switch *get_switch(s_appdata *adata, char *id)
{
    linked_node *switches = adata->lists->switches;

    while (switches != NULL && switches->data != NULL) {
        s_switch *cur = (s_switch *) switches->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        switches = switches->next;
    }

    return (NULL);
}

s_button *get_switch_left(s_appdata *adata, char *id, int layer)
{
    add_button(adata, id, TYPE_CIRCLE, layer);
    resize_button(adata, id, (sfVector2f) { get_float(adata, "switch_size"), 0 });
    color_button_bg(adata, id, get_config_color(adata, "switch_off"));

    char *obj_id = str_add(id, ":object");

    add_object(adata, obj_id, (s_ref) { get_button(adata, id), TYPE_BUTTON });

    return (get_button(adata, id));
}

s_button *get_switch_right(s_appdata *adata, char *id, int layer)
{
    add_button(adata, id, TYPE_CIRCLE, layer);
    resize_button(adata, id, (sfVector2f) { get_float(adata, "switch_size"), 0 });
    color_button_bg(adata, id, get_config_color(adata, "switch_off"));

    char *obj_id = str_add(id, ":object");

    add_object(adata, obj_id, (s_ref) { get_button(adata, id), TYPE_BUTTON });

    return (get_button(adata, id));
}

s_button *get_switch_middle(s_appdata *adata, char *id, int layer)
{
    float length = get_float(adata, "switch_length");
    float size = get_float(adata, "switch_size");

    add_button(adata, id, TYPE_RECT, layer);
    resize_button(adata, id, (sfVector2f) { length, size * 2 });
    color_button_bg(adata, id, get_config_color(adata, "switch_off"));

    char *obj_id = str_add(id, ":object");

    add_object(adata, obj_id, (s_ref) { get_button(adata, id), TYPE_BUTTON });

    return (get_button(adata, id));
}

s_button *get_switch_indicator(s_appdata *adata, char *id, int layer)
{
    float size = get_float(adata, "switch_size");
    float padding = get_float(adata, "switch_padding");

    add_button(adata, id, TYPE_CIRCLE, layer + 1);
    resize_button(adata, id, (sfVector2f) { size - padding, 0 });
    color_button_bg(adata, id, get_config_color(adata, "switch_indicator_idle"));

    char *obj_id = str_add(id, ":object");

    add_object(adata, obj_id, (s_ref) { get_button(adata, id), TYPE_BUTTON });
    set_object_hover_bg(adata, obj_id, get_config_color(adata, "switch_indicator_hover"));
    set_object_pressed_bg(adata, obj_id, get_config_color(adata, "switch_indicator_pressed"));

    return (get_button(adata, id));
}

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

void add_switch(s_appdata *adata, char *id, int layer)
{
    s_switch *switch_ = get_switch(adata, id);

    if (switch_ != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    s_switch *new_switch = malloc(sizeof(s_switch));

    if (new_switch == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

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

void set_switch_rtex(s_appdata *adata, char *id, char *rtex_id)
{
    s_switch *switch_ = get_switch(adata, id);
    s_rtex *rtex = get_rtex(adata, rtex_id);

    if (switch_ == NULL || rtex == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    set_button_rtex(adata, switch_->indicator->id, rtex_id);
    set_button_rtex(adata, switch_->left_round->id, rtex_id);
    set_button_rtex(adata, switch_->middle_rect->id, rtex_id);
    set_button_rtex(adata, switch_->right_round->id, rtex_id);
}

void set_switch_ontoggle(s_appdata *adata, char *id, void (*on_toggle)(s_appdata *adata, s_ref *ref))
{
    s_switch *switch_ = get_switch(adata, id);

    if (switch_ == NULL) {
        my_printf(get_error(adata, "unknown_id"));
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

void toggle_switch(s_appdata *adata, char *id)
{
    s_switch *switch_ = get_switch(adata, id);

    if (switch_ == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    switch_->state = switch_->state ? sfFalse : sfTrue;
    float length = get_float(adata, "switch_length");
    sfColor off_color = get_config_color(adata, "switch_off");
    sfColor on_color = get_config_color(adata, "switch_on");

    if (!switch_->state) length *= -1;

    sfVector2f new_pos = get_button_pos(adata, switch_->indicator->id);
    new_pos.x += length;

    s_target indicator_target;
    indicator_target.pos = new_pos;
    indicator_target.flags = trf_move;

    s_target color_target;
    color_target.color = switch_->state ? on_color : off_color;
    color_target.flags = trf_color;

    float anim_speed = get_float(adata, "switch_animation_speed");
    s_ref *indicator_ref = get_ref(adata, get_button(adata, switch_->indicator->id), TYPE_BUTTON);
    s_ref *left_ref = get_ref(adata, get_button(adata, switch_->left_round->id), TYPE_BUTTON);
    s_ref *middle_ref = get_ref(adata, get_button(adata, switch_->middle_rect->id), TYPE_BUTTON);
    s_ref *right_ref = get_ref(adata, get_button(adata, switch_->right_round->id), TYPE_BUTTON);

    transform(adata, indicator_ref, anim_speed, indicator_target);
    transform(adata, left_ref, anim_speed * 2, color_target);
    transform(adata, middle_ref, anim_speed * 2, color_target);
    transform(adata, right_ref, anim_speed * 2, color_target);
}

sfBool get_switch_state(s_appdata *adata, char *id)
{
    s_switch *switch_ = get_switch(adata, id);

    if (switch_ == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return (sfFalse);
    }

    return (switch_->state);
}

void delete_switch(s_appdata *adata, char *id)
{
    s_switch *switch_ = get_switch(adata, id);

    if (switch_ == NULL) {
        my_printf(get_error(adata, "unknown_id"));
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

void move_switch(s_appdata *adata, char *id, sfVector2f pos)
{
    s_switch *switch_ = get_switch(adata, id);

    if (switch_ == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    move_button(adata, switch_->left_round->id, pos);
    update_switch(adata, switch_);
}

void translate_switch(s_appdata *adata, char *id, sfVector2f pos_ch)
{
    s_switch *switch_ = get_switch(adata, id);

    if (switch_ == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    translate_button(adata, switch_->left_round->id, pos_ch);
    update_switch(adata, switch_);
}

void set_switch_active(s_appdata *adata, char *id, sfUint8 active)
{
    s_switch *switch_ = get_switch(adata, id);

    if (switch_ == NULL) {
        my_printf(get_error(adata, "unknown_id"));
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
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    set_button_origin(adata, switch_->left_round->id, origin);
    update_switch(adata, switch_);
}

sfVector2f get_switch_pos(s_appdata *adata, char *id)
{
    s_switch *switch_ = get_switch(adata, id);

    if (switch_ == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (get_button_pos(adata, switch_->left_round->id));
}

sfVector2f get_switch_origin(s_appdata *adata, char *id)
{
    s_switch *switch_ = get_switch(adata, id);

    if (switch_ == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return ((sfVector2f) { -1, -1 });
    }

    return (get_button_origin(adata, switch_->left_round->id));
}
