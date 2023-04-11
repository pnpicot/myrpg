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

    add_syringe(adata, health);
    set_syringe_texture(adata, health, get_texture(adata, "health_syr"));
}

void init_ingame_inventory(s_appdata *adata, char *container, char *rtex)
{
    init_syringes(adata);

    char *id = get_str(adata, "inventory");
    float width = get_float(adata, "inv_width");
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");

    add_rect(adata, id, 3);
    set_rect_rtex(adata, id, rtex);
    add_to_container(adata, container, (s_ref) { get_rect(adata, id), TYPE_RECT });

    sfVector2f size = { width, 50.0f };
    sfVector2f origin = { size.x / 2, size.y / 2 };

    set_rect_origin(adata, id, origin);
    move_rect(adata, id, (sfVector2f) { win_w / 2, win_h / 2 });
    color_rect(adata, id, get_color(0, 0, 0, 150));
}
