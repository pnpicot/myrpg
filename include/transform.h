/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Transform module
*/

#pragma once

#include "main.h"

s_transform *get_transform(s_appdata *adata, char *id);
void delete_transform_next(s_appdata *adata, s_transform *cur);
void delete_transform(s_appdata *adata, char *id);
void transform_move(s_appdata *adata, s_transform *trf);
void transform_scale(s_appdata *adata, s_transform *trf);
void transform_color(s_appdata *adata, s_transform *transform);
void transform_rotation(s_appdata *adata, s_transform *trf);
void end_transform(s_appdata *adata, s_transform *trf);
void transform_update(s_appdata *adata);
void transform_init(s_appdata *adata, s_transform *ntrf, \
float delta_time, s_target target);
void transform_next(s_appdata *adata, s_transform *ntrf, \
s_target target, float delay);
void transform(s_appdata *adata, float delay, s_target target);
