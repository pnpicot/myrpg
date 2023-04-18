/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Inventory module
*/

#include "main.h"

void init_syringes(s_appdata *adata)
{
    char *health = get_str(adata, "health_syr");
    char *health1 = str_add(get_str(adata, "health_syr"), "1");
    char *health2 = str_add(get_str(adata, "health_syr"), "2");
    char *health3 = str_add(get_str(adata, "health_syr"), "3");

    add_syringe(adata, health);
    set_syringe_texture(adata, health, get_texture(adata, "health_syr"));

    add_syringe(adata, health1);
    set_syringe_texture(adata, health1, get_texture(adata, "health_syr"));

    add_syringe(adata, health2);
    set_syringe_texture(adata, health2, get_texture(adata, "health_syr"));

    add_syringe(adata, health3);
    set_syringe_texture(adata, health3, get_texture(adata, "health_syr"));
}

void init_inventory_items(s_appdata *adata, char *container, char *rtex, \
sfFloatRect inv_bounds)
{
    linked_node *syringes = adata->game_data->syringes;
    char *inv_id = get_str(adata, "inventory");
    int ite = 0;
    int inv_layer = get_int(adata, "inv_layer");
    float inv_width = get_float(adata, "inv_width");
    float padding = get_float(adata, "inv_padding");
    float item_height = get_float(adata, "inv_item_height");
    int win_w = get_int(adata, "win_w");

    while (syringes != NULL && syringes->data != NULL) {
        s_syringe *cur = (s_syringe *) syringes->data;
        char *id = str_m_add(4, inv_id, "@[:item-", nbr_to_str(ite), "]");

        add_button(adata, id, TYPE_RECT, inv_layer + 1);
        set_button_rtex(adata, id, rtex);
        add_to_container(adata, id, (s_ref) { get_button(adata, id), TYPE_BUTTON });
        color_button_bg(adata, id, get_color(255, 255, 255, 10));
        color_button_fg(adata, id, sfWhite);
        set_button_font(adata, id, get_font(adata, "courier"));
        resize_button_text(adata, id, 20);
        edit_button(adata, id, cur->id);

        sfVector2f size;
        size.x = (inv_width * win_w) - (padding * 2);
        size.y = item_height;

        sfVector2f pos;
        pos.x = inv_bounds.left + padding;
        pos.y = inv_bounds.top + padding + (30.0f + padding * 2) + (ite * item_height) + (ite * padding);

        resize_button(adata, id, size);
        move_button(adata, id, pos);

        ite++;
        syringes = syringes->next;
    }
}

void init_inventory_title(s_appdata *adata, char *container, char *rtex, \
sfFloatRect inv_bounds)
{
    char *id = str_add(get_str(adata, "inventory"), "@[:title]");
    float padding = get_float(adata, "inv_padding");

    add_text(adata, id, get_int(adata, "inv_layer") + 1);
    set_text_rtex(adata, id, rtex);
    add_to_container(adata, container, (s_ref) { get_text(adata, id), TYPE_TEXT });
    set_text_font(adata, id, get_font(adata, "courier"));
    edit_text(adata, id, "Inventory");
    color_text(adata, id, sfWhite);
    resize_text(adata, id, 22);

    sfFloatRect bounds = get_text_bounds(adata, id);
    sfVector2f origin;
    sfVector2f pos;

    origin.x = bounds.width / 2;
    origin.y = bounds.height / 2;

    pos.x = inv_bounds.left + (inv_bounds.width / 2);
    pos.y = inv_bounds.top + ((30.0f + padding * 2) / 2);

    set_text_origin(adata, id, origin);
    move_text(adata, id, pos);
    init_inventory_items(adata, container, rtex, inv_bounds);
}

void init_ingame_inventory(s_appdata *adata, char *container, char *rtex)
{
    init_syringes(adata);

    char *id = get_str(adata, "inventory");
    float width = get_float(adata, "inv_width");
    float item_height = get_float(adata, "inv_item_height");
    float padding = get_float(adata, "inv_padding");
    int syr_count = linked_count(adata->game_data->syringes);
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");

    add_rect(adata, id, get_int(adata, "inv_layer"));
    set_rect_rtex(adata, id, rtex);
    add_to_container(adata, container, (s_ref) { get_rect(adata, id), TYPE_RECT });

    float list_height = (syr_count * item_height) + (padding * syr_count);
    sfVector2f size = { width * win_w, (30.0f + padding * 2) + list_height + padding };
    sfVector2f origin = { size.x / 2, size.y / 2 };

    set_rect_origin(adata, id, origin);
    resize_rect(adata, id, size);
    move_rect(adata, id, (sfVector2f) { win_w / 2, win_h / 2 });
    color_rect(adata, id, get_color(0, 0, 0, 200));

    sfFloatRect bounds = get_rect_bounds(adata, id);

    init_inventory_title(adata, container, rtex, bounds);
}
