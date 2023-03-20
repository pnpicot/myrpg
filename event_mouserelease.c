/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Mouse release event module
*/

#include "include/main.h"

void register_mouserelease(s_appdata *adata, sfMouseButtonEvent mouse)
{
    input_check_released(adata);
    slider_check_released(adata);
    object_check_released(adata);
}
