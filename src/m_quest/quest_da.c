/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Quest module
*/

#include "main.h"

void init_quests_n(s_appdata *adata)
{
    char *third = "wsbiergzfrh";
    add_quest(adata, third);
    set_quest_icon(adata, third, get_texture(adata, "health_syr"));
    set_quest_title(adata, third, "Use a syringe");
    set_quest_text(adata, third, "Try to use a syringe.\n"
    "You can do this by pressing the 'I' key or the 'Tab' key on your keyboard."
    "\n If you succeed, you will be able to use the syringe's abilities. \n"
    "Syringe are gathered by killing enemies. \n");
    set_quest_check(adata, third, &check_third_quest);
}

void init_quests(s_appdata *adata)
{
    char *first = "duqdzqiu";
    add_quest(adata, first);
    set_quest_icon(adata, first, get_texture(adata, "bloom_block"));
    set_quest_title(adata, first, "Use your transference");
    set_quest_text(adata, first, "Try to use your transference to take control "
    "of an enemy. \nYou can do this by pressing the 'E' key on your keyboard.\n"
    "If you succeed, you will be able to use the enemy's abilities. \n");
    set_quest_check(adata, first, &check_first_quest);
    char *second = "eoapea";
    add_quest(adata, second);
    set_quest_icon(adata, second, get_texture(adata, "ghost"));
    set_quest_title(adata, second, "Kill an enemy");
    set_quest_text(adata, second, "Try to kill an enemy. \nYou can do this by "
    "taking control of an enemy and using its abilities. \n"
    "You will gain Moula when you kill an enemy. \n"
    "You can use Moula to buy new abilities in the skill tree. \nYou can access"
    " the skill tree by pressing the 'T' key on your keyboard. \n");
    set_quest_check(adata, second, &check_second_quest);
    init_quests_n(adata);
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
    cur->popup_rect->active = 0;
    cur->popup_text->active = 0;
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
