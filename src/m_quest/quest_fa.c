/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Quest module
*/

#include "main.h"

void init_quest_item_next(s_appdata *adata, s_tmp_questitem tmp)
{
    float width = get_float(adata, "quest_width");
    float item_height = get_float(adata, "quest_item_height");
    float padding = get_float(adata, "quest_padding");
    color_button_bg(adata, tmp.id, get_color(247, 245, 195, 100));
    color_button_fg(adata, tmp.id, sfWhite);
    set_button_font(adata, tmp.id, get_font(adata, "courier"));
    edit_button(adata, tmp.id, substr(tmp.cur->title, 0, 40));
    resize_button_text(adata, tmp.id, 18);
    tmp.cur->item = get_button(adata, tmp.id);
    sfVector2f size;
    size.x = width - (padding * 2);
    size.y = item_height;
    float y_shift = (item_height * tmp.ite) + (padding * tmp.ite);
    sfVector2f pos = { tmp.bg_pos.x + padding, 0 };
    pos.y = tmp.bg_pos.y + padding + 40.0f + y_shift;
    resize_button(adata, tmp.id, size);
    move_button(adata, tmp.id, pos);
    tmp.cur->popup_text = get_quest_popup_text(adata, tmp.cur, size, pos);
    tmp.cur->popup_rect = get_quest_popup_rect(adata, tmp.cur);
    init_quest_item_icon(adata, tmp.cur, size, pos);
}

void init_quest_items(s_appdata *adata, char *bg_id, sfVector2f bg_size,
sfVector2f bg_pos)
{
    int layer = get_int(adata, "quest_layer");
    char *rtex = get_str(adata, "rtex_ui");
    char *container = get_str(adata, "ctn_game");
    linked_node *quests = adata->game_data->quests;
    int ite = 0;
    for (;quests != NULL && quests->data != NULL;++ite) {
        s_quest *cur = (s_quest *) quests->data;
        char *str_ite = nbr_to_str(ite);
        char *id = str_m_add(4, bg_id, "@[:item-", str_ite, "]");
        free(str_ite);
        add_button(adata, id, TYPE_RECT, layer + 1);
        set_button_rtex(adata, id, rtex);
        s_ref ref = { get_button(adata, id), TYPE_BUTTON };
        add_to_container(adata, container, ref);
        add_to_container(adata, get_str(adata, "ctn_quest"), ref);
        init_quest_item_next(adata, (s_tmp_questitem) { id, cur, ite, bg_pos });
        init_quest_item_object(adata, id, ref);
        quests = quests->next;
    }
}

void init_quest_title_n(s_appdata *adata, char *bg_id, sfVector2f bg_size,
sfVector2f bg_pos)
{
    char *id = str_add(bg_id, "@[:title]");
    float padding = get_float(adata, "quest_padding");
    sfFloatRect bounds = get_text_bounds(adata, id);
    sfVector2f origin = { bounds.width / 2, bounds.height / 2 };

    set_text_origin(adata, id, origin);

    sfVector2f pos;
    pos.x = bg_pos.x + (bg_size.x / 2);
    pos.y = bg_pos.y + padding + (bounds.height / 2);

    move_text(adata, id, pos);
    init_quest_items(adata, bg_id, bg_size, bg_pos);
}

void init_quest_title(s_appdata *adata, char *bg_id, sfVector2f bg_size,
sfVector2f bg_pos)
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
    char *str_quest_count = nbr_to_str(quest_count);
    edit_text(adata, id, str_m_add(3, "Quests (", str_quest_count, ")"));
    free(str_quest_count);
    set_text_rtex(adata, id, rtex);
    add_to_container(adata, id, (s_ref) { get_text(adata, id), TYPE_TEXT });
    add_to_container(adata, get_str(adata, "ctn_quest"),
    (s_ref) { get_text(adata, id), TYPE_TEXT });
    resize_text(adata, id, 22);
    init_quest_title_n(adata, bg_id, bg_size, bg_pos);
}

void init_quest_ui_n(s_appdata *adata, char *id)
{
    char *container = get_str(adata, "ctn_game");
    char *rtex = get_str(adata, "rtex_ui");

    set_rect_rtex(adata, id, rtex);
    add_to_container(adata, container,
    (s_ref) { get_rect(adata, id), TYPE_RECT });
    add_to_container(adata, get_str(adata, "ctn_quest"),
    (s_ref) { get_rect(adata, id), TYPE_RECT });
    color_rect(adata, id, get_color(0, 0, 0, 230));
    set_rect_outline(adata, id, get_color(40, 40, 40, 230), 1.0f);
}
