/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Quest module
*/

#include "main.h"

s_quest *get_quest(s_appdata *adata, char *id)
{
    linked_node *quests = adata->game_data->quests;

    while (quests != NULL && quests->data != NULL) {
        s_quest *cur = (s_quest *) quests->data;

        if (!my_strcmp(cur->id, id)) return (cur);

        quests = quests->next;
    }

    return (NULL);
}

void delete_quest(s_appdata *adata, char *id)
{
    s_quest *quest = get_quest(adata, id);

    if (quest == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    linked_node *quests = adata->game_data->quests;
    int ite = 0;

    while (quests != NULL && quests->data != NULL) {
        s_quest *cur = (s_quest *) quests->data;

        if (!my_strcmp(cur->id, id)) break;

        ite++;
        quests = quests->next;
    }

    linked_delete(&adata->game_data->quests, ite);
}

void add_quest(s_appdata *adata, char *id)
{
    s_quest *quest = get_quest(adata, id);

    if (quest != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    s_quest *new_quest = malloc(sizeof(s_quest));

    if (new_quest == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    new_quest->id = id;
    new_quest->text = NULL;
    new_quest->title = NULL;
    new_quest->icon = NULL;
    new_quest->popup_rect = NULL;
    new_quest->popup_text = NULL;

    linked_add(adata->game_data->quests, new_quest);
}

void set_quest_title(s_appdata *adata, char *id, char *title)
{
    s_quest *quest = get_quest(adata, id);

    if (quest == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    quest->title = title;
}

void set_quest_text(s_appdata *adata, char *id, char *text)
{
    s_quest *quest = get_quest(adata, id);

    if (quest == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    quest->text = text;
}

void set_quest_icon(s_appdata *adata, char *id, sfTexture *texture)
{
    s_quest *quest = get_quest(adata, id);

    if (quest == NULL) {
        my_printf(get_error(adata, "unknown_id"));
        return;
    }

    quest->icon = texture;
}

void init_quests(s_appdata *adata)
{
    char *first = "duqdzqiu";

    add_quest(adata, first);
    set_quest_icon(adata, first, get_texture(adata, "health_syr"));
    set_quest_title(adata, first, "First quest");
    set_quest_text(adata, first, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent \nvolutpat nibh dolor, blandit laoreet ante porttitor sit amet. Duis \ntempus congue tempus. Pellentesque euismod condimentum nisi nec \ncongue. Etiam quis metus id ex finibus porta eget sed nunc. Sed \nlacus elit, pharetra ac felis ut, sagittis ornare erat. Mauris \ninterdum, velit ut hendrerit ultricies, lectus urna vehicula dolor,\n sed interdum lorem nibh a elit. Fusce tempus mauris ex, a rutrum \n elit porttitor sed. In quis ultricies enim, nec venenatis risus.");

    char *second = "eoapea";

    add_quest(adata, second);
    set_quest_icon(adata, second, get_texture(adata, "wall"));
    set_quest_title(adata, second, "Second quest");
    set_quest_text(adata, second, "Integer pulvinar leo urna, id ultricies libero venenatis ut. Fusce\n suscipit nec justo id iaculis. Morbi sapien sapien, tempus sit amet\n urna nec, finibus pellentesque augue. In rutrum sagittis feugiat. \nProin lobortis feugiat feugiat. Sed ac consequat massa, a viverra \nnunc. Mauris elementum ac tellus nec placerat. Interdum et malesuada\n fames ac ante ipsum primis in faucibus. Etiam tristique erat sit \namet tellus auctor, quis facilisis est pellentesque. Quisque a \nlectus sed ex accumsan posuere vitae id odio.");
}

void init_quest_item_icon(s_appdata *adata, s_quest *cur, \
sfVector2f item_size, sfVector2f item_pos)
{
    char *id = str_add(cur->id, "@[:icon]");
    char *rtex = get_str(adata, "rtex_ui");
    char *container = get_str(adata, "ctn_game");
    float item_height = get_float(adata, "quest_item_height");
    float padding = get_float(adata, "quest_padding");
    int layer = get_int(adata, "quest_layer");

    add_sprite(adata, id, layer + 2);
    set_sprite_rtex(adata, id, rtex);
    add_to_container(adata, container, (s_ref) { get_sprite(adata, id), TYPE_SPRITE });
    set_sprite_texture(adata, id, cur->icon);

    sfVector2f target_size = { item_height - padding * 2, item_height - padding * 2 };
    sfVector2u size = sfTexture_getSize(cur->icon);
    sfVector2f scale;

    scale.x = target_size.x / size.x;
    scale.y = target_size.y / size.y;

    sfVector2f pos;
    pos.x = item_pos.x + padding;
    pos.y = item_pos.y + padding;

    scale_sprite(adata, id, scale);
    move_sprite(adata, id, pos);
}

s_text *get_quest_popup_text(s_appdata *adata, s_quest *cur, \
sfVector2f bg_size, sfVector2f bg_pos)
{
    char *id = str_add(cur->id, "@[:popup_text]");
    int layer = get_int(adata, "quest_layer");
    char *rtex = get_str(adata, "rtex_ui");
    float padding = get_float(adata, "quest_padding");
    char *container = get_str(adata, "ctn_game");

    add_text(adata, id, layer + 1);
    set_text_rtex(adata, id, rtex);
    add_to_container(adata, container, (s_ref) { get_text(adata, id), TYPE_TEXT });
    edit_text(adata, id, cur->text);
    color_text(adata, id, sfWhite);
    set_text_font(adata, id, get_font(adata, "courier"));

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

s_rect *get_quest_popup_rect(s_appdata *adata, s_quest *cur)
{
    char *id = str_add(cur->id, "@[:popup_rect]");
    int layer = get_int(adata, "quest_layer");
    char *rtex = get_str(adata, "rtex_ui");
    float padding = get_float(adata, "quest_padding");
    char *container = get_str(adata, "ctn_game");
    sfFloatRect bounds = get_text_bounds(adata, cur->popup_text->id);

    add_rect(adata, id, layer);

    sfVector2f size;
    size.x = bounds.width + (padding * 2);
    size.y = bounds.height + padding;

    sfVector2f pos;
    pos.x = bounds.left - padding;
    pos.y = bounds.top - padding;

    resize_rect(adata, id, size);
    move_rect(adata, id, pos);
    set_rect_rtex(adata, id, rtex);
    add_to_container(adata, container, (s_ref) { get_rect(adata, id), TYPE_RECT });
    color_rect(adata, id, get_color(0, 0, 0, 230));

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

void init_quest_items(s_appdata *adata, char *bg_id, sfVector2f bg_size, sfVector2f bg_pos)
{
    char *id = str_add(bg_id, "@[:title]");
    float width = get_float(adata, "quest_width");
    float padding = get_float(adata, "quest_padding");
    int layer = get_int(adata, "quest_layer");
    char *rtex = get_str(adata, "rtex_ui");
    char *container = get_str(adata, "ctn_game");
    float item_height = get_float(adata, "quest_item_height");
    linked_node *quests = adata->game_data->quests;
    int ite = 0;

    while (quests != NULL && quests->data != NULL) {
        s_quest *cur = (s_quest *) quests->data;
        char *id = str_m_add(4, bg_id, "@[:item-", nbr_to_str(ite), "]");

        add_button(adata, id, TYPE_RECT, layer + 1);
        set_button_rtex(adata, id, rtex);
        add_to_container(adata, container, (s_ref) { get_button(adata, id), TYPE_BUTTON });
        color_button_bg(adata, id, get_color(247, 245, 195, 100));
        color_button_fg(adata, id, sfWhite);
        set_button_font(adata, id, get_font(adata, "courier"));
        edit_button(adata, id, substr(cur->title, 0, 40));
        resize_button_text(adata, id, 18);

        sfVector2f size;
        size.x = width - (padding * 2);
        size.y = item_height;

        sfVector2f pos;
        pos.x = bg_pos.x + padding;
        pos.y = bg_pos.y + padding + 40.0f + (item_height * ite) + (padding * ite);

        resize_button(adata, id, size);
        move_button(adata, id, pos);

        char *obj_id = str_add(id, "@[:object]");

        add_object(adata, obj_id, (s_ref) { get_button(adata, id), TYPE_BUTTON });
        set_object_hover_bg(adata, obj_id, get_color(247, 245, 195, 120));
        set_object_pressed_bg(adata, obj_id, get_color(247, 245, 195, 140));
        set_object_onclick(adata, obj_id, &toggle_quest);
        init_quest_item_icon(adata, cur, size, pos);

        cur->popup_text = get_quest_popup_text(adata, cur, size, pos);
        cur->popup_rect = get_quest_popup_rect(adata, cur);

        ite++;
        quests = quests->next;
    }
}

void init_quest_title(s_appdata *adata, char *bg_id, sfVector2f bg_size, sfVector2f bg_pos)
{
    char *id = str_add(bg_id, "@[:title]");
    float padding = get_float(adata, "quest_padding");
    int layer = get_int(adata, "quest_layer");
    char *rtex = get_str(adata, "rtex_ui");
    char *container = get_str(adata, "ctn_game");
    int quest_count = linked_count(adata->game_data->quests);

    add_text(adata, id, layer + 1);
    set_text_font(adata, id, get_font(adata, "courier"));
    color_text(adata, id, sfWhite);
    edit_text(adata, id, str_m_add(3, "Quests (", nbr_to_str(quest_count), ")"));
    set_text_rtex(adata, id, rtex);
    add_to_container(adata, id, (s_ref) { get_text(adata, id), TYPE_TEXT });
    resize_text(adata, id, 22);

    sfFloatRect bounds = get_text_bounds(adata, id);
    sfVector2f origin = { bounds.width / 2, bounds.height / 2 };

    set_text_origin(adata, id, origin);

    sfVector2f pos;
    pos.x = bg_pos.x + (bg_size.x / 2);
    pos.y = bg_pos.y + padding + (bounds.height / 2);

    move_text(adata, id, pos);
    init_quest_items(adata, bg_id, bg_size, bg_pos);
}

void init_quest_ui(s_appdata *adata)
{
    char *id = get_str(adata, "quest_bg");
    float width = get_float(adata, "quest_width");
    float padding = get_float(adata, "quest_padding");
    int layer = get_int(adata, "quest_layer");
    int win_h = get_int(adata, "win_h");
    char *rtex = get_str(adata, "rtex_ui");
    char *container = get_str(adata, "ctn_game");
    float item_height = get_float(adata, "quest_item_height");
    int quest_count = linked_count(adata->game_data->quests);

    add_rect(adata, id, layer);

    sfVector2f size;
    size.x = width;
    size.y = 50.0f + (item_height * quest_count) + (padding * quest_count);

    sfVector2f pos = { 10, (win_h / 2) - (size.y / 2) };

    resize_rect(adata, id, size);
    move_rect(adata, id, pos);
    set_rect_rtex(adata, id, rtex);
    add_to_container(adata, container, (s_ref) { get_rect(adata, id), TYPE_RECT });
    color_rect(adata, id, get_color(0, 0, 0, 230));
    set_rect_outline(adata, id, get_color(40, 40, 40, 230), 1.0f);
    init_quest_title(adata, id, size, pos);
}
