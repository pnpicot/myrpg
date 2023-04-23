/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Inventory module
*/

#include "main.h"

void init_inventory_title(s_appdata *adata, char *container, char *rtex, \
sfFloatRect inv_bounds)
{
    char *id = str_add(get_str(adata, "inventory"), "@[:title]");
    float padding = get_float(adata, "inv_padding");
    char *ctn = get_str(adata, "ctn_inv");
    add_text(adata, id, get_int(adata, "inv_layer") + 1);
    set_text_rtex(adata, id, rtex);
    s_ref ref = { get_text(adata, id), TYPE_TEXT };
    add_to_container(adata, container, ref);
    add_to_container(adata, ctn, ref);
    set_text_font(adata, id, get_font(adata, "courier"));
    edit_text(adata, id, "Inventory");
    color_text(adata, id, sfWhite);
    resize_text(adata, id, 22);
    sfFloatRect bounds = get_text_bounds(adata, id);
    sfVector2f origin = { bounds.width / 2, bounds.height / 2 };
    sfVector2f pos;
    pos.x = inv_bounds.left + (inv_bounds.width / 2);
    pos.y = inv_bounds.top + ((30.0f + padding * 2) / 2);
    set_text_origin(adata, id, origin);
    move_text(adata, id, pos);
    init_inventory_items(adata, container, rtex, inv_bounds);
}

void init_inventory_next(s_appdata *adata, char *id, \
char *container, char *rtex)
{
    char *ctn = get_str(adata, "ctn_inv");
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    float width = get_float(adata, "inv_width");
    float item_height = get_float(adata, "inv_item_height");
    float padding = get_float(adata, "inv_padding");
    int syr_count = linked_count(adata->game_data->syringes);
    float list_height = (syr_count * item_height) + (padding * syr_count);
    float size_y = (30.0f + padding * 2) + list_height + padding;
    sfVector2f size = { width * win_w, size_y };
    sfVector2f origin = { size.x / 2, size.y / 2 };
    set_rect_origin(adata, id, origin);
    resize_rect(adata, id, size);
    move_rect(adata, id, (sfVector2f) { win_w / 2, win_h / 2 });
    color_rect(adata, id, get_color(0, 0, 0, 230));
    sfFloatRect bounds = get_rect_bounds(adata, id);
    init_inventory_title(adata, container, rtex, bounds);
    set_container_active(adata, ctn, 0);
}

void init_ingame_inventory(s_appdata *adata, char *container, char *rtex)
{
    init_syringes(adata);
    char *ctn = get_str(adata, "ctn_inv");
    add_container(adata, ctn);
    char *id = get_str(adata, "inventory");
    add_rect(adata, id, get_int(adata, "inv_layer"));
    set_rect_rtex(adata, id, rtex);
    s_ref ref = { get_rect(adata, id), TYPE_RECT };
    add_to_container(adata, container, ref);
    add_to_container(adata, ctn, ref);
    init_inventory_next(adata, id, container, rtex);
}
