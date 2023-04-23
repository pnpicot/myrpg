/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Quest module
*/

#include "main.h"

void init_quets_n(s_appdata *adata)
{
    char *second = "eoapea";

    add_quest(adata, second);
    set_quest_icon(adata, second, get_texture(adata, "wall"));
    set_quest_title(adata, second, "Second quest");
    set_quest_text(adata, second, "Integer pulvinar leo urna, id ultricies libe"
    "ro venenatis ut. Fusce\n suscipit nec justo id iaculis. Morbi sapien sapie"
    "n, tempus sit amet\n urna nec, finibus pellentesque augue. In rutrum sagit"
    "tis feugiat. \nProin lobortis feugiat feugiat. Sed ac consequat massa, a v"
    "iverra \nnunc. Mauris elementum ac tellus nec placerat. Interdum et malesu"
    "ada\n fames ac ante ipsum primis in faucibus. Etiam tristique erat sit \na"
    "met tellus auctor, quis facilisis est pellentesque. Quisque a \nlectus sed"
    " ex accumsan posuere vitae id odio.");
}

void init_quests(s_appdata *adata)
{
    char *first = "duqdzqiu";

    add_quest(adata, first);
    set_quest_icon(adata, first, get_texture(adata, "health_syr"));
    set_quest_title(adata, first, "Use your transference");
    set_quest_text(adata, first, "Lorem ipsum dolor sit amet, consectetur adipi"
    "scing elit. Praesent \nvolutpat nibh dolor, blandit laoreet ante porttitor"
    " sit amet. Duis \ntempus congue tempus. Pellentesque euismod condimentum n"
    "isi nec \ncongue. Etiam quis metus id ex finibus porta eget sed nunc. Sed "
    "\nlacus elit, pharetra ac felis ut, sagittis ornare erat. Mauris \ninterdu"
    "m, velit ut hendrerit ultricies, lectus urna vehicula dolor,\n sed interdu"
    "m lorem nibh a elit. Fusce tempus mauris ex, a rutrum \n elit porttitor se"
    "d. In quis ultricies enim, nec venenatis risus.");
    set_quest_check(adata, first, &check_first_quest);

    init_quets_n(adata);
}

void init_quest_item_icon_n(s_appdata *adata, s_quest *cur)
{
    char *id = str_add(cur->id, "@[:icon]");
    char *rtex = get_str(adata, "rtex_ui");
    char *container = get_str(adata, "ctn_game");
    int layer = get_int(adata, "quest_layer");

    add_sprite(adata, id, layer + 2);
    set_sprite_rtex(adata, id, rtex);
    add_to_container(adata, container,
    (s_ref) { get_sprite(adata, id), TYPE_SPRITE });
    add_to_container(adata, get_str(adata, "ctn_quest"),
    (s_ref) { get_sprite(adata, id), TYPE_SPRITE });
    set_sprite_texture(adata, id, cur->icon);
}

void init_quest_item_icon(s_appdata *adata, s_quest *cur, \
sfVector2f item_size, sfVector2f item_pos)
{
    char *id = str_add(cur->id, "@[:icon]");
    float item_height = get_float(adata, "quest_item_height");
    float padding = get_float(adata, "quest_padding");
    init_quest_item_icon_n(adata, cur);
    sfVector2f target_size = {
    item_height - padding * 2, item_height - padding * 2 };
    sfVector2f scale = get_target_scale(target_size, cur->icon);
    sfVector2f pos;
    pos.x = item_pos.x + padding;
    pos.y = item_pos.y + padding;
    scale_sprite(adata, id, scale);
    move_sprite(adata, id, pos);
}

s_text *get_quest_popup_text_n(s_appdata *adata, s_quest *cur)
{
    char *id = str_add(cur->id, "@[:popup_text]");
    char *rtex = get_str(adata, "rtex_ui");
    int layer = get_int(adata, "quest_layer");
    char *container = get_str(adata, "ctn_game");

    add_text(adata, id, layer + 1);
    set_text_rtex(adata, id, rtex);
    add_to_container(adata, container,
    (s_ref) { get_text(adata, id), TYPE_TEXT });
    add_to_container(adata, get_str(adata, "ctn_quest"),
    (s_ref) { get_text(adata, id), TYPE_TEXT });
    edit_text(adata, id, cur->text);
    color_text(adata, id, sfWhite);
    set_text_font(adata, id, get_font(adata, "courier"));
}
