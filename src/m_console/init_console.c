/*
** EPITECH PROJECT, 2023
** m_console
** File description:
** init_console
*/

#include "main.h"

void init_console_next(s_appdata *adata)
{
    char *console_titlebar_id = get_str(adata, "console_titlebar_id");
    add_rect(adata, console_titlebar_id, 3);
    color_rect(adata, console_titlebar_id, get_color(25, 25, 25, 240));
    set_rect_rtex(adata, console_titlebar_id, get_str(adata, "rtex_ui"));
    resize_rect(adata, console_titlebar_id, (sfVector2f) { 600, 50 });
    move_rect(adata, console_titlebar_id, (sfVector2f) { 100, 75 });

    char *consolde_text_id = get_str(adata, "console_text_id");
    add_text(adata, consolde_text_id, 4);
    set_text_rtex(adata, consolde_text_id, get_str(adata, "rtex_ui"));
    set_text_font(adata, consolde_text_id, get_font(adata, "mono"));
    color_text(adata, consolde_text_id, sfWhite);
    resize_text(adata, consolde_text_id, 30);
    edit_text(adata, consolde_text_id, "Console");
    move_text(adata, consolde_text_id, (sfVector2f) { 110, 85 });

}

void init_console(s_appdata *adata)
{
    char *console_id = get_str(adata, "console_id");
    add_container(adata, console_id);
    char *console_background_id = get_str(adata, "console_background_id");
    add_rect(adata, console_background_id, 3);
    color_rect(adata, console_background_id, get_color(0, 0, 0, 240));
    set_rect_rtex(adata, console_background_id, get_str(adata, "rtex_ui"));
    resize_rect(adata, console_background_id, (sfVector2f) { 600, 400 });
    move_rect(adata, console_background_id, (sfVector2f) { 100, 125 });
    init_console_next(adata);
    char *console_titlebar_id = get_str(adata, "console_titlebar_id");
    char *consolde_text_id = get_str(adata, "console_text_id");
    add_to_container(adata, console_id, (s_ref)
    { get_rect(adata, console_background_id), TYPE_RECT });
    add_to_container(adata, console_id, (s_ref)
    { get_rect(adata, console_titlebar_id), TYPE_RECT });
    add_to_container(adata, console_id, (s_ref)
    { get_text(adata, consolde_text_id), TYPE_TEXT });
    set_container_active(adata, console_id, sfFalse);
}
