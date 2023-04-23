/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Quest module
*/

#include "main.h"

s_text *get_quest_popup_text(s_appdata *adata, s_quest *cur, \
sfVector2f bg_size, sfVector2f bg_pos)
{
    char *id = str_add(cur->id, "@[:popup_text]");
    int layer = get_int(adata, "quest_layer");
    float padding = get_float(adata, "quest_padding");

    get_quest_popup_text_n(adata, cur);

    sfFloatRect bounds = get_text_bounds(adata, id);
    sfVector2f origin = { 0, bounds.height / 2 };
    sfVector2f pos;

    pos.x = bg_size.x + bg_pos.x + 10.0f + padding * 3;
    pos.y = bg_pos.y + (bg_size.y / 2);

    set_text_origin(adata, id, origin);
    move_text(adata, id, pos);

    s_text *text = get_text(adata, id);

    return (text);
}

void get_quest_popup_rect_n(s_appdata *adata, s_quest *cur, sfVector2f size,
sfFloatRect bounds)
{
    char *id = str_add(cur->id, "@[:popup_rect]");
    char *container = get_str(adata, "ctn_game");
    float padding = get_float(adata, "quest_padding");
    char *rtex = get_str(adata, "rtex_ui");
    sfVector2f pos;
    pos.x = bounds.left - padding;
    pos.y = bounds.top - padding;

    resize_rect(adata, id, size);
    move_rect(adata, id, pos);
    set_rect_rtex(adata, id, rtex);
    add_to_container(adata, container,
    (s_ref) { get_rect(adata, id), TYPE_RECT });
    add_to_container(adata, get_str(adata, "ctn_quest"),
    (s_ref) { get_rect(adata, id), TYPE_RECT });
    color_rect(adata, id, get_color(0, 0, 0, 230));
}

s_rect *get_quest_popup_rect(s_appdata *adata, s_quest *cur)
{
    char *id = str_add(cur->id, "@[:popup_rect]");
    int layer = get_int(adata, "quest_layer");
    float padding = get_float(adata, "quest_padding");
    sfFloatRect bounds = get_text_bounds(adata, cur->popup_text->id);
    add_rect(adata, id, layer);
    sfVector2f size;
    size.x = bounds.width + (padding * 2);
    size.y = bounds.height + padding;
    get_quest_popup_rect_n(adata, cur, size, bounds);
    s_rect *rect = get_rect(adata, id);
    return (rect);
}

void toggle_quest(s_appdata *adata, s_ref *ref)
{
    s_button *button = (s_button *) ref->ref;
    const char *title = get_text_str(adata, button->text->id);
    linked_node *quests = adata->game_data->quests;

    while (quests != NULL && quests->data != NULL) {
        s_quest *cur = (s_quest *) quests->data;

        if (!my_strcmp(cur->title, title)) {
            cur->popup_rect->active = !cur->popup_rect->active;
            cur->popup_text->active = !cur->popup_text->active;
        } else {
            cur->popup_rect->active = 0;
            cur->popup_text->active = 0;
        }

        quests = quests->next;
    }
}

void init_quest_item_object(s_appdata *adata, char *id, s_ref ref)
{
    char *obj_id = str_add(id, "@[:object]");
    add_object(adata, obj_id, ref);
    set_object_hover_bg(adata, obj_id, get_color(247, 245, 195, 120));
    set_object_pressed_bg(adata, obj_id, get_color(247, 245, 195, 140));
    set_object_onclick(adata, obj_id, &toggle_quest);
}
