/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Mouse release event module
*/

#include "main.h"

void register_mouserelease(s_appdata *adata, sfMouseButtonEvent mouse)
{
    input_check_released(adata);
    slider_check_released(adata);

    int btn_event = object_check_released(adata);

    if (!btn_event) add_light_to_cursor(adata);
}
