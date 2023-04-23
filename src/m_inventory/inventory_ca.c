/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Inventory module
*/

#include "main.h"

sfVector2f get_target_scale(sfVector2f target_size, sfTexture *texture)
{
    sfVector2u size = sfTexture_getSize(texture);
    sfVector2f scale;

    scale.x = target_size.x / size.x;
    scale.y = target_size.y / size.y;

    return (scale);
}

void init_inventory_item_sprite(s_appdata *adata, sfVector2f syr_pos, \
char *syr_id, s_syringe *cur)
{
    char *id = str_add(syr_id, "@[:icon]");
    float height = get_float(adata, "inv_item_height");
    char *container = get_str(adata, "ctn_game");
    float padding = get_float(adata, "inv_padding");
    char *ctn = get_str(adata, "ctn_inv");
    add_sprite(adata, id, get_int(adata, "inv_layer") + 2);
    set_sprite_texture(adata, id, cur->tex);
    set_sprite_color(adata, id, cur->color);
    set_sprite_rtex(adata, id, get_str(adata, "rtex_ui"));
    s_ref ref = { get_sprite(adata, id), TYPE_SPRITE };
    add_to_container(adata, container, ref);
    add_to_container(adata, ctn, ref);
    sfVector2f target_size = { height - padding * 2, height - padding * 2 };
    sfVector2f scale = get_target_scale(target_size, cur->tex);
    sfVector2f pos;
    pos.x = syr_pos.x + padding;
    pos.y = syr_pos.y + padding;
    scale_sprite(adata, id, scale);
    move_sprite(adata, id, pos);
}

void init_item_object(s_appdata *adata, char *id, s_ref ref,
s_syringe *syringe)
{
    char *obj_id = str_add(id, "@[:object]");
    add_object(adata, obj_id, ref);
    set_object_hover_bg(adata, obj_id, get_color(255, 255, 255, 20));
    set_object_pressed_bg(adata, obj_id, get_color(255, 255, 255, 30));
    set_object_onclick(adata, obj_id, syringe->on_use);
}

void init_item_next(s_appdata *adata, s_tmp_invitem tmp)
{
    float inv_width = get_float(adata, "inv_width");
    float padding = get_float(adata, "inv_padding");
    float item_height = get_float(adata, "inv_item_height");
    int win_w = get_int(adata, "win_w");
    s_syringe *cur = tmp.cur;
    color_button_bg(adata, tmp.id, get_color(255, 255, 255, 10));
    color_button_fg(adata, tmp.id, sfWhite);
    set_button_font(adata, tmp.id, get_font(adata, "courier"));
    resize_button_text(adata, tmp.id, 20);
    char *new_text = str_m_add(3, cur->name, " x", nbr_to_str(cur->count));
    edit_button(adata, tmp.id, new_text);
    sfVector2f size = { 0, item_height };
    size.x = (inv_width * win_w) - (padding * 2);
    float y_shift = (tmp.ite * item_height) + (tmp.ite * padding);
    sfVector2f pos;
    pos.x = tmp.inv_bounds.left + padding;
    pos.y = tmp.inv_bounds.top + padding + (30.0f + padding * 2) + y_shift;
    resize_button(adata, tmp.id, size);
    move_button(adata, tmp.id, pos);
    init_inventory_item_sprite(adata, pos, tmp.id, cur);
}

void init_inventory_items(s_appdata *adata, char *container, char *rtex, \
sfFloatRect inv_bounds)
{
    linked_node *syringes = adata->game_data->syringes;
    char *inv_id = get_str(adata, "inventory");
    int ite = 0;
    char *ctn = get_str(adata, "ctn_inv");
    while (syringes != NULL && syringes->data != NULL) {
        s_syringe *cur = (s_syringe *) syringes->data;
        char *str_ite = nbr_to_str(ite);
        char *id = str_m_add(4, inv_id, "@[:item-", str_ite, "]");
        free(str_ite);
        add_button(adata, id, TYPE_RECT, get_int(adata, "inv_layer") + 1);
        set_button_rtex(adata, id, rtex);
        s_ref ref = { get_button(adata, id), TYPE_BUTTON };
        add_to_container(adata, container, ref);
        add_to_container(adata, ctn, ref);
        init_item_next(adata, (s_tmp_invitem) { id, ite, cur, inv_bounds });
        init_item_object(adata, id, ref, cur);
        ite++;
        syringes = syringes->next;
    }
}
